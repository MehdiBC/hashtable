#include "hashtable.h"
#include <stdio.h>
#define EMPTY -1

void ajouter(Paire tab[], int taille, int cle, Element* valeur){
    //index = (h(key)+i) mod sizeTab
    int indice = calculIndice(cle, taille);
    int numberTest;
    for(numberTest = 0; tab[indice%taille].cle!=EMPTY; numberTest++, indice++);
    if(numberTest<=taille){
        tab[indice%taille].cle = cle;
        tab[indice%taille].e = valeur;
    }else printf("Tab Overflow");
}

int supprimer(Paire tab[], int taille, int cle){
    int indice = calculIndice(cle, taille);
    int numberTest;
    for(numberTest = 0; tab[indice%taille].cle!=cle; numberTest++, indice++);
    if(numberTest<=taille) {
        tab[indice%taille].cle = EMPTY;
        return indice;
    }else{
        printf("Element not found");
        return -1;
    }
}

Paire recherche(Paire tab[], int taille, int cle){
    int indice = calculIndice(cle, taille);
    int numberTest;
    for(numberTest = 0; tab[indice].cle!=cle; numberTest++, indice++);
    if(numberTest<=taille) {
        return tab[indice];
    }else{
        printf("Element not found");
        return {EMPTY, NULL};
    }
}

void afficher(Paire p){
    if(p.cle!=EMPTY)
        printf("(%d, %d, %d)\n", p.cle, p.e->x, p.e->y);
    else printf("(-, -, -)\n");
}

void afficher(Paire tab[], int taille){
    for(int indice=0; indice<taille; indice++){
        afficher(tab[indice]);
    }
}
