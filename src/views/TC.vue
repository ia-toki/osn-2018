<template>
  <Game ref="game"></Game>
</template>

<script>
/* eslint-disable no-console */

import Game from './Game.vue'

export default {
  components: {
    Game,
  },
  mounted() {
    this.tc = {
      '1': '0..3.\n3 1\n2 4 4\n2 2 3\n2 1 3\n',
      '2': '0..3.\n3 1\n2 4 4\n1 1\n2 1 2\n'
    }
    this.changeTC(this.$route.params.tc)
  },
  beforeRouteUpdate (to, from, next) {
    this.changeTC(to.params.tc)
    next()
  },
  methods: {
    changeTC (tc) {
      this.$refs.game.changeTC(this.tc[tc])
    }
  }
}
</script>

<style scoped lang="scss">
@import "~element-ui/packages/theme-chalk/src/common/var";

</style>
