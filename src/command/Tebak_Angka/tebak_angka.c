#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "tebak_angka.h"
#include "../../ADT/User/user.h"
#include "../../command/Score/score.h"

// Fungsi untuk memeriksa apakah input adalah angka valid
boolean isValidNumber(Word word) {
    for (int i = 0; i < word.Length; i++) {
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') {
            return false; // Jika ada karakter bukan digit
        }
    }
    return true;
}

int getInt() {
    int result = 0;

    STARTINPUTWORD();
    if (!isValidNumber(CurrentWord)) { // Validasi input
        printf("Input tidak valid! Masukkan angka.\n");
        return -1; // Kembalikan nilai error
    }

    // Konversi dari Word ke integer
    for (int i = 0; i < CurrentWord.Length; i++) {
        result = result * 10 + (CurrentWord.TabWord[i] - '0');
    }
    return result;
}

void tebak_angka(User *user) {
    if (user == NULL) {
        printf("Error: User tidak diinisialisasi!\n");
        return;
    }

    int try = MAX_TRIES;
    int poin = 0; // Skor pemain

    srand(time(NULL)); // Inisialisasi random seed
    int digit = (rand() % 3) + 1; // Menentukan banyaknya digit angka yang akan ditebak
    int key_value = rand() % (int)(pow(10, digit)); // Angka acak

    // Debug: Tampilkan nilai yang harus ditebak
    printf("[DEBUG] Angka yang harus ditebak: %d\n", key_value);

    boolean win = false;

    while (try > 0 && !win) {
        printf("Tebak angka: ");
        int value = getInt();

        if (value == -1) { // Input tidak valid
            printf("Input tidak valid, coba lagi!\n");
            continue;
        }

        if (value < key_value) {
            printf("Tebakanmu lebih kecil!\n");
            printf("(Kesempatanmu %d kali lagi untuk mencoba)\n", (try - 1));
        } else if (value > key_value) {
            printf("Tebakanmu lebih besar!\n");
            printf("(Kesempatanmu %d kali lagi untuk mencoba)\n", (try - 1));
        } else {
            printf("Tebakanmu benar!\n");
            poin = score(75, try); // Hitung skor
            printf(" +%d rupiah telah ditambahkan ke akun anda.\n", poin);
            user->money += poin; // Tambah uang ke akun pengguna
            win = true;
        }
        try--;
    }

    if (!win) {
        printf("Yahh kamu kalah \\(>A<)/\n");
        printf("Angka yang benar adalah %d\n", key_value);
    }

    printf("Poin yang diperoleh: %d\n", poin);
    printf("Total uang Anda sekarang: %d\n", user->money);

    // Update the user's money in the users list
    for (int i = 0; i < users.count; i++) {
        if (WordCompare(users.users[i].name, user->name)) {
            users.users[i].money = user->money;
            break;
        }
    }
}