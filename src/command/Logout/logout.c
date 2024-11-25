#include <stdio.h>
#include "logout.h"

void logout(char *current_user)
{
    if (current_user == NULL || current_user[0] == '\0')
    {
        printf("Tidak ada pengguna yang sedang login.\n");
        return;
    }

    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", current_user);
    current_user[0] = '\0';
}