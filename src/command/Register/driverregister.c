#include <stdio.h>
#include "register.h"

#define MAX_USERS 10

// gcc driverregister.c register.c ../../ADT/Mesin/mesinkarakter.c ../../ADT/Mesin/mesinkata.c  ../../ADT/User/user.c -o driverregister
int main()
{
    // Inisialisasi ListUser
    ListUser users;
    users.count = 0;

    // Tambahkan beberapa pengguna awal untuk pengujian
    for (int i = 0; i < 2; i++)
    {
        sprintf(users.users[i].name, "user%d", i + 1);     // Username awal
        sprintf(users.users[i].password, "pass%d", i + 1); // Password awal
        users.users[i].money = 1000 * (i + 1);             // Saldo awal
        users.count++;
    }

    // Tampilkan daftar pengguna saat ini
    printf("Daftar pengguna awal:\n");
    for (int i = 0; i < users.count; i++)
    {
        printf("User %d: %s, Password: %s, Money: %d\n", i + 1,
                users.users[i].name,
                users.users[i].password,
                users.users[i].money);
    }

    printf("\n--- Mulai Proses Registrasi ---\n");

    // Skenario 1: Pendaftaran pengguna baru yang valid
    printf("\nSkenario 1: Pendaftaran pengguna baru yang valid\n");
    registerUser(&users);

    // Skenario 2: Pendaftaran dengan username yang sudah ada
    printf("\nSkenario 2: Pendaftaran dengan username yang sudah ada\n");
    registerUser(&users);

    // Skenario 3: Kapasitas penuh
    printf("\nSkenario 3: Kapasitas penuh\n");
    while (users.count < MAX_USERS)
    {
        printf("[DEBUG] Menambahkan pengguna ke-%d untuk mengisi kapasitas\n", users.count + 1);
        registerUser(&users);
    }

    printf("\n[DEBUG] Daftar pengguna setelah penuh:\n");
    for (int i = 0; i < users.count; i++)
    {
        printf("User %d: %s, Password: %s, Money: %d\n", i + 1,
            users.users[i].name,
            users.users[i].password,
            users.users[i].money);
    }

    // Skenario 4: Tambahan pengguna saat penuh
    printf("\nSkenario 4: Pendaftaran saat kapasitas penuh\n");
    registerUser(&users);

    return 0;
}
