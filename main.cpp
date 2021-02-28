#include <cmath>
#include <iostream>
#include <string>
#include "sondage_lineaire.h"

using namespace std;

void test(){
    Paire tab[10];
    for(int i=0; i<10; tab[i].cle=EMPTY, i++); //initialization of tab clé = -1 is considered empty
    //define elements
    Element e1 = {1,2};
    ajouter(tab, 10, 0, &e1);
    Element e2 = {4,7};
    ajouter(tab, 10, 4, &e2);
    Element e3 = {7,1};
    ajouter(tab, 10, 7, &e3);
    Element e4 = {4,8};
    ajouter(tab, 10, 42, &e4);
    afficher(tab, 10);
    printf("\n###########\n\n");
    //search for an element
    afficher(recherche(tab, 10, 4));
    afficher(recherche(tab, 1, 4));
    printf("\n###########\n\n");
    //delete elements
    supprimer(tab, 10, 0);
    afficher(tab, 10);
}

int main() {
    test();
    return 0;
}
