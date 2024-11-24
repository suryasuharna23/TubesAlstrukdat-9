#include <stdio.h>
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/User/user.h"

void registerUser(ListUser *users)
{
    char username[MAX_LEN];
    char password[MAX_LEN];
    int i, j;

    printf("\n[DEBUG] Starting registration process\n");
    printf("[DEBUG] Current user count: %d\n", users->count);

    // Input username
    printf("Masukkan username baru: ");
    STARTINPUTWORD();
    printf("[DEBUG] Input word length: %d\n", CurrentWord.Length);
    printf("[DEBUG] Input word content: ");
    for (i = 0; i < CurrentWord.Length; i++)
    {
        printf("%c", CurrentWord.TabWord[i]);
    }
    printf("\n");

    // Copy username
    for (i = 0; i < CurrentWord.Length && i < MAX_LEN - 1; i++)
    {
        username[i] = CurrentWord.TabWord[i];
    }
    username[i] = '\0';
    printf("[DEBUG] Username copied: %s\n", username);

    // Username validation
    for (i = 0; i < users->count; i++)
    {
        printf("[DEBUG] Comparing with existing user %d: %s\n", i, users->users[i].name);
        int isSame = 1;
        for (j = 0; j < MAX_LEN; j++)
        {
            if (username[j] != users->users[i].name[j])
            {
                isSame = 0;
                break;
            }
            if (username[j] == '\0' && users->users[i].name[j] == '\0')
            {
                break;
            }
        }
        if (isSame)
        {
            printf("[DEBUG] Username match found with user %d\n", i);
            printf("Username \"%s\" sudah terdaftar. Silakan coba lagi.\n", username);
            return;
        }
    }

    // Input password
    printf("Masukkan password baru: ");
    STARTINPUTWORD();
    printf("[DEBUG] Password length: %d\n", CurrentWord.Length);

    for (i = 0; i < CurrentWord.Length && i < MAX_LEN - 1; i++)
    {
        password[i] = CurrentWord.TabWord[i];
    }
    password[i] = '\0';
    printf("[DEBUG] Password copied\n");

    // Add new user
    if (users->count < MAX_LEN)
    {
        printf("[DEBUG] Adding new user at index %d\n", users->count);

        // Copy username
        for (i = 0; username[i] != '\0'; i++)
        {
            users->users[users->count].name[i] = username[i];
        }
        users->users[users->count].name[i] = '\0';

        // Copy password
        for (i = 0; password[i] != '\0'; i++)
        {
            users->users[users->count].password[i] = password[i];
        }
        users->users[users->count].password[i] = '\0';

        users->users[users->count].money = 0;
        users->count++;

        printf("[DEBUG] New user added successfully\n");
        printf("Registrasi berhasil! Selamat datang, %s.\n", username);
    }
    else
    {
        printf("[DEBUG] User list full\n");
        printf("Gagal menambahkan pengguna baru. Kapasitas maksimum tercapai.\n");
    }
}