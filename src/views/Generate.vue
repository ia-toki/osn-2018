<template>
  <el-container>
    <el-aside class="aside" width="30%">
      <el-checkbox-group 
        class="option"
        v-model="tcs">
        <el-checkbox-button 
          v-for="tc in tc_option"
          :key="tc.tc"
          :label="tc.tc"
          :disabled="!data[tc.tc]">
          {{tc.name}}
        </el-checkbox-button>
      </el-checkbox-group>
      <el-radio-group 
        class="option"
        v-model="language">
        <el-radio-button 
          v-for="lang in language_option"
          :key="lang.lang"
          :label="lang.lang">
          {{lang.name}}
        </el-radio-button>
      </el-radio-group>
      <div class="option">
        <el-button @click="copyToClipboard">{{$t('generate.copy')}}</el-button>
        <el-button @click="downloadFile">{{$t('generate.download')}}</el-button>
      </div>
      <div class="option">
        <el-button 
          type="danger"
          @click="confirmDelete">
          {{$t('generate.delete')}}
        </el-button>
      </div>
    </el-aside>
    <el-main>
      <codemirror 
        ref="codemirror"
        class="codemirror"
        :value="code" 
        :options="cmOptions">
      </codemirror>
    </el-main>
  </el-container>
</template>

<script>
/* eslint-disable no-console */
import FileSaver from 'file-saver'

import cpp_template from '../templates/cpp.handlebars'
import pascal_template from '../templates/pascal.handlebars'

const modeMap = {
  'Pascal': 'text/x-pascal',
  'C++': 'text/x-c++src',
}

const templateMap = {
  'Pascal': pascal_template,
  'C++': cpp_template
}

const extensionMap = {
  'Pascal': 'pas',
  'C++': 'cpp'
}

export default {
  data() {
    return {
      cmOptions: {
        readOnly: true,
        mode: 'text/x-pascal',
      },
    }
  },
  localStorage: {
    data: {
      type: Object
    },
    language: {
      type: String,
      default: 'Pascal'
    },
    tcs: {
      type: Array,
      default: []
    },
  },
  mounted() {
    this.$refs.codemirror.codemirror.setSize(null, '100%')
  },
  computed: {
    tc_option () {
      return [{tc: '1', name: this.$t('generate.tc1')}, {tc: '2', name: this.$t('generate.tc2')}]
    },
    language_option () {
      return [{lang: 'Pascal', name: this.$t('generate.pascal')}, {lang: 'C++', name: this.$t('generate.cpp')}]
    },
    code () {
      return templateMap[this.language]({ 
        data: this.tcs.map(x => this.data[x]).filter(x => x)
      })
    }
  },
  watch: {
    language (value) {
      this.cmOptions.mode = modeMap[value]
    }
  },
  methods: {
    copyToClipboard () {
      this.$copyText(this.code).then(() => {
        this.$message({
          type: 'success',
          message: this.$t('generate.copyMessage.success')
        })
      }).catch(() => {
        this.$message({
          type: 'error',
          message: this.$t('generate.copyMessage.error')
        })
      })
    },
    downloadFile () {
      try {
        const blob = new Blob([this.code], {type: "text/plain"})
        FileSaver.saveAs(blob, `berebut-pizza.${extensionMap[this.language]}`)
        this.$message({
          type: 'success',
          message: this.$t('generate.downloadMessage.success')
        })
      } catch (e) {
        this.$message({
          type: 'error',
          message: this.$t('generate.downloadMessage.error')
        })
      }
    },
    confirmDelete () {
      this.$confirm(this.$t('generate.deleteWarning.body'), this.$t('generate.deleteWarning.title'), {
        confirmButtonText: this.$t('generate.deleteWarning.confirm'),
        cancelButtonText: this.$t('generate.deleteWarning.cancel'),
        type: 'warning'
      }).then(() => {
        this.tcs = []
        this.data = {}
        this.$message({
          type: 'success',
          message: this.$t('generate.deleteWarning.success')
        })
      })
    }
  }
}
</script>

<style scoped lang="scss">
@import "~element-ui/packages/theme-chalk/src/common/var";

.aside {
  padding: $--main-padding;
}

.option {
  margin-bottom: 16px;
}

.codemirror {
  height: 100%;
}

</style>
