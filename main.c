#include <stdio.h>
#include <stdlib.h>

int main()
{
    // programme qui g�re les mati�res et les note d'un �l�ve
    // Entrez le nombre des mati�res
    // et les nom des mati�res
    // et la note de chaque mati�res
    // resultat : -la somme des notes
    //            -la moyenne des notes

    printf("nombre des matieres");
    int n ;
    scanf("%d",&n);

    char mat[n][30];
    int notes[n];

    float moy=0,som=0;
    printf("donner les matieres\n");
    for(int i = 0;i<n;i++){
        printf("la matiere nombre %d \n",i+1);
        scanf("%s",mat[i]);
    }
    printf("donner moi les notes de chaque matiere\n");
    for(int j = 0;j<n;j++){
        printf("la note de %s \n",mat[j]);
        scanf("%d",&notes[j]);
        som += notes[j];
    }
    moy = som / n;

    for(int i = 0;i<n;i++){
        printf("%s : %d \n",mat[i],notes[i]);

    }
    printf("la somme des notes est : %.2f \n",som);
    printf("la moyenne des notes est : %.2f",moy);



    return 0;
}
