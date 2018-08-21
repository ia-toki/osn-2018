<template>
  <el-container id="app">
    <el-header class="header" height="auto">
      <h1>{{$t('title')}}</h1>
      <div class="spacer"></div>
      <el-menu 
        mode="horizontal"
        router
        :default-active="$route.path">
        <el-menu-item index="/">{{$t('pages.home')}}</el-menu-item>
        <el-menu-item index="/tc/1">{{$t('pages.tc1')}}</el-menu-item>
        <el-menu-item index="/tc/2">{{$t('pages.tc2')}}</el-menu-item>
        <el-menu-item index="/custom">{{$t('pages.custom')}}</el-menu-item>
        <el-menu-item index="/generate">{{$t('pages.generate')}}</el-menu-item>
      </el-menu>
      <el-radio-group class="locale" v-model="locale" size="mini">
        <el-radio-button label="id">ID</el-radio-button>
        <el-radio-button label="en">EN</el-radio-button>
      </el-radio-group>
    </el-header>
    <router-view></router-view>
  </el-container>
</template>

<script>
/* eslint-disable no-console */

export default {
  name: 'app',
  components: {
  },
  localStorage: {
    data: {
      type: Object,
      default: {}
    },
    locale: {
      type: String,
      default: 'id'
    }
  },
  data() {
    return {
      
    }
  },
  watch: {
    locale (value) {
      this.$i18n.locale = value
    },
    '$i18n.locale' () {
      document.title = this.$t('title')
    }
  },
  mounted() {
    document.title = this.$t('title')
    this.$i18n.locale = this.locale
  },
  methods: {
  }
}
</script>

<style lang="scss">
@import "~element-ui/packages/theme-chalk/src/common/var";
html, body {
  height: 100%;
  margin: 0;
}

body {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: $--color-text-regular;
}

#app {
  height: 100%;
}

.spacer {
  flex: 1;
}

.header {
  display: flex;
  align-items: center;
}

.locale {
  margin-left: 20px;
}

</style>
