#include "load.h"
#include <stdlib.h>
#include <stdio.h>

void LOAD(const char *filename, ArrayDinStore *store, ArrayDinUser *userList) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File konfigurasi tidak ditemukan: %s\n", filename);
        return;
    }

    // Membaca jumlah barang
    int nBarang;
    fscanf(file, "%d\n", &nBarang);
    for (int i = 0; i < nBarang; i++) {
        int price;
        char name[MAX_LEN];
        fscanf(file, "%d %[^\n]s\n", &price, name);

        Barang barang = CreateBarang(name, price);
        InsertLast(store, barang, true);
    }

    // Membaca jumlah pengguna
    int nUser;
    fscanf(file, "%d\n", &nUser);
    for (int i = 0; i < nUser; i++) {
        int money;
        char username[MAX_LEN], password[MAX_LEN];
        fscanf(file, "%d %s %s\n", &money, username, password);

        User user;
        CreateUser(&user, username, password, money);
        InsertUser(userList, user);
    }

    fclose(file);
    printf("Data berhasil dimuat dari %s\n", filename);
}