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
#include "command/Clear/clear.h"
#include "ASCII/ascii.h"
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

    clear();
    char *commandStr;
    while (running)
    {
        if (!IsStarted)
        {
            ascii_welcome();
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
                Load("default"); 
                IsStarted = true;  
                clear(); 
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
                clear(); 
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
            clear(); 

        }
        else
        {
            
            if (!loggedIn)
            {
                ascii_sesi();
                printf("\nSelamat karena kamu sudah berhasil memulai sesi game.\n");
                printf("Sekarang silakan untuk memasuki game menggunakan suatu akun pengguna :)\n");
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
                    clear(); 
                }
                else if (isEqual(CurrentWord, "REGISTER"))
                {
                    boolean registrationSuccessful = false;
                    RegisterUser(&users, &registrationSuccessful);
                    if (registrationSuccessful)
                    {
                        loggedIn = true;
                    }
                    clear(); 
                }

                else if (isEqual(CurrentWord, "QUIT"))
                {
                    running = false;
                    printf("Terima kasih telah menggunakan PURRMART!\n");
                    clear();
                }

                else
                {
                    printf("Perintah tidak dikenal: %s\n", commandStr);
                    clear();
                }
                 

            }
            else if (loggedIn)
            {
                if (CurrentUser.name[0] == '\0')
                {
                    loggedIn = false;
                    continue;
                }
                ascii_mainmenu();
                printf("\nSelamat datang di PURRMART, pusat lengkap untuk semua kebutuhan Anda!\n");
                printf("Bayangkan sebuah tempat di mana apa pun yang Anda cari ada dalam satu genggaman, cepat, dan terpercaya.\n");
                printf("Jelajahi koleksi terbaik kami dan temukan produk yang dirancang untuk memenuhi kebutuhan Anda.");
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
                printf("| 19. OPTIMASIRUTE      - Analisis rute paling optimal     |\n");
                printf("| 20. HELP              - Tampilkan bantuan                |\n");
                printf("| 21. SAVE              - Simpan konfigurasi               |\n");
                printf("| 22. LOGOUT            - Keluar dari sesi pengguna        |\n");
                printf("+----------------------------------------------------------+\n");

                printf(">>> ");
                STARTINPUTWORD();
                commandStr = WordToString(CurrentWord);
                clear();
                if (isEqual(CurrentWord, "LOGOUT"))
                {
                    printf("Berhasil logout. Sampai jumpa, %s!\n", CurrentUser.name);
                    loggedIn = false;                // Logout
                    CurrentUser = (User){"", "", 0}; // Reset CurrentUser
                    clear();
                }
                else if (isEqual(CurrentWord, "WORK"))
                {
                    ascii_work();
                    Work(&CurrentUser);
                    clear();
                }
                else if (isEqual(CurrentWord, "PROFILE"))
                {
                    ascii_profile();
                    Profile(&CurrentUser);
                    clear();
                }
                else if (isEqual(CurrentWord, "WORK CHALLENGE")){
                    ascii_work_challenge();
                    printf("Daftar challenge yang tersedia: \n");
                    printf("1. Tebak Angka (biaya main = 200)\n");
                    printf("2. WORDL399 (biaya main = 500)\n");
                    printf(">>> ");
                    STARTINPUTWORD();
                    if (isEqual(CurrentWord, "Tebak Angka"))
                    {
                        clear();
                        ascii_tebak_angka();
                        tebak_angka(&CurrentUser);
                        clear();
                    }
                    else if (isEqual(CurrentWord, "WORDL399"))
                    {
                        clear();
                        ascii_wordl3();
                        wordl3_challenge(&CurrentUser);
                        clear();
                    }
                }
                else if (isEqual(CurrentWord, "STORE LIST"))
                {
                    ascii_slist();
                    SList(&listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "STORE REQUEST"))
                {
                    ascii_srequest();
                    SRequest(&requestQueue, &listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "STORE SUPPLY"))
                {
                    ascii_ssupply();
                    SSupply(&requestQueue, &listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "STORE REMOVE"))
                {
                    ascii_sremove();
                    SRemove(&listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "SAVE"))
                {
                    ascii_save();
                    printf("Masukkan nama file untuk menyimpan: ");
                    STARTINPUTWORD();                // Mengambil input dari pengguna
                    Save(WordToString(CurrentWord), &listbarang, &users); // Menyimpan dengan nama file yang diinputkan
                    clear();
                }
                else if (isEqual(CurrentWord, "HELP"))
                {
                    ascii_help();
                    help_main();
                    clear();
                }
                else if (isEqual(CurrentWord, "CART ADD"))
                {
                    ascii_cart_add();
                    CartAdd(&CurrentUser, &listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "CART REMOVE"))
                {
                    ascii_cart_remove();
                    CartRemove(&CurrentUser, &listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "CART SHOW"))
                {
                    ascii_cart_show();
                    CartShow(&CurrentUser, &listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "CART PAY"))
                {
                    ascii_cart_pay();
                    CartPay(&CurrentUser, &listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "HISTORY"))
                {
                    ascii_history();
                    ShowPurchaseHistory(&CurrentUser.riwayat_pembelian);
                    clear();
                }
                else if (isEqual(CurrentWord, "WISHLIST ADD"))
                {
                    ascii_wishlist_add();
                    wishlistAdd(&CurrentUser.wishlist, &listbarang);
                    clear();
                }
                else if (isEqual(CurrentWord, "WISHLIST SHOW"))
                {
                    ascii_wishlist_show();
                    wishlistShow(CurrentUser.wishlist);
                    clear();
                }
                else if (isEqual(CurrentWord, "WISHLIST SWAP"))
                {
                    ascii_wishlist_swap();
                    wishlistSwap(&CurrentUser.wishlist);
                    clear();
                }
                else if (isEqual(CurrentWord, "WISHLIST REMOVE"))
                {
                    ascii_wishlist_remove();
                    wishlistRemove(&CurrentUser.wishlist);
                    clear();
                }
                else if (isEqual(CurrentWord, "WISHLIST CLEAR"))
                {
                    ascii_wishlist_clear();
                    wishlistClear(&CurrentUser.wishlist);
                    clear();
                }
                else if (isEqual(CurrentWord, "OPTIMASIRUTE"))
                {
                    ascii_optimasirute();
                    mulaiTSP();
                    clear();
                }
                else
                {
                    printf("Perintah tidak dikenal. Silakan coba lagi.\n");
                    while(1){
                        printf("Ketik 'OK' untuk kembali ke menu utama: ");
                        printf("\n>>> ");
                        STARTINPUTWORD();
                        if (isEqual(CurrentWord, "OK")){
                            break;
                        } else {
                            printf("Input tidak valid.\n");
                        }
                    }
                    clear();
                }
                users.users[user_id] = CurrentUser;
            }
        }
    }

    return 0;
}