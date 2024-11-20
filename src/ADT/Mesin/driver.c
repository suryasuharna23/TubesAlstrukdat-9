#include "mesinkata.h"
//#include "mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char *file = "teks.txt";

    printf("----TES MESIN KATA----\n");

    printf("Tes START dari file\n");
    STARTWORD(file);
    while (!EndWord) {
        PrintCurrentWord();
        ADVWORD();
    }

    printf("Tes START dari INPUT\n");
    STARTINPUTWORD();
    PrintCurrentWord();

    printf("Tes GetWord dan isEqual\n");
    
    STARTINPUTWORD();
    Word w = GetWord(CurrentWord, 1);
    if (isEqual(w, "hai!")){
        printf("hai jg\n");
    }
    else{
        printf("ga sama\n");
    }

    printf("Tes string to word\n");
    char input[]="123";
    Word word = StringtoWord(input); // ga ada printnya karena tipe datanya word
    printf("berhasil dah\n");

    printf("Tes word ke string\n");
    char *str = WordToString(word);
    printf("%s\n", str);

    printf("Tes word ke integer\n");
    int num = WordToInt(word);
    printf("%d\n", num);

    free(str);
    

    return 0;
}