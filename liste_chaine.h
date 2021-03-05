#include <stdio.h>
#include <stdlib.h>

#ifndef test
#include "hashtable.h"
#define test
#endif // test

/* ########################## definition de la liste chainée ########################## */

typedef struct Liste Liste;
struct Liste{
    Paire p;
    Liste* next;
    Liste* prev;
};

Liste* initialisation(Paire p){
    Liste* liste = (Liste*)malloc(sizeof(*liste));

    if (liste == NULL){
        exit(EXIT_FAILURE);
    }

    liste->p = p;
    liste->next = NULL;
    liste->prev = NULL;

    return liste;
}

void insertion(Liste* liste, Paire p){
    /* Création du nouvel élément*/
    Liste* nouveau = (Liste*)malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }
    nouveau->p = p;
    nouveau->next = NULL;

    /* Insertion de l'élément au début de la liste */
    while(liste->next){
        liste = liste->next;
    }
    liste->next = nouveau;
    nouveau->prev = liste;
}

Liste* suppression(Liste *liste, int cle){
    Liste* first = liste;
    while(liste != NULL && liste->next != NULL && (liste->p).cle != cle){
        liste = liste->next;
    }
    if (liste == NULL){
        printf("Element of key %d not found", cle);
        exit(EXIT_FAILURE);
    }else if(liste->next == NULL && liste->prev == NULL && (liste->p).cle == cle){
        free(liste);
        first = NULL;
    }else if(liste->next == NULL && (liste->p).cle == cle){
        (liste->prev)->next = NULL;
        free(liste);
    }else if(liste->prev == NULL && (liste->p).cle == cle){
        first = liste->next;
        (liste->next)->prev = NULL;
        free(liste);
    }else{
        printf("%d Not found\n", cle);
    }
    return first;
}

Paire recherche(Liste* liste, int cle){
    while(liste != NULL && (liste->p).cle != cle){
        liste = liste->next;
    }
    if(liste){
        return liste->p;
    }else{
        printf("Element not found\n");
        return {EMPTY, NULL};
    }
}

void afficher_liste(Liste *l){
    while(l){
        printf("(%d,%d,%d)->", (l->p).cle, ((l->p).e)->x, ((l->p).e)->y);
        l=l->next;
    }
    printf("NULL\n");
}

//fonction de test
void test_liste(){
    Element e1 = {1,2};
    Liste* l=initialisation({2, &e1});
    Element e2 = {3,4};
    insertion(l, {1, &e2});
    Element e3 = {8,7};
    insertion(l, {3, &e3});
    afficher_liste(l);
    l=suppression(l, 2);
    l=suppression(l, 3);
    afficher_liste(l);
}
