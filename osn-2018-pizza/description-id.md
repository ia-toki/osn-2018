## Potongan Pizza

### Deskripsi

Anda dan Pak Dengklek menyukai pizza. Setiap hari, Anda berdua pergi ke restoran terdekat untuk menyantap N buah pizza dengan rasa yang berbeda-beda. Anda dan Pak Dengklek saling mengetahui rasa mana saja yang disukai oleh masing-masing. Pizza dengan rasa ke-i terdiri atas A[i] potongan.

Anda hanya akan memakan pizza dengan rasa yang Anda sukai, dan Pak Dengklek hanya akan memakan pizza dengan rasa yang ia sukai.  Supaya adil, Anda dan Pak Dengklek memutuskan untuk mengambil N buah pizza tersebut bergantian, dengan cara mengambil satu potongan pizza pada setiap giliran.

Baik Anda maupun Pak Dengklek ingin mengambil potongan pizza sebanyak mungkin. Misalkan K adalah banyaknya pizza terbanyak secara matematis yang mungkin Anda makan apabila Anda dan Pak Dengklek saling menggunakan strategi yang optimal. Maka, Anda harus berhasil mengambil sebanyak K potongan pizza.

Namun, ada kalanya Pak Dengklek akan selalu mengambil potongan pizza dengan rasa yang memiliki indeks terkecil yang ia sukai. Maka, Anda harus berhasil mengambil setidaknya sebanyak K potongan pizza (tidak harus sebanyak mungkin).

### Informasi Tipe Soal

Soal ini adalah soal interaktif. Pada soal ini, Anda akan menulis program yang menunjukkan proses pemilihan potongan pizza untuk Anda. Program Anda akan berinteraksi dengan program juri, yang menunjukkan proses pemilihan potongan pizza untuk Pak Dengklek.

### Format Interaksi

Pada mulanya, program Anda akan menerima "label kasus uji". Label kasus uji adalah sebuah string yang dijelaskan sebagai berikut:

- Panjang string tersebut adalah banyaknya subsoal ditambah satu.
- Karakter ke-0 (indeks dimulai dari 0) akan berisi 0 jika kasus uji tersebut merupakan contoh kasus uji, atau berisi '.' (titik) jika bukan.
- Untuk setiap nilai i di antara 1 hingga banyaknya subsoal, berlaku:
  - jika kasus uji tersebut memenuhi batasan subsoal ke-i, maka karakter ke-i berisi i, atau
  - jika kasus uji tersebut tidak memenuhi batasan subsoal ke-i, maka karakter ke-i berisi karakter '.' (titik).

Sebagai contoh, apabila label sebuah kasus uji sebuah soal adalah `0..345`, maka:

- Soal tersebut memiliki 5 buah subsoal,
- Kasus uji tersebut merupakan contoh kasus uji, dan
- Kasus uji tesebut memenuhi batasan subsoal ke-3, ke-4, dan ke-5.

Selanjutnya, program Anda akan menerima sebuah baris berisi:

    N S

dengan S menyatakan strategi pengambilan potongan pizza Pak Dengklek, dengan:

- `1`: Pada setiap gilirannya, Pak Dengklek akan selalu mengambil potongan pizza dengan rasa yang memiliki indeks terkecil yang ia sukai.
- `2`: Pak Dengklek akan selalu mengambil potongan pizza secara optimal, sedemikian sehingga ia berhasil mengambil potongan pizza sebanyak mungkin.

Selanjutnya, program Anda akan menerima dua buah baris berisi:

    P
    X[1] X[2] .. X[P]

dengan P menyatakan banyaknya rasa pizza yang Anda sukai, dan X menyatakan rasa-rasa pizza yang Anda sukai.

Selanjutnya, program Anda akan menerima dua buah baris berisi:

    Q
    Y[1] Y[2] .. Y[Q]

dengan Q menyatakan banyaknya rasa pizza yang Pak Dengklek sukai, dan Y menyatakan rasa-rasa pizza yang ia sukai.

Kemudian, Anda dan juri (Pak Dengklek) bergantian mengambil potongan pizza, dimulai dari Anda.

Pada setiap giliran Anda, program Anda harus mengeluarkan sebuah baris berisi sebuah bilangan bulat C yang menyatakan bahwa Anda akan mengambil satu potongan pizza dengan rasa C. Apabila tidak ada lagi pizza dengan rasa yang Anda sukai, maka C harus bernilai 0.

Pada setiap giliran Pak Dengklek, program juri akan mengeluarkan  sebuah baris berisi sebuah bilangan bulat D yang menyatakan bahwa Pak Dengklek akan mengambil satu potongan pizza dengan rasa D (dengan strategi sebagaimana yang dinyatakan dengan S). Apabila tidak ada lagi pizza dengan rasa yang Pak Dengklek sukai, maka D akan bernilai 0.

Interaksi akan selesai dan program Anda **harus berhenti** apabila dalam suatu interaksi, nilai C dan D secara berturut-turut adalah 0. (Dengan kata lain, Anda berdua sudah tidak dapat lagi mengambil pizza.)

Catatan: perhatikan bahwa nilai K tidak diberikan pada masukan.

### Contoh Interaksi 1

| Program Anda         | Program Juri |
| ---------------------| ------------ |
|                      | 0..34\n3 1\n2 4 4\n2 3 2\n2 1 3\n |
| 2                    | |
|                      | 1 |
| 3                    | |
|                      | 1 |
| 3                    | |
|                      | 3 |
| 3                    | |
|                      | 0 |
| 2                    | |
|                      | 0 |
| 2                    | |
|                      | 0 |
| 2                    | |
|                      | 0 |
| 0                    | |
| (Interaksi selesai)  | (Interaksi selesai) |

### Penjelasan Contoh 1

Anda berhasil mengambil 7 potongan pizza. Sebenarnya, apabila Pak Dengklek menggunakan strategi optimal, maka Anda hanya mungkin mengambil paling banyak K = 6 potongan pizza. Seandainya Anda hanya berhasil mengambil 6 potongan pizza pun, program Anda tetap dinyatakan benar.

### Contoh Interaksi 2

| Program Anda         | Program Juri |
| -------------------- | ------------ |
|                      | 0...4\n3 1\n3 4 4\n1 1\n2 1 2\n |
| 1                    | |
|                      | 1 |
| 1                    | |
|                      | 2 |
| 0                    | |
|                      | 2 |
| 0                    | |
|                      | 2 |
| 0                    | |
|                      | 2 |
| 0                    | |
|                      | 0 |
| (Interaksi selesai)  | (Interaksi selesai) |

### Penjelasan Contoh 2

Anda berhasil mengambil 2 potongan pizza. Seandainya Pak Dengklek menggunakan strategi optimal, maka Anda juga hanya dapat mengambil paling banyak K = 2 potongan pizza, sehingga program Anda dinyatakan benar.

### Contoh Interaksi 3 (Contoh Gagal)

| Program Anda         | Program Juri |
| -------------------- | ------------ |
|                      | 0..34\n1 1\n4\n1 1\n1 1\n |
| 1                    | |
|                      | 1 |
| 0                    | |
|                      | 1 |
| 0                    | |
|                      | 1 |
| 0                    | |
|                      | 0 |
| (Interaksi selesai)  | (Interaksi selesai) |

### Penjelasan Contoh 3

Baik Anda maupun Pak Dengklek seharusnya dapat mengambil masing-masing 2 potongan pizza, sehingga K = 2. Namun, karena Anda berhasil untuk hanya mengambil 1 saja, program Anda dinyatakan gagal.

### Contoh Interaksi 4 (Contoh Gagal)

| Program Anda         | Program Juri |
| -------------------- | ------------ |
|                      | 0..34\n1 1\n4\n1 1\n1 1\n |
| 2                    | |
| (Interaksi selesai)  | (Interaksi selesai) |

### Penjelasan Contoh 4

Anda mengambil potongan pizza yang tidak ada (tidak ada pizza rasa ke-2) sehingga program Anda langsung dinyatakan gagal.

### Subsoal

Untuk semua subsoal, berlaku:

- 1 ≤ N ≤ 10
- 1 ≤ S ≤ 2
- 1 ≤ A[i] ≤ 10
- 0 ≤ P, Q ≤ N
- X dan Y masing-masing berisi bilangan-bilangan dari 1 hingga N tanpa pengulangan.

#### Subsoal 1 (15 poin):

Hanya berisi kasus uji berikut:

    .1.34
    4 1
    2 4 6 8
    2 3 4
    2 2 4

Catatan: pada kasus uji ini, diketahui bahwa K = 10.

#### Subsoal 2 (15 poin):

Hanya berisi kasus uji berikut:

    ..2.4
    6 1
    1 2 3 4 5 6
    6 1 2 3 4 5 6
    3 4 5 6

Catatan: pada kasus uji ini, diketahui bahwa K = 14.

#### Subsoal 3 (40 poin):

- S = 1
- Semua A[i] bernilai genap.

#### Subsoal 4 (30 poin):

- Tidak ada batasan tambahan.
