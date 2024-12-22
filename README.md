PURRMART - Tugas Besar IF2111 Algoritma dan Struktur Data

DISIAPKAN OLEH: 
- 18223033	Persada Ramiiza Abyudaya
- 18223073	Nawaf Amjad Rizqi A. Ismail
- 18223075	Surya Suharna
- 18221022	Athira Dhyanissa Tafkir
- 18223061	Naura Ayurachmani

- ASISTEN TUGAS BESAR: Vincent Franstyo

PURRMART adalah aplikasi simulasi e-commerce berbasis Command-Line Interface (CLI) yang dirancang untuk membantu OWCA dalam memenuhi kebutuhan mereka selama masa kritis. Aplikasi ini memungkinkan pengguna untuk:
- Menampilkan barang toko
- Meminta dan menyuplai barang baru ke toko
- Menyimpan dan membeli barang dalam keranjang
- Menampilkan barang yang sudah dibeli
- Membuat dan menghapus wishlist
- Bekerja untuk menghasilkan uang


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
        
4. Sistem Keranjang
   - Melihat daftar barang di keranjang.
   - Menambahkan barang ke keranjang.
   - Menghapus barang dari keranjang.
   - Membeli barang di keranjang.
     
5. Sistem Wishlist
   - Melihat daftar barang di wishlist.
   - Menambahkan barang ke wishlist.
   - Menghapus barang dari wishlist berdasarkan posisi barang atau nama barang.
   - Mengosongkan wishlist.
   - Menukar posisi barang di wishlist.
     
6.  Penyimpanan dan Pemulihan Data
   - Menyimpan state aplikasi ke file konfigurasi.
   - Memuat state aplikasi dari file konfigurasi.


CARA MENJALANKAN:
1. Setelah kompilasi berhasil, jalankan program:
   ./purrmart
2. Anda akan melihat main menu dengan beberapa opsi seperti:
    START
    LOAD <filename>
    HELP
3. Ikuti instruksi di layar untuk menjalankan fitur-fitur aplikasi.

COMMAND DESKRIPSI:
- START	          - Memulai sesi baru dengan membaca file konfigurasi default.
- LOAD <filename>	 - Memuat state aplikasi dari file konfigurasi yang disimpan.
- LOGIN	          - Masuk ke dalam sistem menggunakan akun terdaftar.
- REGISTER	       - Mendaftarkan akun baru ke dalam sistem.
- PROFILE          - Menampilkan profil dari pengguna.
- WORK	          - Melakukan pekerjaan untuk mendapatkan uang.
- WORK CHALLENGE	 - Menyelesaikan challenge seperti Tebak Angka dan W0RDL3.
- STORE LIST	    - Melihat daftar barang yang tersedia di toko.
- STORE REQUEST	 - Meminta penambahan barang baru ke toko melalui antrian permintaan.
- STORE SUPPLY	    - Menambahkan barang dari antrian permintaan ke toko.
- STORE REMOVE	    - Menghapus barang dari toko.
- CART ADD         - Menambahkan barang ke keranjang.
- CART REMOVE      - Menghapus barang dari keranjang.
- CART SHOW        - Menampilkan barang di keranjang.
- CART PAY         - Membeli barang di keranjang.
- HISTORY          - Menampilkan riwayat pembelian.
- WISHLIST ADD     - Menambahkan barang ke wishlist.
- WISHLIST REMOVE  - Menghapus barang dari wishlist.
- WISHLIST SWAP    - Menukar posisi barang di wishlist.
- WISHLIST CLEAR   - Mengosongkan wishlist.
- WISHLIST SHOW    - Menampilkan daftar wishlist.
- OPTIMASIRUTE     - Menghasilkan rute paling efektif untuk pengiriman barang.
- SAVE <filename>	 - Menyimpan state aplikasi ke file konfigurasi.
- HELP             - Menampilkan bantuan.
- LOGOUT           - Keluar dari sesi pengguna.
- QUIT	          - Keluar dari aplikasi.

LISENSI:
Proyek ini dibuat untuk keperluan akademik dalam mata kuliah IF2111 Algoritma dan Struktur Data. Semua hak cipta adalah milik Institut Teknologi Bandung dan tim pengembang.
