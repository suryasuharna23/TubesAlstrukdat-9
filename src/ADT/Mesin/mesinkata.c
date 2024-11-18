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

