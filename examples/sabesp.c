#include <stdio.h>
#include <stdlib.h>
#include "checkdigit.h"

int main()
{
    int a,b,c,d,e;
    for (a = 4; a < 6; a++)
    for (b = 0; b < 10; b++)
    for (c = 0; c < 10; c++)
    for (d = 0; d < 10; d++)
    for (e = 0; e < 10; e++)
    {
        char number[9];
        sprintf(number, "024%d%d%d%d%d", a, b, c, d, e);
        char number2[10];
        unsigned dv1 = mod11_impl1(number);
        sprintf(number2, "%s%d", number, dv1);
        unsigned dv2 = mod11_impl1(number2);
        printf("insert into sabesp values ('%s%d%d');\n", number, dv1, dv2);
    }

    return 0;
}



