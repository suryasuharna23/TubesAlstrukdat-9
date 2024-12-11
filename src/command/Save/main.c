#include <stdio.h>
#include "save.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"

ListUser users;
ListBarang barangs;

int main() {
    // Initialize user and barang lists
    CreateListUser(&users);
    CreateListBarang(&barangs);

    // Add some users
    AddUser(&users, "Alice", "password123", 1000);
    AddUser(&users, "Bob", "securepass", 1500);
    AddUser(&users, "Persada", "securepass", 1500);
    AddUser(&users, "Izzudin", "securepass", 1500);
    AddUser(&users, "Baskara", "securepass", 1500);


    // Add some barang
    AddBarang(&barangs, "Laptop", 5000);
    AddBarang(&barangs, "Windah", 5000);
    AddBarang(&barangs, "Phone", 3000);
    AddBarang(&barangs, "Kuyang", 3000);
    AddBarang(&barangs, "Jalangkung", 3000);


    // Save data to file
    Save();

    return 0;
}