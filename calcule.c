#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc2n();
void eq1dedre();
void eq2degre();

int main()
{
//     #########programme d'un calcule###########
//  calculer tous les operation entre 2 nombres (1)
//  calculer equation de 1er degre              (2)
//  calculer equation de 2eme degre             (3)
//  quiter le programme                         (4)

    printf("### calcule ###");
    printf("\n");
    int choice;
    start :

    do{

        printf("######## MENU ########");
        printf("\n");
        printf("\t 1 : calculer 2 nombres \n");
        printf("\t 2 : calculer equation 1er degre \n");
        printf("\t 3 : calculer equation 2eme degre \n");
        printf("\t 4 : quiter le programme \n");

        printf("Choisissez un option s'il vous plait :\t");
        scanf("%d",&choice);

        switch(choice){
        case 1 :
            system("cls");
            calc2n();
            goto start;
            break;
        case 2 :
            system("cls");
            eq1degre();
            goto start;
            break;
        case 3 :
            system("cls");
            eq2degre();
            goto start;
            break;
        case 4 :

            break;
        }


    }while(choice != 4);

    return 0;
}
void eq2degre(){
    printf("\t***Equation deuxieme degre***\n");

    double a,b,c,delta,sol;
    printf("\tle nombre A ");
    scanf("%lf",&a);
    printf("\tle nombre B ");
    scanf("%lf",&b);
    printf("\tle nombre C ");
    scanf("%lf",&c);

    delta = pow(b,2) - 4 * a * c ;

    if(delta < 0){
        printf("\tAucune solution \n\n");
    }else if(delta == 0){

        sol = (-b)/ (2 * a);
        printf("\tun solution : x = %f \n\n",sol);

    }else{

        printf("\tdeux solutions : \n");
        sol = -b - sqrt(delta) / 2 * a;
        printf("\t\t X1 = %f ",sol);
        sol = -b + sqrt(delta) / 2 * a;
        printf("\t\t X2 = %f \n\n",sol);
    }


}
void eq1degre(){
    double a,b;
    printf("\t***Equation premier degre***\n");
    printf("\tle nombre A ");
    scanf("%lf",&a);
    if(a == 0){
        printf("\timposible");
    }else{
        printf("\tle nombre B ");
        scanf("%lf",&b);
    }

    double s = -b/a;

    printf("  %.0fx + (%.0f) = 0\n",a,b);
    printf("        %.0fx  = -(%.0f)\n",a,b);
    printf("          x  = -(%.0f) / %.0f\n",b,a);
    printf("          x  = %.2f \n",s);


}


void calc2n(){


    double n1,n2,res;
    char op;

    printf("\tEntrer le 1er nombre et le operateur et en fin le 2eme nombre\n");
    printf("\tle premier nombre\t");
    scanf("%lf",&n1);
    printf("\n");
    printf("\tl'operateur\t");
    scanf("%s",&op);
    printf("\n");
    printf("\tle douzième nombre\t");
    scanf("%lf",&n2);


    switch(op)
    {
    case '+':
        res = n1 + n2;
        break;
    case '-':
        res = n1 - n2;
        break;
    case '*':
        res = n1 * n2;
        break;
    case '/':
        res = n1 / n2;
        break;
    }


    printf("###############################");
    printf("\n");
    printf("\t\t %.2f %c %.2f = %.2f",n1,op,n2,res);
    printf("\n");
    printf("###############################");
}
