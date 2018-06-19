## Ojek Daring

### Deskripsi

Terdapat V kota di Sumatra Barat, dinomori 1 hingga V. Terdapat E buah ruas jalan dua arah yang menghubungkan kota-kota, dinomori 1 hingga E. Ruas jalan ke-i menghubungkan kota X[i] dengan Y[i], dan memiliki jarak K[i]. Setiap pasang kota terhubung oleh paling banyak satu ruas jalan. Tidak ada ruas jalan yang menghubungkan sebuah kota dengan dirinya sendiri.

Hanya terdapat dua moda transportasi: ojek pangkalan (lokal) dan ojek daring (*online*). Keduanya dapat Anda pesan melalui telepon genggam Anda, yang lalu akan menghampiri Anda di manapun Anda berada.

Terdapat beberapa aturan pemesanan ojek, bergantung pada lokasi Anda sekarang dan jenis ojek, sebagaimana dijelaskan berikut:

- Jika Anda sedang berada tepat pada suatu kota (yakni, tepat pada suatu ujung dari suatu ruas jalan), maka Anda dapat memesan dan mulai menaiki ojek pangkalan maupun ojek daring.
- Jika Anda sedang berada pada bagian manapun dari suatu ruas jalan yang memiliki jarak berupa bilangan bulat dari kedua ujungnya (selanjutnya akan disebut "bagian bulat"), selain pada kota sebagaimana dijelaskan di atas, maka Anda:
  - dapat memesan dan mulai menaiki ojek pangkalan.
  - dapat memesan dan mulai menaiki ojek daring, hanya apabila ruas jalan tersebut TIDAK dikuasai oleh ojek pangkalan. Ruas jalan ke-i dikuasai oleh ojek pangkalan apabila Q[i] = 1.

Setelah Anda memesan ojek dan menaikinya, untuk kedua jenis ojek, Anda boleh melewati kota dan jalan manapun, kemudian dapat turun di kota manapun maupun bagian bulat manapun dari ruas jalan manapun.

Untuk ojek pangkalan, tarif sekali naik adalah C\_p (yakni, jauh-dekat harga sama), dan jarak maksimum dalam satu perjalanan adalah M\_p.

Untuk ojek daring, tarif sekali naik adalah C\_d × (jarak yang ditempuh), dan jarak maksimum dalam satu perjalanan adalah M\_d.

Anda ingin pergi dari kota A menuju kota B, dengan hanya memanfaatkan ojek (tanpa jalan kaki). Tentukan tarif termurah yang bisa Anda capai!

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

    V E
    C_d M_d
    M_p M_p
    A B
    X[1] Y[1] K[1] Q[1]
    X[2] Y[2] K[2] Q[2]
    .
    .
    X[E] Y[E] K[E] Q[E]

### Format Keluaran

Sebuah baris berisi tarif termurah untuk pergi dari kota A ke kota B.

### Contoh Masukan 1

    0...4567
    4 4
    1 3
    2 1
    1 2
    1 2 7 1
    1 3 2 0
    3 4 4 0
    4 2 6 0
    
### Contoh Keluaran 1

    11

### Penjelasan Contoh 1

TODO

### Contoh Masukan 2

    0...4567
    7 9
    1 1
    2 1
    1 7
    1 2 1 1
    2 3 1 1
    3 1 1 1
    3 4 1 1
    4 5 1 1
    5 3 1 1
    5 6 1 1
    6 7 1 1
    7 5 1 1

### Contoh Keluaran 2

    3

### Penjelasan Contoh 2

TODO

### Subsoal

Untuk semua subsoal, berlaku:

- 2 ≤ V ≤ 200
- V - 1 ≤ E ≤ V × (V - 1) / 2
- 1 ≤ C\_p, C\_d ≤ 10^9
- 1 ≤ M\_p, M\_d ≤ 200
- 1 ≤ A, B, X[i], Y[i] ≤ V
- A != B
- Untuk setiap i, X[i] != Y[i]
- 1 ≤ K[i] ≤ 10^9
- 0 ≤ Q[i] ≤ 1
- Setiap pasang kota terhubung oleh paling banyak satu ruas jalan.
- Dijamin selalu terdapat cara untuk pergi dari setiap kota ke semua kota lainnya, melalui kota-kota dan jalan-jalan.

#### Subsoal 1:

Hanya berisi kasus uji berikut:

TODO

#### Subsoal 2:

Hanya berisi kasus uji berikut:

TODO

#### Subsoal 3:

- C\_d = C\_p = 1
- M\_d = M\_p = 1
- K[i] = 1

#### Subsoal 4:

- M\_d = M\_p = 1

#### Subsoal 5:

- K[i] ≤ 10

#### Subsoal 6:

- K[i] ≤ 200

#### Subsoal 7:

- Tidak ada batasan tambahan.
