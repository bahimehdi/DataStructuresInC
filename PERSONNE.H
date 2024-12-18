#ifndef PERSONNE
#define PERSONNE

#include "LISTE_CHAINEE.h"

typedef char ch15 [16];
typedef void Objet;
typedef struct personne{
    ch15 nom;
    ch15 prenom;

}Personne;
Personne* creerPersonne(char* nom,char* prenom);
char* afficherPersonne(Objet* objet);
int comparerPersonne(Objet* obj1,Objet* obj2);
#endif