#include <stdio.h>
#include "help.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"

void help_main(){
    printf("Berikut adalah daftar perintah yang dapat digunakan:\n");
    printf("\n+-------------------------------------------------------------------+\n");
    printf("| No  | Command               | Description                        |\n");
    printf("+-------------------------------------------------------------------+\n");
    printf("| 1   | START                 | Mulai permainan atau aktivitas     |\n");
    printf("| 2   | LOAD                  | Memuat data yang disimpan          |\n");
    printf("| 3   | LOGIN                 | Masuk sebagai pengguna terdaftar   |\n");
    printf("| 4   | REGISTER              | Membuat akun baru                  |\n");
    printf("| 5   | PROFILE               | Menampilkan profil pengguna        |\n");
    printf("| 6   | STORE SUPPLY          | Menambahkan barang ke toko         |\n");
    printf("| 7   | STORE REMOVE          | Menghapus barang dari toko         |\n");
    printf("| 8   | STORE LIST            | Menampilkan daftar barang di toko  |\n");
    printf("| 9   | STORE REQUEST         | Melihat permintaan barang          |\n");
    printf("| 10  | WORK                  | Bekerja untuk mendapatkan uang     |\n");
    printf("| 11  | TEBAK ANGKA           | Bermain tebak angka                |\n");
    printf("| 12  | WORDL3                | Bermain challenge Wordl3           |\n");
    printf("| 13  | CART ADD              | Menambahkan barang ke keranjang    |\n");
    printf("| 14  | CART REMOVE           | Menghapus barang dari keranjang    |\n");
    printf("| 15  | CART SHOW             | Menampilkan barang di keranjang    |\n");
    printf("| 16  | CART PAY              | Membeli barang di keranjang        |\n");
    printf("| 17  | HISTORY               | Menampilkan riwayat pembelian      |\n");
    printf("| 18  | WISHLIST ADD          | Menambahkan barang ke wishlist     |\n");
    printf("| 19  | WISHLIST REMOVE       | Menghapus barang dari wishlist     |\n");
    printf("| 20  | WISHLIST SWAP         | Menukar posisi barang di wishlist  |\n");
    printf("| 21  | WISHLIST CLEAR        | Mengosongkan wishlist              |\n");
    printf("| 22  | WISHLIST SHOW         | Menampilkan daftar wishlist        |\n");
    printf("| 23  | HELP                  | Menampilkan bantuan                |\n");
    printf("| 24  | SAVE                  | Menyimpan konfigurasi atau data    |\n");
    printf("| 25  | LOGOUT                | Keluar dari sesi pengguna          |\n");
    printf("| 26  | QUIT                  | Keluar dari program                |\n");
    printf("+-------------------------------------------------------------------+\n");
    printf("\n");
    while(1){
        printf("Ketik 'BACK' untuk kembali: \n");
        printf(">>> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")){
            break;
        } else {
            printf("Input tidak valid. \n");
        }
    }
}