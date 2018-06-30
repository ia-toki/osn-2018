<template>
  <svg class="pizza" :class="{'notplayer': !dengklek, 'notopponent': !juri}" :width="size" :height="size">
    <Slice 
      v-for="(slice, idx) in selected"
      :key="slice.id"
      :x="size/2" 
      :y="size/2" 
      :radius="size/2 * 0.9" 
      :idx="idx" 
      :max="maxCount"
      :disabled="slice.value"
      :type="!slice.value ? '' : slice.juri ? 'danger' : 'success'"
      @click.native="$emit('choose', idx)">
    </Slice>
    <text class="count" :x="size/2" :y="size/2" dominant-baseline="central" text-anchor="middle" :font-size="size/2">{{count}}</text>
    <circle 
      v-if="dengklek" 
      class="sign"
      :cx="size/2" :cy="size/2" :r="size/2">
    </circle>
    <rect 
      v-if="juri" 
      class="sign"
      :x="0" :y="0" :width="size" :height="size">
    </rect>
  </svg>
</template>

<script>
import Slice from './Slice.vue'

export default {
  components: {
    Slice,
  },
  props: {
    size: {
      type: Number,
      default: 100
    },
    selected: {
      type: Array,
      default: () => [false]
    },
    dengklek: Boolean,
    juri: Boolean
  },
  data() {
    return {
      
    }
  },
  computed: {
    count() {
      return this.selected.filter(x => !x.value).length // not the most optimized, but meh
    },
    maxCount() {
      return this.selected.length
    },
    crossPath() {
      const scaled = Math.sqrt(2) / 2 * this.size
      return `M ${(this.size-scaled)/2} ${(this.size-scaled)/2} l ${scaled} ${scaled} m 0 ${-scaled} l ${-scaled} ${scaled}`
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style lang="scss" scoped>
@import "~element-ui/packages/theme-chalk/src/common/var";
@import "~element-ui/packages/theme-chalk/src/mixins/utils";

.count {
  fill: $--color-text-placeholder;
  stroke: none;
  @include utils-user-select(none);
  pointer-events: none;
}

.notplayer {
  pointer-events: none;
}

.sign {
  fill: none;
  stroke: $--color-success;
  stroke-width: $--border-width-base;
  transform-origin: center;
  transform: scale(0.95)
}
</style>
