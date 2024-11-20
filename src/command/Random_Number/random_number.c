#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int randomNumber(int x){
    int rest;

    unsigned long long a = 1664525;
    unsigned long long c = 1013904223;
    unsigned long long m = pow(2, 32);

    if (x == 0){
        rest = time(NULL)*1000;
    } else {
        rest = (a*(randomNumber(x-1)) +c)%m;
    }

    if (rest < 0){
        rest *= (-1);
    }

    return rest;
}