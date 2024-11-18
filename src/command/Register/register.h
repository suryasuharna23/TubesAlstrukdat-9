#ifndef REGISTER_H
#define REGISTER_H

typedef struct {
    char username[50];
    char password[50];
} User;

void registerUser();

#endif