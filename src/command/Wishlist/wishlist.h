#ifndef WISHLIST_H
#define WISHLIST_H

#include "../../ADT/Barang/barang.h"
#include "../../ADT/LinkedList/listlinier.h"

void wishlistAdd(List *L, ListBarang *listbarang);
void wishlistSwap(List *L);
void wishlistRemove(List *L);
void wishlistClear(List *L);
void wishlistShow(List L);

#endif
