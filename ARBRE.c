#include "arbre.h"

// Creer un arbre
Arbre* creerArbre(Noeud* racine, char* (*afficher)(Objet *), int (*comparer)(Objet *, Objet *)){
    Arbre* arbre = (Arbre*) malloc(sizeof(Arbre));
    if (arbre != NULL) initArbre(arbre, racine, afficher, comparer);
    return arbre;
}

// Creation d'un noeud a l'interieur de l'arbre
Noeud* cNd(Objet* objet, Noeud* gauche, Noeud* droite){
    Noeud* nouveau = (Noeud*) malloc(sizeof(Noeud));
    if(nouveau != NULL){
        nouveau->reference = objet;
        nouveau->gauche = gauche;
        nouveau->droite = droite;
    }
    return nouveau;
}

// Creation d'une feuille dans l'arbre
Noeud* cF(Objet* objet){
    return cNd(objet, NULL, NULL);
}

/* Parcours en profondeur */
// methode prefixe : P SAG SAD
void prefixe(Noeud* racine, char* (*afficher)(Objet *)){
    if(racine != NULL){
        printf("%s ", afficher(racine->reference));
        prefixe(racine->gauche, afficher);
        prefixe(racine->droite, afficher);
    }
}

// methode infixe : SAG P SAD
void infixe(Noeud* racine, char* (*afficher)(Objet *)){
    if(racine != NULL){
        infixe(racine->gauche, afficher);
        printf("%s ", afficher(racine->reference));
        infixe(racine->droite, afficher);
    }
}

// methode postifxe : SAG SAD P
void postfixe(Noeud* racine, char* (*afficher)(Objet *)){
    if(racine != NULL){
        postfixe(racine->gauche, afficher);
        postfixe(racine->droite, afficher);
        printf("%s ", afficher(racine->reference));
    }
}

// Parcours en largeur
void enLargeur(Noeud* racine, char* (*afficher)(Objet *)){
    Liste* li = creerListe(0, NULL, NULL);
    insererEnFin(li, racine);
    while(!listeVide(li)){
        Noeud* extrait = (Noeud*) extraireEnTete(li);
        printf("%s ", afficher(extrait->reference));
        if(extrait->gauche != NULL) insererEnFin(li, extrait->gauche);
        if(extrait->droite != NULL) insererEnFin(li, extrait->droite);
    }
}

// Trouver un noeud
Noeud* trouverNoeud(Noeud* racine, Objet* objet, int (*comparer)(Objet *, Objet *)){
    Noeud* pNom;
    if(racine == NULL) pNom = NULL;
    else if(comparer(racine->reference, objet) == 0) pNom = racine;
    else{
        pNom = trouverNoeud(racine->gauche, objet, comparer);
        if(pNom == NULL) pNom = trouverNoeud(racine->droite, objet, comparer);
    }
    return pNom;
}

// Taille d'un arbre
int taille(Noeud* racine){
    if(racine == NULL) return 0;
    else return 1 + taille(racine->gauche) + taille(racine->droite);
}

// Hauteur d'un arbre
int hauteur(Noeud* racine){
    if(racine == NULL) return 0;
    else return 1 + max(hauteur(racine->gauche), hauteur(racine->droite));
}

int max(int a, int b){
    return (a>b) ? a : b;
}

static void initArbre(Arbre* arbre, Noeud* racine, char* (*afficher)(Objet *), int (*comparer)(Objet *, Objet *)){
    arbre->racine = racine;
    arbre->afficher = afficher;
    arbre->comparer = comparer;
}


Arbre* creerArbreGenealogique(){
    Noeud* racine = cNd((Objet*)"Samir",
                        cNd((Objet*)"Kamal",
                            cNd((Objet*)"Yassine", NULL, cNd((Objet*)"Hind", NULL, cF((Objet*)"Yasmine"))),
                            NULL),
                        cNd((Objet*)"Sarah",
                            cF((Objet*)"Karim"),
                            NULL));
    return creerArbre(racine, NULL, NULL);
}

Arbre* creerArbreArithmetique() {
    Noeud* racine = cNd((Objet*)"-",
                        cNd((Objet*)"*",
                            cNd((Objet*)"+",
                                cF((Objet*)"a"),
                                cF((Objet*)"b")),
                            cNd((Objet*)"-",
                                cF((Objet*)"c"),
                                cF((Objet*)"d"))),
                        cF((Objet*)"e"));
    return creerArbre(racine, NULL, NULL);
}

