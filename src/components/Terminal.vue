<template>
  <div class="terminal">
    <div class="logs" ref="logs">
      <el-row class="log" v-for="log in logs" :key="log.id">
        <el-col
          :span="12"
          :offset="log.server ? 12 : 0">
          <span :class="{error: log.error}">{{log.msg}}</span>
        </el-col>
      </el-row>
    </div>
    <el-form @submit.native.prevent="submit">
      <el-input 
        class="input"
        placeholder="Tekan Enter untuk mengirim" 
        v-model="input"
        :disabled="disabled"
        clearable>
        <el-button 
          class="submit" 
          slot="append"
          native-type="submit">
          Kirim
        </el-button>
      </el-input>
    </el-form>
  </div>
</template>

<script>
export default {
  props: {
    disabled: Boolean
  },
  data() {
    return {
      curId: 0,
      logs: [],
      input: ''
    }
  },
  mounted() {
    this.reset()
  },
  methods: {
    reset() {
      this.curId = 0
      this.logs = []
      this.input = ''
    },
    addClient(msg) {
      this.addMessage(false, false, msg)
    },
    addServer(msg) {
      this.addMessage(true, false, msg)
    },
    addClientError(msg) {
      this.addMessage(false, true, msg)
    },
    addServerError(msg) {
      this.addMessage(true, true, msg)
    },
    addMessage(server, error, msg) {
      if (msg.length == 0) return
      let log;
      if (this.logs.length > 0) log = this.logs[this.logs.length-1]
      if (!log || log.server != server || log.error != error) {
        log = {id: this.curId++, server:server, error:error, msg: ''}
        this.logs.push(log)
      }
      log.msg += msg
      this.scrollToBottom()
    },
    submitCallback(msg) {
      this.addClient(msg)
    },
    submit() {
      if (this.input.length == 0) return
      this.submitCallback(this.input + '\n')
      this.input = ''
    },
    scrollToBottom() {
      this.$nextTick(() => {
        const logsDom = this.$refs.logs;
        logsDom.scrollTo(0, logsDom.scrollHeight)
      })
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style lang="scss" scoped>
@import "~element-ui/packages/theme-chalk/src/common/var";
.terminal {
  display: flex;
  flex-direction: column;
}

.logs {
  flex: 1;
  border: $--border-base;
  border-radius: $--border-radius-base;
  margin-bottom: 12px;
  min-height: 100px;
  overflow-x: hidden;
  overflow-y: auto;
}

.log {
  padding: 12px 15px;
  white-space: pre-wrap;
}

.log + .log {
  border-top: $--border-base;
}

.error {
  color: $--color-danger;
}
</style>
