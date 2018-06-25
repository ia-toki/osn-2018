import Vue from 'vue'
import Router from 'vue-router'
import Home from './pages/Home.vue'
import TC from './pages/TC.vue'
import Custom from './pages/Custom.vue'
import Generate from './pages/Generate.vue'

Vue.use(Router)

export default new Router({
  routes: [
    { path: '/', name:'home', component: Home },
    { path: '/tc/:tc', name:'tc', component: TC },
    { path: '/custom', name:'custom', component: Custom },
    { path: '/generate', name:'generate', component: Generate },
  ]
})
