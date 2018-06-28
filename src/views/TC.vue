<template>
  <Game ref="game"></Game>
</template>

<script>
/* eslint-disable no-console */

import Game from './Game.vue'

import tc1 from '../testcases/tc1.in'
import tc2 from '../testcases/tc2.in'

export default {
  components: {
    Game,
  },
  mounted() {
    this.tc = {
      '1': tc1,
      '2': tc2
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
