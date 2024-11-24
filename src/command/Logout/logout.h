#ifndef LOGOUT_H
#define LOGOUT_H

#include "../../Boolean/boolean.h"

typedef struct
{
    char name[50];
    char password[50];
    int money;
    boolean is_logged_in; 
} User;

void logout(User *current_user);
#endif