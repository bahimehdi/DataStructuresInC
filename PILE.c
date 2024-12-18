#include "PILE.h"

// Creer une pile
pile* creerPile(int type, char*(*afficher)(Objet *), int (*comparer)(Objet *, Objet *)){
    return creerListe(0, afficher, comparer);
}

// Savoir si la pile est vide
bool pileVide(pile* p){
    return listeVide(p);
}

// Ajouter un element
void empiler(pile* p, Objet* objet){
    insererEnTete(p, objet);
}

// Retrait d'un element
Objet* depiler(pile* p){
    return extraireEnTete(p);
}

// Lister une pile
void listerPile(pile* p){
    listerListe(p);
}

// Detruire une pile
void detruirePile(pile* p){
    detruireListe(p);
}