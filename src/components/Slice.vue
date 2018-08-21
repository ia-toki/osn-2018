<template>
  <g class="slice" 
    :class="[type ? 'is-' + type : '', {'is-disabled':disabled}]" 
    :transform="`translate(${x} ${y})`">
    <path :d="paths"></path>
    <text :x="textX" :y="textY" dominant-baseline="central" text-anchor="middle"><slot></slot></text>
  </g>
</template>

<script>
export default {
  props: {
    x: {
      type: Number,
      default: 0
    },
    y: {
      type: Number,
      default: 0
    },
    radius: {
      type: Number,
      default: 100
    },
    idx: {
      type: Number,
      default: 0
    },
    max: {
      type: Number,
      default: 1
    },
    disabled: Boolean,
    type: String
  },
  data() {
    return {
      
    }
  },
  computed: {
    paths() {
      const r = this.radius
      const t = 2 * Math.PI / this.max
      const t0 = t * this.idx - Math.PI / 2
      const t1 = t * (this.idx + 1) - Math.PI / 2
      const x0 = r * Math.cos(t0)
      const y0 = r * Math.sin(t0)
      const x1 = r * Math.cos(t1)
      const y1 = r * Math.sin(t1)
      if (this.max == 1) {
        return `M ${x0} ${y0} A ${r} ${r} 0 0 1 ${-x0} ${-y0} A ${r} ${r} 0 0 1 ${x0} ${y0}` // circle
      } else {
        return `M 0 0 L ${x0} ${y0} A ${r} ${r} 0 0 1 ${x1} ${y1} Z`
      }
    },
    textX() {
      return this.radius / 2 * Math.cos(2 * Math.PI / this.max * (this.idx + 0.5) - Math.PI / 2)
    },
    textY() {
      return this.radius / 2 * Math.sin(2 * Math.PI / this.max * (this.idx + 0.5) - Math.PI / 2)
    }
  },
  methods: {
    
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style lang="scss" scoped>
@import "~element-ui/packages/theme-chalk/src/common/var";
@import "~element-ui/packages/theme-chalk/src/mixins/mixins";
@import "~element-ui/packages/theme-chalk/src/mixins/utils";

@mixin plain($color) {
  text {
    fill: $color;
    stroke: none;
    transition: .1s;
  }
  path {
    fill: mix($--color-white, $color, 90%);
    stroke: mix($--color-white, $color, 60%);
    stroke-width: $--border-width-base;
    transition: .1s;
  }

  &:hover,
  &:focus {
    text {
      fill: $--color-white;
    }
    path {
      fill: $color;
      stroke: $color;
    }
  }

  &:active {
    text {
      fill: $--color-white;
    }
    path {
      fill: mix($--color-black, $color, $--button-active-shade-percent);
      stroke: mix($--color-black, $color, $--button-active-shade-percent);
    }
  }

  &.is-disabled {
    &,
    &:hover,
    &:focus,
    &:active {
      cursor: not-allowed;

      text {
        fill: mix($--color-white, $color, 40%);
      }
      
      path {
        fill: mix($--color-white, $color, 90%);
        stroke: mix($--color-white, $color, 80%);
      }
    }
  }
}

.slice {
  @include utils-user-select(none);
  font-weight: $--button-font-weight;
  cursor: pointer;

  @include plain($--button-primary-fill);

  &.is-success {
    @include plain($--button-success-fill);
  }

  &.is-danger {
    @include plain($--button-danger-fill);
  }
}
</style>
