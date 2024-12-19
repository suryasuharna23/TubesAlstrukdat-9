#include <stdio.h>
#include <stdlib.h>
#include "score.h"

int score(int m, int A) {
    int score = (A * m) + (randomNumber(10) % 10);
    return score;
}