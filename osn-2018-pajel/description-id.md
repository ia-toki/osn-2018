## Permainan Pajel

### Deskripsi

Pak Dengklek membuat permainan soliter baru untuk Anda bernama Pajel. Pada permainan ini, terdapat sebuah papan berisi petak-petak berukuran N baris dan N kolom. Mulanya, setiap petak berwana putih. Anda diminta untuk mewarnai nol atau lebih petak dengan warna merah (M) atau biru (B), yang memenuhi seluruh syarat pada pinggir luar keempat sisi papan.

Petak-petak pada pinggir luar sisi atas papan berisi syarat berupa salah satu dari:

- Sebuah bilangan bulat positif diikuti dengan karakter 'M' atau 'B': bilangan menyatakan jarak petak berwarna terdekat pada kolom tersebut dari sisi atas, dan karakter menyatakan warnanya.
- Karakter '0': menyatakan bahwa tidak ada petak berwarna apapun pada kolom tersebut.
- Karakter '-': tidak menyatakan syarat apapun sehingga dapat diabaikan.

Petak-petak pada pinggir luar sisi kiri, kanan, dan bawah didefinisikan dengan cara yang mirip (untuk sisi kiri dan kanan, "kolom" diganti dengan "baris" pada aturan di atas).

Dua buah petak berwarna sama (selain putih) yang berbagi sisi yang sama dikatakan berada pada satu wilayah yang sama.

Sebagai contoh, berikut adalah dua buah solusi berbeda dari permainan Pajel yang sama. Pada kedua solusi berikut, terdapat 3 buah wilayah.

[pajel_1.png] [pajel2_.png]


Berikut ini adalah solusi lainnya, yang mengandung 6 wilayah.

[pajel_3.png]

Pada permainan ini, tujuan Anda adalah untuk mewarnai petak-petak sedemikian sehingga banyaknya wilayah berbeda sesedikit mungkin. Misalkan banyaknya wilayah berbeda pada solusi juri adalah P, dan pada solusi Anda adalah P. Nilai Anda akan bergantung pada seberapa dekat Q ke P, menggunakan rumus yang akan dijelaskan pada bagian Penilaian.

### Informasi Tipe Soal

Soal ini adalah soal "output-only". Untuk setiap kasus uji, Anda menuliskan keluaran program ke dalam sebuah berkas keluaran.

Masukan untuk soal ini dapat diunduh di sini. Di dalam berkas .zip tersebut terdapat 1 + 8 masukan untuk diselesaikan: osn-2018-pajel\_0.in, osn-2018-pajel\_1.in, osn-2018-pajel\_2.in, ..., osn-2018-pajel\_8.in. Masukan contoh (nomor 0) tidak dinilai.

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

- N menyatakan banyaknya baris dan kolom.
- P menyatakan banyaknya wilayah yang bisa dicapai oleh solusi juri.
- U[i] menyatakan syarat di atas kolom ke-i.
- L[i] menyatakan syarat di kiri baris ke-i.
- R[i] menyatakan syarat di kanan baris ke-i.
- D[i] menyatakan syarat di bawah kolom ke-i.

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

### Batasan

- 5 ≤ N ≤ 500
- 1 ≤ P ≤ N^2
- Dijamin terdapat setidaknya satu solusi.

### Penilaian

TBA