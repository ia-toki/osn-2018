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

  start(tc) {
    this._clientInterpreter.start()
    this._serverInterpreter.start()

    this._output.write(tc)
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
    let x = 0
    let y = 0
    this.pizzas.forEach(pizza => {
      if (pizza.j && pizza.d) x += pizza.count
      if (!pizza.j && pizza.d) y += pizza.count
    })
    this.K = Math.floor((x + 1)/2) + y
    this.dengklek = 0
    this.juri = 0
  }

  serverAnswer(x) {
    this._serverResponse = x
    if (x == 0 || 
        (x-1 >= 0 && x-1 < this.pizzas.length && 
        this.pizzas[x-1].j && this.pizzas[x-1].count > 0)) 
    {
      this.update(true, x)
      this.checkQuit()
    } else {
      this.error('grader salah\n')
    }
  }

  clientAnswer(x) {
    this._clientResponse = x
    if (x == 0 || 
        (x-1 >= 0 && x-1 < this.pizzas.length && 
        this.pizzas[x-1].d && this.pizzas[x-1].count > 0)) 
    {
      this.update(false, x)
      this.checkQuit()
      this.getAnswer()
    } else {
      this.error('masukan salah\n')
    }
  }

  update(juri, x) {
    if (x == 0) return
    const idx = x - 1
    const pizza = this.pizzas[idx]

    if (!juri) this.dengklek++
    else this.juri++

    pizza.count--
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
      if (this.dengklek >= this.K) {
        this.error('ACCEPTED\n')
        this.emit('accepted')
      } else {
        this.error('WRONG ANSWER\n')
        this.emit('wronganswer')
      }
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
