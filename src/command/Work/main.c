#include <stdio.h>
#include "../../ADT/User/user.h"
#include "work.h"

int main() {
    // Inisialisasi pengguna
    User currentUser;
    CreateUser(&currentUser, "johndoe", "janedoe", 500); // mungkin ini akan dihapus di program keseluruhannya

    // Menampilkan informasi awal
    printf("Informasi User Sebelum Bekerja:\n");
    PrintUser(&currentUser);

    // Memulai fitur WORK
    work(&currentUser);

    // Menampilkan informasi setelah bekerja
    printf("\nInformasi User Setelah Bekerja:\n");
    PrintUser(&currentUser);

    return 0;
}
