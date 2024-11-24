#include <stdio.h>
#include "login.h"
#include "../../ADT/Mesin/mesinkata.h"

void Login(ListUser *users, char *currentUser)
{
    char username[MAX_LEN];
    char password[MAX_LEN];
    int userIdx = -1;

    printf("Silakan LOGIN terlebih dahulu.\n");

    // cek ada pengguna yang login
    if (currentUser[0] != '\0')
    {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser);
        return;
    }

    printf("Username: ");
    STARTINPUTWORD(); 
    Word wordUsername = CurrentWord;

    // copy Word ke username
    for (int i = 0; i < wordUsername.Length; i++)
    {
        username[i] = wordUsername.TabWord[i];
    }
    username[wordUsername.Length] = '\0'; 

    // cari username di daftar pengguna
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

    printf("Password: ");
    STARTINPUTWORD(); 
    Word wordPassword = CurrentWord;

    // copy Word ke password
    for (int i = 0; i < wordPassword.Length; i++)
    {
        password[i] = wordPassword.TabWord[i];
    }
    password[wordPassword.Length] = '\0'; 

    Word passwordWord = StringtoWord(users->users[userIdx].password);
    if (isEqual(wordPassword, passwordWord.TabWord))
    {
        for (int i = 0; i < wordUsername.Length; i++)
        {
            currentUser[i] = wordUsername.TabWord[i];
        }
        currentUser[wordUsername.Length] = '\0'; 
        printf("Anda telah login ke PURRMART sebagai %s.\n", currentUser);
    }
    else
    {
        printf("Password salah.\n");
    }
}