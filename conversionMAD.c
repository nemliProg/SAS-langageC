#include <stdlib.h>
#include <stdio.h>

int main(){

    double mad,mEUR,mUSD,mLB;
    const double eur = 0.09568;
    const double usd = 0.10964;
    const double lb = 0.08198;


    printf("\t\t\t\t### Younes Conversion ###\n\n");
    printf("\t\tmontant en MAD : ");
    scanf("%lf",&mad);
    printf("\n\n");
    mEUR = mad * eur ;
    mUSD = mad * usd ;
    mLB = mad * lb ;

    printf("\tmontant en MAD : %.5f mad \n",mad);
    printf("\tmontant en EUR : %.5f eur\n",mEUR);
    printf("\tmontant en USD : %.5f usd\n",mUSD);
    printf("\tmontant en Livre britannique : %.5f lb\n",mLB);



    return 0;
}
