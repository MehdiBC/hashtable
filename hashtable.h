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

