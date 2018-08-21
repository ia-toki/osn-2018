/* eslint-disable no-constant-condition */
/* eslint-disable no-console */
/* eslint-disable no-unused-vars */
import {Duplex, PassThrough} from 'readable-stream'
import ClientInterpreter from './ClientInterpreter.js'
import ServerInterpreter from './ServerInterpreter.js'

export default class Client extends Duplex {
  constructor(options) {
    super(options)
    this._input = new PassThrough()
    this._output = new PassThrough()
    this._output2 = new PassThrough()

    this._serverInterpreter = new ServerInterpreter(this._input)
    this._serverInterpreter.init = this.serverInit.bind(this)
    this._serverInterpreter.answer = this.serverAnswer.bind(this)
    this._clientInterpreter = new ClientInterpreter(this._output2)
    this._clientInterpreter.answer = this.clientAnswer.bind(this)

    this._output.pipe(this._output2)
    this._output.on('data', (data) => {
      this.push(data)
    })

    this._isDestroyed = false;
  }

  start() {
    this._clientInterpreter.start()
    this._serverInterpreter.start()
  }

  serverInit(conf) {
    this._serverInit(conf)
  }

  serverAnswer(x) {
    this._serverResponse = x
    this._serverAnswer(x)
    this.checkQuit()
  }

  clientAnswer(x) {
    this._clientResponse = x
    this._clientAnswer(x)
    this.checkQuit()
  }

  _serverInit(conf) {
    console.log(conf)
  }

  _serverAnswer(x) {
    console.log(x)
  }

  _clientAnswer(x) {
    console.log(x)
  }

  getAnswer() {
    let choose = -1
    for (let i=0; i<this.pizzas.length; i++) {
      if (!this.pizzas[i].j && this.pizzas[i].count > 0) { // select the smallest
        choose = i
        break
      }
    }

    if (choose != -1) {
      return this.answer(choose + '\n')
    } else {
      return this.answer('0\n')
    }
  }

  answer(msg) {
    if (!this._isDestroyed) this._output.write(msg)
  }

  checkQuit() {
    if (this._clientResponse == 0 && this._serverResponse == 0) {
      this._clientInterpreter.break()
      this._serverInterpreter.break()
      this.destroy()
      this.emit('destroy')
    }
  }

  _destroy() {
    this._input.destroy()
    this._output.destroy()
    this._output2.destroy()
    this._isDestroyed = true
  }

  _read(size) {
    // hmmm TODO
  }

  _write(chunk, encoding, callback) {
    this._input.write(chunk, encoding, callback)
  }
}
