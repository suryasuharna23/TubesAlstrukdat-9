#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "save.h"

void save(const char *filename, ArrayDinUser *userArray, listBarang *barangList)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    // nyimpen info pengguna
    fprintf(file, "Users:\n");
    for (int i = 0; i < userArray->Neff; i++)
    {
        fprintf(file, "Username: %s\n", userArray->users[i].name);
        fprintf(file, "Password: %s\n", userArray->users[i].password);
        fprintf(file, "Uang: %d\n", userArray->users[i].money);
    }

    // nyimpen info barang
    fprintf(file, "Barang:\n");
    for (int i = 0; i < barangList->count; i++)
    {
        fprintf(file, "Nama: %s\n", barangList->items[i].name);
        fprintf(file, "Harga: %d\n", barangList->items[i].price);
    }

    fclose(file);
    printf("Save file berhasil disimpan.\n");
}