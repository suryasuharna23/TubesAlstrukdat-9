#include <stdio.h>
#include "login.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/User/user.h"

void Login(ListUser *users, User *CurrentUser) {
    Word username;
    Word password;
    int userIdx = -1;

    printf("Silakan LOGIN terlebih dahulu.\n");

    // cek ada pengguna yang login
    if (CurrentUser->name[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", CurrentUser->name);
        return;
    }

    printf("Username: ");
    while (true) {
        STARTINPUTWORD();
        username = CurrentWord;
        if (IsBlankExist(username) || !IsLetterOrDigit(username) || username.Length == 0) {
            printf("Username tidak valid. Coba lagi.\nUsername: ");
        } else {
            break;
        }
    }

    printf("Password: ");
    while (true) {
        STARTINPUTWORD();
        password = CurrentWord;
        if (IsBlankExist(password) || password.Length == 0) {
            printf("Password tidak valid. Coba lagi.\nPassword: ");
        } else {
            break;
        }
    }

    // Cari username dalam daftar pengguna
    for (int i = 0; i < users->count; i++) {
        int match = 1;
        for (int j = 0; j < username.Length; j++) {
            if (users->users[i].name[j] != username.TabWord[j]) {
                match = 0;
                break;
            }
        }
        if (match && users->users[i].name[username.Length] == '\0') {
            userIdx = i;
            break;
        }
    }

    if (userIdx != -1) {
        int match = 1;
        for (int j = 0; j < password.Length; j++) {
            if (users->users[userIdx].password[j] != password.TabWord[j]) {
                match = 0;
                break;
            }
        }
        if (match && users->users[userIdx].password[password.Length] == '\0') {
            // Salin data pengguna ke CurrentUser
            for (int j = 0; j < username.Length; j++) {
                CurrentUser->name[j] = users->users[userIdx].name[j];
            }
            CurrentUser->name[username.Length] = '\0';
            for (int j = 0; j < password.Length; j++) {
                CurrentUser->password[j] = users->users[userIdx].password[j];
            }
            CurrentUser->password[password.Length] = '\0';
            CurrentUser->money = users->users[userIdx].money;
            printf("Anda telah login ke PURRMART sebagai %s.\n", CurrentUser->name);
        } else {
            printf("Login gagal. Password salah.\n");
        }
    } else {
        printf("Login gagal. Username tidak ditemukan.\n");
    }
}