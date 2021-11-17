#include <stdlib.h>
#include <stdio.h>

void logo();

int main()
{


    int t[1000],i=0,n,c=1;

    do{
        do{
            system("cls");
            logo();
            printf("\tDonner un nombre positif :  ");
            scanf("%d",&t[i]);
            system("cls");
            i++;
        }while(t[i-1] >= 0);
        system("cls");
        logo();
        printf("\n");
        printf("\t");
        printf("\t");



        for(int j=0;j<i-1;j++){
            printf("[%d]\t",t[j]);
        }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("press any number to continue and enter");
        scanf("%d");
        system("cls");
        printf("\t\t\t\tTry again\t\tYES:1 or NO:0 \t");
        scanf("%d",&c);

        printf("\n");
        printf("\n");
        printf("\n");
    }while(c==1);





    return 0;
}

void logo(){
    printf("\t\t\t\t #########################\n");
    printf("\t\t\t\t ##      EXERCICE 1     ##\n");
    printf("\t\t\t\t #########################\n\n\n");
};

