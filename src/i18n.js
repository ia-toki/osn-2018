import Vue from 'vue'
import VueI18n from 'vue-i18n'

import idHelp from './helps/id.md'
import enHelp from './helps/en.md'

Vue.use(VueI18n)

export default new VueI18n({
  locale: 'id',
  messages: {
    id: {
      title: 'Potongan Pizza',
      home: {
        body: idHelp,
      },
      pages: {
        home: 'Beranda',
        tc1: 'TC 1',
        tc2: 'TC 2',
        custom: 'Custom',
        generate: 'Generate',
      },
      game: {
        prompt: 'Tekan Enter untuk mengirim',
        submit: 'Kirim',
        pass: 'Pass',
      },
      custom: {
        prompt: 'Masukan testcase, jangan lupa newline di akhir baris',
        submit: 'Kirim',
        invalid: 'Format tidak benar',
      },
      generate: {
        tc1: 'TC 1',
        tc2: 'TC 2',
        pascal: 'Pascal',
        cpp: 'C++',
        copy: 'Copy',
        download: 'Download',
        delete: 'Hapus Semua Progress',
      },
    },
    en: {
      title: 'Pizza Slices',
      home: {
        body: enHelp
      },
      pages: {
        home: 'Home',
        tc1: 'TC 1',
        tc2: 'TC 2',
        custom: 'Custom',
        generate: 'Generate',
      },
      game: {
        prompt: 'Press Enter to submit',
        submit: 'Submit',
        pass: 'Pass',
      },
      custom: {
        prompt: 'Input testcase, don\'t forget newline in the end of line',
        submit: 'Submit',
        invalid: 'Format is invalid',
      },
      generate: {
        tc1: 'TC 1',
        tc2: 'TC 2',
        pascal: 'Pascal',
        cpp: 'C++',
        copy: 'Copy',
        download: 'Download',
        delete: 'Delete All Progress',
      },
    },
  }
})
