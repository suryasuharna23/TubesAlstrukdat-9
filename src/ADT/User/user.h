#ifndef USER_H
#define USER_H

#define MAX_LEN 50 // Panjang maksimal nama dan password

#include "user.h"
#include "boolean.h"

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

typedef struct {
    User *users;
    int Neff;        // Banyaknya elemen efektif
    int Capacity;    // Kapasitas maksimum array
} ArrayDinUser;

typedef int IdxType;

// Selektor
#define U(array) (array).users
#define Neff(array) (array).Neff

// Fungsi dan Prosedur
void CreateArrayDinUser(ArrayDinUser *array, int capacity);
void DeallocateArrayDinUser(ArrayDinUser *array);

void InsertUser(ArrayDinUser *array, User user);
void DeleteUserAt(ArrayDinUser *array, IdxType i);
void DeleteUserLast(ArrayDinUser *array);

int LengthUser(ArrayDinUser array);
boolean IsEmptyArrayDinUser(ArrayDinUser array);
void ResizeArrayUser(ArrayDinUser *array, int newCapacity);
void PrintAllUsers(ArrayDinUser array);

// Fungsi untuk menambah saldo pada user
void AddMoney(User *user, int amount);

#endif
