import Vue from 'vue'
import App from './App.vue'
import ElementUI from 'element-ui'
import 'element-ui/packages/theme-chalk/src/index.scss'
import VueRouter from 'vue-router'
import VueCodemirror from 'vue-codemirror'
import 'codemirror/lib/codemirror.css'
import 'codemirror/mode/clike/clike.js'
import 'codemirror/mode/pascal/pascal.js'
import 'codemirror/theme/neo.css'

import Home from './pages/Home.vue'
import TC from './pages/TC.vue'
import Custom from './pages/Custom.vue'
import Generate from './pages/Generate.vue'

Vue.use(VueRouter)
Vue.use(ElementUI)
Vue.use(VueCodemirror, {
  options: {
    lineNumbers: true,
    theme: 'neo',
  }
})

Vue.config.productionTip = false

const routes = [
  { path: '/', name:'home', component: Home },
  { path: '/tc/:tc', name:'tc', component: TC },
  { path: '/custom', name:'custom', component: Custom },
  { path: '/generate', name:'generate', component: Generate },
]

const router = new VueRouter({
  routes
})

new Vue({
  router,
  render: h => h(App)
}).$mount('#app')
