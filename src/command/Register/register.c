#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "user.h"

void registerUser(ListUser *users) {
    char username[MAX_LEN];
    char password[MAX_LEN];
    int i, j;
    Word CKata;

    // Input username menggunakan mesinkata
    printf("Masukkan username baru: ");
    STARTINPUTWORD(); // Mulai membaca input untuk username
    for (i = 0; i < CKata.Length && i < MAX_LEN - 1; i++) {
        username[i] = CKata.TabWord[i];
    }
    username[i] = '\0'; // Null terminator

    // Validasi apakah username sudah ada
    for (i = 0; i < users->count; i++) {
        int isSame = 1; // Flag untuk menandai kesamaan username
        for (j = 0; j < MAX_LEN; j++) {
            if (username[j] != users->users[i].name[j]) {
                isSame = 0; // Jika ada karakter yang berbeda, bukan username yang sama
                break;
            }
            if (username[j] == '\0' && users->users[i].name[j] == '\0') {
                break; // Jika kedua string mencapai null terminator, berhenti membandingkan
            }
        }
        if (isSame) {
            printf("Username \"%s\" sudah terdaftar. Silakan coba lagi.\n", username);
            return;
        }
    }

    // Input password menggunakan mesinkata
    printf("Masukkan password baru: ");
    STARTINPUTWORD(); // Mulai membaca input untuk password
    for (i = 0; i < CKata.Length && i < MAX_LEN - 1; i++) {
        password[i] = CKata.TabWord[i];
    }
    password[i] = '\0'; // Null terminator

    // Menambahkan pengguna ke daftar
    if (users->count < MAX_LEN) {
        // Salin username ke daftar pengguna
        for (i = 0; username[i] != '\0'; i++) {
            users->users[users->count].name[i] = username[i];
        }
        users->users[users->count].name[i] = '\0'; // Null terminator

        // Salin password ke daftar pengguna
        for (i = 0; password[i] != '\0'; i++) {
            users->users[users->count].password[i] = password[i];
        }
        users->users[users->count].password[i] = '\0'; // Null terminator

        users->users[users->count].money = 0; // Default saldo awal

        users->count++; // Increment jumlah pengguna
        printf("Registrasi berhasil! Selamat datang, %s.\n", username);
    } else {
        printf("Gagal menambahkan pengguna baru. Kapasitas maksimum tercapai.\n");
    }
}

int main() {
    // Inisialisasi daftar pengguna
    ListUser users;
    users.count = 2;

    // Data pengguna awal (contoh)
    for (int i = 0; i < 5; i++) users.users[0].name[i] = "admin"[i];
    users.users[0].name[5] = '\0';
    for (int i = 0; i < 8; i++) users.users[0].password[i] = "admin123"[i];
    users.users[0].password[8] = '\0';
    users.users[0].money = 1000;

    for (int i = 0; i < 4; i++) users.users[1].name[i] = "user"[i];
    users.users[1].name[4] = '\0';
    for (int i = 0; i < 8; i++) users.users[1].password[i] = "userpass"[i];
    users.users[1].password[8] = '\0';
    users.users[1].money = 500;

    // Tampilkan daftar pengguna sebelum registrasi
    printf("Daftar pengguna sebelum registrasi:\n");
    for (int i = 0; i < users.count; i++) {
        printf("%d. Username: %s, Saldo: %d\n", i + 1, users.users[i].name, users.users[i].money);
    }

    // Memanggil fungsi registerUser
    registerUser(&users);

    // Tampilkan daftar pengguna setelah registrasi
    printf("\nDaftar pengguna setelah registrasi:\n");
    for (int i = 0; i < users.count; i++) {
        printf("%d. Username: %s, Saldo: %d\n", i + 1, users.users[i].name, users.users[i].money);
    }

    return 0;
}