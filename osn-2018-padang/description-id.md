## Pertahanan Padang

### Deskripsi

Kota Padang terkenal dengan "sajak biner"-nya. Sebuah sajak biner adalah sebuah string S yang memenuhi seluruh syarat berikut:

- S yang hanya terdiri atas karakter '0' atau '1'.
- S terdiri atas setidaknya 1 karakter.
- S[0] = '1'. (Indeks string dimulai dari 0.)

Sebuah "sajak biner bergantian" adalah sebuah string S yang memenuhi seluruh syarat berikut:

- S adalah sajak biner.
- S[i] dan S[i-1] berbeda, untuk i > 0.

Sebagai contoh, "1", "10", "101", dan "1010" adalah sajak-sajak biner bergantian, sedangkan "", "0", "01", "010", dan "100" bukan.

Suatu hari, kota Padang tengah diserang sesosok makhluk jahat! Pak Dengklek, sang penguasa kota Padang, sedang berunding dengan makhluk jahat tersebut agar ia segera pergi. Rupanya, makhluk jahat tersebut hanya ingin dibuatkan sebuah sajak biner S yang memenuhi seluruh berikut:

- S mengandung tepat A buah subsekuens yang berupa sajak biner bergantian dengan panjang ganjil.
- S mengandung tepat B buah subsekuens yang berupa sajak biner bergantian dengan panjang genap. 

Sebuah subsekuens dari S dihasilkan dengan membuang nol atau lebih karakter dari S. Sebagai contoh, sajak biner "1101" memiliki tepat 7 buah subsekuens sajak biner bergantian: "1" (3 buah), "10" (2 buah), dan "101" (2 buah).

Karena mungkin saja terdapat banyak sajak biner yang memenuhi syarat, makhluk jahat tersebut ingin sajak biner yang terkecil secara leksikografis (lihat bagian Catatan).

Karena sajak biner S bisa panjang sekali, makhluk jahat tersebut memberikan keringanan dengan hanya akan memberikan Q buah pertanyaan. Pertanyaan ke-i berupa: apakah karakter-karakter S dari indeks L[i] sampai dengan R[i], inklusif?

Bantulah Pak Dengklek untuk menjawab pertanyaan-pertanyaan tersebut!

### Catatan

Urutan leksikografi didefinisikan sebagai berikut: string U dikatakan lebih kecil secara leksikografis daripada string V apabila U merupakan prefiks dari V, atau pada indeks terkecil i yang mana U[i] berbeda dengan V[i], berlaku U[i] < V[i].

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

    A B Q
    L[1] R[1]
    L[2] R[2]
    .
    .
    L[Q] R[Q]
    
### Format Keluaran

Apabila tidak ada sajak biner S yang memenuhi syarat, keluarkan sebuah baris berisi:

    TIDAK MUNGKIN
    
Apabila ada, keluarkan:

    MUNGKIN
    T[1]
    T[2]
    .
    .
    T[Q]
    
dengan T[i] adalah jawaban dari pertanyaan ke-i, apabila L[i] dan R[i] adalah indeks yang terdapat pada S, atau `DI LUAR BATAS` apabila tidak.

### Contoh Masukan 1

    0....56.8
    5 2 4
    0 3
    1 2
    3 3
    0 4

### Contoh Keluaran 1

    MUNGKIN
    1101
    10
    1
    DI LUAR BATAS

### Penjelasan Contoh 1

Sajak biner terkecil secara leksikografis yang memenuhi syarat adalah S = "1101":

- Terdapat A = 5 subsekuens berupa sajak biner bergantian dengan panjang ganjil: "1" (3 buah) dan "101" (2 buah).
- Terdapat B = 2 subsekuens berupa sajak biner bergantian dengan panjang genap: "10" (2 buah).

### Contoh Masukan 2

    0....56.8
    3 2 4
    0 3
    1 2
    3 3
    0 4

### Contoh Keluaran 2

    TIDAK MUNGKIN

### Subsoal

Untuk semua subsoal, berlaku:

- 0 ≤ A, B ≤ 10^15
- A + B > 0
- 0 ≤ Q ≤ 20.000
- 0 ≤ L[i] ≤ R[i] < 10^16
- R[i] - L[i] ≤ 50

#### Subsoal 1 (10 poin):

Hanya berisi kasus uji berikut:

    .1..456.8
    3 9 1
    1 4

#### Subsoal 2 (10 poin):

Hanya berisi kasus uji berikut:

    ..2..56.8
    25 3 4
    0 7
    0 8
    0 9
    0 10

#### Subsoal 3 (10 poin): 

- A + B ≤ 8
- Q = 1

#### Subsoal 4 (11 poin):

- A + B ≤ 18
- Q = 1

#### Subsoal 5 (15 poin):

- A, B ≤ 2.000

#### Subsoal 6 (20 poin):

- A, B ≤ 1.000.000

#### Subsoal 7 (14 poin):

- Q = 0

#### Subsoal 8 (10 poin):

- Tidak ada batasan tambahan.
