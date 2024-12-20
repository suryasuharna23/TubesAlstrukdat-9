#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "../Mesin/mesinkata.h"

void CreateUser(User *CurrentUser)
{
    // Initialize strings to empty
    CurrentUser->name[0] = '\0';
    CurrentUser->password[0] = '\0';
    CurrentUser->money = 0;
    CreateEmpty(&CurrentUser->keranjang);
    CreateEmptyList(&CurrentUser->wishlist);
    CreateEmptyS(&CurrentUser->riwayat_pembelian);
}

void CreateListUser(ListUser *users)
{
    users->count = 0;
}

void AddMoney(User *user, int amount)
{
    user->money += amount;
}

void TakeMoney(User *user, int amount)
{
    user->money -= amount;
}

void AddUser(ListUser *users, char *name, char *password, int money)
{
    StringCopy(users->users[users->count].name, name);
    StringCopy(users->users[users->count].password, password);
    users->users[users->count].money = money;
    users->count++;
}

void InsertUser(ListUser *users, User user)
{
    if (users->count < MAX_LEN)
    {
        users->users[users->count] = user;
        users->count++;
    }
    else
    {
        printf("User list is full.\n");
    }
}

int IndexUser(ListUser *users, char *name)
{
    int i = 0;
    while (i < users->count && !WordCompare(users->users[i].name, name))
    {
        i++;
    }
    return i;
}

int CountUser(ListUser *users)
{
    return users->count;
}

boolean IsUserValid(ListUser *users, char *name, char *password)
{
    int i = IndexUser(users, name);
    return i < users->count && WordCompare(users->users[i].password, password);
}

boolean IsUserExist(ListUser *users, char *name)
{
    return IndexUser(users, name) < users->count;
}

void InitCurrentUser(User *U)
{
    U->name[0] = '\0';                   // Kosongkan nama
    U->password[0] = '\0';               // Kosongkan password
    U->money = 0;                        // Set saldo awal
    CreateEmptyS(&U->riwayat_pembelian); // Inisialisasi stack kosong
    CreateEmptyList(&U->wishlist);       // Inisialisasi list kosong
}

int searchUserIndex(ListUser users, char *username)
{
    for (int i = 0; i < users.count; i++)
    {
        if (WordCompare(users.users[i].name, username) == 0)
        {
            return i;
        }
    }
    return -1;
}