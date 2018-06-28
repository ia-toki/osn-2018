<template>
  <el-container>
    <el-aside class="aside" width="30%">
      <el-checkbox-group 
        class="option"
        v-model="tcs">
        <el-checkbox-button 
          v-for="tc in tc_option"
          :key="tc.tc"
          :label="tc.tc">
        {{tc.name}}
        </el-checkbox-button>
      </el-checkbox-group>
      <el-radio-group 
        class="option"
        v-model="language">
        <el-radio-button 
          v-for="lang in language_option"
          :key="lang"
          :label="lang">
        </el-radio-button>
      </el-radio-group>
      <div class="option">
        <el-button>Copy</el-button>
        <el-button>Download</el-button>
      </div>
      <div class="option">
        <el-button type="danger">Delete All Progress</el-button>
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

export default {
  data() {
    return {
      tc_option: [{tc: '1', name: 'TC 1'}, {tc: '2', name: 'TC 2'}],
      language_option: ['Pascal', 'C++'],
      cmOptions: {
        readOnly: true,
        mode: 'text/x-pascal',
      },
      data: {
        type: Object,
        default: {}
      }
    }
  },
  localStorage: {
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
    this.data = {
      '1': {
        testcase: 1,
        N: 4, S: 1,
        A: [2, 4, 6, 8],
        D: 2, Ds: [3, 4],
        J: 2, Js: [2, 4],
        interaction: [
          { answer: 4, response: 2 },
          { answer: 4, response: 2 },
          { answer: 0 },
        ]
      },
      '2': {
        testcase: 1,
        N: 4, S: 1,
        A: [2, 4, 6, 8],
        D: 2, Ds: [3, 4],
        J: 2, Js: [2, 4],
        interaction: [
          { answer: 4, response: 2 },
          { answer: 4, response: 2 },
          { answer: 0 },
        ]
      }
    }
  },
  computed: {
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
