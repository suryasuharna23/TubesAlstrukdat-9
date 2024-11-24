#include <stdio.h>
#include <stdlib.h>
#include "ADT/Mesin/mesinkata.h"
#include "ADT/Mesin/mesinkarakter.h"
#include "ADT/User/user.h"
#include "ADT/Barang/barang.h"
#include "ADT/Queue/queue.h"
#include "command/Help/help.h"
#include "command/Load/load.h"
#include "command/Login/login.h"
#include "command/Register/register.h"
#include "command/Work/work.h"
#include "command/Store/store.h"
#include "command/QUANTUMWORDL3/QuantumWordl3.h"
#include "command/Tebak_Angka/tebak_angka.h"
#include "command/WORDL3/wordl3.h"
#include "command/Random_Number/random_number.h"    
#include "command/Score/score.h"
#include "command/Quit/quit.h"
#include "command/Save/save.h"
#include "command/Score/score.h"
#include "command/Store/store.h"

int main(){
    while(true){
        print(">>");
        STARTINPUTWORD();

        if (isEqual(CurrentWord,"START")){
            printf("Valid");
        }
        
    }
}


