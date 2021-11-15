#include <stdlib.h>
#include <stdio.h>

int main(){

    double n;

    printf("donner un nombre :\t");
    scanf("%lf",&n);

    if(n>0){
        printf("%.3f est positif \n",n);
    }else if(n<0){
        printf("%.3f est negatif \n",n);
    }else {
        printf("%.3f est nul \n",n);
    }



    return 0;
}
