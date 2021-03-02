#define EMPTY -1 //-1 is considered as empty key this is just for initialization or as a returned error not found

struct Element{
    int x;
    int y;
};

struct Paire{
    int cle;
    Element* e;
};

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

