<template>
  <Game ref="game" @accepted="win" @wronganswer="lose"></Game>
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
  localStorage: {
    data: {
      type: Object,
    }
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
    },
    win (data) {
      this.$message({
        message: 'Menang',
        type: 'success'
      })
      data.testcase = parseInt(this.$route.params.tc)

      this.data[this.$route.params.tc] = data
      this.data = this.data // force update
    },
    lose () {
      this.$message({
        message: 'Kalah',
        type: 'error'
      })
    }
  }
}
</script>

<style scoped lang="scss">
@import "~element-ui/packages/theme-chalk/src/common/var";

</style>
