import Vue from 'vue'
import Router from 'vue-router'
import Home from './views/Home.vue'
import TC from './views/TC.vue'
import Custom from './views/Custom.vue'
import Generate from './views/Generate.vue'

Vue.use(Router)

export default new Router({
  routes: [
    { path: '/', name:'home', component: Home },
    { path: '/tc/:tc', name:'tc', component: TC },
    { path: '/custom', name:'custom', component: Custom },
    { path: '/generate', name:'generate', component: Generate },
  ]
})
