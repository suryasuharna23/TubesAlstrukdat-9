#include <stdio.h>
#include <string.h>
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

    InitCurrentUser(CurrentUser);

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
        if (strncmp(users->users[i].name, username.TabWord, username.Length) == 0 && users->users[i].name[username.Length] == '\0') {
            userIdx = i;
            break;
        }
    }

    if (userIdx != -1) {
        if (strncmp(users->users[userIdx].password, password.TabWord, password.Length) == 0 && users->users[userIdx].password[password.Length] == '\0') {
            // Salin data pengguna ke CurrentUser
            strcpy(CurrentUser->name, users->users[userIdx].name);
            strcpy(CurrentUser->password, users->users[userIdx].password);
            CurrentUser->money = users->users[userIdx].money;

            // Salin riwayat pembelian
            CreateEmptyS(&CurrentUser->riwayat_pembelian);
            for (int j = 0; j <= users->users[userIdx].riwayat_pembelian.top; j++) {
                Push(&CurrentUser->riwayat_pembelian, users->users[userIdx].riwayat_pembelian.purchases[j]);
            }

            // Salin wishlist
            CreateEmptyList(&CurrentUser->wishlist);
            address_list P = First(users->users[userIdx].wishlist);
            while (P != Nol) {
                InsVLast(&CurrentUser->wishlist, Info(P));
                P = Next(P);
            }

            printf("Anda telah login ke PURRMART sebagai %s.\n", CurrentUser->name);
            return; // Pastikan fungsi keluar setelah login berhasil
        } else {
            printf("Login gagal. Password salah.\n");
        }
    } else {
        printf("Login gagal. Username tidak ditemukan.\n");
    }
}