#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functii.h"
#include "structuri.h"

int main()
{
    int numar_total_bilete,q,i,y;//calculez numarul de bilete care au fost puse
    //un numar intre 100.000 si 1.000.000
    srand(time(NULL));
    numar_total_bilete=rand()%10;
    if(numar_total_bilete==0)
        numar_total_bilete=1000000;
    else
    {
        numar_total_bilete=numar_total_bilete*10;
        for(i=1;i<5;i++)
            {
                q=rand()%10;
                numar_total_bilete=numar_total_bilete+q;
                numar_total_bilete=numar_total_bilete*10;
            }
    }
    printf("numarul de bilete inscrise este: %d \n",numar_total_bilete);
    generare_bilete(numar_total_bilete);
    extragerea_numerelor_castigatoare(numar_total_bilete);
    cas(numar_total_bilete);
    return 0;
}
