#include <stdio.h>
#include <stdlib.h>

#define LONG 7

void initialiser(int[][LONG]);
void avancer(int, int[]);
int rechercheVide(int[][LONG],int[]);
void placer(int [][LONG], int, int[]);
void afficher(int [][LONG]);

int main()
{
    int n_incr = 1;

    int pos[2];
    pos[0] = LONG/2;
    pos[1] = LONG/2-1;

    int magic[LONG][LONG];

    initialiser(magic);

    for(n_incr=1; n_incr < LONG*LONG+1 ;n_incr++) {

        avancer(1, pos);

        if(rechercheVide(magic, pos) == 0){
            avancer(0, pos);
        }

        placer(magic, n_incr, pos);

    }
    afficher(magic);

    return 0;
}


/***********************************************
But :

Entrees :

Sorties :

Description :
***********************************************/

void initialiser(int tablo[LONG][LONG]){

    int n_i=0, n_j=0;

    for(n_i=0;n_i<LONG;n_i++){
        for(n_j=0;n_j<LONG;n_j++){

            tablo[n_i][n_j]=0;

        }
    }

}


/***********************************************
But :

Entrees :

Sorties :

Description :
***********************************************/

void avancer(int droite, int posi[2]){



    posi[0] = posi[0] - 1;
    posi[1] = posi[1] + 1;

    if(droite == 0){
        posi[1] = posi[1] - 2;
    }

    if(posi[1] == -1){
        posi[1] = LONG -1;
    }if(posi[1] == LONG){
        posi[1] = 0;
    }

    if(posi[0] == -1){
        posi[0] = LONG - 1;
    }if(posi[0] == LONG){
        posi[0] = 0;
    }

}


/***********************************************
But :

Entrees :

Sorties :

Description :
***********************************************/

int rechercheVide(int tablo[LONG][LONG], int posi[2]){

    if(tablo[posi[0]][posi[1]] != 0) {
        return 0;
    }else{
        return 1;
    }

}


/***********************************************
But :

Entrees :

Sorties :

Description :
***********************************************/

void placer(int table[LONG][LONG], int n_nom, int posi[2]) {

    table[posi[0]][posi[1]] = n_nom;

}


/***********************************************
But :

Entrees :

Sorties :

Description :
***********************************************/

void afficher(int tablo[LONG][LONG]) {

    int n_i=0, n_j=0;

    for(n_i=0;n_i<LONG;n_i++){
        for(n_j=0;n_j<LONG;n_j++){

            if(tablo[n_i][n_j] > 9) {
                printf("%d ", tablo[n_i][n_j]);
            }else{
                printf(" %d ", tablo[n_i][n_j]);
            }

        }
        printf("\n");
    }

}
