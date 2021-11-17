#include <stdlib.h>
#include <stdio.h>

void remplirT(float T[],int taille);
void searchN(float T[],int taille,float n);
void afficheT(float T[],int taille);
void triParInsertion(int T[],int taille);

int main()
{

    float t[50];
    int n;
    float g;
    printf("donner la taille du tableau \t");
    scanf("%d",&n);

    remplirT(t,n);



    printf("donner un nombre \t");
    scanf("%f",&g);

    searchN(t,n,g);

    printf("Affichage avant le tri");
    afficheT(t,n);

    triParInsertion(t,n);

    printf("Affichage apres le tri");
    afficheT(t,n);

    return 0;
}

void remplirT(float T[],int taille)
{

    for(int i = 0 ; i<taille ; i++)
    {
        printf("donner T[%d] \n",i+1);
        scanf("%f",&T[i]);
    }


}

void searchN(float T[],int taille,float n)
{
    int c=0;
    for(int i=0; i<taille; i++)
    {
        if(T[i] == n)
        {
            c++;
        }
    }

    if(c==0)
    {
        printf("non Trouve\n");
    }
    else
    {
        printf("Trouve\n");
    }
}
void afficheT(float T[],int taille)
{
    int i = 0;
    while(i<taille){
        printf("%.2f\t",T[i]);
        i++;
    }
    printf("\n");
}

void triParInsertion(int T[],int taille)
{
    int i,j,currentValue;
    for(i=1; i<taille; i++)
    {
        currentValue = T[i];
        j=i-1;
        while( j>=0 && T[j] > currentValue)
        {
            T[j+1] = T[j];
            j--;
        }
        T[j+1] = currentValue;
    }


}

