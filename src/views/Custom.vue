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
              :placeholder="$t('custom.prompt')"
              :rows="10"
              v-model="form.tc">
            </el-input>
          </el-form-item>
          <el-form-item>
            <el-button
              class="submit"
              type="primary"
              native-type="submit">
              {{$t('custom.submit')}}
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
      this.playing = false
      tc = tc || ''
      this.form.tc = tc
      if (tc != '') {
        this.$refs.form.validate((valid) => {
          if (valid) {
            this.reformat(this.form.tc).then((reformat) => {
              this.playing = true
              this.$refs.game.changeTC(reformat)
            })
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
    async reformat (value) {
      const conf = await this.interpretConf(value)
      return [
        conf.subtask, 
        `${conf.N} ${conf.S}`, 
        conf.A.join(' '),
        `${conf.D} ${conf.Didx.join(' ')}`,
        `${conf.J} ${conf.Jidx.join(' ')}`,
      ].join('\n') + '\n'
    },
    interpretConf (value) {
      return new Promise((resolve, reject) => {
        const input = new PassThrough()
        input.write(value)
        const interpreter = new ServerInterpreter(input)

        let ret = null

        const unique = (value, index, self) => self.indexOf(value) == index

        let err = [this.$t('custom.invalid')]
        interpreter.init = (conf) => {
          ret = conf
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
            err.push('0 <= P <= N.')
          }
          if (!(0 <= conf.J && conf.J <= conf.N)) {
            err.push('0 <= Q <= N.')
          }

          conf.Didx.forEach((v, i) => {
            if (!(1 <= v && v <= conf.N)) {
              err.push(`1 <= X_${i+1} <= N.`)
            }
          })

          if (!(conf.Didx.length == conf.Didx.filter(unique).length)) {
            err.push('Pizza Anda harus unik.')
          }

          conf.Jidx.forEach((v, i) => {
            if (!(1 <= v && v <= conf.N)) {
              err.push(`1 <= Y_${i+1} <= N.`)
            }
          })

          if (!(conf.Jidx.length == conf.Jidx.filter(unique).length)) {
            err.push('Pizza Dengklek harus unik.')
          }
        }

        interpreter.start().then(() => {
          if (err.length === 0) {
            resolve(ret)
          } else {
            reject(new Error(err.join('\n')))
          }
        })

        interpreter.break()
        input.destroy()
      })
    },
    validateTC (rule, value, callback) {
      this.interpretConf(value).then(() => {
        callback()
      }, (e) => {
        callback(e)
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

</style>
