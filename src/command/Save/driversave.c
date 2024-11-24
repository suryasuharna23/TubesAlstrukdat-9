#include <stdio.h>
#include <stdlib.h>
#include "save.h"

//cara compile:
// gcc driver_save.c save.c ../../ADT/Mesin/mesinkarakter.c ../../ADT/Mesin/mesinkata.c ../../ADT/Barang/barang.c ../../ADT/User/user.c -o save

int main() {
    ArrayDinUser  arr_user;
    CreateArrayDinUser (&arr_user, MAX_USER_COUNT);

    listBarang list_barang;
    InitializeListBarang(&list_barang); 

    User user1;
    CreateUser (&user1, "Surya", "pazzword", 50);
    InsertUser (&arr_user, user1);

    User user2;
    CreateUser (&user2, "Sada", "alstrukdead", 150);
    InsertUser (&arr_user, user2);

    Barang barang1 = CreateBarang("meja", 5);
    list_barang.items[list_barang.count++] = barang1; 
    Barang barang2 = CreateBarang("kursi", 15);
    list_barang.items[list_barang.count++] = barang2; 

    Word filenameWord;
    printf("Masukkan nama file untuk menyimpan: ");
    STARTINPUTWORD();
    filenameWord = CurrentWord; 

    save(WordToString(filenameWord), &arr_user, &list_barang);

    DeallocateArrayDinUser (&arr_user);

    return 0;
}