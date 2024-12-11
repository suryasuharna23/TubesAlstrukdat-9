#include <stdio.h>
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "register.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../Load/load.h"
#include "../Save/save.h"

void PrintAllUsers(ListUser *users) {
    printf("All registered users:\n");
    for (int i = 0; i < users->count; i++) {
        printf("Username: %s, Password: %s, Money: %d\n", users->users[i].name, users->users[i].password, users->users[i].money);
    }
}

void PrintAllBarangs(ListBarang *barangs) {
    printf("All available barangs:\n");
    for (int i = 0; i < barangs->count; i++) {
        printf("Name: %s, Price: %d\n", barangs->items[i].name, barangs->items[i].price);
    }
}

// Definisikan variabel yang hilang
ListBarang listbarang;
ListUser users;

int main() {
    boolean flag = false;
    char loadFilename[100];
    char saveFilename[100];

    // Inisialisasi daftar pengguna
    CreateListUser(&users);
    CreateListBarang(&listbarang);

    // Minta pengguna untuk memasukkan nama file untuk memuat pengguna
    printf("Masukkan nama file untuk memuat pengguna: ");
    scanf("%s", loadFilename);

    // Muat pengguna dari file konfigurasi
    Load(loadFilename);

    // Daftarkan pengguna baru
    RegisterUser(&users, &flag);

    if (flag) {
        printf("Pendaftaran pengguna berhasil dan disimpan.\n");
    } else {
        printf("Pendaftaran pengguna gagal.\n");
    }

    // Print all users and barangs
    PrintAllUsers(&users);
    PrintAllBarangs(&listbarang);

    return 0;
}