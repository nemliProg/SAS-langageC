#include<stdlib.h>
#include <stdio.h>

int main(){

    int t[50],currentValue,n,i,j;

    printf("entrer la taille :   \t");
    scanf("%d",&n);
    printf("Remplissage du tableau : \n");

    for(i=0;i<n;i++){

        printf("\tnombre N%d :\t",i+1);
        scanf("%d",&t[i]);
    }
    printf("Affichage avant le TRI:\n");

    for(i=0;i<n;i++){
        printf("%d \t",t[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        currentValue = t[i];
        j=i-1;
        while( j>=0 && t[j] > currentValue){
            t[j+1] = t[j];
            j--;
        }
        t[j+1] = currentValue;
    }
    printf("Affichage apres le TRI:\n");
    for(i=0;i<n;i++){
        printf("%d \t",t[i]);
    }






    return 0;
}
