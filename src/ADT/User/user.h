#ifndef USER_H
#define USER_H

#define MAX_LEN 50 

#include "../../Boolean/boolean.h"

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

typedef struct {
    User users[MAX_LEN];
    int count;
} ListUser;

typedef struct {
    User *users;
    int Neff;        
    int Capacity;    
} ArrayDinUser;

typedef int IdxType;

// Selektor
#define U(array) (array).users
#define Neff(array) (array).Neff

// Konstruktor list user
void InitializeListUser(ListUser *list);

// Fungsi dan Prosedur
void CreateUser(User *user, const char *name, const char *password, int money);
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
