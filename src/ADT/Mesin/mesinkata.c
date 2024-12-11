#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
    while (GetCC() == BLANK && !IsEOP() && GetCC() == NL){
        ADV();
    }
}

void STARTWORD(char *FILE){
    START(FILE);
    IgnoreBlanks();
    if (EOP){
        EndWord = true;
    }
    else{
        EndWord =false;
        CopyWord();
    }
}

void STARTINPUTWORD() {
    int i = 0;
    char c = getchar();
    while (c != '\n' && c != EOF && i < NMax - 1) {
        CurrentWord.TabWord[i] = c;
        i++;
        c = getchar();
    }
    CurrentWord.TabWord[i] = '\0';
    CurrentWord.Length = i;
    EndWord = (i == 0);
}

void ADVWORD() {
    IgnoreBlanks();  // Abaikan spasi

    if (EOP) {  // Jika sudah mencapai akhir input
        EndWord = true;
    } else {
        CopyWord();  // Salin kata baru jika ada
    }
}


void ADVSENTENCE(){
    IgnoreBlanks();
    if (CurrentChar == '\n'){
        EndWord = true;
    }
    else{
        CopyWord();
    }
} // Ga surya pake

void CopyWord(){
    int i=0;
    while (GetCC() != BLANK && GetCC() != LN && !IsEOP() && i<NMax){
        CurrentWord.TabWord[i] = GetCC();
        i++;
        ADV();
    }
    CurrentWord.Length=i;
    if (CurrentWord.TabWord[i]=='\0');
}

void PrintCurrentWord() {
    for (int i = 0; i < CurrentWord.Length; i++) {
        printf("%c", CurrentWord.TabWord[i]);
    }
    printf("\n");
} // surya gak pake

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
} // surya gak pake

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
} // surya gak pake

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

char *WordToString (Word word){
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

void GetLine(){
    int i = 0;
    START(NULL);
    while(GetCC() != LN){
        CurrentWord.TabWord[i] = GetCC();
        ADVIgnoreLN();
        i++;
    }
    CurrentWord.TabWord[i] = '\0';
    CurrentWord.Length = i;
}

void StringCopy(char *str1, char *str2){
    int i = 0;
    while (str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

void StringConcat(char *str1, char *str2){
    int i = 0;
    while (str1[i] != '\0'){
        i++;
    }
    int j = 0;
    while (str2[j] != '\0'){
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}



void STARTINPUT() {
    START(NULL);
    IgnoreBlanks();
    if (CurrentChar == '\n' || CurrentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVIgnoreLN() {
    IgnoreBlanks();
    if (CurrentChar == '\n') {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

boolean IsBlankExist(Word word) {
    for (int i = 0; i < word.Length; i++) {
        if (word.TabWord[i] == BLANK) {
            return true;
        }
    }
    return false;
}

boolean IsLetterOrDigit(Word word) {
    for (int i = 0; i < word.Length; i++) {
        if (!isalnum(word.TabWord[i])) {
            return false;
        }
    }
    return true;
}