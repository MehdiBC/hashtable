#include <stdio.h>

#ifndef test
#include "hashtable.h"
#include "liste_chaine.h"
#define test
#endif // test

void initialisation(Liste* tab[], int taille){
    for(int i=0; i<taille; i++){
        tab[i]=NULL;
    }
}

void ajouter(Liste* tab[], int taille, int cle, Element* valeur){
    int index = calculIndice(cle, taille);
    if(tab[index]==NULL){
        tab[index] = initialisation({cle, valeur});
    }else{
        insertion(tab[index], {cle, valeur});
    }
}

Paire recherche(Liste* tab[], int taille, int cle){
    int index = calculIndice(cle, taille);
    if(tab[index]!=NULL){
        return recherche(tab[index], cle);
    }else{
        printf("Element not found\n");
        return {EMPTY, NULL};
    }
}

int supprimer(Liste* tab[], int taille, int cle){
    int index = calculIndice(cle, taille);
    if(tab[index]!=NULL){
        tab[index]=suppression(tab[index], cle);
        return index;
    }else{
        printf("Element not found\n");
        return -1;
    }
}

void afficher(Liste* tab[], int taille){
    for(int i=0; i<taille; i++){
        afficher_liste(tab[i]);
    }
}

void test_chainage(){
    Liste* tab[10];
    initialisation(tab, 10);
    Element e[10] = { {1,2}, {4,7}, {7,1}, {4,8}, {4,8}, {4,8}, {4,8}, {4,8}, {4,8}, {4,8} };
    for(int i=0; i<10; i++){
        ajouter(tab, 10, rand()%10, &(e[i]));
    }
    afficher(tab, 10);
    printf("###################\n");
    afficher(recherche(tab,10,0));
    supprimer(tab,10,0);
    printf("###################\n");
    afficher(tab, 10);
}
