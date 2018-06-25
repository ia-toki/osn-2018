module.exports = {
  configureWebpack: {
    module: {
      rules: [
        {
          test: /\.handlebars$/,
          use: 'handlebars-loader'
        }
      ]
    }
  }
}