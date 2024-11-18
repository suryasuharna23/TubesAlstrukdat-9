#include <stdio.h>
#include "user.h"

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