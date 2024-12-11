#include "load.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../command/Help/help.h"

ListBarang listbarang;
ListUser users;

void ConcatString(char *str1, char *str2, char *result) {
    while (*str1) {
        *result++ = *str1++;
    }
    while (*str2) {
        *result++ = *str2++;
    }
    *result = '\0';
}

boolean Load(char* filename) {
    char file_path[MAX_LEN], default_path[MAX_LEN] = "config/default.txt";
    FILE *file;

    if (filename == NULL) {
        filename = default_path;
    } else {
        ConcatString("config/", filename, file_path);
        filename = file_path;
    }

    printf("Trying to open file: %s\n", filename); // Debug print

    while ((file = fopen(filename, "r")) == NULL) {
        printf("Save file tidak ditemukan. \nSilakan masukkan nama file yang benar atau ketik 'BACK' untuk kembali: ");
        while (1) {
            STARTINPUTWORD();
            if (isEqual(CurrentWord, "BACK")) {
                help_welcome();
                return false;
            }
            filename = WordToString(CurrentWord);
            ConcatString("config/", filename, file_path);
            printf("Trying to open file: %s\n", file_path); // Debug print
            file = fopen(file_path, "r");
            if (file != NULL) {
                break;
            }
            printf("Save file tidak ditemukan. \nSilakan masukkan nama file yang benar atau ketik 'BACK' untuk kembali: ");
        }
    }

    // Read Barang Data
    int num_barang = 0;
    if (fscanf(file, "%d\n", &num_barang) != 1) {
        printf("Failed to read number of Barang.\n");
        fclose(file);
        return false;
    }
    printf("Number of Barang: %d\n", num_barang); // Debug print

    for (int i = 0; i < num_barang; i++) {
        int price;
        char name[MAX_LEN];
        if (fscanf(file, "%d %[^\n]\n", &price, name) != 2) {
            printf("Failed to read Barang %d.\n", i + 1);
            fclose(file);
            return false;
        }
        printf("Read Barang: %s, %d\n", name, price); // Debug print
        AddBarang(&listbarang, name, price); // Tambahkan ke listStore
    }

    // Read User Data
    int num_user = 0;
    if (fscanf(file, "%d\n", &num_user) != 1) {
        printf("Failed to read number of Users.\n");
        fclose(file);
        return false;
    }
    printf("Number of Users: %d\n", num_user); // Debug print

    for (int i = 0; i < num_user; i++) {
        int money;
        char username[MAX_LEN], password[MAX_LEN];
        if (fscanf(file, "%d %s %s\n", &money, username, password) != 3) {
            printf("Failed to read User %d.\n", i + 1);
            fclose(file);
            return false;
        }
        printf("Read User: %d, %s, %s\n", money, username, password); // Debug print
        AddUser(&users, username, password, money);
    }

    fclose(file);
    printf("Konfigurasi berhasil dimuat dari %s\n", filename);
    help_login();
    return true;
}