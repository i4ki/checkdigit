#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "checkdigit.h"

#define ASCII_0 48
#define TESTCALLBACK(callback) \
    do { \
        count = 0; \
    for (i = 0; i < sz_n; i++)\
    {\
        char temp[15];\
        bzero(temp, 15);\
        strncpy(temp, numbers[i], 15);\
        uint8_t dv = getDV(temp);\
        char* number = getNumber(temp);\
        count += test_mod(dv, number, callback, #callback);\
    } \
        printf("===== " #callback " result =====\n"); \
        printf("acertos = %d\n\n", count); \
    }while(0)


unsigned test_mod(uint8_t, const char*, unsigned (*callback)(const char*), const char*);

typedef struct {
    char* number;
    uint8_t dv;
} num_dv;

const char numbers[][255] = {

#include "prc_numbers_sem_ano.h"

};

char* getNumber(char* number)
{
    number[strlen(number)-1] = '\0';
    return number;
}

uint8_t getDV(const char* number)
{
    uint8_t sz = strlen(number);
    return GETINT(number[sz-1]);
}

/* contador de acertos */
unsigned count = 0;

int main()
{
    int i;

    uint8_t sz_n = sizeof(numbers)/sizeof(*numbers);
    
//    TESTCALLBACK(mod11_impl1);
//    TESTCALLBACK(mod11_impl2);
//    TESTCALLBACK(mod11_reverse_impl1);
//    TESTCALLBACK(mod11_reverse_impl2);
    TESTCALLBACK(mod10_impl1);
//    TESTCALLBACK(mod10_impl2);


    return 0;

}

unsigned test_mod(uint8_t expected, const char* number, unsigned (*callback)(const char*), const char* algorithm_name)
{
    uint8_t v = callback(number);

    ASSERT_DV(v, expected, number, algorithm_name);

    return v == expected;
}

