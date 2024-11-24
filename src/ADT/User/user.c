#include <stdio.h>
#include <stdlib.h>
#include "user.h"

// Membuat list user kosong
void InitializeListUser(ListUser *list){
    list->count = 0;
}

// Membuat user baru
void CreateUser(User *user, const char *name, const char *password, int money) {
    int i = 0;
    while (name[i] != '\0' && i < MAX_LEN - 1) {
        user->name[i] = name[i];
        i++;
    }
    user->name[i] = '\0';

    i = 0;
    while (password[i] != '\0' && i < MAX_LEN - 1) {
        user->password[i] = password[i];
        i++;
    }
    user->password[i] = '\0';
    user->money = money;
}

// Menampilkan informasi user
void PrintUser(const User *user) {
    printf("Name: %s\n", user->name);
    printf("Password: %s\n", user->password);
    printf("Money: %d\n", user->money);
}

void AddMoney(User *user, int amount) {
    if (amount > 0) {
        user->money += amount;
    }
}

// Membuat Array Dinamis untuk User
void CreateArrayDinUser(ArrayDinUser *array, int capacity) {
    if (capacity > 0) {
        array->users = (User *)malloc((unsigned int)capacity * sizeof(User));
        array->Neff = 0;
        array->Capacity = capacity;
    } else {
        array->users = NULL;
        array->Neff = 0;
        array->Capacity = 0;
    }
}

// Menghapus Array Dinamis dan Membebaskan Memori
void DeallocateArrayDinUser(ArrayDinUser *array) {
    free(array->users);
    array->users = NULL;
    array->Neff = 0;
    array->Capacity = 0;
}

// Menambahkan User ke Array
void InsertUser(ArrayDinUser *array, User user) {
    if (array->Neff >= array->Capacity) {
        ResizeArrayUser(array, array->Capacity * 2);
    }
    U(*array)[array->Neff] = user;
    array->Neff++;
}

// Menghapus User pada Indeks Tertentu
void DeleteUserAt(ArrayDinUser *array, IdxType i) {
    if (i >= 0 && i < array->Neff) {
        for (int j = i; j < array->Neff - 1; j++) {
            U(*array)[j] = U(*array)[j + 1];
        }
        array->Neff--;
    } else {
        printf("Indeks tidak valid.\n");
    }
}

// Menghapus User Terakhir
void DeleteUserLast(ArrayDinUser *array) {
    if (array->Neff > 0) {
        array->Neff--;
    } else {
        printf("Array kosong, tidak ada yang dihapus.\n");
    }
}

// Mendapatkan Panjang Array
int LengthUser(ArrayDinUser array) {
    return array.Neff;
}

// Mengecek Apakah Array Kosong
boolean IsEmptyArrayDinUser(ArrayDinUser array) {
    return array.Neff == 0;
}

// Mengubah Kapasitas Array
void ResizeArrayUser(ArrayDinUser *array, int newCapacity) {
    if (newCapacity > 0) {
        User *newUsers = (User *)malloc((unsigned int)newCapacity * sizeof(User));
        for (int i = 0; i < array->Neff; i++) {
            newUsers[i] = array->users[i];
        }
        free(array->users);
        array->users = newUsers;
        array->Capacity = newCapacity;
    } else {
        printf("Kapasitas baru tidak valid.\n");
    }
}

// Mencetak Semua User
void PrintAllUsers(ArrayDinUser array) {
    for (int i = 0; i < array.Neff; i++) {
        printf("User #%d:\n", i + 1);
        PrintUser(&U(array)[i]);
        printf("\n");
    }
}