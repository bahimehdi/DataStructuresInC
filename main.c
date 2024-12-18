#include "ARBRE.h"

int menu() {
    printf("\n\n------- GESTION D'ARBRES ------- \n");
    printf("  ARBRES BINAIRES \n");
    printf(" 01 - Creation de l'arbre genealogique \n");
    printf(" 02 - Creation de l'arbre arithmetique \n");
    printf("\n");
    printf(" 03 - Parcours prefixe \n");
    printf(" 04 - Parcours infixe \n");
    printf(" 05 - Parcours postfixe \n");
    printf(" 06 - Trouver un noeud \n");
    printf(" 07 - Taille de l'arbre \n");
    printf(" 08 - Hauteur de l'arbre \n");
    printf(" 09 - Parcours en largeur \n");
    printf(" 00 - Fin du programme \n");
    printf(" ----------------------------------------------------------------\n");
    printf("Votre choix? ");
    int cod;
    scanf("%d", &cod);
    getchar();
    printf("\n");
    return cod;
}

int main() {
    int fini = 0;
    Arbre* arbre1 = NULL;
    Arbre* arbre2 = NULL;
    Noeud* n1 = NULL;

    while (!fini) {
        switch (menu()) {
            case 0:
                fini = 1;
                break;

            case 1:
                arbre1 = creerArbreGenealogique();
                break;

            case 2:
                arbre2 = creerArbreArithmetique();
                break;

            case 3: {
                int c;
                printf("Si vous voulez parcourir l'arbre genealogique tapez 1 sinon tapez 2 : ");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        prefixe(arbre1->racine, afficher);
                        break;
                    case 2:
                        prefixe(arbre2->racine, afficher);
                        break;
                }
                break;
            }

            case 4: {
                int c;
                printf("Si vous voulez parcourir l'arbre genealogique tapez 1 sinon tapez 2 : ");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        infixe(arbre1->racine, afficher);
                        break;
                    case 2:
                        infixe(arbre2->racine, afficher);
                        break;
                }
                break;
            }

            case 5: {
                int c;
                printf("Si vous voulez parcourir l'arbre genealogique tapez 1 sinon tapez 2 : ");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        postfixe(arbre1->racine, afficher);
                        break;
                    case 2:
                        postfixe(arbre2->racine, afficher);
                        break;
                }
                break;
            }

           case 6: {
                int c;
                char n[100];
                Objet* r;
                printf("Si vous voulez chercher un noeud dans l'arbre genealogique tapez 1 sinon tapez 2 : ");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        printf("\tVeuillez saisir le noeud que vous recherchez : ");
                        scanf("%s", n);
                        r = n;
                        n1 = trouverNoeud(arbre1->racine, r, comparer);
                        if (n1 == NULL)
                            printf("\tLe noeud n'existe pas dans l'arbre\n");
                        else
                            printf("\tLe noeud existe dans l'arbre : %s\n", afficher(n1->reference));
                        break;

                    case 2:
                        printf("\tVeuillez saisir le noeud que vous recherchez : ");
                        scanf("%s", n);
                        r = n;
                        n1 = trouverNoeud(arbre2->racine, r, comparer);
                        if (n1 == NULL)
                            printf("\tLe noeud n'existe pas dans l'arbre\n");
                        else
                            printf("\tLe noeud existe dans l'arbre : %s\n", afficher(n1->reference));
                        break;
                }
                break;
            }
            case 7: {
                int c, t;
                printf("Si vous voulez la taille de l'arbre genealogique tapez 1 sinon tapez 2 : ");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        t = taille(arbre1->racine);
                        printf("\tLa taille de l'arbre est : %d\n", t);
                        break;
                    case 2:
                        t = taille(arbre2->racine);
                        printf("\tLa taille de l'arbre est : %d\n", t);
                        break;
                }
                break;
            }

            case 8: {
                int c, h;
                printf("Si vous voulez la hauteur de l'arbre genealogique tapez 1 sinon tapez 2 : ");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        h = hauteur(arbre1->racine);
                        printf("\tLa hauteur de l'arbre est : %d\n", h);
                        break;
                    case 2:
                        h = hauteur(arbre2->racine);
                        printf("\tLa hauteur de l'arbre est : %d\n", h);
                        break;
                }
                break;
            }

            case 9: {
                int c;
                printf("Si vous voulez parcourir l'arbre genealogique tapez 1 sinon tapez 2 : ");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        enLargeur(arbre1->racine, afficher);
                        break;
                    case 2:
                        enLargeur(arbre2->racine, afficher);
                        break;
                }
                break;
            }
        }
    }

    printf("\nFin du programme.\n");
    return 0;
}
