#include <stdio.h>
#include <stdlib.h>
#include "world3.h"

int randomIdx(){
    srand(time(NULL));

    int idx = rand() % 10;

    return idx;
}

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
    int try = 5; // banyak kesempatan mencoba
    boolean win = false;

    int line = randomIdx();

    char *keyword = "word_list.txt";

    READLINE(keyword, line);
    Word key_word = CurrentWord;

    while (try > 0 && !win) {
        // ngeprint si karakter kosong, tiap nyobain bakal berkurang jumlah barisnya
        for (int i = 0; i < try; i++){
            printf("_ _ _ _ _\n");
        }

        printf("Masukkan kata tebakan Anda: ");
        STARTINPUTWORD();
        Word word = CurrentWord;

        if (word.Length != 5){ // kalau panjang katanya ga sesuai
            printf("Panjang kata tidak sesuai\n");
            try++;
        } else {
            printf("Hasil: \n");
            for (int i = 0; i < word.Length; i++){
                boolean match = false;

                for (int j = 0; j < key_word.Length; j++){
                    if ((word.TabWord[i] == key_word.TabWord[j])) { // kalau karakter sama, di tempat yang sama
                        if ((i == j)){
                            printf("%c ", word.TabWord[i]);
                        } else if (i != j){
                            printf("%c* ", word.TabWord[i]);
                        }
                        match = true;
                        break; 
                    } 
                }
                        
                if (!match){
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

            // kalau katanya sama menang, dan pengecekan berhenti
            if (count == word.Length){
                win = true;
                printf("Selamat anda menang!");
            }
        }
        // banyak kesempatan mencoba berkurang
        try--;
    }

    if (!win){
        printf("Anda belum beruntung\n");
    }
}
