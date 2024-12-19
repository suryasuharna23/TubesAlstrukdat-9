#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "tebak_angka.h"
#include "../../ADT/User/user.h"
#include "../../command/Score/score.h"

boolean isValidNumber(Word word) {
    for (int i = 0; i < word.Length; i++) {
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') {
            return false; // kalo ada karakter bukan digit
        }
    }
    return true;
}

int getInt() {
    int result = 0;

    STARTINPUTWORD();
    if (!isValidNumber(CurrentWord)) { 
        printf("Input tidak valid! Masukkan angka.\n");
        return -1; 
    }

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
    int poin = 0; 

    srand(time(NULL)); 
    int digit = (rand() % 3) + 1; 
    int key_value = rand() % (int)(pow(10, digit)); 

    boolean win = false;

    while (try > 0 && !win) {
        printf("Masukkan angka tebakanmu: \n");
        printf(">>> ");
        int value = getInt();

        if (value == -1) { 
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
            poin = score(75, try);
            printf(" +%d rupiah telah ditambahkan ke akun anda.\n", poin);
            user->money += poin; 
            win = true;
        }
        try--;
    }

    if (!win) {
        printf("--------------------------------------------\n");
        printf("Yahh kamu kalah :(\n");
        printf("Angka yang benar adalah %d\n", key_value);
    }
    printf("-------------------------------------------------\n");
    printf("Poin yang diperoleh: %d\n", poin);
    printf("Total uang Anda sekarang: %d\n", user->money);

    for (int i = 0; i < users.count; i++) {
        if (WordCompare(users.users[i].name, user->name)) {
            users.users[i].money = user->money;
            break;
        }
    }
    printf("Apakah kamu ingin bermian lagi? (YES/BACK)\n");
    printf(">>> ");
    STARTINPUTWORD();
    char *response = WordToString(CurrentWord);
    if (WordCompare(response, "YES")) {
        tebak_angka(user);
    } else if (WordCompare(response, "BACK")) {
        return;
    } else {
        printf("Input tidak valid.\n");
    }
}