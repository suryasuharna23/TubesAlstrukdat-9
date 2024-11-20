#include <stdio.h>
#include "score.h"

int score(int m, int A){
    int score = (A * m) + (randomNumber(3) % 10);

    return score;
}