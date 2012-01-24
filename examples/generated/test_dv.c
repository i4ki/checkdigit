#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dv.h"

int main(int argc, char** argv)
{
    FILE* fd;
    char buffer[13];
    size_t n;

    if (argc < 2)
    {
        fprintf(stdout, "usage: %s <file>\n", *argv);
        return 0;
    }

    fd = fopen(argv[1], "r");

    bzero(buffer, 13);
    while ((n = fread(buffer, sizeof(char), 13, fd)) > 0)
    {
        char processo_dv[13], processo[12];
        strncpy(processo_dv, buffer, 12);
        processo_dv[12] = '\0';  
        strncpy(processo,processo_dv,11);
        processo[11] = '\0';

        unsigned dv = dv_precatorio_sc(processo);

        char expected[13];
        sprintf(expected, "%s%d", processo, dv);

        if (!strcmp(expected, processo_dv))
        {
            printf("OK\n");
        } else {
            printf("processo '%s' deveria ser '%s'\n", expected, processo_dv);
        }
    }

    fclose(fd);

    return 0;
}
