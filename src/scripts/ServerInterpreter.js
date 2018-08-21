/* eslint-disable no-constant-condition */
/* eslint-disable no-console */
/* eslint-disable no-unused-vars */
import Scanner from './Scanner.js'

export default class ServerInterpreter {
  constructor(readable) {
    this._readable = readable
    this._scanner = new Scanner(this._readable)
  }

  async start() {
    const conf = {}
    conf.subtask = await this._scanner.getLine()
    conf.N = await this._scanner.getInt()
    conf.S = await this._scanner.getInt()
    conf.A = []
    for (let i=0; i<conf.N; i++) {
      conf.A.push(await this._scanner.getInt())
    }
    conf.D = await this._scanner.getInt()
    conf.Didx = []
    for (let i=0; i<conf.D; i++) {
      conf.Didx.push(await this._scanner.getInt())
    }
    conf.J = await this._scanner.getInt()
    conf.Jidx = []
    for (let i=0; i<conf.J; i++) {
      conf.Jidx.push(await this._scanner.getInt())
    }

    this.init(conf)

    while (true) {
      this._break = false
      
      this.answer(await this._scanner.getInt())

      if (this._break) {
        break
      }
    }
  }

  init(conf) {
    console.log(conf)
  }

  answer(x) {
    console.log(x)
  }

  break() {
    this._break = true
  }
}
