#include "personne.h"


// Creer une liste Personne
Personne* creerPersonne(char* nom, char* prenom){
    Personne* p = (Personne*)malloc(sizeof(Personne));
    strcpy(p->nom, nom);
    strcpy(p->prenom, prenom);
    return p;
}

// Afficher personne
char* afficherPersonne (Objet* objet){
    Personne* p = (Personne*) objet;
    char* output   = (char*) malloc (sizeof(Personne));
    snprintf(output, sizeof (Personne), "%s %s\n", p->nom , p->prenom);
    return output;
}

// Comparer deux personnes
int comparerPersonne (Objet* objet1, Objet* objet2){
    Personne* p1 = (Personne*) objet1;
    Personne* p2 = (Personne*) objet2;
    return strcmp (p1->nom, p2->nom);
}