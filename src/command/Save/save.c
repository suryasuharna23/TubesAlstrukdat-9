#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"

extern ListBarang listbarang;
extern ListUser users;

void Save(char *filename)
{
    FILE *file;
    char filepath[256];

    StringCopy(filepath, "config/");
    StringConcat(filepath, filename);
    StringConcat(filepath, ".txt");

    file = fopen(filepath, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing: %s\n", filepath);
        return;
    }

    // Save Barang Data
    fprintf(file, "%d\n", listbarang.count);
    for (int i = 0; i < listbarang.count; i++)
    {
        fprintf(file, "%d %s\n", listbarang.items[i].price, listbarang.items[i].name);
    }

    // Save User Data
    fprintf(file, "%d\n", users.count);
    for (int i = 0; i < users.count; i++)
    {
        // Basic user info
        fprintf(file, "%d %s %s\n", users.users[i].money, users.users[i].name, users.users[i].password);

        // Purchase History
        Stack *history = &users.users[i].riwayat_pembelian;
        int history_count = history->top + 1;
        fprintf(file, "%d\n", history_count);

        // Save each purchase
        for (int j = history_count - 1; j >= 0; j--)
        {
            Purchase purchase = history->purchases[j];
            fprintf(file, "%d %d\n", purchase.count, purchase.totalCost);

            for (int k = 0; k < purchase.count; k++)
            {
                int price_per_item = purchase.items[k].total / purchase.items[k].quantity;
                fprintf(file, "%d %d %s\n",
                        price_per_item,
                        purchase.items[k].quantity,
                        purchase.items[k].name);
            }
        }

        // Save Wishlist
        List *wishlist = &users.users[i].wishlist;
        int wishlist_count = 0;
        address_list P = First(*wishlist);
        while (P != Nol)
        {
            wishlist_count++;
            P = Next(P);
        }
        fprintf(file, "%d\n", wishlist_count);

        P = First(*wishlist);
        while (P != Nol)
        {
            fprintf(file, "%s\n", Info(P));
            P = Next(P);
        }
    }

    fclose(file);
    printf("Data berhasil disimpan ke %s\n", filepath);
}