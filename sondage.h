#include <stdio.h>

#ifndef test
#include "hashtable.h"
#define test
#endif // test

//recherche de case vide
#define SONDAGE_QUADRATIQUE for(numberTest = 1, i=0; tab[indice].e!=NULL; numberTest++, i++){indice=(indice+i*i)%taille;}
#define SONDAGE_LINEAIRE for(numberTest = 1; tab[indice].e!=NULL; indice=(++indice)%taille, numberTest++);
#define SONDAGE_DOUBLE for(numberTest = 1, i=0; tab[indice].e!=NULL; indice=(indice+hashIndex(i))%taille, i++, numberTest++);

//recherche de la cle dans la table de hashage
#define SONDAGE_QUADRATIQUE_RECHERCHE for(numberTest = 1, i=0; numberTest<=(*maxNumberTests) && tab[indice].e!=NULL && tab[indice].cle!=cle; numberTest++, i++){indice=(indice+i*i)%taille;}
#define SONDAGE_LINEAIRE_RECHERCHE for(numberTest = 1; numberTest<=(*maxNumberTests) &&  tab[indice].e!=NULL && tab[indice].cle!=cle; indice=(++indice)%taille, numberTest++);
#define SONDAGE_DOUBLE_RECHERCHE for(numberTest = 1, i=0; numberTest<=(*maxNumberTests) &&  tab[indice].e!=NULL && tab[indice].cle!=cle; indice=(indice+hashIndex(i))%taille, i++, numberTest++);

#define SONDAGE SONDAGE_LINEAIRE // définir la methode d'implementation pour la recherche de case vide
#define SONDAGE_RECHERCHE SONDAGE_LINEAIRE_RECHERCHE // définir la methode d'implementation pour la recherche de case vide

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
        int numberTest;
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
    SONDAGE_RECHERCHE
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
    SONDAGE_RECHERCHE
    if(numberTest<=*maxNumberTests) {
        return tab[indice];
    }else{
        printf("Element not found\n");
        return {EMPTY, NULL};
    }
}

void afficher(Paire tab[], int taille){
    for(int indice=0; indice<taille; indice++){
        afficher(tab[indice]);
    }
}

//fonction de test
void test_sondage(){
    Paire tab[10];
    for(int i=0; i<10; tab[i].e=NULL, i++); //initialization of tab clé = -1 is considered empty
    //define elements
    int nbPaire=0, maxNbTest=0;
    Element e[10] = { {1,2}, {4,7}, {7,1}, {4,8}, {4,8}, {4,8}, {4,8}, {4,8}, {4,8}, {4,8} };
    for(int i=0; i<10; i++){
        ajouter(tab, 10, rand()%10, &(e[i]), &nbPaire, &maxNbTest);
    }
    afficher(tab, 10);
    printf("\n###########\n\n");
    //search for an element
    afficher(recherche(tab, 10, 4, &maxNbTest));
    afficher(recherche(tab, 10, 14, &maxNbTest));
    printf("\n###########\n\n");
    //delete elements
    supprimer(tab, 10, 0, &nbPaire, &maxNbTest);
    Element e11 = {4,8};
    ajouter(tab, 10, 25, &e11, &nbPaire, &maxNbTest);
    afficher(tab, 10);

}
