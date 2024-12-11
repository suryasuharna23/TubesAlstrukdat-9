#include <stdio.h>
#include <stdlib.h>
#include "score.h"

int randomNumber(int max) {
    return rand() % max;
}

int score(int m, int A) {
    int score = (A * m) + randomNumber(10);
    return score;
}