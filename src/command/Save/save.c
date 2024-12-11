#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"

extern ListBarang listbarang;
extern ListUser users;

void Save(char *filename) {
    FILE *file;
    char filepath[256];

    // Construct the full path to the config folder
    StringCopy(filepath, "config/");
    StringConcat(filepath, filename);
    StringConcat(filepath, ".txt");

    file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Error opening file for writing: %s\n", filepath);
        return;
    }

    // Save Barang Data
    fprintf(file, "%d\n", listbarang.count);
    for (int i = 0; i < listbarang.count; i++) {
        fprintf(file, "%d %s\n", listbarang.items[i].price, listbarang.items[i].name);
    }

    // Save User Data
    fprintf(file, "%d\n", users.count);
    for (int i = 0; i < users.count; i++) {
        fprintf(file, "%d %s %s\n", users.users[i].money, users.users[i].name, users.users[i].password);
    }

    fclose(file);
    printf("Data berhasil disimpan ke %s\n", filepath);
}