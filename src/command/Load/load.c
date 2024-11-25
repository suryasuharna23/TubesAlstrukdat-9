#include "load.h"
#include <stdlib.h>
#include <stdio.h>

void LOAD(const char *filename, ArrayDinStore *store, ArrayDinUser *userList)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File konfigurasi tidak ditemukan: %s\n", filename);
        return;
    }

    // Initialize arrays with proper size
    store->store = (Barang *)malloc(100 * sizeof(Barang)); // Or appropriate size
    store->Neff = 0;
    store->Capacity = 100;

    userList->users = (User *)malloc(100 * sizeof(User));
    userList->Neff = 0;
    userList->Capacity = 100;

    // Read number of items
    int nBarang;
    if (fscanf(file, "%d\n", &nBarang) != 1 || nBarang < 0 || nBarang > 100)
    {
        printf("Error: Jumlah barang tidak valid\n");
        fclose(file);
        return;
    }

    // Read items with better format handling
    for (int i = 0; i < nBarang; i++)
    {
        int price;
        char name[MAX_LEN];
        if (fscanf(file, "%d %[^\n]", &price, name) != 2)
        {
            printf("Error: Format barang tidak valid\n");
            fclose(file);
            return;
        }
        getc(file); // consume newline

        Barang barang = CreateBarang(name, price);
        InsertLast(store, barang, true);
    }

    // Read users with similar checks
    int nUser;
    if (fscanf(file, "%d\n", &nUser) != 1 || nUser < 0 || nUser > 100)
    {
        printf("Error: Jumlah pengguna tidak valid\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < nUser; i++)
    {
        int money;
        char username[MAX_LEN], password[MAX_LEN];
        if (fscanf(file, "%d %s %s", &money, username, password) != 3)
        {
            printf("Error: Format pengguna tidak valid\n");
            fclose(file);
            return;
        }
        getc(file); // consume newline

        User user;
        CreateUser(&user, username, password, money);
        InsertUser(userList, user);
    }

    fclose(file);
    printf("\nData berhasil dimuat dari %s\n", filename);
}

void PrintLoadedData(ArrayDinStore *store, ArrayDinUser *userList)
{
    if (store == NULL || userList == NULL)
    {
        printf("Error: Invalid data structures\n");
        return;
    }

    // Print store contents
    printf("\nDaftar Barang (%d item):\n", store->Neff);
    if (store->Neff == 0)
    {
        printf("Tidak ada barang\n");
    }
    else
    {
        for (int i = 0; i < store->Neff; i++)
        {
            printf("Barang %d: ", i + 1);
            PrintBarang(&store->store[i]);
            printf("Harga: %d\n\n", store->store[i].price);
        }
    }

    // Print user contents
    printf("\nDaftar Pengguna (%d user):\n", userList->Neff);
    if (userList->Neff == 0)
    {
        printf("Tidak ada pengguna\n");
    }
    else
    {
        for (int i = 0; i < userList->Neff; i++)
        {
            printf("User %d:\n", i + 1);
            printf("Username: %s\n", userList->users[i].name);
            printf("Password: %s\n", userList->users[i].password);
            printf("Money: %d\n\n", userList->users[i].money);
        }
    }
}