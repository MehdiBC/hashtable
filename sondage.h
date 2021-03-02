#include "hashtable.h"
#include <stdio.h>

#define SONDAGE_QUADRATIQUE for(numberTest = 1, i=0; tab[indice].e!=NULL; numberTest++, i++){indice=(indice+i*i)%taille;}
#define SONDAGE_LINEAIRE for(numberTest = 1; tab[indice].e!=NULL; indice=(++indice)%taille, numberTest++);
#define SONDAGE_DOUBLE for(numberTest = 1, i=0; tab[indice].e!=NULL; indice=(indice+hashIndex(i))%taille, i++, numberTest++);

#define SONDAGE SONDAGE_DOUBLE

int hashIndex(int cle){
//calculer la fonction de hashage
//exemple:
    return 3*cle+5;
}

void ajouter(Paire tab[], int taille, int cle, Element* valeur, int *nbrePaire, int *maxNumberTests){
    //verifying that we still have place in the table
    if(*nbrePaire<=taille){
        //index = (h(key)+i²) mod sizeTab
        int indice = calculIndice(cle, taille);
        int numberTest, i;
        SONDAGE
        tab[indice].cle = cle;
        tab[indice].e = valeur;
        (*nbrePaire)++;
        printf("ajout d'un element: number of test:%d et l'indice: %d\n", numberTest, indice);
        if(numberTest>*maxNumberTests) *maxNumberTests=numberTest;
    }else printf("Tab Overflow\n");
}

int supprimer(Paire tab[], int taille, int cle, int *nbrePaire, int *maxNumberTests){
    int indice = calculIndice(cle, taille);
    int numberTest, i;
    SONDAGE
    if(numberTest<=(*maxNumberTests)) {
        tab[indice].e = NULL;
        (*nbrePaire)--;
        return indice;
    }else{
        printf("Element not found\n");
        return -1;
    }
}

Paire recherche(Paire tab[], int taille, int cle, int *maxNumberTests){
    int indice = calculIndice(cle, taille);
    int numberTest, i;
    SONDAGE
    if(numberTest<=*maxNumberTests) {
        return tab[indice];
    }else{
        printf("Element not found\n");
        return {EMPTY, NULL};
    }
}

void afficher(Paire p){
    if(p.e!=NULL)
        printf("(%d, %d, %d)\n", p.cle, p.e->x, p.e->y);
    else printf("(-, -, -)\n");
}

void afficher(Paire tab[], int taille){
    for(int indice=0; indice<taille; indice++){
        afficher(tab[indice]);
    }
}
