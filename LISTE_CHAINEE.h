#ifndef LISTE_CHAINEE
#define LISTE_CHAINEE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void Objet; // Definition le type Objet


// Definition d'un element
typedef struct element{
    Objet *reference;
    struct element *suivant;
} Element;

// Definition de la structure
typedef struct{
    Element *premier;
    Element *dernier;
    Element *courant;
    int nbElt;
    int type; // 0:simple 1:croissant 2:decroissant
    char *(*afficher)(Objet *);
    int (*comparer)(Objet *, Objet *);
} Liste;

int comparer (Objet* objet1, Objet* objet2);
char* afficher(Objet* objet);


static Element* creerElement();
static Element* elementCourant(Liste *li);
static Objet* objetCourant(Liste *li);
static void ouvrirListe(Liste *li);
static bool finListe(Liste *li);
static void insererApres(Liste *li, Element *precedent, Objet *objet);
static Objet* extraireApres(Liste *li, Element *precedent);

void initListe(Liste *li, int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));
Liste* creerListe(int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));
int nbElement(Liste *li);
void insererEnTete(Liste *li, Objet *objet);
void insererEnFin(Liste *li, Objet *objet);
Objet* extraireEnTete(Liste *li);
Objet* extraireFin(Liste *li);
bool extraireObjet(Liste *li, Objet* objet);
bool listeVide(Liste *li);
Objet* chercherObjet(Liste *li, Objet *objetCherche);
void listerListe(Liste *li);
void detruireListe(Liste *li);


#endif 