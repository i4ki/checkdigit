#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkdigit.h"

#define O_ASC 0x01
#define O_DESC 0x02

unsigned dv_precatorio_sc(char processo[12])
{
   int i;

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

   unsigned dv = (soma % 11);
   return dv ? dv - 1 : dv;
}

unsigned mod11_generic(const char* number, unsigned endc, unsigned order)
{
    unsigned number_len = strlen(number);
    unsigned short c = 9;
    unsigned soma = 0;
    int i;

    for (   i = (order == O_DESC) ? (number_len - 1) : 0; 
            (order == O_DESC) ? (i >= 0) : (i < number_len); 
            (order == O_DESC) ? (i--) : (i++))
    {
        unsigned num = number[i] - ASCII_0;
        if (num < 0 || num > 9)
        {
            fprintf(stderr, "error, number out of digit range\n");
            exit(1);
        }

        soma += num * c;
        c = c == endc ? 9 : c - 1;
    }

    unsigned ret = soma % 11;

    return ret == 10 ? 0 : ret;
}

unsigned mod11_impl1(const char* number)
{
    return mod11_generic(number, 1, O_DESC);
}

unsigned mod11_impl2(const char* number)
{
    return mod11_generic(number, 2, O_DESC);
}

unsigned mod11_reverse_impl1(const char* number)
{
    return mod11_generic(number, 1, O_ASC);
}

unsigned mod11_reverse_impl2(const char* number)
{
    return mod11_generic(number, 2, O_ASC);
}

unsigned mod10_generic(const char* number, unsigned short initc)
{
    unsigned number_len = strlen(number);
    unsigned short c = initc;
    unsigned soma = 0;
    int i;

    for (i = number_len - 1; i >= 0; i--)
    {
        unsigned num = GETINT(number[i]);

        if (num < 0 || num > 9)
            THROW_ERROR_RANGE(num);
    
        soma += num * c;
        
        c = c == 1 ? 2 : 1;
    }

    return ((soma > 10 && soma < 100) ? (soma % 10) : (soma < 10) ? (soma) : (soma % 100));
}

unsigned mod10_impl1(const char* number)
{
    return mod10_generic(number, 1);
}

unsigned mod10_impl2(const char* number)
{
    return mod10_generic(number, 2);
}



