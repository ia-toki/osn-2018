import Vue from 'vue'
import App from './App.vue'
import ElementUI from 'element-ui'
import 'element-ui/packages/theme-chalk/src/index.scss'
import VueCodemirror from 'vue-codemirror'
import 'codemirror/lib/codemirror.css'
import 'codemirror/mode/clike/clike.js'
import 'codemirror/mode/pascal/pascal.js'
import 'codemirror/theme/neo.css'
import VueLocalStorage from 'vue-localstorage'
import VueClipboard from 'vue-clipboard2'

import router from './router'

Vue.use(VueLocalStorage, {
  bind: true
})
Vue.use(VueClipboard)
Vue.use(ElementUI)
Vue.use(VueCodemirror, {
  options: {
    lineNumbers: true,
    theme: 'neo',
  }
})

Vue.config.productionTip = false

new Vue({
  router,
  render: h => h(App)
}).$mount('#app')
