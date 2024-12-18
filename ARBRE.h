#ifndef ARBRE_H
#define ARBRE_H

#include "LISTE_CHAINEE.h"

// Noeud d'arbre binaire
typedef struct noeud{
    Objet* reference;
    struct noeud* gauche;
    struct noeud* droite;
} Noeud;

// La racine de l'arbre
typedef struct{
    Noeud* racine;
    char* (*afficher)(Objet *);
    int (*comparer)(Objet *, Objet *);
} Arbre;

static void initArbre(Arbre* arbre, Noeud* racine, char* (*afficher)(Objet *), int (*comparer)(Objet *, Objet *));

Noeud* cNd(Objet* objet, Noeud* gauche, Noeud* droite);
Noeud* cF(Objet* objet);
Arbre* creerArbre(Noeud* racine, char* (*afficher)(Objet *), int (*comparer)(Objet *, Objet *));
void prefixe(Noeud* racine, char* (*afficher)(Objet *));
void infixe(Noeud* racine, char* (*afficher)(Objet *));
void postfixe(Noeud* racine, char* (*afficher)(Objet *));
Noeud* trouverNoeud(Noeud* racine, Objet* objet, int (*comparer)(Objet *, Objet *));
int taille(Noeud* racine);
int hauteur(Noeud* racine);
void enLargeur(Noeud* racine, char* (*afficher)(Objet *));
int max(int a, int b);

Arbre* creerArbreGenealogique();
Arbre* creerArbreArithmetique();


#endif