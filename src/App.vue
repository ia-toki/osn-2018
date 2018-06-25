<template>
  <el-container id="app">
    <el-header class="header" height="auto">
      <h1>Berebut Pizza</h1>
      <el-menu 
        class="navbar" 
        mode="horizontal"
        router
        :default-active="$route.path">
        <el-menu-item index="/">Home</el-menu-item>
        <el-menu-item index="/tc/1">TC 1</el-menu-item>
        <el-menu-item index="/tc/2">TC 2</el-menu-item>
        <el-menu-item index="/custom">Custom</el-menu-item>
        <el-menu-item index="/generate">Generate</el-menu-item>
      </el-menu>
    </el-header>
    <router-view></router-view>
  </el-container>
</template>

<script>
/* eslint-disable no-console */

export default {
  name: 'app',
  components: {
  },
  data() {
    return {
      
    }
  },
  mounted() {
  },
  methods: {
  }
}
</script>

<style lang="scss">
@import "~element-ui/packages/theme-chalk/src/common/var";
html, body {
  height: 100%;
  margin: 0;
}

#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: $--color-text-regular;
  height: 100%;
}

.header {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

</style>
