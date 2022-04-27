#include <stdio.h>
#include <stdlib.h>

#define LONG 7 //La longeur desiree

void initialiser(int[][LONG]);
void avancer(int, int[]);
int rechercheVide(int[][LONG],int[]);
void placer(int [][LONG], int, int[]);
void afficher(int [][LONG]);

int main()
{
    int n_incr; //Permet de savoir quel nombre on met dans une case

    int pos[2]; //Un tableau qui stocke les positions, ça permet de les manipulers entres les differentes fonctions
    pos[0] = LONG/2; //Je les fais commencer une case au sud-ouest avant la case intitiale, car des le debut du code, ca bougera a la premiere boucle au bon endroit
    pos[1] = LONG/2-1;

    int magic[LONG][LONG]; //Le tableau qui stockera toutes les nombres

    initialiser(magic); //On rempli le tableau de 0

    for(n_incr=1; n_incr <= LONG*LONG ;n_incr++) { //Une boucle qui va faire le nombre d'itteration qu'il y a de case dans tableau

        avancer(1, pos); //Notre fonction avancer, le 1 est comme un bool, et dit qu'on a pas besoin de recule, la pos est notre tableau de position

        if(rechercheVide(magic, pos) == 0){ //recherche vide renvoie 1 ou 0 comme un booleen pour savoir si c'est libre
            avancer(0, pos); //Si c'est pas libre, on doit re avancer mais en arriere, d'ou le zero
        }

        placer(magic, n_incr, pos); //Puis on place le nombre incrementer dans le tableau a la bonne position

    }
    afficher(magic); //Et a la fin de la boucle, on affiche

    return 0;
}


/***********************************************
But : Initialiser un tableau

Entrees : Le tableau

Sorties : Le tableau initialise

Description : On fait 2 boucles, l'une dans l'autre, car c'est a 2 dimension
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
But : Aller a la prochaine position

Entrees : Le booleen de la recherche de vide et la position

Sorties : La nouvelle position

Description : C'est long, regardez les commentaires
***********************************************/

void avancer(int droite, int posi[2]){



    posi[0] = posi[0] - 1; //A chaque fois, on va au Nord une fois
    posi[1] = posi[1] + 1; //Et a l'Est une fois

    if(droite == 0){ //On verifie le booleen, si il est faut, on revient deux fois a l'Ouest
        posi[1] = posi[1] - 2;
    }

    if(posi[1] == -1){ //On verifie qu'on va pas trop a l'Ouest
        posi[1] = LONG -1; //Sinon on retourne tout a l'Est

    }if(posi[1] == LONG){ //L'inverse avec l'Est
        posi[1] = 0; //Tout a l'Ouest
    }

    if(posi[0] == -1){ //Et pareil pour le Nord
        posi[0] = LONG - 1; //On retourne au Sud

    }if(posi[0] == LONG){ //Et l'inverse
        posi[0] = 0; //Au Nord
    }

}


/***********************************************
But : Rechercher que la case ou on se situe est bien vide

Entrees : La position et le tableau

Sorties : Un booleen, 1 si il y a rien (un 0), et 0 si il y a quelque chose

Description : On va juste a la position et regarde si c'est pas egale a 0
***********************************************/

int rechercheVide(int tablo[LONG][LONG], int posi[2]){

    if(tablo[posi[0]][posi[1]] != 0) {
        return 0;
    }else{
        return 1;
    }

}


/***********************************************
But : Placer le nombre dans le tableau

Entrees : Tout se qui est possible, le tableau, l'incrementation et la position

Sorties : Un nouveau nombre dans le tableau

Description : On va juste a la bonne position dans le tableau, puis on met le nombre incremente
***********************************************/

void placer(int table[LONG][LONG], int n_nom, int posi[2]) {

    table[posi[0]][posi[1]] = n_nom;

}


/***********************************************
But : Afficher le tableau

Entrees : Le tableau fini

Sorties : Un joli tableau affiche sur l'invite de commande

Description : Deux boucle car c'est deux dimmension
***********************************************/

void afficher(int tablo[LONG][LONG]) {

    int n_i=0, n_j=0;

    for(n_i=0;n_i<LONG;n_i++){
        for(n_j=0;n_j<LONG;n_j++){

            if(tablo[n_i][n_j] > 9) { //On verifie qu'il est au dessus de 9
                printf("%d ", tablo[n_i][n_j]);
            }else{
                printf(" %d ", tablo[n_i][n_j]); //Pour mettre un espace au moins de 10, comme ça le tableau est droit ;)
            }

        }
        printf("\n");
    }

}
