#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK && !IsEOP()){
        ADV();
    }
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    if (IsEOP()){
        EndWord = true;
    }
    else{
        EndWord =false;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if (IsEOP()){
        EndWord = true;
    }
    else{
        CopyWord();
    }
}

void CopyWord(){
    int i=0;
    while ((currentChar != BLANK) && (currentChar != MARK) && (i<NMax)){
        CurrentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    CurrentWord.Length=i;
}

void PrintCurrentWord() {
    for (int i = 0; i < CurrentWord.Length; i++) {
        printf("%c", CurrentWord.TabWord[i]);
    }
    printf("\n");
}

