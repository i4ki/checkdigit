#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dv.h"

unsigned dv_precatorio_sc(char processo[12])
{
   int i;
#define ASCII_0 48

   unsigned short c = 9;
   unsigned soma = 0;
   for (i = strlen(processo)-1; i >= 0; i--)
   {
        int num = processo[i] - ASCII_0;
        if (num < 0 || num > 9)
        {
            fprintf(stderr, "error ... out of range ... only digits in process number\n");
            exit(1);
        }
        soma += num * c;
        c = (c == 1) ? 9 : c-1;
   }

   int dv = (soma % 11);
   return dv ? dv - 1 : dv;
}

