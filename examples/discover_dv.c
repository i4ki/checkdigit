#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "checkdigit.h"

void test_mod11_generic(uint8_t expected, const char* s);
void test_mod11(uint8_t, const char*, unsigned (*callback)(const char*), const char*);

#define NUM_ELEM 2

typedef struct {
    char *number;
    unsigned short dv;
} num_dv;

static num_dv n_dv[NUM_ELEM] = {
    {"252244",9},
    {"925507",6}
};

int main()
{
    int i;
    for (i = 0; i < NUM_ELEM; i++)
    {
        test_mod11(n_dv[i].dv, n_dv[i].number, mod11_generic, "mod11_generic");
        //test_mod11(n_dv[i].dv, n_dv[i].number, mod11_generic, "mod11_generic");
        //test_mod11(n_dv[i].dv, processo, mod11_impl2, "mod11_impl2");
        //test_mod11(n_dv[i].dv, n_dv[i].number, mod11_impl2, "mod11_impl2");
    }

    return 0;
}

void test_mod11_generic(uint8_t expected, const char* number)
{
    uint8_t v = mod11_generic(number);

    ASSERT_DV(v, expected, number);
}

void test_mod11(uint8_t expected, const char* number, unsigned (*callback)(const char*), const char* algorithm_name)
{
    uint8_t v = callback(number);

    ASSERT_DV(v, expected, number, algorithm_name);
}

