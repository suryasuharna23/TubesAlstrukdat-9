// driverlogin.c
#include <stdio.h>
#include "login.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/User/user.h"



int main()
{
    
    ListUser users;
    users.count = 2;

    // Test user 1: alice/pass123
    for (int i = 0; "alice"[i] != '\0'; i++)
    {
        users.users[0].name[i] = "alice"[i];
    }
    users.users[0].name[5] = '\0';

    for (int i = 0; "pass123"[i] != '\0'; i++)
    {
        users.users[0].password[i] = "pass123"[i];
    }
    users.users[0].password[7] = '\0';

    // Test user 2: bob/pass456
    for (int i = 0; "bob"[i] != '\0'; i++)
    {
        users.users[1].name[i] = "bob"[i];
    }
    users.users[1].name[3] = '\0';

    for (int i = 0; "pass456"[i] != '\0'; i++)
    {
        users.users[1].password[i] = "pass456"[i];
    }
    users.users[1].password[7] = '\0';

    char currentUser[MAX_LEN] = "";

    printf("=== Driver Program Login ===\n\n");
    Login(&users, currentUser);
    Login(&users, currentUser);

    
    currentUser[0] = '\0';

    Login(&users, currentUser);
    Login(&users, currentUser);

    return 0;
}