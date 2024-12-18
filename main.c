#include "LISTE_CHAINEE.c"

int menu () {
    printf ("\n\n GESTION D'UNE LISTE D'ENTIERS \n\n");
    printf ("1 - Creer une liste\n");
    printf ("2 - Insertion en tete de liste \n");
    printf ("3 - Insertion en fin de liste \n");
    printf ("4 - Retrait en tete de liste \n");
    printf ("5 - Retrait en fin de liste \n");
    printf ("6 - Retrait d'un objet a partir de sa reference\n");
    printf ("7 - Afficher les objets de la liste \n");
    printf ("8 - Chercher Un objet \n");
    printf ("9 - Destruction de la liste \n");
    printf ("10 - Fin\n");
    printf ("\n");
    printf ("Votre choix ? "); 
    int cod; scanf ("%d", &cod); getchar();
    printf ("\n");
    return cod;
}

int main() {
    Liste* li = NULL;
    int* a;
    Objet* extrait;

    int choix = menu();
    do {
        switch(choix) {
            case 1: {
                if (li != NULL)
                    printf("La liste est deja cree, veuillez detruire la liste avant de la recreer.\n");
                else {
                    li = creerListe(0, afficher, comparer);
                    li != NULL ? printf("Liste cree avec succes.\n") : printf("Erreur lors de la creation de la liste.\n");
                }
                break;
            }
            case 2: {
                if (li == NULL) {
                    printf("Veuillez creer une liste d'abord.\n");
                } else {
                    a = (int*)malloc(sizeof(int));
                    printf("Veuillez saisir l'element a inserer: ");
                    scanf("%d", a);
                    insererEnTete(li, a);
                }
                break;
            }
            case 3: {
                if (li == NULL) {
                    printf("Veuillez creer une liste d'abord.\n");
                } else {
                    a = (int*)malloc(sizeof(int));
                    printf("Veuillez saisir l'element a inserer: ");
                    scanf("%d", a);
                    insererEnFin(li, a);
                }
                break;
            }
            case 4: {
                if (li == NULL) {
                    printf("Veuillez creer une liste d'abord.\n");
                } else {
                    extrait = extraireFin(li);
                    extrait == NULL ? printf("La liste est vide.\n") : printf("L'element retire en tete de la liste est: %s\n", afficher(extrait));
                }
                break;
            }
            case 5: {
                if (li == NULL) {
                    printf("Veuillez creer une liste d'abord.\n");
                } else {
                    extrait = extraireFin(li);
                    extrait == NULL ? printf("La liste est vide.\n") : printf("L'element retire en fin de la liste est: %s\n", afficher(extrait));
                }
                break;
            }
            case 6: {
                if (li == NULL) {
                    printf("Veuillez creer une liste d'abord.\n");
                } else {
                    a = (int*)malloc(sizeof(int));
                    printf("Veuillez saisir l'element a retirer: ");
                    scanf("%d", a);
                    if (extraireObjet(li, a)) {
                        printf("L'element %d a ete retire.\n", *a);
                    } else {
                        printf("L'element %d n'a pas ete trouve dans la liste.\n", *a);
                    }
                }
                break;
            }
            case 7: {
                if (li == NULL) {
                    printf("Veuillez creer une liste d'abord.\n");
                } else {
                    listerListe(li);
                    printf("\n");
                }
                break;
            }
            case 8: {
                if (li == NULL) {
                    printf("Veuillez creer une liste d'abord.\n");
                } else {
                    a = (int*)malloc(sizeof(int));  
                    printf("Veuillez saisir l'element a chercher: ");
                    scanf("%d", a);

                    Objet* trouve = chercherObjet(li, a);
                    if (trouve != NULL) {
                        printf("L'objet %d a ete trouve dans la liste.\n", *a);
                    } else {
                        printf("L'objet %d n'a pas ete trouve dans la liste.\n", *a);
                    }
                    free(a); 
                }
                break;
            }
            case 9: {
                if (li == NULL) {
                    printf("Veuillez creer une liste d'abord.\n");
                } else {
                    detruireListe(li);
                    printf("Liste detruite avec succes.\n");
                }
                break;
            }
            case 10: {
                printf("Fin du programme.\n");
                break;
            }
            default:
                printf("Choix invalide. Essayez a nouveau.\n");
                break;
        }
        choix = menu(); 
    } while (choix != 10); 
    return 0;
}
