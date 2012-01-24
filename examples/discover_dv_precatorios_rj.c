#include <stdio.h>
#include <stdlib.h>
#include "checkdigit.h"

void test_mod11_generic(unsigned short int expected, const char* s);
void test_mod11(unsigned short int, const char*, unsigned (*callback)(const char*), const char*);

typedef struct {
    char* year;
    char* number;
    unsigned short int dv;
} num_dv;

#define NUM_ELEM 12
static num_dv n_dv[NUM_ELEM] = {
    {"1998","03463",9},
    {"1998","00456",0},
    {"1998","00461",6},
    {"1998","00465",9},
    {"1998","00466",7},
    {"1998","00467",5},
    {"1998","00468",3},
    {"1999","00489",0},
    {"1999","03536",1},
    {"1999","00516",0},
    {"1999","00517",9},
    {"1999","00532",2}
};

int main()
{
    int i;
    for (i = 0; i < NUM_ELEM; i++)
    {
        char processo[10];
        sprintf(processo, "%s%s", n_dv[i].year, n_dv[i].number);
        //test_mod11(n_dv[i].dv, processo, mod11_generic, "mod11_generic");
        //test_mod11(n_dv[i].dv, n_dv[i].number, mod11_generic, "mod11_generic");
        test_mod11(n_dv[i].dv, processo, mod11_impl2, "mod11_impl2");
        //test_mod11(n_dv[i].dv, n_dv[i].number, mod11_impl2, "mod11_impl2");
    }

    return 0;
}

void test_mod11_generic(unsigned short int expected, const char* number)
{
    unsigned short int v = mod11_generic(number);

//    ASSERT_DV(v, expected, number);
}

void test_mod11(unsigned short int expected, const char* number, unsigned (*callback)(const char*), const char* algorithm_name)
{
    unsigned short int v = callback(number);

    ASSERT_DV(v, expected, number, algorithm_name);
}

