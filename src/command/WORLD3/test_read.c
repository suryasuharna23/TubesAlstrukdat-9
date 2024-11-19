#include <stdio.h>
#include "world3.h"

int main(){
    int idx;

    scanf("%d", &idx);

    char *file = "word_list.txt";

    READLINE(file, idx);
    PrintCurrentWord();

    return 0;
}