#include <stdio.h>
#include <stdbool.h>
#include "ADT/User/user.h"
#include "ADT/Barang/barang.h"
#include "ADT/Mesin/mesinkata.h"
#include "ADT/Mesin/mesinkarakter.h"
#include "ADT/Queue/queue.h"
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
#include "command/Graph/graph.h"
#include "ASCII/ASCII.h"
#include "Loading/Loadingscreen.h"

ListUser users;
ListBarang listbarang;
Queue requestQueue;
User CurrentUser;
Stack purchaseHistory;
List wishlist;

void STARTINPUTWORD();
Word CurrentWord;

int main()
{
    boolean running = true;
    boolean loggedIn = false;
    boolean IsStarted = false;
    int user_id = -1;
    CreateListUser(&users);
    CreateListBarang(&listbarang);
    CreateUser(&CurrentUser);
    CreateQueue(&requestQueue);
    CreateEmptyS(&purchaseHistory);
    CreateEmptyList(&wishlist);

    printf("****************************************\n");
    printf("*      Selamat Datang di PURRMART      *\n");
    printf("****************************************\n");

    char *commandStr;

    while (running)
    {
        if (!IsStarted)
        {
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

            if (isEqual(CurrentWord, "START"))
            {
                displayLoadingDots(3);
                printASCII();
                Load("default");
                IsStarted = true;
            }
            else if (isEqual(CurrentWord, "LOAD"))
            {
                printf("Masukkan nama file konfigurasi: ");
                STARTINPUTWORD();
                if (Load(WordToString(CurrentWord)))
                {
                    printf("Konfigurasi berhasil dimuat.\n");
                    IsStarted = true;
                }
                else
                {
                    printf("Gagal memuat konfigurasi.\n");
                }
            }
            else if (isEqual(CurrentWord, "QUIT"))
            {
                running = false;
                printf("Terima kasih telah menggunakan PURRMART!\n");
            }
            else
            {
                printf("Perintah tidak dikenal: %s\n", commandStr);
            }
        }
        else
        {
            if (!loggedIn)
            {
                printf("\n+----------------------------------------+\n");
                printf("|         MENU LOGIN / REGISTER          |\n");
                printf("+----------------------------------------+\n");
                printf("| 1. LOGIN                               |\n");
                printf("| 2. REGISTER                            |\n");
                printf("| 3. QUIT                                |\n");
                printf("+----------------------------------------+\n");

                printf(">>> ");
                STARTINPUTWORD();
                commandStr = WordToString(CurrentWord);

                if (isEqual(CurrentWord, "LOGIN"))
                {
                    Login(&users, &CurrentUser, &user_id);
                    loggedIn = true;
                }
                else if (isEqual(CurrentWord, "REGISTER"))
                {
                    boolean registrationSuccessful = false;
                    RegisterUser(&users, &registrationSuccessful);
                    if (registrationSuccessful)
                    {
                        loggedIn = true;
                    }
                }

                else if (isEqual(CurrentWord, "QUIT"))
                {
                    running = false;
                    printf("Terima kasih telah menggunakan PURRMART!\n");
                }

                else
                {
                    printf("Perintah tidak dikenal: %s\n", commandStr);
                }
            }
            else if (loggedIn)
            {
                if (CurrentUser.name[0] == '\0')
                {
                    loggedIn = false;
                    continue;
                }
                printf("\n+----------------------------------------------------------+\n");
                printf("|                  MENU UTAMA PURRMART                     |\n");
                printf("+----------------------------------------------------------+\n");
                printf("| 1.  PROFILE           - Tampilkan profile                |\n");
                printf("| 2.  STORE SUPPLY      - Pasok barang ke toko             |\n");
                printf("| 3.  STORE REMOVE      - Hapus barang ke toko             |\n");
                printf("| 4.  STORE LIST        - Tampilkan barang                 |\n");
                printf("| 5.  STORE REQUEST     - Lihat request barang             |\n");
                printf("| 6.  WORK              - Bekerja                          |\n");
                printf("| 7.  WORK CHALLENGE    - Challenges                       |\n");
                printf("| 9.  CART ADD          - Tambah barang ke keranjang       |\n");
                printf("| 10. CART REMOVE       - Hapus barang dari keranjang      |\n");
                printf("| 11. CART SHOW         - Tampilkan barang di keranjang    |\n");
                printf("| 12. CART PAY          - Beli barang di keranjang         |\n");
                printf("| 13. HISTORY           - Tampilkan history pembelian      |\n");
                printf("| 14. WISHLIST ADD      - Tambah barang ke wishlist        |\n");
                printf("| 15. WISHLIST REMOVE   - Hapus barang dari wishlist       |\n");
                printf("| 16. WISHLIST SWAP     - Menukar posisi barang wishlist   |\n");
                printf("| 17. WISHLIST CLEAR    - Bersihkan wishlist               |\n");
                printf("| 18. WISHLIST SHOW     - Tampilkan wishlist               |\n");
                printf("| 19. HELP              - Tampilkan bantuan                |\n");
                printf("| 20. SAVE              - Simpan konfigurasi               |\n");
                printf("| 21. LOGOUT            - Keluar dari sesi pengguna        |\n");
                printf("+----------------------------------------------------------+\n");

                printf(">>> ");
                STARTINPUTWORD();
                commandStr = WordToString(CurrentWord);

                if (isEqual(CurrentWord, "LOGOUT"))
                {
                    printf("Berhasil logout. Sampai jumpa, %s!\n", CurrentUser.name);
                    loggedIn = false;                // Logout
                    CurrentUser = (User){"", "", 0}; // Reset CurrentUser
                }
                else if (isEqual(CurrentWord, "WORK"))
                {
                    Work(&CurrentUser);
                }
                else if (isEqual(CurrentWord, "PROFILE"))
                {
                    Profile(&CurrentUser);
                }
                else if (isEqual(CurrentWord, "WORK CHALLENGE")){
                    printf("Daftar challenge yang tersedia: \n");
                    printf("1. Tebak Angka (biaya main = 200)\n");
                    printf("2. WORDL399 (biaya main = 500)\n");
                    printf(">>> ");
                    STARTINPUTWORD();
                    if (isEqual(CurrentWord, "Tebak Angka"))
                    {
                        tebak_angka(&CurrentUser);
                    }
                    else if (isEqual(CurrentWord, "WORDL399"))
                    {
                        wordl3_challenge(&CurrentUser);
                    }
                }
                else if (isEqual(CurrentWord, "STORE LIST"))
                {
                    SList(&listbarang);
                }
                else if (isEqual(CurrentWord, "STORE REQUEST"))
                {
                    SRequest(&requestQueue, &listbarang);
                }
                else if (isEqual(CurrentWord, "STORE SUPPLY"))
                {
                    SSupply(&requestQueue, &listbarang);
                }
                else if (isEqual(CurrentWord, "STORE REMOVE"))
                {
                    SRemove(&listbarang);
                }
                else if (isEqual(CurrentWord, "SAVE"))
                {
                    printf("Masukkan nama file untuk menyimpan: ");
                    STARTINPUTWORD(); // Mengambil input dari pengguna
                    Save(WordToString(CurrentWord), &listbarang, &users); // Menyimpan dengan nama file yang diinputkan
                }
                else if (isEqual(CurrentWord, "HELP"))
                {
                    help_main();
                }
                else if (isEqual(CurrentWord, "CART ADD"))
                {
                    CartAdd(&CurrentUser, &listbarang);
                }
                else if (isEqual(CurrentWord, "CART REMOVE"))
                {
                    CartRemove(&CurrentUser, &listbarang);
                }
                else if (isEqual(CurrentWord, "CART SHOW"))
                {
                    CartShow(&CurrentUser, &listbarang);
                }
                else if (isEqual(CurrentWord, "CART PAY"))
                {
                    CartPay(&CurrentUser, &listbarang);
                }
                else if (isEqual(CurrentWord, "HISTORY"))
                {
                    ShowPurchaseHistory(&CurrentUser.riwayat_pembelian);
                }
                else if (isEqual(CurrentWord, "WISHLIST ADD"))
                {
                    wishlistAdd(&CurrentUser.wishlist, &listbarang);
                }
                else if (isEqual(CurrentWord, "WISHLIST SHOW"))
                {
                    wishlistShow(CurrentUser.wishlist);
                }
                else if (isEqual(CurrentWord, "WISHLIST SWAP"))
                {
                    wishlistSwap(&CurrentUser.wishlist);
                }
                else if (isEqual(CurrentWord, "WISHLIST REMOVE"))
                {
                    wishlistRemove(&CurrentUser.wishlist);
                }
                else if (isEqual(CurrentWord, "WISHLIST CLEAR"))
                {
                    wishlistClear(&CurrentUser.wishlist);
                }
                // else if (isEqual(CurrentWord, "OPTIMASIRUTE"))
                // {
                //     prosesRute();
                // }
                else
                {
                    printf("Perintah tidak dikenal. Silakan coba lagi.\n");
                }
                users.users[user_id] = CurrentUser;
            }
        }
    }

    return 0;
}