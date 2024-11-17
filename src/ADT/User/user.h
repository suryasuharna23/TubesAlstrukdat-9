#ifndef USER_H
#define USER_H

#define MAX_LEN 50 // Panjang maksimal nama dan password

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

// Fungsi untuk membuat user baru
void CreateUser(User *user, const char *name, const char *password, int money);

// Fungsi untuk mencetak informasi user
void PrintUser(const User *user);

#endif
