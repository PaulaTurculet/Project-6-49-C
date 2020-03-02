#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include "structuri.h"
int cauta(int v[],int j,int x)//functia verifica daca in bilete exista doua numere la fel dintre cele 6
{
    int i;
    for (i=1;i<j;i++)
        if(v[i]==x)
            return 0;
    return 1;
}
void sort(int v[],int n)//sorteaza numerele din bilete
{
    int sort=1,i,aux=0;
    do{
        sort=1;
        for(i=1;i<n;i++)
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                sort=0;
            }
    }while(sort==0);
}
int cate_numere_castigatoare(int a[],int b[])//verifica cate numere castigatoare sunt in fiecare bilet
{
    int i=1,j=1,nr=0;
    while(i<=MAXBILET && j<=MAXBILET)
    {
        while(a[i]<b[j] && i<7)
            i++;
        while(b[j]<a[i] && j<7)
            j++;
        if(a[i]==b[j])
        {
            nr++;
            i++;
            j++;
        }
    }
    return nr;
}
int castiguri(struct bilet* bi ,int b)
{
    int a=(*bi).pret*b;
    return a;
}
void generare_bilete(int m)//creez biletele in fisier si le sortez
{
    int p=1,i,j,r,x;
    FILE *f;
    f=fopen("innput.txt","r+");
    if(f==NULL)
    {
        printf("fisierul nu exista");
        f=fopen("innput.txt","w");
    }
    if(f==NULL)
    {
        printf("nu se poate");
        return ;
    }

    struct bilet B;
    for(j=1;j<=m;j++)
    {
        for( i=1;i<=6;i++)
            {
                 r=rand()%49+1;
                 B.numerele_biletului[i]=r;
                 while(cauta(B.numerele_biletului,i,r)==0)
                        r=rand()%49+1;
                 B.numerele_biletului[i]=r;
            }
        sort(B.numerele_biletului,MAXBILET);
        for(i=1;i<=MAXBILET;i++)
            fprintf(f,"%d ",B.numerele_biletului[i]);
        fprintf(f,"\n");
      }


}
void extragerea_numerelor_castigatoare(int numar_total_bilete)//generez in vegtorul castig cele 6 numere castigatoare le sortez
{
    int i,r,castig[7],v[7],j,k,valori[7]={0},x,report=0;
    for(i=1;i<=MAXBILET;i++)
    {
        r=rand()%49+1;
        castig[i]=r;
        while(cauta(castig,i,r)==0)
            r=rand()%49+1;
        castig[i]=r;
    }
    printf("numerele castigatoare sunt\n");
    for(i=1;i<=MAXBILET;i++)
    {
        sort(castig,MAXBILET);
        printf("%d ",castig[i]);
    }
    printf("\n");
    printf("   ________________________________________________________");
    printf("\n");
    printf("   | CATEGORIE | Numar castiguri | Valoare castig |");

    printf("\n");
    printf("   ________________________________________________________");
    printf("\n");
    printf("\n");
    FILE *f;
    f=fopen("innput.txt","r");
    fseek(f,0,SEEK_SET); //ma plasez la inceputul fisierului
    for(i=1;i<=numar_total_bilete;i++)
    {
        for(j=1;j<=MAXBILET;j++)
        {
            fscanf(f,"%d",&x);
            v[j]=x;
        }
       // fseek(f,0,SEEK_CUR);
        k=cate_numere_castigatoare( castig,v);  //k retine cate nr castigatoare sunt de fiecare fel
        valori[k]++;
    }

    for(i=3;i<=MAXBILET;i++)
       {

            if(i==3)
            printf("   |     %d             %d        30,00 ",i,valori[i]);
            if(i==4)
            printf("   |     %d             %d         488,00 ",i,valori[i]);
            if(i==5)
            printf("   |     %d             %d          85.000,00 ",i,valori[i]);
            if(i==6)
                if(valori[i]==0)
                    printf("   |     %d             REPORT      255.145,10     ",i);
                else
                    printf("   |     %d             %d       255.145,10 ",i,valori[i]);
            printf("\n");
       }



}
void cas(int num)
{
    int y;
    struct bilet b;
    b.pret=1;
    y=castiguri(&b,num);
    printf("\n");
    printf("  |________________________________________________________|");
    printf("\n");
    printf("             FOND TOTAL DE CASTIGURI %d lei",y);
    printf("\n");
    printf("  |________________________________________________________|");
}


#endif // FUNCTII_H_INCLUDED
