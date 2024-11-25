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
#include "command/Logout/logout.h"
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
    boolean EarlyQuit = false; //kalau belom start/load
    boolean isShopOpen = false; //kalau udah start/load
    boolean startSession = false; //kalau udah start
    boolean loggedIn = false; //kalau udah login
    boolean isRegistered = false; //kalau udah register

    ArrayDinStore arraydinStore;
    ArrayDinUser arraydinUser;
    listBarang listbarang;
    ListUser listuser;
    char currentUser[MAX_LEN] = {0};
    Queue req;
    Word fileword;

    // pembuatan store
    arraydinStore.store = (Barang *)malloc(5 * sizeof(Barang));
    arraydinStore.Neff = 0;
    arraydinStore.Capacity = 5;

    // pembuatan list user
    CreateArrayDinUser(&arraydinUser, 5);
    listuser.count = 0;

    printf("Input Menu (START/LOAD/QUIT/HELP):\n");
    while (true){
        printf(">> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "QUIT")){
            Quit(&isShopOpen);
            break;
        }

        else if(isEqual(CurrentWord, "START")){
            isShopOpen = true;
            startSession = true;
            boolean isRegister = false;

            while(startSession){

                //printf("Selamat datang di REGISTER!\n");
                //registerUser(&listuser, &isRegister);

                
                while (!isRegister){
                    printf("\n");
                    help_main();

                    STARTINPUTWORD();
                    if (isEqual(CurrentWord, "WORK"))
                    {

                    }

                    else if (isEqual(CurrentWord, "WORK CHALLENGE"))
                    {
                        printf("Daftar challenge yang tersedia: \n");
                        printf("1. Tebak Angka (biaya main=200)\n");
                        printf("2. W0RDL399 (biaya main=500)\n");
                        printf("\n");
                        printf("Kamu mau main challenge nomor berapa? ");
                        STARTINPUTWORD();
                        if (isEqual(CurrentWord, "1"))
                        {
                            // kurangin 200 dari sallary
                            int poin = tebak_angka();
                            // tambahin poin ke sallary
                        }
                        else if (isEqual(CurrentWord, "wordl3"))
                        {
                            // kurangin 500 dari sallary
                            wordl3_challenge();
                            // tambahin poin ke sallary
                        }
                        else
                        {
                            printf("Oitt, gaada dipilihan tuh. Masukin pilihan lain!\n");
                        }
                    }

                    else if (isEqual(CurrentWord, "LIST"))
                    {
                        printf("sebelum list\n");

                        LOAD(WordToString(fileword), &arraydinStore, &arraydinUser);
                        SList(&arraydinStore);
                        printf("berhasil\n");
                    }

                    else if (isEqual(CurrentWord, "REQUEST"))
                    {
                        SRequest(&arraydinStore, &req);
                    }

                    else if (isEqual(CurrentWord, "SUPPLY"))
                    {
                        SSupply(&arraydinStore, &req);
                    }

                    else if (isEqual(CurrentWord, "REMOVE"))
                    {
                        SRemove(&arraydinStore);
                    }

                    else if (isEqual(CurrentWord, "LOGOUT"))
                    {
                        logout(currentUser);
                        loggedIn = false;
                        isRegistered = false;
                        startSession = false; 
                        printf("Input Menu (REGISTER/LOGIN/QUIT/HELP):\n");
                        break;
                    }

                    else if (isEqual(CurrentWord, "QUIT"))
                    {
                        isRegister = false;
                        startSession = false;
                        Quit(&isShopOpen);
                    }

                    else if (isEqual(CurrentWord, "SAVE"))
                    {
                        printf("Masukkan nama file untuk menyimpan: ");
                        STARTINPUTWORD();
                        fileword = CurrentWord;

                        save(WordToString(fileword), &arraydinUser, &listbarang);

                        DeallocateArrayDinUser(&arraydinUser);
                    }
                }
            

            }

        }

        else if (isEqual(CurrentWord, "LOAD")){
            printf("Masukkan nama file: ");
            STARTINPUTWORD();
            fileword = GetWord(CurrentWord, 1);

            LOAD(WordToString(fileword), &arraydinStore, &arraydinUser);
            // boolean isRegistered = false;
            boolean isRegister = false;

            printf("Input Menu (REGISTER/LOGIN):\n");
            printf(">> ");
            STARTINPUTWORD();

            if (isEqual(CurrentWord, "REGISTER")){
                registerUser(&listuser, &isRegister);
            }

            else if (isRegister || isEqual(CurrentWord, "LOGIN")){
                Login(&listuser, currentUser);
                loggedIn = (currentUser[0] != '\0');

                while (loggedIn){
                    help_main();

                    STARTINPUTWORD();
                    if (isEqual(CurrentWord, "WORK")){

                    }

                    else if (isEqual(CurrentWord, "WORK CHALLENGE"))
                    {
                        printf("Daftar challenge yang tersedia: \n");
                        printf("1. Tebak Angka (biaya main=200)\n");
                        printf("2. W0RDL399 (biaya main=500)\n");
                        printf("\n");
                        printf("Kamu mau main challenge nomor berapa? ");
                        STARTINPUTWORD();
                        if (isEqual(CurrentWord, "1"))
                        {
                            // kurangin 200 dari sallary
                            int poin = tebak_angka();
                            // tambahin poin ke sallary
                        }
                        else if (isEqual(CurrentWord, "2"))
                        {
                            // kurangin 500 dari sallary
                            int poin = wordl3_challenge();
                            // tambahin poin ke sallary
                        }
                        else
                        {
                            printf("Oitt, gaada dipilihan tuh. Masukin pilihan lain!\n");
                        }
                    }

                    else if (isEqual(CurrentWord, "LIST"))
                    {
                        printf("sebelum list\n");

                        LOAD(WordToString(fileword), &arraydinStore, &arraydinUser);
                        SList(&arraydinStore);
                        printf("berhasil\n");
                    }

                    else if (isEqual(CurrentWord, "REQUEST"))
                    {
                        SRequest(&arraydinStore, &req);
                    }

                    else if (isEqual(CurrentWord, "SUPPLY"))
                    {
                        SSupply(&arraydinStore, &req);
                    }

                    else if (isEqual(CurrentWord, "REMOVE"))
                    {
                        SRemove(&arraydinStore);
                    }

                    else if (isEqual(CurrentWord, "LOGOUT"))
                    {
                        logout(currentUser);
                        loggedIn = false;
                        isRegister = false; 
                        startSession = false;
                        printf("Input Menu (REGISTER/LOGIN/QUIT):\n");
                        break;
                    }

                    else if (isEqual(CurrentWord, "QUIT"))
                    {
                        loggedIn = false;
                        isRegistered = false;
                        Quit(&isShopOpen);
                    }

                    else if (isEqual(CurrentWord, "SAVE"))
                    {
                        printf("Masukkan nama file untuk menyimpan: ");
                        STARTINPUTWORD();
                        fileword = CurrentWord;

                        save(WordToString(fileword), &arraydinUser, &listbarang);

                        DeallocateArrayDinUser(&arraydinUser);
                    }
                }


            }

            
        }
        else if (isEqual(CurrentWord, "HELP")){
            help_welcome();
        }
    }


    return 0;
}