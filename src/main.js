import Vue from 'vue'
import App from './App.vue'
import ElementUI from 'element-ui'
import 'element-ui/packages/theme-chalk/src/index.scss'
import VueRouter from 'vue-router'

import Home from './pages/Home.vue'
import TC from './pages/TC.vue'

Vue.use(VueRouter)
Vue.use(ElementUI)

Vue.config.productionTip = false

const routes = [
  { path: '/', component: Home },
  { path: '/tc/:tc', component: TC },
]

const router = new VueRouter({
  routes
})

new Vue({
  router,
  render: h => h(App)
}).$mount('#app')
