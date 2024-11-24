#include <stdio.h>
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/User/user.h"

void registerUser(ListUser *users)
{
    char username[MAX_LEN];
    char password[MAX_LEN];
    int i, j;

    printf("Masukkan username baru: ");
    STARTINPUTWORD();
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

    // Username validation
    for (i = 0; i < users->count; i++)
    {
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
            printf("Username \"%s\" sudah terdaftar. Silakan coba lagi.\n", username);
            return;
        }
    }

    // Input password
    printf("Masukkan password baru: ");
    STARTINPUTWORD();

    for (i = 0; i < CurrentWord.Length && i < MAX_LEN - 1; i++)
    {
        password[i] = CurrentWord.TabWord[i];
    }
    password[i] = '\0';

    // Add new user
    if (users->count < MAX_LEN)
    {

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

        printf("Registrasi berhasil! Selamat datang, %s.\n", username);
    }
    else
    {
        printf("Gagal menambahkan pengguna baru. Kapasitas maksimum tercapai.\n");
    }
}