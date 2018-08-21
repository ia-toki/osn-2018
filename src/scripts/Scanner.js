/* eslint-disable no-constant-condition */

export default class Scanner {
  constructor (readable) {
    this._readable = readable
    this._cache = ''
    this._readable.setEncoding('utf8')
    this._readable.pause()
  }

  async getToken (regex) {
    return new Promise((resolve) => {
      const cb = () => {
        let res
        while (true) {
          res = this._cache.match(regex)
          if (res) break
          const temp = this._readable.read()
          if (temp) this._cache += temp
          else break
        }
        if (res) {
          this._cache = this._cache.substr(res.index + res[1].length)
          this._readable.removeListener('readable', cb)
          resolve(res[2])
        }
      }
      this._readable.on('readable', cb)
      cb()
    })
  }

  async getLine () {
    return this.getToken(/(^([^\r\n]*)\r?\n)/)
  }

  async getString () {
    return this.getToken(/((\S+)\s+)/)
  }
  async getInt () {
    return parseInt(await this.getToken(/(([-+]?\d+))\D/))
  }
  
  async getFloat () {
    return parseFloat(await this.getToken(/(([+-]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)))\D/))
  }

}