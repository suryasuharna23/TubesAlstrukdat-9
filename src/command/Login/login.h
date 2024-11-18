#ifndef LOGIN_H
#define LOGIN_H

typedef struct {
    char username[50];
    char password[50];
} User;

extern User users[];
extern int userCount;

void loginUser();
void logoutUser();

#endif