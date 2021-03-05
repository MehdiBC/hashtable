/* ########################## definition des structures de données ########################## */

#define EMPTY -1 //-1 is considered as empty key this is just for initialization or as a returned error not found

struct Element{
    int x;
    int y;
};

struct Paire{
    int cle;
    Element* e;
};

void afficher(Paire p){
    if(p.e!=NULL)
        printf("(%d, %d, %d)\n", p.cle, p.e->x, p.e->y);
    else printf("(-, -, -)\n");
}

int hashFunction(int cle){
//calculer la fonction de hashage
//exemple:
    return 3*cle+14;
}

int compressFunction(int hashcode, int taille){
    return hashcode%taille;
}

int calculIndice(int cle, int taille){
    return compressFunction(hashFunction(cle),taille);
}

