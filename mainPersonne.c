#include "PERSONNE.c"
#include "LISTE_CHAINEE.c"

int menu () {
    printf ("\n\nGESTION D'UNE LISTE DE PERSONNES\n\n");
    printf ("0 - Fin\n");
    printf ("1 - Insertion en tete de liste\n");
    printf ("2 - Insertion en fin de liste\n");
    printf ("3 - Retrait en tete de liste\n");
    printf ("4 - Retrait en fin de liste\n");
    printf ("5 - Retrait d'un \202l\202ment a partir de son nom\n");
    printf ("6 - Parcours de la liste\n");
    printf ("7 - Recherche d'un \202l\202ment a partir de son nom\n");
    printf ("8 - Destruction de la liste\n");
    printf ("\n");
    printf ("Votre choix ? ");
    int cod; scanf ("%d", &cod);
    printf ("\n");
    return cod;
}

int main(){
    Liste* lp = creerListe(0, afficherPersonne, comparerPersonne);
    bool fini = false;
    ch15 nom, prenom, vide = "?";
    Personne *nouveau, *extrait, *cherche, *pp;

    while(!fini){
        switch(menu()){

            case 0:{
                printf("\n*****FIN DU PROGRAMME*****\n");
                fini = true;
            }break;

            case 1:{
                printf("\nVeuillez saisir le nom de la personne :\n");
                scanf("%s", nom);
                printf("\nVeuillez saisir le prenom de la personne :\n");
                scanf("%s", prenom);
                nouveau = creerPersonne(nom, prenom);
                insererEnTete(lp, nouveau);
            }break;

            case 2:{
                printf("\nVeuillez saisir le nom de la personne :\n");
                scanf("%s", nom);
                printf("\nVeuillez saisir le prenom de la personne :\n");
                scanf("%s", prenom);
                nouveau = creerPersonne(nom, prenom);
                insererEnFin(lp, nouveau);
            }break;

            case 3:{
                extrait = (Personne*) extraireEnTete(lp);
                (extrait != NULL) ? printf("\nElement %s %s extrait en tete de liste.\n", extrait->nom, extrait->prenom) : printf("\nListe vide.\n");
            }break;

            case 4:{
                extrait = (Personne*) extraireFin(lp);
                (extrait != NULL) ? printf("\nElement %s %s extrait en fin de liste.\n", extrait->nom, extrait->prenom) : printf("\nListe vide.\n");
            }break;

            case 5:{
                printf("\nVeuillez saisir le nom de la personne à extraire :\n");
                scanf("%s", nom);

                Personne* pp = creerPersonne(nom, "?");
                if (extraireObjet(lp, pp)) {
                    printf("\nToutes les personnes avec le nom %s ont \202t\202 extraites de la liste.\n", nom);
                } else {
                    printf("\nAucune personne avec ce nom n'existe dans la liste.\n");
                }
            }
            break;
                
            case 6:{
                if(lp->nbElt == 0) printf("\nLa liste est vide.\n");
                else listerListe(lp);
            }
                break;

            case 7:{
               printf("\nVeuillez saisir le nom de la personne a chercher :\n");
               scanf("%s", nom);
               Personne* pp = creerPersonne(nom, vide);
               Personne* ppp = (Personne*) chercherObjet(lp, pp);
               if(ppp != NULL) printf("\n%s %s existe dans la liste\n", ppp->nom, ppp->prenom);
               else printf("\n %s %s n'existe pas dans la liste.\n");
               }break;
            
            case 8:{
                detruireListe(lp);
                printf("\nLa liste de personne est d\202truite avec succ\202s.\n");
            }break;
        }
    }
    
    printf("\nFin du programme.\n");
    return 0;
}
