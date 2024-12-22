#include <stdio.h>
#include <stdlib.h>

void clear() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear"); 
#endif
}
