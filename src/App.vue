<template>
  <el-container id="app">
    <el-header class="header" height="auto">
      <h1>Berebut Pizza</h1>
      <el-menu 
        class="navbar" 
        mode="horizontal"
        default-active="tc1"
        @select="changePage">
        <el-menu-item index="tc1">TC 1</el-menu-item>
        <el-menu-item index="tc2">TC 2</el-menu-item>
        <el-menu-item index="custom">Custom</el-menu-item>
        <el-menu-item index="generate">Generate</el-menu-item>
      </el-menu>
    </el-header>
    <Game ref="game"></Game>
  </el-container>
</template>

<script>
/* eslint-disable no-console */
import Game from './pages/Game.vue'

export default {
  name: 'app',
  components: {
    Game,
  },
  data() {
    return {
      
    }
  },
  mounted() {
    this.tc1 = '0..3.\n3 1\n2 4 4\n2 2 3\n2 1 3\n'
    this.tc2 = '0..3.\n3 1\n2 4 4\n1 1\n2 1 2\n'
    this.$refs.game.changeTC(this.tc1)
  },
  methods: {
    changePage(key, keyPath) {
      console.log(key, keyPath)
      if (key == 'tc1') {
        this.$refs.game.changeTC(this.tc1)
      } else if (key == 'tc2') {
        this.$refs.game.changeTC(this.tc2)
      }
    },
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
