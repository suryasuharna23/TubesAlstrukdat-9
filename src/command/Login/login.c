#include <stdio.h>
#include "login.h"
#include "../../ADT/Mesin/mesinkata.h"

void Login(ListUser *users, char *currentUser)
{
    char username[MAX_LEN];
    char password[MAX_LEN];
    int userIdx = -1;

    printf("Silakan LOGIN terlebih dahulu.\n");

    // Cek apakah sudah ada pengguna yang login
    if (currentUser[0] != '\0')
    {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser);
        return;
    }

    // Input username
    printf("Username: ");
    STARTINPUTWORD(); // Mulai membaca input kata untuk username
    Word wordUsername = CurrentWord;

    // Salin Word ke username
    for (int i = 0; i < wordUsername.Length; i++)
    {
        username[i] = wordUsername.TabWord[i];
    }
    username[wordUsername.Length] = '\0'; // Tambahkan null terminator

    // Cari username di daftar pengguna
    for (int i = 0; i < users->count; i++)
    {
        Word userWord = StringtoWord(users->users[i].name);
        if (isEqual(wordUsername, userWord.TabWord))
        {
            userIdx = i;
            break;
        }
    }

    if (userIdx == -1)
    {
        printf("Username tidak ditemukan.\n");
        return;
    }

    // Input password
    printf("Password: ");
    STARTINPUTWORD(); // Mulai membaca input kata untuk password
    Word wordPassword = CurrentWord;

    // Salin Word ke password
    for (int i = 0; i < wordPassword.Length; i++)
    {
        password[i] = wordPassword.TabWord[i];
    }
    password[wordPassword.Length] = '\0'; // Tambahkan null terminator

    // Validasi password
    Word passwordWord = StringtoWord(users->users[userIdx].password);
    if (isEqual(wordPassword, passwordWord.TabWord))
    {
        // Salin nama pengguna ke currentUser
        for (int i = 0; i < wordUsername.Length; i++)
        {
            currentUser[i] = wordUsername.TabWord[i];
        }
        currentUser[wordUsername.Length] = '\0'; // Tambahkan null terminator
        printf("Anda telah login ke PURRMART sebagai %s.\n", currentUser);
    }
    else
    {
        printf("Password salah.\n");
    }
}