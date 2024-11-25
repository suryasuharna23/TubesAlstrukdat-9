#include <stdio.h>
#include <stdlib.h>
#include "Boolean/boolean.h"
#include "ADT/Mesin/mesinkata.h"
#include "ADT/Mesin/mesinkarakter.h"
#include "ADT/User/user.h"
#include "ADT/Barang/barang.h"
#include "ADT/Queue/queue.h"
#include "command/Help/help.h"
#include "command/Load/load.h"
#include "command/Login/login.h"
#include "command/Logout/logout.h"
#include "command/Register/register.h"
#include "command/Work/work.h"
#include "command/Store/store.h"
#include "command/Tebak_Angka/tebak_angka.h"
#include "command/WORDL3/wordl3.h"
#include "command/Random_Number/random_number.h"
#include "command/Score/score.h"
#include "command/Quit/quit.h"
#include "command/Save/save.h"
#include "command/Score/score.h"
#include "command/Store/store.h"
#include "command/Start/start.h"
#include "ASCII/ASCII.h"

int main(void) {
    // Inisialisasi state program
    ArrayDinStore store; 
    CreateStore(&store,10);

    ListUser listuser;
    InitializeListUser(&listuser);

    Queue que;
    CreateQueue(&que);

    User u;
    CreateUser(&u, "", "", 0);

    printf("Input Menu (START/LOAD/QUIT/HELP):\n");
    while (true){
        printf(">> ");
        STARTINPUTWORD();
        
        if(isEqual(CurrentWord, "START")){
            start(&store, &listuser, "config/default.txt");
        }
    }
    
    return 0;
}