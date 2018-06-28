module.exports = {
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
        }
      ]
    }
  }
}