<template>
  <el-container>
    <el-aside class="aside" width="30%">
      <el-checkbox-group 
        class="option"
        v-model="tcs">
        <el-checkbox-button 
          v-for="tc in tc_option"
          :key="tc"
          :label="tc">
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
    </el-aside>
    <el-main>
      <codemirror 
        ref="codemirror"
        class="codemirror"
        v-model="code" 
        :options="cmOptions">
      </codemirror>
    </el-main>
  </el-container>
</template>

<script>
/* eslint-disable no-console */

const modeMap = {
  'Pascal': 'text/x-pascal',
  'C++': 'text/x-c++src',
}

export default {
  data() {
    return {
      tcs: [],
      tc_option: ['TC 1', 'TC 2'],
      language: 'Pascal',
      language_option: ['Pascal', 'C++'],
      code: 'begin\nend\n',
      cmOptions: {
        // readOnly: true,
        mode: 'text/x-pascal',
      }
    }
  },
  mounted() {
    this.$refs.codemirror.codemirror.setSize(null, '100%')
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
