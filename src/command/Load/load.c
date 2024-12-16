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

    printf("File opened successfully: %s\n", filepath);

    // Read Barang Data
    int num_barang = 0;
    if (fscanf(file, "%d\n", &num_barang) != 1) {
        printf("Failed to read number of Barang.\n");
        fclose(file);
        return false;
    }
    printf("Number of Barang: %d\n", num_barang); // Debug print

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
        printf("Barang %d: %s, %d\n", i + 1, barang.name, barang.price); // Debug print
    }

    // Read User Data
    int num_users = 0;
    if (fscanf(file, "%d\n", &num_users) != 1) {
        printf("Failed to read number of Users.\n");
        fclose(file);
        return false;
    }
    printf("Number of Users: %d\n", num_users); // Debug print

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
        printf("User %d: %s, %s, %d\n", i + 1, user.name, user.password, user.money); // Debug print

        // Read Purchase History
        int num_history;
        if (fscanf(file, "%d\n", &num_history) != 1) {
            printf("Failed to read Purchase History count for User %d.\n", i + 1);
            fclose(file);
            return false;
        }
        printf("Number of Purchase History for User %d: %d\n", i + 1, num_history); // Debug print

        for (int j = 0; j < num_history; j++) {
            Purchase purchase;
            if (fscanf(file, "%d %d\n", &purchase.count, &purchase.totalCost) != 2) {
                printf("Failed to read Purchase %d for User %d.\n", j + 1, i + 1);
                fclose(file);
                return false;
            }
            printf("Purchase History %d for User %d: %d items, total %d\n", j + 1, i + 1, purchase.count, purchase.totalCost); // Debug print

            for (int k = 0; k < purchase.count; k++) {
                if (fscanf(file, "%d %[^\n]\n", &purchase.items[k].quantity, purchase.items[k].name) != 2) {
                    printf("Failed to read Purchase Item %d for Purchase %d of User %d.\n", k + 1, j + 1, i + 1);
                    fclose(file);
                    return false;
                }
                printf("Purchase Item %d for Purchase History %d for User %d: %d %s\n", k + 1, j + 1, i + 1, purchase.items[k].quantity, purchase.items[k].name); // Debug print

                // Find barang manually
                int found = 0;
                for (int l = 0; l < listbarang.count; l++) {
                    if (StringCompare(listbarang.items[l].name, purchase.items[k].name) == 0) {
                        purchase.items[k].total = purchase.items[k].quantity * listbarang.items[l].price;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Failed to find price for item %s.\n", purchase.items[k].name);
                    fclose(file);
                    return false;
                }
            }

            Push(&user.riwayat_pembelian, purchase);
        }

        // Read Wishlist
        int num_wishlist;
        if (fscanf(file, "%d\n", &num_wishlist) != 1) {
            printf("Failed to read Wishlist count for User %d.\n", i + 1);
            fclose(file);
            return false;
        }
        printf("Number of Wishlist items for User %d: %d\n", i + 1, num_wishlist); // Debug print

        for (int j = 0; j < num_wishlist; j++) {
            char wishlist_item[MAX_LEN];
            if (fscanf(file, "%[^\n]\n", wishlist_item) != 1) {
                printf("Failed to read Wishlist Item %d for User %d.\n", j + 1, i + 1);
                fclose(file);
                return false;
            }
            InsVLast(&user.wishlist, wishlist_item);
            printf("Wishlist item %d for User %d: %s\n", j + 1, i + 1, wishlist_item); // Debug print
        }

        users.users[users.count++] = user; // Add user to users
    }

    fclose(file);
    printf("Data successfully loaded from %s\n", filepath);
    return true;
}