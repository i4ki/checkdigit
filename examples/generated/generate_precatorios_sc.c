#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dv.h"

int main()
{
    int a,b,c,d,e,f;

    for (a = 0; a < 10; a++)
        for (b = 0; b < 10; b++)
            for (c = 0; c < 10; c++)
                for (d = 0; d < 10; d++)
                    for (e = 0; e < 10; e++)
                        for (f = 0; f < 10; f++)
                        {
                            char processo[13];
                            char tmp[12];
                            sprintf(tmp, "500%d%d00%d%d%d%d",a,b,c,d,e,f);
                            unsigned dv = dv_precatorio_sc(tmp);
                            sprintf(processo, "%s%d",tmp,dv);
                            printf("INSERT INTO sc.precatorios_generated (precatorio) VALUES ('%s');\n", processo);
                            //printf("%s\n",processo);
                        }

    return 0;
}
