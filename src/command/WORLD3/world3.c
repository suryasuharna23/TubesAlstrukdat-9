#include <stdio.h>
#include <stdlib.h>
#include "world3.h"

void READLINE(char *filename, int IdxLine){
    START(filename);
    int currentLine = 0;

    while ((currentLine < IdxLine) && (!IsEOP())){
        while ((currentChar != '\n') && (!IsEOP())){
            ADV();
        }
        if (currentChar == '\n'){
            ADV();
        }
        currentLine++;
    }

    IgnoreBlanks();
    if (!IsEOP()){
        CopyWord();
        EndWord = false;
    } else {
        EndWord = true;
    }
}

void world3_challenge() {
    int try = MAX_TRIES; // banyak kesempatan mencoba
    boolean win = false; // menentukan apakah pemain menang atau kalah

    // implementasi random number untuk menentukan keyword dan poin secara acak
    int line = randomNumber(3) % 100;

    char *keyword = "word_list.txt";

    READLINE(keyword, line);
    Word key_word = CurrentWord;

    printf("WELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n");

    while (try > 0 && !win) {
        // ngeprint si karakter kosong, tiap nyobain bakal berkurang jumlah barisnya
        for (int i = 0; i < try; i++){
            printf("_ _ _ _ _\n");
        }

        // menerima input kata yang ditebak
        printf("Masukkan kata tebakan Anda: ");
        STARTINPUTWORD();
        Word word = CurrentWord;

        if (word.Length != 5){ // kalau panjang katanya ga sesuai
            printf("Panjang kata tidak sesuai\n");
        } else { // kalau sesuai
            printf("Hasil: \n");
            for (int i = 0; i < word.Length; i++){ // memanggil karakter dari kata pada yang ditebak
                boolean match = false; // menentukan karakter yang sama

                // mengecek tiap karakter dari input kata yang ditebak dengan keyword yang terpilih acak
                for (int j = 0; j < key_word.Length; j++){
                    if ((word.TabWord[i] == key_word.TabWord[j])) { 
                        if ((i == j)){ // kalau karakter ada dan pada posisi yang sama
                            printf("%c ", word.TabWord[i]); 
                        } else if (i != j){ // kalau karakter ada, tetapi beda posisi
                            printf("%c* ", word.TabWord[i]);
                        }
                        match = true; // karakter yang sama ditemukan
                        break; // pengecekan berhenti dan berpindah ke karakter berikutnya
                    } 
                }
                        
                if (!match){ // jika karakter dari kata yang ditebak tidak ada pada keyword
                    printf("%c%% ", word.TabWord[i]);
                }
            }

            printf("\n");

            // ini buat ngecek kalau katanya sama
            int count= 0;
            for (int i = 0; i < word.Length; i++){
                if (word.TabWord[i] == key_word.TabWord[i]){
                    count++;
                }
            }

            // kalau katanya sama, pemain menang, dan pengecekan berhenti
            if (count == word.Length){
                win = true; // kalau pemain menang, win bernilai true, program berhenti
                printf("Selamat anda menang!\n");
                int score = try * 150;
                printf("+%d rupiah telah ditambahkan ke akun Anda.\n", score);
            }
        }
        // banyak kesempatan mencoba berkurang
        try--;
    }

    if (!win){ // kalau pemain kalah, program berhenti
        printf("Boo! Anda kalah.\n");
    }
}
