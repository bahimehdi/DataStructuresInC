#include "LISTE_CHAINEE.h"

// fonction comparer
int comparer(Objet* objet1, Objet* objet2) {
    return strcmp((char*)objet1, (char*)objet2);
}

// fonction afficher
char* afficher(Objet* objet) {
    static char chaine[100];
    snprintf(chaine, sizeof(chaine), "%d", *(int*)objet); 
    return chaine;
}


// Verifier si la liste est vide
bool listeVide(Liste *li){
    return li->nbElt == 0;
}

// Nombre d'element
int nbElement(Liste *li){
    return li->nbElt;
}

// Fin liste
bool finListe(Liste *li){
    return li->courant == NULL;
}

// Initialiser une liste  
void initListe(Liste *li, int type, char* (*afficher)(Objet *), int (*comparer)(Objet *, Objet *)){
    li->premier = NULL;
    li->dernier = NULL;
    li->courant = NULL;
    li -> nbElt = 0;
    li->type = type;
    li->afficher = afficher;
    li->comparer = comparer;
}

// Creer une liste
Liste* creerListe(int type, char* (*afficher)(Objet *), int (*comparer)(Objet *, Objet *)){
    Liste *li = (Liste *)malloc(sizeof(Liste));
    initListe(li, type, afficher, comparer);
    return li;
}

// Inserer en tete
void insererEnTete(Liste *li, Objet *objet){
    Element *nouveau = creerElement();
    nouveau->reference = objet;
    nouveau->suivant = li->premier;
    li->premier = nouveau;
    if (li->dernier == NULL) li->dernier = nouveau;
    li->nbElt++;
}

// Trouver l'objet courant
static Objet* objetCourant(Liste *li){
    if (li == NULL) return NULL;
    Element* ptc = elementCourant(li);
    return ptc == NULL ? NULL : ptc->reference;
}

// Inserer en fin
void insererEnFin(Liste *li, Objet *objet){
    insererApres(li, li->dernier, objet);
}

// Lister une liste
void listerListe(Liste *li){
    ouvrirListe(li);
    while (!finListe(li)){
        Objet* objet = objetCourant(li);
        printf("%s\n", li->afficher(objet));
    }
}

// Chercher un objet dans une liste chainee
Objet* chercherObjet(Liste *li, Objet *objetCherche){
    bool trouve = false;
    ouvrirListe(li);
    Objet* objet;
    while (!finListe(li) && !trouve) {
        objet = objetCourant(li);
        trouve = li->comparer(objetCherche, objet) == 0;
    }
    return trouve ? objet : NULL;
}

// Extraire en tete
Objet* extraireEnTete(Liste *li){
    Element* extrait = li->premier;
    if(!listeVide(li)){
        li->premier = li->premier->suivant;
        if(li->premier == NULL) li->dernier = NULL;
        li->nbElt--;
    }
    return extrait != NULL ? extrait->reference : NULL;
}

// Extraire en fin
Objet* extraireFin(Liste *li){
    Objet* extrait;
    if(listeVide(li)) extrait = NULL;
    else if(li->premier == li->dernier) extrait = extraireEnTete(li);
    else{
        Element* ptc = li->premier;
        while(ptc->suivant != li->dernier) ptc = ptc->suivant;
        extrait = extraireApres(li, ptc);
    }
    return extrait;
}

// Extraire un objet
bool extraireObjet(Liste *li, Objet *objet) {
    bool trouve = false;
    Element *precedent = NULL;
    Element *ptc = li->premier;
    while (ptc != NULL) {
        if (li->comparer(ptc->reference, objet) == 0) {
            Element *temp = ptc;
            if (precedent == NULL) {
                li->premier = ptc->suivant;
                if (ptc == li->dernier) li->dernier = NULL;
            } else {
                precedent->suivant = ptc->suivant;
                if (ptc == li->dernier) li->dernier = precedent;
            }
            ptc = ptc->suivant;
            free(temp);
            trouve = true;
        } else {
            precedent = ptc;
            ptc = ptc->suivant;
        }
    }
    return trouve;
}


// Detruire une liste
void detruireListe(Liste *li){
    Element* ptc = li->premier;

    while(ptc != NULL){
        Element* prochain = ptc->suivant;
        free(ptc);
        ptc = prochain;    
    }
    initListe(li, 0, NULL, NULL);
}

// Creation d'un element
static Element *creerElement(){
    return (Element *)malloc(sizeof(Element));
}

// Ouverture d'une liste
static void ouvrirListe(Liste *li){
    li->courant = li->premier;
}

// Trouver l'element courant
static Element* elementCourant(Liste *li){
    Element* ptc = li->courant;
    if(li->courant != NULL) li->courant = li->courant->suivant; 
    return ptc;
}

// Inserer apres un certain element
static void insererApres(Liste *li, Element *precedent, Objet *objet){
    if(precedent == NULL) insererEnTete(li, objet);
    else{
        Element *nouveau = creerElement();
        nouveau->reference = objet;
        nouveau->suivant = precedent->suivant;
        precedent->suivant = nouveau;
        if(precedent == li->dernier) li->dernier = nouveau;
        li->nbElt++;
    }
}

// Extraire apres un certain element
static Objet* extraireApres(Liste *li, Element *precedent){
    Element* extrait = precedent->suivant;
    if(extrait->suivant){
        precedent->suivant = extrait->suivant;
        if(extrait == li->dernier) li->dernier = precedent;
        li->nbElt--;
    }
    return extrait != NULL ? extrait->reference : NULL;
}