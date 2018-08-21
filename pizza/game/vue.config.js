const baseUrl = '/'

const WebpackObfuscator = require('webpack-obfuscator')

module.exports = {
  baseUrl: process.env.NODE_ENV === 'production'
    ? baseUrl
    : '/',
  productionSourceMap: false,
  configureWebpack: {
    module: {
      rules: [
        {
          test: /\.handlebars$/,
          use: 'handlebars-loader'
        },
        {
          test: /\.in$/,
          use: 'raw-loader'
        },
        {
          test: /\.md$/,
          use: 'raw-loader'
        },
      ]
    },
    optimization: {
      minimizer: [
        new WebpackObfuscator({
          compact: true,
          controlFlowFlattening: false,
          deadCodeInjection: false,
          debugProtection: false,
          debugProtectionInterval: false,
          disableConsoleOutput: true,
          identifierNamesGenerator: 'hexadecimal',
          log: false,
          renameGlobals: false,
          rotateStringArray: true,
          selfDefending: true,
          stringArray: true,
          stringArrayEncoding: true,
          stringArrayThreshold: 0.75,
          unicodeEscapeSequence: true
        })
      ]
    }
  }
}