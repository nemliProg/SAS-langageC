#include <stdlib.h>
#include <stdio.h>
int main(){
    int n1,n2;

    printf("1er nombre :\t");
    scanf("%d",&n1);
    printf("2eme nombre :\t");
    scanf("%d",&n2);

    if(n1>n2){
        printf("%d \n",n1);
    }else{
        printf("%d \n",n2);
    }

    return 0;
}
