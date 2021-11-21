#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void nominees(char tab[20][50],int taille);
void initialiserVotesToZero(int votes[20],int taille);
void collecteVotes(int nbNomin,int nbElec,char nomN[20][50],char idE[200][10],int nominVotes[20]);
int egalite(int nbNomin,int nominVotes[20]);
void trophe();
int main()
{


    printf("\n\t\t\t\t\t\tElection Presidentielle\n\n\n");

    int nbN,nbE;
    int test=0;

    do{
        if(test==0){
    printf("\t\tdonner le nombre des nominees : ");
    scanf("%d",&nbN);
        }else{
            printf("\t\tle minimum 5,donner le nombre des nominees :\t");
            scanf("%d",&nbN);
        }
        test++;
    }while(nbN<5);

    test=0;
    do{
        if(test==0){
    printf("\t\tdonner le nombre des electeurs : ");
    scanf("%d",&nbE);
        }else{
            printf("le minimum 10,donner le nombre des electeurs :\t");
            scanf("%d",&nbE);
        }
        test++;
    }while(nbE<10);

    char nameN [20][50],cinE [200][10],nameN2 [20][50];
    int i,j;
    for(i=0; i<nbN; i++)
    {
        printf("\t\tdonner le nom de Nominee N-%d :",i+1);
        scanf("%s",&nameN[i]);
    }
    for(i=0; i<nbE; i++)
    {
        printf("\t\tdonner le nom de Electeur N-%d :",i+1);
        scanf("%s",&cinE[i]);
    }
    int nomineesVotes[20];
    float nomineesVotesPercent[20];
//    premiere tour
    tour1 :

    system("cls");
    printf("\n\t\t\t\t\t\tElection Presidentielle\n\n\n");
    printf("\n\t\t\t\tPremiere TOUR\n\n");
    collecteVotes(nbN,nbE,nameN,cinE,nomineesVotes);

    for(i=0;i<nbN;i++){
         printf("%s : %d votes. \n",nameN[i],nomineesVotes[i]);

    }
    
    int tst = egalite(nbN,nomineesVotes);
    
    if(tst == 1){
	    goto tour1;
	}

//    calcul %
    int c = 0;
    for(i=0;i<nbN;i++){
        nomineesVotesPercent[i] = (((float) nomineesVotes[i])/ (float)nbE)*100;
        if(nomineesVotesPercent[i] >= 15){
            strcpy(nameN2[c],nameN[i]);
            c++;
        }
    }
//    left
    nbN = c;


//	2eme TOUR
    tour2:
    system("cls");
    printf("\n\t\t\t\t\t\tElection Presidentielle\n\n\n");
    printf("\n\t\t\t\tDouxieme TOUR\n\n");
    collecteVotes(nbN,nbE,nameN2,cinE,nomineesVotes);
    
    test = egalite(nbN,nomineesVotes);
    
    if(test == 1){
	    goto tour2;
	}
    
	int minIndex = 0 ;
	int min = nomineesVotes[0];
	for(i=1;i<nbN;i++){
        if(min > nomineesVotes[i]){
        	min = nomineesVotes[i];
        	minIndex = i;
		}
    }
    
    for(i=minIndex;i<nbN;i++){
        strcpy(nameN2[i],nameN2[i+1]);
    }
	nbN--;
	
//	3eme TOUR
	tour3 :
		
	system("cls");
    printf("\n\t\t\t\t\t\tElection Presidentielle\n\n\n");
    printf("\n\t\t\t\tTroisieme TOUR\n\n");
    collecteVotes(nbN,nbE,nameN2,cinE,nomineesVotes);
    
	int maxIndex = 0 ;
	int max = nomineesVotes[0];
	for(i=1;i<nbN;i++){
        if(max < nomineesVotes[i]){
        	max = nomineesVotes[i];
        	maxIndex = i;
		}
    }
    
    int count = 0;
    for(i=1;i<nbN;i++){
        if(max == nomineesVotes[i]){
        	count++;
		}
    }
	
	if(count > 1){
		goto tour3;
	}
    
	strcpy(nameN2[0],nameN2[maxIndex]);
	nomineesVotes[0] = nomineesVotes[maxIndex];
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t\tTHE WINNER IS %s with %d \n\n",nameN2[0],nomineesVotes[0]);
	trophe();
	
	
    return 0;
}

void nominees(char tab[20][50],int taille)
{
    printf("\t\t\t Tableau des nominees\n");
    int i;
    for(i=0; i<taille; i++)
    {
        printf("\t%s : choisis %d . \n",tab[i],i+1);
        printf("__________________________________________\n");
    }

}

void initialiserVotesToZero(int votes[20],int taille)
{
	int i;
    for(i=0; i<taille; i++)
    {
        votes[i]=0;
    }

}

int egalite(int nbNomin,int nominVotes[20]){
    	int count = 0,i;
	    for(i=1;i<nbNomin;i++){
	        if(nominVotes[0] == nominVotes[i]){
	             count++;
	        }
	        if(count != i){
	            break;
	        }
	    }
	    if(count == (nbNomin-1)){
	        return 1;
    	}else{
    		return 0;
		}
	}

void collecteVotes(int nbNomin,int nbElec,char nomN[20][50],char idE[200][10],int nominVotes[20]){
    initialiserVotesToZero(nominVotes,nbNomin);
    int ch,i,j;
    for(i=0; i<nbElec; i++)
    {
        printf("L'Electeur qui a le numero d'identification national %s\n",idE[i]);
        nominees(nomN,nbNomin);
		printf("\n");

        printf("\t\tTaper votre choix");
        scanf("%d",&ch);
        while(ch <= 0 || ch > nbNomin)
        {
            printf("\tTaper votre choix, Voir la liste des nominees.");
            scanf("%d",&ch);
        }
        for(j=0;j<nbNomin;j++){
            if(ch == j+1){
                nominVotes[j]++;
            }
        }
    }
}


void trophe(){
	printf("\t\t\t\t\t________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t___¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t¶¶¶¶______¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_______¶¶¶¶ \n");
	printf("\t\t\t\t\t¶¶¶_______¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________¶¶¶ \n");
	printf("\t\t\t\t\t¶¶________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________¶¶¶ \n");
	printf("\t\t\t\t\t¶¶¶_____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶______¶¶¶ \n");
	printf("\t\t\t\t\t¶¶¶____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶____¶¶¶¶ \n");
	printf("\t\t\t\t\t_¶¶¶___¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶¶____¶¶¶ \n");
	printf("\t\t\t\t\t_¶¶¶¶___¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶__¶¶¶¶ \n");
	printf("\t\t\t\t\t___¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶¶ \n");
	printf("\t\t\t\t\t____¶¶¶¶¶¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t______¶¶¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶___¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t_______________¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t_________________¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t___________________¶¶¶¶ \n");
	printf("\t\t\t\t\t___________________¶¶¶¶ \n");
	printf("\t\t\t\t\t___________________¶¶¶¶ \n");
	printf("\t\t\t\t\t___________________¶¶¶¶ \n");
	printf("\t\t\t\t\t_______________¶¶¶¶¶¶¶¶¶¶¶¶\n"); 
	printf("\t\t\t\t\t____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n"); 
	printf("\t\t\t\t\t____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t____________¶¶¶____________¶¶¶ \n");
	printf("\t\t\t\t\t____________¶¶¶____________¶¶¶ \n");
	printf("\t\t\t\t\t____________¶¶¶____________¶¶¶ \n");
	printf("\t\t\t\t\t____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t__________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ \n");
	printf("\t\t\t\t\t_________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n");
}
