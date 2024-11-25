#include <stdio.h>
#include <stdlib.h>
#include "Boolean/boolean.h"
#include "ADT/Mesin/mesinkata.h"
#include "ADT/Mesin/mesinkarakter.h"
#include "ADT/User/user.h"
#include "ADT/Barang/barang.h"
#include "ADT/Queue/queue.h"
#include "command/Help/help.h"
#include "command/Load/load.h"
#include "command/Login/login.h"
#include "command/Register/register.h"
#include "command/Work/work.h"
#include "command/Store/store.h"
#include "command/Tebak_Angka/tebak_angka.h"
#include "command/WORDL3/wordl3.h"
#include "command/Random_Number/random_number.h"    
#include "command/Score/score.h"
#include "command/Quit/quit.h"
#include "command/Save/save.h"
#include "command/Score/score.h"
#include "command/Store/store.h"
#include "ASCII/ASCII.h"



int main(){

    boolean EarlyQuit = false;
    boolean isShopOpen = false;
    boolean startSession = false;
    boolean loggedIn = false;

    ArrayDinStore listStore;
    ArrayDinUser userList;
    listBarang listbarang;
    Queue req;
    Word fileword;

    // pembuatan store
    listStore.store = (Barang *)malloc(5 * sizeof(Barang));
    listStore.Neff = 0;
    listStore.Capacity = 5;

    CreateArrayDinUser(&userList, 5);

    //printASCII();
    printf("Input Menu (START/HELP/LOAD):\n");

    while(true){
        printf(">> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "HELP")){
            help_welcome();
        }

        if (isEqual(CurrentWord,"START")){
            printf("Valid\n");
            startSession = true;
            while (startSession){
                printf("Input Menu (REGISTER/LOGIN/QUIT/HELP):\n");
                printf(">> ");
                STARTINPUTWORD();
                if (isEqual(CurrentWord, "REGISTER")){

                }
                else if (isEqual(CurrentWord, "LOGIN")){
                    loggedIn = true;
                    while (loggedIn){
                        printf("Input Menu (Ketik HELP untuk melihat seluruh menu):\n");
                        printf(">> ");
                        STARTINPUTWORD();
                        if (isEqual(CurrentWord, "WORK")){

                        }
                        else if (isEqual(CurrentWord, "WORK CHALLENGE")){
                            printf("Daftar challenge yang tersedia: \n");
                            printf("1. Tebak Angka (biaya main=200)\n");
                            printf("2. W0RDL399 (biaya main=500)\n");
                            printf("\n");
                            printf("Kamu mau main challenge nomor berapa? ");
                            STARTINPUTWORD();
                            if (isEqual(CurrentWord, "1")){
                                // kurangin 200 dari sallary
                                int poin = tebak_angka();
                                // tambahin poin ke sallary
                            } else if (isEqual(CurrentWord, "2")){
                                // kurangin 500 dari sallary
                                int poin = wordl3_challenge();
                                // tambahin poin ke sallary
                            } else {
                                printf("Oitt, gaada dipilihan tuh. Masukin pilihan lain!\n");
                            }
                        }
                        else if (isEqual(CurrentWord, "LIST")){
                            printf("sebelum list\n");

                            LOAD(WordToString(fileword), &listStore, &userList);
                            SList(&listStore);
                            printf("berhasil\n");
                        }
                        else if (isEqual(CurrentWord, "REQUEST")){
                            SRequest(&listStore, &req);
                        }
                        else if (isEqual(CurrentWord, "SUPPLY")){
                            SSupply(&listStore, &req);
                        }
                        else if (isEqual(CurrentWord, "REMOVE")){
                            SRemove(&listStore);
                        }
                        else if (isEqual(CurrentWord, "LOGOUT")){
                            printf("Input Menu (REGISTER/LOGIN/QUIT):\n");
                            startSession = false;
                            loggedIn = false;
                        }
                        else if (isEqual(CurrentWord, "QUIT")){
                            EarlyQuit = true;
                            Quit(&isShopOpen);
                            break;
                        }
                        else if (isEqual(CurrentWord, "SAVE")){
                            printf("Masukkan nama file untuk menyimpan: ");
                            STARTINPUTWORD();
                            fileword = CurrentWord;

                            save(WordToString(fileword), &userList, &listbarang);

                            DeallocateArrayDinUser(&userList);
                        }
                        else if (isEqual(CurrentWord, "HELP")){
                            help_main();
                        }
                        else {
                            printf("Hayo pilihannya ada apa aja hayo!\n");
                        }
                    }
                }
                else if (isEqual(CurrentWord, "QUIT"))
                {
                    EarlyQuit = true;
                    Quit(&isShopOpen);
                    break;
                }
                else if (isEqual(CurrentWord, "HELP")){
                    help_login();
                }
            }
        }

        else if (isEqual(CurrentWord,"LOAD")){

            printf("Masukkan nama file: ");
            STARTINPUTWORD();
            fileword = GetWord(CurrentWord, 1);
            char *filename = WordToString(fileword);

            LOAD(filename, &listStore, &userList);

            if (listStore.Neff > 0 || userList.Neff > 0)
            {
                printf("\nBerhasil memuat file %s\n", filename);

                free(listStore.store);
                free(userList.users);
            }
            else
            {
                printf("Gagal memuat file %s\n", filename);
            }
            free(filename);
        }
        
        else if(isEqual(CurrentWord, "QUIT")){
            EarlyQuit = true;
            Quit(&isShopOpen);
            break;
        }

        else {
            printf("Input tidak valid, masukkan input lain.\n");
        }
    }
    return 0;
}


