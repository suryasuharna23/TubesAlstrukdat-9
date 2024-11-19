#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Mesin/mesinkarakter.h"
#include "../ADT/Mesin/mesinkata.h"
#include "../ADT/User/user.h"
#include "../ADT/Barang/barang.h"


#define MAX_NAME 50
#define MAX_PASSWORD 50
#define BLANK ' '

// Prototipe fungsi
void loadFile(char *filename);
int wordToInt(Word word);
void wordToCharArray(Word word, char *str);

// Fungsi LOAD
void loadFile(char *filename) {
    Barang barangList[100];
    User userList[100];
    int jumlahBarang = 0, jumlahUser = 0;

    // Menambahkan prefix folder "config/"
    char filepath[100];
    int i = 0, j = 0;

    // Salin "config/" ke filepath
    char folder[] = "config/";
    while (folder[i] != '\0') {
        filepath[i] = folder[i];
        i++;
    }

    // Tambahkan nama file ke filepath
    while (filename[j] != '\0') {
        filepath[i] = filename[j];
        i++;
        j++;
    }
    filepath[i] = '\0'; // Null-terminator

    // Buka file menggunakan Mesin Kata
    STARTWORD(filepath);
    if (IsEOP()) {
        printf("Meload %s\n", filepath);
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }

    printf("Meload %s\n", filepath);

    // Membaca jumlah barang
    jumlahBarang = wordToInt(CurrentWord);
    Barang *barangListPtr = malloc(jumlahBarang * sizeof(Barang));
    ADVWORD();

    // Membaca data barang
    for (int i = 0; i < jumlahBarang; i++) {
        barangListPtr[i].price = wordToInt(CurrentWord);
        ADVWORD();
        wordToCharArray(CurrentWord, barangListPtr[i].name);
        ADVWORD();
    }

    // Membaca jumlah pengguna
    jumlahUser = wordToInt(CurrentWord);
    User *userListPtr = malloc(jumlahUser * sizeof(User));
    ADVWORD();

    // Membaca data pengguna
    for (int i = 0; i < jumlahUser; i++) {
        userListPtr[i].money = wordToInt(CurrentWord);
        ADVWORD();
        wordToCharArray(CurrentWord, userListPtr[i].name);
        ADVWORD();
        wordToCharArray(CurrentWord, userListPtr[i].password);
        ADVWORD();
    }

    // Menampilkan hasil pembacaan
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");

    printf("Daftar Barang:\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("  - %s (Harga: %d)\n", barangListPtr[i].name, barangListPtr[i].price);
    }

    printf("Daftar Pengguna:\n");
    for (int i = 0; i < jumlahUser; i++) {
        printf("  - Username: %s, Password: %s, Uang: %d\n",
               userListPtr[i].name, userListPtr[i].password, userListPtr[i].money);
    }

    // Membersihkan memori
    free(barangListPtr);
    free(userListPtr);
}

// Konversi Word menjadi integer
int wordToInt(Word word) {
    int result = 0;
    for (int i = 0; i < word.Length; i++) {
        result = result * 10 + (word.TabWord[i] - '0');
    }
    return result;
}

// Konversi Word menjadi array karakter
void wordToCharArray(Word word, char *str) {
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0'; // Null-terminator
}
