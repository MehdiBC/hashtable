/* ########################## definition des structures de données ########################## */
#include <string>
#include <math.h>
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
    return abs(3*cle+14);
}

int hashFunctionPoly(std::string s, int c){
    // fonction de hachage polynomiale
    // c est le coefficient polynomiale
    int hashcode=0,p=1;
    for(int i=0;i<s.length();i++){
        hashcode += (int) s[i]*p;
        p=p*c;
    }
    return abs(hashcode);
}

int hashFunctionCyc(std::string s, int c){
    // fonction de hachage cyclique
    // c est le nombre de bit de décalage
    int hashcode=0;
    for(int i=0;i<s.length();i++){
        hashcode = (hashcode<<c) | (hashcode>>(32-c));
        hashcode +=  (int) s[i];
    }
    return abs(hashcode);
}

int compressFunction(int hashcode, int taille){
    return hashcode%taille;
}

int calculIndice(int cle, int taille){
    return compressFunction(hashFunction(cle),taille);
}

