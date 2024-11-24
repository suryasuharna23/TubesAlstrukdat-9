#include <stdio.h>
#include <stdlib.h>
#include "load.h"

// Cara compile
// gcc driver_load.c load.c ../../ADT/Mesin/mesinkarakter.c ../../ADT/Mesin/mesinkata.c ../../ADT/Barang/barang.c ../../ADT/User/user.c -o driver

int main() {
    ArrayDinStore store;
    ArrayDinUser userList;
    const char *filename = "tesload.txt";

    store.store = (Barang *)malloc(5 * sizeof(Barang)); 
    store.Neff = 0;
    store.Capacity = 5;

    userList.users = (User *)malloc(5 * sizeof(User)); 
    userList.Neff = 0;
    userList.Capacity = 5;

    STARTWORD((char *)filename);

    if (!EndWord) {
        printf("File '%s' berhasil dibuka. Memulai parsing data...\n", filename);
        
        int nBarang = WordToInt(CurrentWord);
        printf("Jumlah barang: %d\n", nBarang);
        ADVWORD();

        for (int i = 0; i < nBarang; i++) {
            Word harga = GetWord(CurrentWord, 1);
            int price = WordToInt(harga);

            Word nama = GetWord(CurrentWord, 2);
            char *name = WordToString(nama);
            ADVWORD();

            Barang barang = CreateBarang(name, price);
            InsertLast(&store, barang, true);

            free(name);
        }


        Word jumlah_user = GetWord(CurrentWord, 1);
        int nUser = WordToInt(jumlah_user);
        printf("Jumlah pengguna: %d\n", nUser);
        ADVWORD();

        
        for (int i = 0; i < nUser; i++) {
            Word uang = GetWord(CurrentWord, 1);
            int money = WordToInt(uang);

            Word uname = GetWord(CurrentWord, 2);
            char *username = WordToString(uname);

            Word pass = GetWord(CurrentWord, 3);
            char *password = WordToString(pass);
            ADVWORD();

            User user;
            CreateUser(&user, username, password, money);
            InsertUser(&userList, user);


            free(username); 
            free(password); 
        }

        printf("\nData berhasil dimuat dari file '%s'.\n", filename);

        printf("\nDaftar Barang:\n");
        for (int i = 0; i < Length(store); i++) {
            printf("Barang %d:\n", i + 1);
            PrintBarang(&A(store)[i]);
            printf("Harga: %d\n", A(store)[i].price);
        }

        printf("\nDaftar Pengguna:\n");
        PrintAllUsers(userList);


    DeallocateArrayDinStore(&store);
    DeallocateArrayDinUser(&userList);
    }
}