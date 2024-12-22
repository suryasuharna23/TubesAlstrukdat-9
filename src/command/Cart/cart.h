#ifndef CART_H
#define CART_H

#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"

void CartAdd(User *CurrentUser, ListBarang *listbarang);
void CartRemove(User *CurrentUser, ListBarang *listbarang);
void CartShow(User *CurrentUser, ListBarang *listbarang);
void CartPay(User *CurrentUser, ListBarang *listbarang);
Word GetLastWord(Word command);
Word GetItemNameFromCommand(Word command);

#endif // CART_H