#include <stdio.h>
#include "logout.h"


void logout(User *current_user)
{
    // Validasi apakah ada pengguna yang sedang login
    if (current_user != NULL && current_user->is_logged_in)
    {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", current_user->name);
        // Set status pengguna menjadi tidak login
        current_user->is_logged_in = false;
    }
    else
    {
        // Jika tidak ada pengguna yang sedang login
        printf("Tidak ada pengguna yang sedang login.\n");
    }
}