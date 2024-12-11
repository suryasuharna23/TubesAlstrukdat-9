#ifndef WISHLIST_H
#define WISHLIST_H

#include "../../ADT/Barang/barang.h"
#include "../../ADT/LinkedList/listlinier.h"

void wishlistAdd(List *L, ListBarang *listbarang);
void wishlistSwap(List *L, int idx1, int idx2);
void wishlistRemove(List *L);
void wishlistClear(List L, infotypes barang);
void wishlistShow(List L);

#endif
