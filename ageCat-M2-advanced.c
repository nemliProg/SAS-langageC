#include <stdlib.h>
#include <stdio.h>

int main(){

    int tranches[5] = {3,15,20,35,65};
    char tranchesName[6][30] = {"bebe","enfant","ado","jeune","mature","vieux"};
    int dif;
    int tIndex = -1;

    for(int i=0;i<5;i++){
        int dif = age - tranches[i];
        if(dif < 0){
            tIndex=i;
            break;
        }
    }

    if(tIndex == -1)
        printf("%s",tranchesName[5]);
    else{
        printf("%s",tranchesName[tIndex]);
    }


    return 0;
}
