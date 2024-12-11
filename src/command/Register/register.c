#include <stdio.h>
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/User/user.h"

void RegisterUser(ListUser *users, boolean *flag) {
    Word username;
    Word password;
    boolean blank_exist, valid;
    int i;

    // Input username
    printf("Enter your username: ");
    blank_exist = true;
    valid = false;
    while (blank_exist || !valid) {
        STARTINPUTWORD();
        username = CurrentWord;
        blank_exist = IsBlankExist(username);
        valid = IsLetterOrDigit(username);
        if (blank_exist || !valid) {
            printf("Username contains invalid characters. Try again!\nEnter your username: ");
        } else if (username.Length == 0) {
            printf("Username cannot be empty. Try again!\nEnter your username: ");
            valid = false;
        } else {
            break;
        }
    }

    // Input password
    printf("Enter your password: ");
    blank_exist = true;
    valid = false;
    while (blank_exist || !valid) {
        STARTINPUTWORD();
        password = CurrentWord;
        blank_exist = IsBlankExist(password);
        if (blank_exist) {
            printf("Password contains spaces. Try again!\nEnter your password: ");
        } else if (password.Length == 0) {
            printf("Password cannot be empty. Try again!\nEnter your password: ");
            valid = false;
        } else {
            break;
        }
    }

    // Add new user with money set to 0
    AddUser(users, WordToString(username), WordToString(password), 0);
    printf("User %s registered.\n", WordToString(username));
    *flag = true;
}