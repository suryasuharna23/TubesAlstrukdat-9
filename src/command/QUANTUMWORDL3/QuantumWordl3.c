#include <stdio.h>
#include "QuantumWordl3.h"

void checkWord(Word keyword, Word word){
    char flag;
    boolean isLast = false;

    char *history = "../../command/WORDL3/history.txt";

    // print kata yang ada di file history, alias kata-kata hasil tebakan sebelumnya
    STARTWORD(history);
    while (!EndWord) {
        PrintCurrentWord();
        ADVWORD();
    }

    boolean checked[keyword.Length];

    for (int i = 0; i < keyword.Length; i++){
        checked[i] = false;
    }

    for (int i = 0; i < word.Length; i++){ // memanggil karakter dari kata pada yang ditebak
        boolean match = false; // menentukan karakter yang sama
        if (i == word.Length - 1){
            isLast = true;
        }

        // mengecek tiap karakter dari input kata yang ditebak dengan keyword yang terpilih acak
        for (int j = 0; j < keyword.Length; j++){
            if ((word.TabWord[i] == keyword.TabWord[j]) && (checked[j] == false)) { 
                if ((i == j)){ // kalau karakter ada dan pada posisi yang sama
                    flag = ' ';
                    saveChar(flag, word.TabWord[i], isLast);
                    checked[j] = true; // checked menjadi true, berarti karakter pada indeks j dalam kata key_word nantinya tidak perlu dicek lagi
                } else if (i != j){ // kalau karakter ada, tetapi beda posisi
                    flag = '*';
                    saveChar(flag, word.TabWord[i], isLast);
                    checked[j] = true;
                }
                match = true; // karakter yang sama ditemukan
                break; // pengecekan berhenti dan berpindah ke karakter berikutnya
            } 
        }
                
        if (!match){ // jika karakter dari kata yang ditebak tidak ada pada keyword
            flag = '%';
            saveChar(flag, word.TabWord[i], isLast);
        }
    }

    // ini buat ngecek kalau katanya sama
    int count= 0;
    for (int i = 0; i < word.Length; i++){
        if (word.TabWord[i] == keyword.TabWord[i]){
            count++;
        }
    }

}

void QuantumWordl3(){
    int try = MAXTRIES;
    boolean win = false;

    char *keywords = "../../command/WORDL3/word_list.txt";

    READLINE(keywords, (randomNumber(3) % 100));
    Word key_word1 = CurrentWord;

    READLINE(keywords, (randomNumber(3) % 100));
    Word key_word2 = CurrentWord;

    READLINE(keywords, (randomNumber(3) % 100));
    Word key_word3 = CurrentWord;

    READLINE(keywords, (randomNumber(3) % 100));
    Word key_word4 = CurrentWord;
    
    // memasikan semua katanya beda, kalau ada yang sama, diambil lagi ulang
    while (isExactSame(key_word1, key_word2) || isExactSame(key_word2, key_word3) || isExactSame(key_word3, key_word4)){
        READLINE(keywords, (randomNumber(3) % 100));
        Word key_word1 = CurrentWord;

        READLINE(keywords, (randomNumber(3) % 100));
        Word key_word2 = CurrentWord;

        READLINE(keywords, (randomNumber(3) % 100));
        Word key_word3 = CurrentWord;

        READLINE(keywords, (randomNumber(3) % 100));
        Word key_word4 = CurrentWord;
    }

    while (try >= 0 && !win){
        for (int i = 0; i <= (try * 4); i++){
            printf("_ _ _ _ _\n");
        }

        printf("Masukkan kata tebakan Anda: ");
        STARTINPUTWORD();
        Word word1 = CurrentWord;

        printf("Masukkan kata tebakan Anda: ");
        STARTINPUTWORD();
        Word word2 = CurrentWord;

        printf("Masukkan kata tebakan Anda: ");
        STARTINPUTWORD();
        Word word3 = CurrentWord;

        printf("Masukkan kata tebakan Anda: ");
        STARTINPUTWORD();
        Word word4 = CurrentWord;

        checkWord(key_word1, word1);
        checkWord(key_word2, word2);
        checkWord(key_word3, word3);
        checkWord(key_word4, word4);
    }
}