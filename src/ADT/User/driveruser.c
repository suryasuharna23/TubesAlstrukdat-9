#include <stdio.h>
#include "user.h"

void PrintUser(User *user) {
    printf("Name: %s\n", user->name);
    printf("Password: %s\n", user->password);
    printf("Money: %d\n", user->money);
}

int main() {
    ListUser users;
    CreateListUser(&users);

    User user1, user2, user3;

    AddUser(&users, "surya", "securepass", 500);
    AddUser(&users, "suharna", "securepass", 400);
    AddUser(&users, "surya suharna", "securepassssssssssssssssssssssssssssssssssssssssssssssssssssss", 100);

    printf("Users created successfully:\n");
    
    for (int i = 0; i < CountUser(&users); i++) {
        PrintUser(&users.users[i]);
        printf("\n");
    }

    return 0;
}
