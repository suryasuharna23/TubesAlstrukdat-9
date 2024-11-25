PURRMART - Tugas Besar IF2111 Algoritma dan Struktur Data

DISIAPKAN OLEH: 
- 18223033	Persada Ramiiza Abyudaya
- 18223073	Nawaf Amjad Rizqi A. Ismail
- 18223075	Surya Suharna
- 18221022	Athira Dhyanissa Tafkir
- 18223061	Naura Ayurachmani

- ASISTEN TUGAS BESAR: Vincent Franstyo

PURRMART adalah aplikasi simulasi e-commerce berbasis Command-Line Interface (CLI) yang dirancang untuk membantu OWCA dalam memenuhi kebutuhan mereka selama masa kritis. Aplikasi ini memungkinkan pengguna untuk:
- Menampilkan dan mengelola daftar barang toko.
- Mendaftarkan dan mengelola akun pengguna.
- Menyimpan dan membeli barang ke dalam keranjang.
- Melakukan pekerjaan untuk mendapatkan uang.
- Menyelesaikan challenge seru untuk mendapatkan keuntungan tambahan.

Aplikasi ini dibuat menggunakan bahasa C dengan berbagai ADT (Abstract Data Type) untuk merepresentasikan data seperti barang, pengguna, antrian, dan lain-lain.

FITUR UTAMA:
1. Pengelolaan Pengguna
   - Login dan logout ke sistem.
   - Pendaftaran pengguna baru.

2. Pengelolaan Barang
   - Melihat daftar barang di toko.
   - Menambahkan barang baru ke toko melalui antrian permintaan.
   - Menyediakan harga untuk barang baru.
   - Menghapus barang dari toko.

3. Sistem Pekerjaan
   - Melakukan pekerjaan untuk mendapatkan uang.
   - Menyelesaikan challenge seperti:
      - Tebak Angka.
      - W0RDL3.

4. Penyimpanan dan Pemulihan Data
   - Menyimpan state aplikasi ke file konfigurasi.
   - Memuat state aplikasi dari file konfigurasi.

CARA KOMPILASI:
1. Pastikan Anda memiliki compiler C seperti GCC terinstal di komputer Anda.
2. Buka terminal dan arahkan ke folder proyek.
3. Jika Anda memiliki Makefile, cukup jalankan:
   make
4. Jika tidak menggunakan Makefile, kompilasi manual:
   gcc -o purrmart src/*.c
5. Program akan terkompilasi menjadi file bernama purrmart.

CARA MENJALANKAN:
1. Setelah kompilasi berhasil, jalankan program:
   ./purrmart
2. Anda akan melihat main menu dengan beberapa opsi seperti:
    START
    LOAD <filename>
    HELP
3. Ikuti instruksi di layar untuk menjalankan fitur-fitur aplikasi.

COMMAND DESKRIPSI:
START	          - Memulai sesi baru dengan membaca file konfigurasi default.
LOAD <filename>	  - Memuat state aplikasi dari file konfigurasi yang disimpan.
LOGIN	          - Masuk ke dalam sistem menggunakan akun terdaftar.
REGISTER	      - Mendaftarkan akun baru ke dalam sistem.
WORK	          - Melakukan pekerjaan untuk mendapatkan uang.
WORK CHALLENGE	  - Menyelesaikan challenge seperti Tebak Angka dan W0RDL3.
STORE LIST	      - Melihat daftar barang yang tersedia di toko.
STORE REQUEST	  - Meminta penambahan barang baru ke toko melalui antrian permintaan.
STORE SUPPLY	  - Menambahkan barang dari antrian permintaan ke toko.
STORE REMOVE	  - Menghapus barang dari toko.
SAVE <filename>	  - Menyimpan state aplikasi ke file konfigurasi.
QUIT	          - Keluar dari aplikasi.

LISENSI:
Proyek ini dibuat untuk keperluan akademik dalam mata kuliah IF2111 Algoritma dan Struktur Data. Semua hak cipta adalah milik Institut Teknologi Bandung dan tim pengembang.