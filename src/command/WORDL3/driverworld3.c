#include <stdio.h>
#include "wordl3.h"

/* cara compile
cd C:\TUBES_ALSTRUKDEAD\TubesAlstrukdat-9\src\command\WORDL3
gcc driverworld3.c wordl3.c ../../ADT/Mesin/mesinkarakter.c ../../ADT/Mesin/mesinkata.c ../Random_Number/random_number.c ../../command/Score/score.c -o main
*/

int main(){
    int game = 2;

    if (game == 2){
        User user; 
        
        wordl3_challenge(user);
    }

    return 0;
}