<template>
  <el-container>
    <el-container v-show="!playing">
      <el-aside class="aside" width="30%">
        <el-form 
          ref="form"
          :model="form"
          :rules="rules"
          @submit.native.prevent="onSubmit">
          <el-form-item class="text-item" prop="tc">
            <el-input
              class="textarea"
              type="textarea"
              placeholder="Testcase"
              :rows="10"
              v-model="form.tc">
            </el-input>
          </el-form-item>
          <el-form-item>
            <el-button
              class="submit"
              type="primary"
              native-type="submit">
              Submit
            </el-button>
          </el-form-item>
        </el-form>
      </el-aside>
    </el-container>
    <Game ref="game" v-show="playing"></Game>
  </el-container>
</template>

<script>
/* eslint-disable no-console */

import Game from './Game.vue'
import {PassThrough} from 'readable-stream'
import ServerInterpreter from '../scripts/ServerInterpreter.js'

export default {
  components: {
    Game,
  },
  data() {
    return {
      form: {
        tc: ''
      },
      rules: {
        tc: [
          { validator: this.validateTC, trigger: 'blur' }
        ]
      },
      playing: false,
    }
  },
  mounted() {
    this.handleQuery(this.$route.query.tc)
  },
  beforeRouteUpdate (to, from, next) {
    this.handleQuery(to.query.tc)
    next()
  },
  methods: {
    handleQuery (tc) {
      tc = tc || ''
      this.form.tc = tc
      if (tc != '') {
        this.$refs.form.validate((valid) => {
          if (valid) {
            this.playing = true
            this.$refs.game.changeTC(this.form.tc)
          }
        })
      }
    },
    onSubmit () {
      this.$refs.form.validate((valid) => {
        if (valid) {
          this.$router.replace({ name: 'custom', query: {tc: this.form.tc}})
        }
      })
    },
    validateTC (rule, value, callback) {
      const input = new PassThrough()
      input.write(value)
      const interpreter = new ServerInterpreter(input)

      let err = ['Format testcase tidak benar\n(Tips: jangan lupa newline di akhir baris)']
      interpreter.init = (conf) => {
        err = []
        if (!(1 <= conf.N && conf.N <= 10)) {
          err.push('1 <= N <= 10.')
        }
        if (!(conf.S == 1)) {
          err.push('S = 1.')
        }
        conf.A.forEach((v, i) => {
          if (!(1 <= v && v <= 10)) {
            err.push(`1 <= A_${i+1} <= 10.`)
          }
        })
        if (!(0 <= conf.D && conf.D <= conf.N)) {
          err.push('0 <= D <= N.')
        }
        if (!(0 <= conf.J && conf.J <= conf.N)) {
          err.push('0 <= J <= N.')
        }

        conf.Didx.forEach((v, i) => {
          if (!(1 <= v && v <= conf.N)) {
            err.push(`1 <= Ds_${i+1} <= N.`)
          }
        })

        const unique = (value, index, self) => self.indexOf(value) == index

        if (!(conf.Didx.length == conf.Didx.filter(unique).length)) {
          err.push('Pizza Dengklek harus unik.')
        }

        conf.Jidx.forEach((v, i) => {
          if (!(1 <= v && v <= conf.N)) {
            err.push(`1 <= Js_${i+1} <= N.`)
          }
        })

        if (!(conf.Jidx.length == conf.Jidx.filter(unique).length)) {
          err.push('Pizza Juri harus unik.')
        }

      }

      interpreter.start().then(() => {
        if (err.length === 0) {
          callback()
        } else {
          callback(new Error(err.join('\n')))
        }
      })

      interpreter.break()
      input.destroy()
    }
  }
}
</script>

<style scoped lang="scss">
@import "~element-ui/packages/theme-chalk/src/common/var";

.aside {
  padding: $--main-padding;
}

</style>
