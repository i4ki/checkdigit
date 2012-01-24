#include <stdio.h>
#include <checkdigit.h>

int main()
{
    int a,b,c,d,e,y;

    for (y = 1998; y < 2012; y++)
    for (a = 0; a < 10; a++)
        for (b = 0; b < 10; b++)
            for (c = 0; c < 10; c++)
                for (d = 0; d < 10; d++)
                    for (e = 0; e < 10; e++) 
                    {
                        char processo[10];
                        sprintf(processo,"%d%d%d%d%d%d",y,a,b,c,d,e);
                        printf("INSERT INTO rj.precatorios_generated (precatorio) VALUES ('%s%d');\n", processo,mod11_impl2(processo));
                    }

    return 0;
}
