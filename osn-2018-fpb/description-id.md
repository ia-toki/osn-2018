## Festival FPB

### Deskripsi

Di sebuah desa kecil di Padang, terdapat N rumah yang berjajar bersebelahan membentuk sebuah garis lurus. Rumah ke-i memiliki A[i] anggota keluarga.

Untuk menambah pendapatan daerah, sang kepala desa mencanangkan program "Festival FPB". Setiap harinya, kepala desa akan memilih satu atau lebih rumah, lalu membaginya ke dalam tepat K buah kelompok sedemikian sehingga:

- Setiap rumah termasuk ke dalam paling banyak satu kelompok.
- Semua rumah dalam satu kelompok yang sama terletak saling bersebelahan, tidak diselingin oleh rumah lain yang bukan merupakan kelompok tersebut.

Kemudian, setiap kelompok memberikan sumbangan sebesar faktor persekutuan terbesar (FPB) dari banyaknya anggota keluarga di rumah-rumah pada kelompok tersebut.

Kepala desa akan selalu memilih pengelompokan yang berbeda setiap harinya. Festival ini berakhir ketika semua kemungkinan pemilihan K buah kelompok sudah terjadi.

Kepala desa penasaran, pada akhirnya, berapakah total pendapatan dari festival ini? Karena totalnya bisa sangat besar, ia hanya tertarik pada hasilnya modulo 1.000.000.007.

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

    N K
    A[1] A[2] .. A[N]

### Format Keluaran

Sebuah baris berisi total pendapatan, modulo 1.000.000.007.

### Contoh Masukan

    0..3.56..9
    3 2
    6 4 5

### Contoh Keluaran

    44

### Penjelasan Contoh

Berikut adalah semua cara pemilihan K kelompok berikut pendapatannya:

- [6] [4] 5: FPB(6) + FPB(4) = 6 + 4 = 10.
- [6] 4 [5]: FPB(6) + FPB(5) = 6 + 5 = 11.
- [6] [4 5]: FPB(6) + FPB(4, 5) = 6 + 1 = 7.
- [6 4] [5]: FPB(6, 4) + FPB(5) = 2 + 5 = 7.
- 6 [4] [5]: FPB(4) + FPB(5) = 4 + 5 = 9.

Maka, total pendapatan adalah 10 + 11 + 7 + 7 + 9 = 44.

### Subsoal

Untuk semua subsoal, berlaku:

- 1 ≤ N ≤ 50.000
- 1 ≤ K ≤ min(N, 20)
- 1 ≤ A[i] ≤ 100.000

#### Subsoal 1:

Hanya berisi kasus uji berikut:

    .1.34567.9
    9 1
    30 15 3 48 24 8 12 100 52


#### Subsoal 2:

Hanya berisi kasus uji berikut:

    ..23..6.89
    9 3
    1 1 1 1 1 1 1 1 1

### Subsoal 3:

- N ≤ 10

#### Subsoal 4:

- N ≤ 500
- K = 1

#### Subsoal 5:

- N ≤ 500
- K ≤ min(N, 2)

#### Subsoal 6:

- N ≤ 500

#### Subsoal 7:

- K = 1

#### Subsoal 8:

- Semua nilai A[i] sama.

#### Subsoal 9:

- Tidak ada batasan tambahan.
