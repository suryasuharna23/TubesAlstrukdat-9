#include <stdio.h>
#include "boolean.h"

boolean IsLoad(char *file) {
    FILE *check = fopen(file, "r"); // mode "read"
    if (check == NULL) {
        return false; 
    } else {
        fclose(check); 
        return true;   
    }
}