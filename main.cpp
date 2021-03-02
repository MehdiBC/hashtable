#include "sondage.h"

using namespace std;

void test_sondage(){
    Paire tab[10];
    for(int i=0; i<10; tab[i].e=NULL, i++); //initialization of tab clé = -1 is considered empty
    //define elements
    int nbPaire=0, maxNbTest=0;
    Element e1 = {1,2};
    ajouter(tab, 10, 0, &e1, &nbPaire, &maxNbTest);
    Element e2 = {4,7};
    ajouter(tab, 10, 4, &e2, &nbPaire, &maxNbTest);
    Element e3 = {7,1};
    ajouter(tab, 10, 7, &e3, &nbPaire, &maxNbTest);
    Element e4 = {4,8};
    ajouter(tab, 10, 42, &e4, &nbPaire, &maxNbTest);
    Element e5 = {4,8};
    ajouter(tab, 10, 1, &e5, &nbPaire, &maxNbTest);
    Element e6 = {4,8};
    ajouter(tab, 10, 22, &e6, &nbPaire, &maxNbTest);
    Element e7 = {4,8};
    ajouter(tab, 10, 72, &e7, &nbPaire, &maxNbTest);
    Element e8 = {4,8};
    ajouter(tab, 10, 14, &e8, &nbPaire, &maxNbTest);
    Element e9 = {4,8};
    ajouter(tab, 10, 142, &e9, &nbPaire, &maxNbTest);
    Element e10 = {4,8};
    ajouter(tab, 10, 62, &e10, &nbPaire, &maxNbTest);
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


int main() {
    test_sondage();
    return 0;
}
