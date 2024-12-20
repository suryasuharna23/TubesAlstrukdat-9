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

void ConcatString(const char *str1, const char *str2, char *result) {
    while (*str1) {
        *result++ = *str1++;
    }
    while (*str2) {
        *result++ = *str2++;
    }
    *result = '\0';
}

boolean Load(char *filename) {
    FILE *file;
    char filepath[256];

    // Construct the full path to the config folder
    char temp[256];
    ConcatString("config/", filename, temp);
    ConcatString(temp, ".txt", filepath);

    file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error opening file for reading: %s\n", filepath);
        return false;
    }


    // Read Barang Data
    int num_barang = 0;
    if (fscanf(file, "%d\n", &num_barang) != 1) {
        printf("Failed to read number of Barang.\n");
        fclose(file);
        return false;
    }

    listbarang.count = 0; // Initialize listbarang
    for (int i = 0; i < num_barang; i++) {
        int price;
        char name[MAX_LEN];
        if (fscanf(file, "%d %[^\n]\n", &price, name) != 2) {
            printf("Failed to read Barang %d.\n", i + 1);
            fclose(file);
            return false;
        }
        Barang barang;
        barang.price = price;
        int j = 0;
        while (name[j] != '\0') {
            barang.name[j] = name[j];
            j++;
        }
        barang.name[j] = '\0';
        listbarang.items[listbarang.count++] = barang; // Add barang to listbarang
    }

    // Read User Data
    int num_users = 0;
    if (fscanf(file, "%d\n", &num_users) != 1) {
        printf("Failed to read number of Users.\n");
        fclose(file);
        return false;
    }

    users.count = 0; // Initialize users
    for (int i = 0; i < num_users; i++) {
        int money;
        char name[MAX_LEN];
        char password[MAX_LEN];
        if (fscanf(file, "%d %s %s\n", &money, name, password) != 3) {
            printf("Failed to read User %d.\n", i + 1);
            fclose(file);
            return false;
        }

        User user;
        int j = 0;
        while (name[j] != '\0') {
            user.name[j] = name[j];
            j++;
        }
        user.name[j] = '\0';
        j = 0;
        while (password[j] != '\0') {
            user.password[j] = password[j];
            j++;
        }
        user.password[j] = '\0';
        user.money = money;

        CreateEmptyS(&user.riwayat_pembelian);
        CreateEmptyList(&user.wishlist);

        // Read Purchase History
        int num_history;
        if (fscanf(file, "%d\n", &num_history) != 1)
        {
            printf("Failed to read Purchase History count.\n");
            fclose(file);
            return false;
        }

        for (int j = 0; j < num_history; j++)
        {
            Purchase purchase;
            if (fscanf(file, "%d %d\n", &purchase.count, &purchase.totalCost) != 2)
            {
                printf("Failed to read purchase header.\n");
                fclose(file);
                return false;
            }

            for (int k = 0; k < purchase.count; k++)
            {
                int price;
                if (fscanf(file, "%d %d %[^\n]\n",
                    &price,
                    &purchase.items[k].quantity,
                    purchase.items[k].name) != 3)
                {
                    printf("Failed to read purchase item.\n");
                    fclose(file);
                    return false;
                }
                purchase.items[k].total = price;
            }
            Push(&user.riwayat_pembelian, purchase);
        }

        // Read Wishlist
        int num_wishlist;
        if (fscanf(file, "%d\n", &num_wishlist) != 1)
        {
            printf("Failed to read Wishlist count.\n");
            fclose(file);
            return false;
        }

        CreateEmptyList(&user.wishlist);
        for (int j = 0; j < num_wishlist; j++)
        {
            char wishlist_item[MAX_LEN];
            if (fscanf(file, "%[^\n]\n", wishlist_item) != 1)
            {
                printf("Failed to read wishlist item.\n");
                fclose(file);
                return false;
            }
            InsVLast(&user.wishlist, wishlist_item);
        }
    
        InsertUser(&users,user);
    }

    fclose(file);
    return true;
}