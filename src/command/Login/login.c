#include <stdio.h>
#include "login.h"
#include "../Mesin/mesinkata.h"

void Login(ListUser *users, char *currentUser) {
    char username[MAX_LEN];
    char password[MAX_LEN];
    int userIdx = -1;
    
    printf("Silakan LOGIN terlebih dahulu.\n");
    // debug pengguna
    // for (int i = 0; i < users->count; i++) {
    //     for (int j = 0; users->users[i].name[j] != '\0'; j++) {
    //         printf("%c", users->users[i].name[j]);
    //     }
    //     for (int j = 0; users->users[i].password[j] != '\0'; j++) {
    //         printf("%c", users->users[i].password[j]);
    //     }
    //     printf("\n");
    // }

    // Cek apakah sudah ada pengguna yang login
    if (currentUser[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser);
        return;
    }

    // Input username
    printf("Username: ");
    Word wordUsername = GetWord(CurrentWord, 1);

    for (int i = 0; i < wordUsername.Length; i++)
    {
        username[i] = wordUsername.TabWord[i];
    }
    username[wordUsername.Length] = '\0';

    // Cari username di daftar pengguna
    for (int i = 0; i < users->count; i++) {
        int isMatch = 1;
        for (int j = 0; username[j] != '\0' || users->users[i].name[j] != '\0'; j++) {
            if (username[j] != users->users[i].name[j]) {
                isMatch = 0; // Tidak cocok
                break;
            }
        }
        if (isMatch) {
            userIdx = i;
            break;
        }
    }

    // Validasi hasil pencarian username
    if (userIdx == -1) {
        printf("Username atau password salah.\n");
        return;
    }

    // Input password
    printf("Password: ");
    Word wordPassword = GetWord(CurrentWord, 1);

    for (int i = 0; i < wordPassword.Length; i++)
    {
        password[i] = wordPassword.TabWord[i];
    }
    password[wordPassword.Length] = '\0';

    // Validasi password
    int isPasswordMatch = 1;
    for (int i = 0; password[i] != '\0' || users->users[userIdx].password[i] != '\0'; i++) {
        if (password[i] != users->users[userIdx].password[i]) {
            isPasswordMatch = 0; // Password tidak cocok
            break;
        }
    }

    // Login berhasil atau gagal
    if (isPasswordMatch) {
        int i = 0;
        while (users->users[userIdx].name[i] != '\0') {
            currentUser[i] = users->users[userIdx].name[i];
            i++;
        }
        currentUser[i] = '\0'; // Null terminator
        printf("Anda telah login ke PURRMART sebagai %s.\n", currentUser);
    } else {
        printf("Username atau password salah.\n");
    }
}
