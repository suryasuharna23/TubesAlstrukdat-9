#include <stdio.h>
#include <stdbool.h>
#include "ADT/User/user.h"
#include "ADT/Barang/barang.h"
#include "ADT/Mesin/mesinkata.h"
#include "ADT/Mesin/mesinkarakter.h"
#include "ADT/Map/map.h"
#include "ADT/Stack/stack.h"
#include "ADT/LinkedList/listlinier.h"
#include "command/Load/load.h"
#include "command/Save/save.h"
#include "command/Register/register.h"
#include "command/Help/help.h"
#include "command/Login/login.h"
#include "command/Work/work.h"
#include "command/Tebak_Angka/tebak_angka.h"
#include "command/WORDL3/wordl3.h"
#include "command/Store/store.h"
#include "command/Profile/profile.h"
#include "command/Cart/cart.h"
#include "command/History/history.h"
#include "command/Wishlist/wishlist.h"

// Deklarasi global
ListUser users;
ListBarang listbarang;
Queue requestQueue;
User CurrentUser = {"", "", 0}; // Menyimpan data pengguna yang sedang login
Stack purchaseHistory;
List wishlist;

void STARTINPUTWORD();
Word CurrentWord;

int main() {
    boolean running = true;
    boolean loggedIn = false;
    boolean IsStarted = false;  // Menandakan apakah program sudah dimulai

    // Inisialisasi
    CreateListUser(&users);
    CreateListBarang(&listbarang);
    CreateQueue(&requestQueue);
    CreateEmptyS(&purchaseHistory);
    CreateEmptyList(&wishlist);

    printf("****************************************\n");
    printf("*      Selamat Datang di PURRMART      *\n");
    printf("****************************************\n");

    char *commandStr;

    while (running) {
        if (!IsStarted) {
            // Menu Awal: START, LOAD, QUIT
            printf("\n+----------------------------------------+\n");
            printf("|           MENU AWAL PURRMART           |\n");
            printf("+----------------------------------------+\n");
            printf("| 1. START                               |\n");
            printf("| 2. LOAD                                |\n");
            printf("| 3. QUIT                                |\n");
            printf("+----------------------------------------+\n");

            printf(">>> ");
            STARTINPUTWORD();
            commandStr = WordToString(CurrentWord);

            if (isEqual(CurrentWord, "START")) {
                Load("default");  // Memuat data default jika ada
                printf("Data dimuat menggunakan setelan default.\n");
                SList(&listbarang); // Tampilkan barang setelah mulai
                IsStarted = true;  // Set IsStarted menjadi true
            } else if (isEqual(CurrentWord, "LOAD")) {
                printf("Masukkan nama file konfigurasi: ");
                STARTINPUTWORD();
                if (Load(WordToString(CurrentWord))) {
                    printf("Konfigurasi berhasil dimuat.\n");
                    SList(&listbarang); // Tampilkan barang setelah load
                    IsStarted = true;  // Set IsStarted menjadi true
                } else {
                    printf("Gagal memuat konfigurasi.\n");
                }
            } else if (isEqual(CurrentWord, "QUIT")) {
                running = false; // Keluar dari game
                printf("Terima kasih telah menggunakan PURRMART!\n");
            } else {
                printf("Perintah tidak dikenal: %s\n", commandStr);
            }
        } else {
            // Menu Utama setelah IsStarted = true
            if (!loggedIn) {
                // Menu login atau register
                printf("\n+----------------------------------------+\n");
                printf("|         MENU LOGIN / REGISTER          |\n");
                printf("+----------------------------------------+\n");
                printf("| 1. LOGIN                               |\n");
                printf("| 2. REGISTER                            |\n");
                printf("+----------------------------------------+\n");

                printf(">>> ");
                STARTINPUTWORD();
                commandStr = WordToString(CurrentWord);

                if (isEqual(CurrentWord, "LOGIN")) {
                    Login(&users, &CurrentUser);
                    loggedIn = true; // Set status login
                } else if (isEqual(CurrentWord, "REGISTER")) {
                    boolean registrationSuccessful = false;
                    RegisterUser(&users, &registrationSuccessful);
                    if (registrationSuccessful) {
                        loggedIn = true; // Set status login
                    }
                } else {
                    printf("Perintah tidak dikenal: %s\n", commandStr);
                }
            } else {
                // Menu Utama setelah login
                printf("\n+----------------------------------------------------------+\n");
                printf("|                  MENU UTAMA PURRMART                     |\n");
                printf("+----------------------------------------------------------+\n");
                printf("| 1.  PROFILE           - Tampilkan profile                |\n");
                printf("| 2.  STORE SUPPLY      - Pasok barang ke toko             |\n");
                printf("| 3.  STORE REMOVE      - Hapus barang ke toko             |\n");
                printf("| 4.  STORE LIST        - Tampilkan barang                 |\n");
                printf("| 5.  STORE REQUEST     - Lihat request barang             |\n");
                printf("| 6.  WORK              - Bekerja                          |\n");
                printf("| 7.  TEBAK ANGKA       - Tebak Angka                      |\n");
                printf("| 8.  WORDL3            - Challenge Wordl3                 |\n");
                printf("| 9.  CART ADD          - Tambah barang ke keranjang       |\n");
                printf("| 10. CART REMOVE       - Hapus barang dari keranjang      |\n");
                printf("| 11. CART SHOW         - Tampilkan barang di keranjang    |\n");
                printf("| 12. CART PAY          - Beli barang di keranjang         |\n");
                printf("| 13. HISTORY           - Tampilkan history pembelian      |\n");
                printf("| 14. WISHLIST ADD      - Tambah barang ke wishlist        |\n");
                printf("| 15. WISHLIST REMOVE   - Hapus barang dari wishlist       |\n");
                printf("| 16. WISHLIST CLEAR    - Bersihkan wishlist               |\n");
                printf("| 17. WISHLIST SHOW     - Tampilkan wishlist               |\n");
                printf("| 18. HELP              - Tampilkan bantuan                |\n");
                printf("| 19. SAVE              - Simpan konfigurasi               |\n");
                printf("| 20. LOGOUT            - Keluar dari sesi pengguna        |\n");
                printf("+----------------------------------------------------------+\n");

                printf(">>> ");
                STARTINPUTWORD();
                commandStr = WordToString(CurrentWord);

                if (isEqual(CurrentWord, "LOGOUT")) {
                    printf("Berhasil logout. Sampai jumpa, %s!\n", CurrentUser.name);
                    loggedIn = false; // Logout
                    CurrentUser = (User){"", "", 0}; // Reset CurrentUser
                } else if (isEqual(CurrentWord, "WORK")) {
                    Work(&CurrentUser);
                } else if (isEqual(CurrentWord, "PROFILE")) {
                    Profile(&CurrentUser);
                } else if (isEqual(CurrentWord, "TEBAK_ANGKA")) {
                    tebak_angka(&CurrentUser);
                } else if (isEqual(CurrentWord, "WORDL3")) {
                    wordl3_challenge(&CurrentUser);
                } else if (isEqual(CurrentWord, "STORE LIST")) {
                    SList(&listbarang);
                } else if (isEqual(CurrentWord, "STORE REQUEST")) {
                    SRequest(&requestQueue, &listbarang);
                } else if (isEqual(CurrentWord, "STORE SUPPLY")) {
                    SSupply(&requestQueue, &listbarang);
                } else if (isEqual(CurrentWord, "STORE REMOVE")) {
                    SRemove(&listbarang);
                } else if (isEqual(CurrentWord, "SAVE")) {
                    printf("Masukkan nama file untuk menyimpan: ");
                    STARTINPUTWORD();  // Mengambil input dari pengguna
                    Save(WordToString(CurrentWord));  // Menyimpan dengan nama file yang diinputkan
                } else if (isEqual(CurrentWord, "HELP")) {
                    help_main();
                } else if (isEqual(CurrentWord, "CART ADD")) {
                    CartAdd(&CurrentUser, &listbarang);
                } else if (isEqual(CurrentWord, "CART REMOVE")) {
                    CartRemove(&CurrentUser, &listbarang);
                } else if (isEqual(CurrentWord, "CART SHOW")) {
                    CartShow(&CurrentUser, &listbarang);
                } else if (isEqual(CurrentWord, "CART PAY")) {
                    CartPay(&CurrentUser, &listbarang);
                } else if (isEqual(CurrentWord, "HISTORY")) {
                    ShowPurchaseHistory(&CurrentUser.riwayat_pembelian);
                } else if (isEqual(CurrentWord, "WISHLIST ADD")) {
                    wishlistAdd(&CurrentUser.wishlist, &listbarang);
                } else if (isEqual(CurrentWord, "WISHLIST SHOW")) {
                    wishlistShow(CurrentUser.wishlist);
                } else if (isEqual(CurrentWord, "WISHLIST REMOVE")) {
                    wishlistRemove(&CurrentUser.wishlist);
                } else if (isEqual(CurrentWord, "WISHLIST CLEAR")) {
                    wishlistClear(&CurrentUser.wishlist);
                } else {
                    printf("Perintah tidak dikenal. Silakan coba lagi.\n");
                }
            }
        }
    }

    return 0;
}