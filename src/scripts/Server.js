/* eslint-disable no-constant-condition */
/* eslint-disable no-console */
/* eslint-disable no-unused-vars */
import {Duplex, PassThrough} from 'readable-stream'
import ClientInterpreter from './ClientInterpreter.js'
import ServerInterpreter from './ServerInterpreter.js'

export default class Server extends Duplex {
  constructor(options) {
    super(options)
    this._input = new PassThrough()
    this._output = new PassThrough()
    this._error = new PassThrough()
    this._output2 = new PassThrough()

    this._clientInterpreter = new ClientInterpreter(this._input)
    this._clientInterpreter.answer = this.clientAnswer.bind(this)
    this._serverInterpreter = new ServerInterpreter(this._output2)
    this._serverInterpreter.init = this.serverInit.bind(this)
    this._serverInterpreter.answer = this.serverAnswer.bind(this)

    this._output.pipe(this._output2)
    this._output.on('data', (data) => {
      this.push(data)
    })

    this._isDestroyed = false;
  }

  start() {
    this._clientInterpreter.start()
    this._serverInterpreter.start()

    this._output.write([
      '0..3.',
      '3 1',
      '2 4 4',
      '2 2 3',
      '2 1 3'
    ].join('\n') + '\n')
  }

  serverInit(conf) {
    this.pizzas = conf.A.map(x => {
      return {count: x, d: false, j: false}
    })
    conf.Didx.forEach(x => {
      this.pizzas[x-1].d = true
    })
    conf.Jidx.forEach(x => {
      this.pizzas[x-1].j = true
    })
  }

  serverAnswer(x) {
    this._serverResponse = x
    if (x > 0) {
      x -= 1

      if (x >= this.pizzas.length || !this.pizzas[x].j || this.pizzas[x].count == 0) {
        // console.log('server gives invalid response')
        this.error('grader salah\n')
        return
      }

      this.pizzas[x].count--
    }
    this.checkQuit()
  }

  clientAnswer(x) {
    this._clientResponse = x
    if (x > 0) {
      x -= 1

      if (x >= this.pizzas.length || !this.pizzas[x].d || this.pizzas[x].count === 0) {
        // console.log('client gives invalid response')
        this.error('masukan salah\n')
        return
      }

      this.pizzas[x].count--;
    }
    this.checkQuit()

    this.getAnswer()
  }

  getAnswer() {
    let choose = -1
    for (let i=0; i<this.pizzas.length; i++) {
      if (this.pizzas[i].j && this.pizzas[i].count > 0) { // select the smallest
        choose = i
        break
      }
    }

    if (choose != -1) {
      choose += 1
      return this.answer(choose + '\n')
    } else {
      return this.answer('0\n')
    }
  }

  answer(msg) {
    if (!this._isDestroyed) this._output.write(msg)
  }

  error(msg) {
    if (!this._isDestroyed) this._error.write(msg)
  }

  checkQuit() {
    if (this._clientResponse == 0 && this._serverResponse == 0) {
      this.error(this.K + '\n')
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
    this._error.destroy()
    this._isDestroyed = true
  }

  _read(size) {
    // hmmm TODO
  }

  _write(chunk, encoding, callback) {
    this._input.write(chunk, encoding, callback)
  }
}
