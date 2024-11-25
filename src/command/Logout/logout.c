#include <stdio.h>
#include "logout.h"


void logout(User *current_user)
{
    if (current_user != NULL && current_user->is_logged_in)
    {
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", current_user->name);
        current_user->is_logged_in = false;
    }
    else
    {
        printf("Tidak ada pengguna yang sedang login.\n");
    }
}