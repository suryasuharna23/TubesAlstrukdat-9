#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK && !IsEOP()){
        ADV();
    }
}

void STARTWORD(char *FILE){
    START(FILE);
    IgnoreBlanks();
    if (currentChar == '\n' || currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord =false;
        CopyWord();
    }
}

void STARTINPUTWORD() {
    STARTINPUT(); 
    IgnoreBlanks();
    if (currentChar == '\n' || currentChar == MARK) { 
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if (currentChar == '\n' || currentChar == MARK){
        EndWord = true;
    }
    else{
        CopyWord();
    }
}

void CopyWord(){
    int i=0;
    while ((currentChar != BLANK) && (currentChar != '\n') && (currentChar != MARK) && (i<NMax)){
        CurrentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    CurrentWord.Length=i;
    if (CurrentWord.TabWord[CurrentWord.Length-1]=='\r');
}

void PrintCurrentWord() {
    for (int i = 0; i < CurrentWord.Length; i++) {
        printf("%c", CurrentWord.TabWord[i]);
    }
    printf("\n");
}

Word GetWord (Word w1, int a){
    Word w2;
    w2.Length=0;
    int i=0, j=0;

    while (i<w1.Length && w1.TabWord[i]==' '){
        i++;
    }

   while (j != a - 1 && i < w1.Length) {
        if (w1.TabWord[i] == ' ') {
            j++;
        }
        i++;
    }

    
    while (i < w1.Length) {
        if (w1.TabWord[i] == ' ') {
            break; 
        } else {
            w2.TabWord[w2.Length] = w1.TabWord[i];
            w2.Length++;
            i++;
        }
    }

    w2.TabWord[w2.Length] = '\0'; 
    return w2;
}

boolean isEqual(Word w, const char *c){
    int i = 0;

    while (c[i] != '\0') {
        i++;
    }
    int cnt = i;

    if (w.Length != cnt) {
        return false;
    }

    for (i = 0; i < w.Length; i++) {
        if (w.TabWord[i] != c[i]) {
            return false;
        }
    }
    return true;
}