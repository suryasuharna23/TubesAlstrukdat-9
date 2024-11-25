#include <stdio.h>
#include <stdlib.h>
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

void ADVSENTENCE(){
    IgnoreBlanks();
    if (currentChar == '\n'){
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

    //advance terus sampe ketemu huruf
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

/// @brief dapetin sentence
/// @param w1 word masukan
/// @param idx idx offset
/// @return word yang dimulai dari kata ke-idx
Word GetSentence(Word w1, int idx){
    Word w2; w2.Length = 0;
    int cursor = 0;

    // Ignoreblanks
    while (cursor < w1.Length && w1.TabWord[cursor] == ' ') {
        cursor++;
    }

    // Ignore kata ke-x
    int ignore = 0;
    char before = 'a';
    while (ignore < idx && cursor < w1.Length) {
        if (w1.TabWord[cursor] == ' ') {
            if (before != ' ') {
                ignore++;
            }
        }
        before = w1.TabWord[cursor];
        cursor++;
        
    }

    // Copy ke w2
    while (w1.TabWord[cursor] != '\0') {
        w2.TabWord[w2.Length] = w1.TabWord[cursor];
        w2.Length++;
        cursor++;
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

// CONVERTER //

char * WordToString (Word word){
    char* str = (char*)malloc((word.Length + 1) * sizeof(char));
    if (str == NULL) {
        return NULL; 
    }

    for (int i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[word.Length] = '\0'; 
    return str;
}


int WordToInt(Word word){
    int result = 0;
    for (int i = 0; i < word.Length; i++) {
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') {
            return 0; 
        }
        result = result * 10 + (word.TabWord[i] - '0');
    }
    return result;
}


Word StringtoWord (char*string){
    Word word;
    int i = 0;
    word.Length = 0;

    while (string[i] != '\0' && string[i] != BLANK && word.Length < NMax - 1) {
        word.TabWord[word.Length] = string[i];
        word.Length++;
        i++;
    }

    word.TabWord[word.Length] = '\0';

    return word;
}

boolean WordCompare(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}