#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"

void Save(char *filename, ListBarang *listbarang, ListUser *users)
{
    FILE *file;
    char filepath[256];

    // Use StringCopy and StringConcat for filepath
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
    fprintf(file, "%d\n", users->count);
    for (int i = 0; i < users->count; i++)
    {
        fprintf(stdout, "%d %s %s\n", users->users[i].money, users->users[i].name, users->users[i].password);
        fprintf(file, "%d %s %s\n", users->users[i].money, users->users[i].name, users->users[i].password);

        // Save Purchase History
        Stack *history = &users->users[i].riwayat_pembelian;
        int history_count = history->top + 1;
        if (history_count <= 0)
        {
            fprintf(file, "0\n"); // No purchases
        }
        else
        {
            fprintf(file, "%d\n", history_count);
            for (int j = 0; j < history_count; j++)
            {
                Purchase purchase = history->purchases[j];
                fprintf(file, "%d %d\n", purchase.count, purchase.totalCost);

                for (int k = 0; k < purchase.count; k++)
                {
                    int price = purchase.items[k].total / purchase.items[k].quantity;
                    fprintf(file, "%d %d %s\n",
                            price,
                            purchase.items[k].quantity,
                            purchase.items[k].name);
                }
            }
        }

        // Save Wishlist
        List *wishlist = &users->users[i].wishlist;
        int wishlist_count = 0;
        address_list P = First(*wishlist);
        while (P != Nol)
        {
            wishlist_count++;
            P = Next(P);
        }
        fprintf(file, "%d\n", wishlist_count);

        if (wishlist_count > 0)
        {
            P = First(*wishlist);
            while (P != Nol)
            {
                fprintf(file, "%s\n", Info(P));
                P = Next(P);
            }
        }
    }

    fclose(file);
    printf("Data berhasil disimpan ke %s\n", filepath);
}