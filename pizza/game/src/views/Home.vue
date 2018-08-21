<template>
  <el-main>
    <vue-markdown :source="$t('home.body')"></vue-markdown>
  </el-main>
</template>

<script>
/* eslint-disable no-console */

import VueMarkdown from 'vue-markdown'

export default {
  components: {
    VueMarkdown
  }
}
</script>

<style scoped lang="scss">
@import "~element-ui/packages/theme-chalk/src/common/var";

</style>
