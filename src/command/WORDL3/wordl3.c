#include <stdio.h>
#include <stdlib.h>
#include "wordl3.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../command/Score/score.h"

extern char CurrentChar;

void READLINE(char *filename, int IdxLine) {
    START(filename);
    int currentLine = 0;

    while ((currentLine < IdxLine) && (!IsEOP())) {
        while ((CurrentChar != '\n') && (!IsEOP())) {
            ADV();
        }
        if (CurrentChar == '\n') {
            ADV();
        }
        currentLine++;
    }

    IgnoreBlanks();
    if (!IsEOP()) {
        CopyWord();
        EndWord = false;
    } else {
        EndWord = true;
    }
}

void clearHist(char *filename) {
    FILE *clear_hist = fopen(filename, "w");
    fclose(clear_hist);
}

void saveChar(char flag, char letter, boolean isLast) {
    FILE *history;

    history = fopen("../../command/WORDL3/history.txt", "a"); // membuka file history tebakan kata

    // masukin karakter ke file history
    fputc(letter, history);

    if (flag != ' ') { // kalau karakter benar di posisi benar, flagnya ' ', jadi untuk selain itu, bakal dikasih ' ' setelah flagnya
        fputc(flag, history);
    }
    fputc(' ', history);

    if (isLast) { // kalau udah karakter terakhir, ganti baris
        fputc('\n', history);
    }

    fclose(history); // close file
}

void wordl3_challenge(User *user) {
    if (user == NULL) {
        printf("Error: User tidak diinisialisasi!\n");
        return;
    }

    int try = MAX_PLAYS; // banyak kesempatan mencoba
    boolean win = false; // menentukan apakah pemain menang atau kalah
    char flag;
    int poin = 0; //score pemain

    // implementasi random number untuk menentukan keyword dan poin secara acak
    int line = randomNumber(3) % 100;

    // mengambil keyword
    char *keyword = "../../command/WORDL3/word_list.txt";

    READLINE(keyword, line);
    Word key_word = CurrentWord;

    char *history = "../../command/WORDL3/history.txt";
    clearHist(history);

    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n", MAX_PLAYS);

    while (try > 0 && !win) {
        int isLast = false;

        // print kata yang ada di file history, alias kata-kata hasil tebakan sebelumnya
        STARTWORD(history);
        while (!EndWord) {
            PrintCurrentWord();
            ADVWORD();
        }

        // ngeprint si karakter kosong, tiap nyobain bakal berkurang jumlah barisnya
        for (int i = 0; i < try; i++) {
            printf("_ _ _ _ _\n");
        }

        // menerima input kata yang ditebak
        printf("Masukkan kata tebakan Anda: ");
        STARTINPUTWORD();
        Word word = CurrentWord;

        if (word.Length != 5) { // kalau panjang katanya ga sesuai
            printf("Panjang kata tidak sesuai\n");
            boolean *checked = (boolean *)malloc(key_word.Length * sizeof(boolean));

            for (int i = 0; i < key_word.Length; i++) {
                checked[i] = false;
            }

            printf("Hasil: \n");
            for (int i = 0; i < word.Length; i++) { // memanggil karakter dari kata pada yang ditebak
                boolean match = false; // menentukan karakter yang sama
                if (i == word.Length - 1) {
                    isLast = true;
                }

                // mengecek tiap karakter dari input kata yang ditebak dengan keyword yang terpilih acak
                for (int j = 0; j < key_word.Length; j++) {
                    if ((word.TabWord[i] == key_word.TabWord[j]) && (checked[j] == false)) {
                        if ((i == j)) { // kalau karakter ada dan pada posisi yang sama
                            flag = ' ';
                            saveChar(flag, word.TabWord[i], isLast);
                            checked[j] = true; // checked menjadi true, berarti karakter pada indeks j dalam kata key_word nantinya tidak perlu dicek lagi
                        } else if (i != j) { // kalau karakter ada, tetapi beda posisi
                            flag = '*';
                            saveChar(flag, word.TabWord[i], isLast);
                            checked[j] = true;
                        }
                        match = true; // karakter yang sama ditemukan
                        break; // pengecekan berhenti dan berpindah ke karakter berikutnya
                    }
                }

                if (!match) { // jika karakter dari kata yang ditebak tidak ada pada keyword
                    flag = '%';
                    saveChar(flag, word.TabWord[i], isLast);
                }
            }

            char *keyString = WordToString(key_word);
            char *wordString = WordToString(word);

            // kalau katanya sama, pemain menang, dan pengecekan berhenti
            if (WordCompare(keyString, wordString)) {
                win = true; // kalau pemain menang, win bernilai true, program berhenti
                STARTWORD(history);
                while (!EndWord) {
                    PrintCurrentWord();
                    ADVWORD();
                }
                printf("Selamat anda menang!\n");
                poin = score(150, try);
                printf("+%d rupiah telah ditambahkan ke akun Anda.\n", poin);
                user->money += poin; // Tambah uang ke akun pengguna
            }
        }
        // banyak kesempatan mencoba berkurang
        try--;
    }

    if (!win) { // kalau pemain kalah, program berhenti
        STARTWORD(history);
        while (!EndWord) {
            PrintCurrentWord();
            ADVWORD();
        }
        printf("Boo! kamu kalah 'v(- o -)v'\n");
        READLINE(keyword, line);
        printf("Kata yang benar adalah ");
        PrintCurrentWord();
    }

    printf("Poin yang diperoleh: %d\n", poin);
    printf("Total uang Anda sekarang: %d\n", user->money);

    // Update jumlah uang dari si user
    for (int i = 0; i < users.count; i++) {
        if (WordCompare(users.users[i].name, user->name)) {
            users.users[i].money = user->money;
            break;
        }
    }
}