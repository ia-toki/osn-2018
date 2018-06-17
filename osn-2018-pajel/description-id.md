## Permainan Pajel

### Deskripsi

Pak Dengklek membuat permainan soliter baru untuk Anda bernama Pajel. Pada permainan ini, terdapat sebuah papan berisi petak-petak berukuran N baris dan N kolom. Baris-baris dan kolom-kolom dinomori dari 1 sampai dengan N.

Mulanya, setiap petak berwana putih. Anda diminta untuk mewarnai nol atau lebih petak dengan warna merah (M) atau biru (B), yang memenuhi seluruh petunjuk pada pinggir luar keempat sisi papan.

Petak-petak pada pinggir luar sisi atas papan berisi petunjuk berupa salah satu dari:

- Sebuah bilangan bulat positif diikuti dengan karakter 'M' atau 'B': bilangan menyatakan jarak petak berwarna terdekat pada kolom tersebut dari sisi atas, dan karakter menyatakan warnanya.
- Karakter '0': menyatakan bahwa tidak ada petak berwarna apapun pada kolom tersebut.
- Karakter '-': tidak menyatakan petunjuk apapun sehingga dapat diabaikan.

Petak-petak pada pinggir luar sisi kiri, kanan, dan bawah didefinisikan dengan cara yang mirip (untuk sisi kiri dan kanan, "kolom" diganti dengan "baris" pada aturan di atas).

Dua buah petak berwarna sama (selain putih) yang berbagi sisi yang sama dikatakan berada pada satu wilayah yang sama.

Sebagai contoh, berikut adalah dua buah solusi berbeda dari permainan Pajel yang sama. Pada kedua solusi berikut, terdapat 3 buah wilayah.

[pajel_1.png] [pajel_2.png]


Berikut ini adalah solusi lainnya, yang mengandung 6 wilayah.

[pajel_3.png]

Pada permainan ini, tujuan Anda adalah untuk mewarnai petak-petak sesuai dengan petunjuk-petunjuk yang diberikan, sedemikian sehingga banyaknya wilayah berbeda sesedikit mungkin. Misalkan banyaknya wilayah berbeda pada solusi juri adalah P, dan pada solusi Anda adalah Q. Nilai Anda akan bergantung pada seberapa dekat Q ke P, menggunakan rumus yang akan dijelaskan pada bagian Penilaian.

### Informasi Tipe Soal

Soal ini adalah soal "output-only". Untuk setiap kasus uji, Anda menuliskan keluaran program ke dalam sebuah berkas keluaran.

Masukan untuk soal ini dapat diunduh di sini. Di dalam berkas .zip tersebut terdapat 1 + 10 masukan untuk diselesaikan: osn-2018-pajel\_0.in, osn-2018-pajel\_1.in, osn-2018-pajel\_2.in, ..., osn-2018-pajel\_10.in. Masukan contoh (nomor 0) tidak termasuk dalam penilaian peserta.

Untuk setiap berkas masukan yang diselesaikan (Anda tidak harus menyelesaikan semua masukan), buatlah berkas keluaran dengan nama osn-2018-pajel\_X.out, dengan X adalah nomor kasus uji. Setelah itu, kompres semua berkas keluaran dalam sebuah berkas .zip, lalu kumpulkan.

### Format Masukan

Masukan diberikan dalam format berikut:

    N P
    U[1] U[2] ... U[N]
    L[1] R[1]
    L[2] R[2]
    .
    .
    L[N] R[N]
    D[1] D[2] .. D[N]

dengan:

- U[i] menyatakan petunjuk di atas kolom ke-i.
- L[i] menyatakan petunjuk di kiri baris ke-i.
- R[i] menyatakan petunjuk di kanan baris ke-i.
- D[i] menyatakan petunjuk di bawah kolom ke-i.

### Format Keluaran

N baris berisi N karakter, yang menunjukkan warna setiap petak: 'M' untuk merah, 'B' untuk biru, '-' untuk putih.

### Contoh Masukan

    5 3
    1M - - - -
    - -
    1B 3B
    0 -
    - -
    5M 1M
    4B - 2M - -

### Contoh Keluaran

    MM---
    BBB--
    -----
    -MMMM
    ----M

### Penjelasan Contoh

Contoh keluaran tersebut menyatakan solusi dari gambar pertama di atas.

### Penilaian

Untuk setiap kasus uji:

| Kondisi        | Poin                          |
| -------------- | ----------------------------- |
| Q < P          | 11                            |
| Q = P          | 10                            |
| 1 ≤ Q - P ≤ 40 | floor(10 - sqrt(2 × (Q - P))) |
| Q - P > 40     | 0                             | 

### Kasus-Kasus Uji

Untuk setiap kasus uji:

- 5 ≤ N ≤ 500
- 1 ≤ P ≤ N^2
- Dijamin terdapat setidaknya satu solusi yang memenuhi seluruh petunjuk.

#### osn-2018-pajel_1.in

- N = 10
- P = 4

#### osn-2018-pajel_2.in

- N = 10
- P = 9

#### osn-2018-pajel_3.in

- N = 30
- P = 9
- Pandang seluruh petunjuk pada sisi-sisi papan sebagai mata-mata rantai yang tersambung mengelilingi papan. Di antara dua petunjuk bukan '-', selalu terdapat setidaknya 4 petunjuk '-'.

#### osn-2018-pajel_4.in

- N = 60
- P = 139
- Tidak ada petunjuk '-'.

#### osn-2018-pajel_5.in

- N = 100
- P = 137
- Tidak ada petunjuk berwarna 'B'.

#### osn-2018-pajel_6.in

- N = 150
- P = 152
- Bilangan pada setiap petunjuk (jika ada), tidak lebih dari 9.

#### osn-2018-pajel_7.in

- N = 250
- P = 181
- Seluruh petunjuk pada sisi kiri dan sisi kanan adalah '-'.

#### osn-2018-pajel_8.in

- N = 357
- P = 156
- Petunjuk bukan '-' hanya terdapat pada baris dan kolom yang indeksnya sama dengan 3 dalam modulo 4.

#### osn-2018-pajel_9.in

- N = 499
- P = 427
- Pandang seluruh petunjuk pada sisi-sisi papan sebagai mata-mata rantai yang tersambung mengelilingi papan. Di antara dua petunjuk bukan '-', selalu terdapat setidaknya 2 petunjuk '-'.

#### osn-2018-pajel_10.in

- N = 500
- P = 978
