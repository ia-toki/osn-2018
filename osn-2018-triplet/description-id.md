## Tantangan Triplet

### Deskripsi

Pak Dengklek memiliki N buah bilangan: A[1], A[2], ..., A[N]. Tentukan banyaknya triplet (i, j, k) yang memenuhi seluruh syarat berikut:

- 1 ≤ i < j < k ≤ N
- A[i] ≠ A[j]
- A[i] ≠ A[k]
- A[j] ≠ A[k]

### Format Masukan

Baris pertama akan berisi "label kasus uji". Label kasus uji adalah sebuah string yang dijelaskan sebagai berikut:

- Panjang string tersebut adalah banyaknya subsoal ditambah satu.
- Karakter ke-0 (indeks dimulai dari 0) akan berisi 0 jika kasus uji tersebut merupakan contoh kasus uji, atau berisi '.' (titik) jika bukan.
- Untuk setiap nilai i di antara 1 hingga banyaknya subsoal, berlaku:
  - jika kasus uji tersebut memenuhi batasan subsoal ke-i, maka karakter ke-i berisi i, atau
  - jika kasus uji tersebut tidak memenuhi batasan subsoal ke-i, maka karakter ke-i berisi karakter '.' (titik).

Sebagai contoh, apabila label sebuah kasus uji sebuah soal adalah `0..345`, maka:

- Soal tersebut memiliki 5 buah subsoal,
- Kasus uji tersebut merupakan contoh kasus uji, dan
- Kasus uji tesebut memenuhi batasan subsoal ke-3, ke-4, dan ke-5.

Baris-baris berikutnya diberikan dalam format berikut:

    N
    A[1] A[2] .. A[N]

### Format Keluaran

Sebuah baris berisi banyaknya triplet yang memenuhi syarat.

### Contoh Masukan

    0..3456
    4
    1 4 1 2

### Contoh Keluaran

    2

### Penjelasan Contoh

Triplet-triplet yang memenuhi adalah (1, 2, 4) dan (2, 3, 4).

### Subsoal

Untuk semua subsoal, berlaku:

- 3 ≤ N ≤ 100.000
- 1 ≤ A[i] ≤ 100.000

#### Subsoal 1:

Hanya berisi kasus uji berikut:

    .1.3456
    10
    1 2 3 4 5 6 7 8 9 10

#### Subsoal 2:

Hanya berisi kasus uji berikut:

    ..23456
    15
    5 4 5 4 4 2 1 3 3 5 3 5 2 4 5

### Subsoal 3:

- N ≤ 100

#### Subsoal 4:

- N ≤ 2.000

#### Subsoal 5:

- A[i] ≤ 100

#### Subsoal 6:

- Tidak ada batasan tambahan.
