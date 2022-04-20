#include "print.h"

int print(const char* str)
{
    write(1, str, strlen(str));
    return (0);
}