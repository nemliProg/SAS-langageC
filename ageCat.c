#include <stdlib.h>
#include <stdio.h>

int main(){

    if(age < 3){
        printf("Bébé");
    }else if(age <15){
        printf("Enfant");
    }else if(age <20){
        printf("Adolescent");
    }else if(age <35){
        printf("jeune");
    }else if(age <65){
        printf("Mature");
    }else{
        printf("Vieux");
    }

    return 0;
}
