# Balatro-Like Run — Task 1
## Struktur File

| File | Fungsi |
|------|--------|
| `IInputGenerator.h` | Interface untuk generator input + struct TurnInput |
| `IScoringRule.h` | Interface untuk penghitung score |
| `IRewardRule.h` | Interface untuk penghitung reward |
| `InputGenerators.h/.cpp` | FixedInputGenerator & RandomInputGenerator |
| `ScoringRules.h/.cpp` | SimpleScoring |
| `RewardRules.h/.cpp` | BaseRewardRule & BonusRewardRule |
| `ShopSystem.h/.cpp` | Sistem toko sederhana |
| `RunSession.h/.cpp` | Game loop utama (sutradara) |
| `main.cpp` | Entry point, merakit semua komponen |

---

## Refleksi

### 1. Struktur invariant dalam program ini

Struktur invariant itu urutan fase fix di `RunSession::run()`. Tiap ronde wajib lewat 6 step ini berurutan: generate input → base score → reward → update uang → toko → lanjut ronde. Urutannya ga boleh diutak-atik. `RunSession` hanaya mengatur alur , bukan mengurus isi dalam tiap fase.


### 2. Bagian mutable (bisa diubah)

Implementasi `IInputGenerator`
Dapat ditukar secara bebas antara FixedInputGenerator (input tetap) atau RandomInputGenerator (input acak) sesuai kebutuhan sesi.

Logika `IScoringRule`
Mekanisme penghitungan skor dapat diubah atau diganti dengan aturan baru tanpa memengaruhi sistem lainnya.

Logika `IRewardRule`
Aturan pemberian hadiah dapat dimodifikasi, misalnya mengubah ambang batas reward atau jenis hadiah yang diberikan.

Perilaku `ShopSystem`
Dapat diperluas atau dimodifikasi, seperti menambahkan logika spesifik untuk transaksi pembelian item atau perubahan harga.

Perakitan di `main()`
Fungsi main() berfungsi sebagai satu-satunya Entry Point dan pusat konfigurasi (Dependency Injector) untuk menyusun komponen-komponen di atas.

### 3. Kenapa RunSession tidak perlu diubah saat InputGenerator diganti?

Karena `RunSession` hanya menyimpan pointer ke interface `IInputGenerator`, bukan ke implementasi spesifik manapun. Dia hanya tahu bahwa "ada sesuatu yang bisa generate input" — dia tidak peduli apakah itu `FixedInputGenerator` atau `RandomInputGenerator`. Ketika kita mengganti generator di `main()`, kita cukup mengoper objek berbeda yang memenuhi kontrak interface yang sama. Karena kontraknya tidak berubah (fungsi `generate()` tetap mengembalikan `TurnInput`), `RunSession` tidak punya alasan untuk ikut berubah. Inilah manfaat utama dari pemrograman berbasis interface, bukan class konkret.

### 4. Apa yang terjadi jika logika scoring diletakkan di dalam RunSession?

Jika logika scoring diletakkan di dalam `RunSession`, maka setiap kali kita ingin mengubah cara scoring bekerja — misalnya mengganti dari scoring sederhana ke sistem berbasis multiplier — kita terpaksa membuka dan memodifikasi `RunSession`. Hal ini melanggar invariant, karena `RunSession` seharusnya menjadi inti program yang stabil dan tidak boleh berubah. Kode juga menjadi lebih sulit dikembangkan dan diuji. Dengan menjaga logika scoring di class terpisah yang mengimplementasikan `IScoringRule`, `RunSession` tetap tidak tersentuh meskipun perilaku scoring berubah sepenuhnya. Pemisahan inilah yang menjaga arsitektur tetap bersih dan fleksibel.
