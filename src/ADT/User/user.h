#ifndef USER_H
#define USER_H

#define MAX_LEN 50 

#include "../../Boolean/boolean.h"
#include "../List/list.h"
#include "../Map/map.h"
#include "../Stack/stack.h"
#include "../LinkedList/listlinier.h"

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
    Map keranjang;
    Stack riwayat_pembelian;
    List wishlist;
} User;

typedef struct {
    User users[MAX_LEN];
    int count;
} ListUser;

extern ListUser users;
extern boolean IsLogin;

void CreateListUser(ListUser *users);
void CreateUser(User *CurrentUser);
void AddUser(ListUser *users, char *name, char *password, int money);
void InsertUser(ListUser *users, User user);
void AddMoney(User *user, int amount);
void TakeMoney(User *user, int amount);
boolean IsUserValid(ListUser *users, char *name, char *password);
boolean IsUserExist(ListUser *users, char *name);
int CountUser(ListUser *users);
int IndexUser(ListUser *users, char *name);
boolean WordCompare(const char *str1, const char *str2);
void InitCurrentUser(User *U);

#endif // USER_H
