<template>
  <el-container id="app">
    <el-header>
      <h1>Berebut Pizza</h1>
    </el-header>
    <el-container>
      <el-aside class="aside" width="30%">
        <Terminal 
          class="terminal" 
          ref="terminal" 
          :disabled="finished"></Terminal>
      </el-aside>
      <el-main class="main">
        <h2>{{dengklek}} / {{juri}}</h2>
        <!-- <el-button 
          v-for="(pizza, idx) in pizzas" 
          :key="pizza.id" 
          @click="choose(idx)">
          {{pizza.count}} / {{pizza.maxCount}} / {{pizza.d}} / {{pizza.j}}
        </el-button> -->
        <div class="pizzas">
          <div
            class="pizza"
            v-for="(pizza, idx) in pizzas"
            :key="pizza.id">
            <Pizza
              @choose="choose(idx, $event)"
              :dengklek="pizza.d"
              :juri="pizza.j"
              :selected="pizza.selected">
            </Pizza>
            <span class="pizza-text">{{idx + 1}}</span>
          </div>
        </div>
        <div>
          <el-button 
            class="pass" 
            :disabled="finished"
            @click="noChoose">
            Pass
          </el-button>
        </div>
      </el-main>
    </el-container>
  </el-container>
</template>

<script>
/* eslint-disable no-console */
import Terminal from './components/Terminal.vue'
import Server from './scripts/Server.js'
import Client from './scripts/Client.js'
import Pizza from './components/Pizza.vue'

export default {
  name: 'app',
  components: {
    Terminal,
    Pizza,
  },
  data() {
    return {
      pizzas: [],
      dengklek: 0,
      juri: 0,
      finished: false
    }
  },
  mounted() {
    this.server = new Server()
    this.server.setEncoding('utf8')
    this.client = new Client()
    this.client.setEncoding('utf8')
    this.server.on('data', (data) => {
      this.$refs.terminal.addServer(data)
    })
    this.server._error.on('data', (data) => {
      this.$refs.terminal.addServerError(data)
    })
    this.client.on('data', (data) => {
      this.$refs.terminal.addClient(data)
    })

    this.server.on('destroy', () => {
      this.finished = true
    })

    this.client._serverInit = this.serverInit.bind(this)
    this.client._serverAnswer = this.serverAnswer.bind(this)
    this.client._clientAnswer = this.clientAnswer.bind(this)

    this.$refs.terminal.submitCallback = (msg) => {
      this._choosenSlice = -1
      this.client.answer(msg)
    }
    this.server.pipe(this.client).pipe(this.server)
    this.server.start()
    this.client.start()
  },
  methods: {
    serverInit(conf) {
      this.pizzas = []
      for (let i=0; i<conf.N; i++) {
        const selected = []
        for (let j=0; j<conf.A[i]; j++) {
          selected.push({id: j, value: false, juri: false})
        }
        this.pizzas.push({id: i, count: conf.A[i], maxCount: conf.A[i], selected: selected, d: false, j: false})
      }
      for (let i=0; i<conf.D; i++) {
        this.pizzas[conf.Didx[i]-1].d = true
      }
      for (let i=0; i<conf.J; i++) {
        this.pizzas[conf.Jidx[i]-1].j = true
      }
      this.dengklek = 0
      this.juri = 0
    },

    serverAnswer(x) {
      if (x > 0) {
        x -= 1

        if (x >= this.pizzas.length || !this.pizzas[x].j || this.pizzas[x].count == 0) {
          // console.log('server gives invalid response')
          return
        }

        this.update(true, x, -1)
      }
    },

    clientAnswer(x) {
      if (x > 0) {
        x -= 1

        if (x >= this.pizzas.length || !this.pizzas[x].d || this.pizzas[x].count == 0) {
          // console.log('client gives invalid response')
          return
        }

        this.update(false, x, this._choosenSlice)
      }
    },

    update(juri, idx, slice) {
      const pizza = this.pizzas[idx]

      if (slice == -1) { // find the lowest index
        for (let i=0; i<pizza.selected.length; i++) {
          if (!pizza.selected[i].value) {
            slice = i
            break
          }
        }
        if (slice == -1) return // not valid
      }
      if (pizza.selected[slice].value) return // not valid

      if (!juri) this.dengklek++
      else this.juri++

      pizza.selected[slice].value = true
      pizza.selected[slice].juri = juri
      pizza.count--
    },

    choose(idx, slice) {
      const pizza = this.pizzas[idx]
      if (!pizza.d) return // not valid
      if (pizza.count == 0) return // not valid
      if (pizza.selected[slice].value) return // not valid

      this._choosenSlice = slice

      idx += 1
      this.client.answer(idx + '\n')
    },
    
    noChoose() {
      this.client.answer('0\n')
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

.aside {
  padding: $--main-padding;
}

.terminal {
  height: 100%;
}

.pizzas {
  display: flex;
}

.pizza + .pizza {
  margin-left: 16px;
}

.pizza-text {
  display: block;
  font-size: 2em;
  text-align: center;
}

</style>
