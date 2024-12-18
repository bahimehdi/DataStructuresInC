#include "LISTE_CHAINEE.h"

#ifndef PILE
#define PILE

typedef Liste pile;

pile* creerPile(int type, char*(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));
bool pileVide(pile *p);
void empiler(pile *p, Objet* objet);
Objet* depiler(pile *p);
void listerPile(pile *p);
void detruirePile(pile *p);

#endif