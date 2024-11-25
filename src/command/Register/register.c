#include <stdio.h>
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/User/user.h"

void registerUser(ListUser *users, boolean *flag)
{
    char username[MAX_LEN];
    char password[MAX_LEN];
    int i, j;
    User u;
    ArrayDinUser array;

    boolean readFile = true;
    if (readFile)
    {

        STARTWORD("default.txt");
        ADVWORD();
        while (!EndWord)
        {
            Word money = GetWord(CurrentWord, 1);
            Word uname = GetWord(CurrentWord, 2);
            Word password = GetWord(CurrentWord, 3);

            int uang = WordToInt(money); // asumsi default.txt sudah berisikan nama dan harga yang valid
            CreateUser(&u, WordToString(uname), WordToString(password), WordToInt(money));

            InsertUser(&array, u);
            ADVWORD();
        }
        readFile = false;
    }

    printf("Masukkan username baru: ");
    STARTINPUTWORD();

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
        *flag = true;
    }
    else
    {
        printf("Gagal menambahkan pengguna baru. Kapasitas maksimum tercapai.\n");
    }
}