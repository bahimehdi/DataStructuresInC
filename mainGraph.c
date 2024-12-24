#include"GRAPHEMAT.c"

int menu()
{
	printf("\n\n=====Menu=====\n\n");
	printf(" 1 - Creer un graphe\n");
	printf(" 2 - Detruire le graphe\n");
	printf(" 3 - Ajouter un sommet\n");
	printf(" 4 - Ajouter un arc\n");
	printf(" 5 - Ecrire graphe\n");
	printf(" 6 - Parcourir en profondeur\n");
	printf(" 0 - Fin du programme\n");
	printf("\n\n Votre choix : ");
	int choix;
	scanf("%d", &choix);
	getchar();
	printf("\n\n");
	return choix;
}

int main()
{
    booleen fin = faux;
    GrapheMat *graphe = NULL; // Initialize the graph pointer

    while (!fin)
    {
        switch (menu())
        {
        case 0:
        {
            fin = vrai;
            break;
        }
        case 1:
        {
            printf("Veuillez saisir le nombre maximal de sommets : ");
            int nMax;
            scanf("%d", &nMax);
            graphe = creerGrapheMat(nMax, 100); // Default weight value set to 100
            printf("Graphe créé avec succès !\n");
            break;
        }
        case 2:
        {
            if (graphe)
            {
                detruireGraphe(graphe);
                graphe = NULL;
                printf("Graphe détruit avec succès !\n");
            }
            else
            {
                printf("Aucun graphe à détruire.\n");
            }
            break;
        }
        case 3:
        {
            if (graphe)
            {
                printf("Veuillez saisir le nom de votre sommet : ");
                NomSom nom;
                scanf("%s", nom);
                ajouterUnSommet(graphe, nom);
            }
            else
            {
                printf("Veuillez créer un graphe d'abord.\n");
            }
            break;
        }
        case 4:
        {
            if (graphe)
            {
                printf("Veuillez saisir le sommet de départ : ");
                NomSom somD;
                scanf("%s", somD);
                printf("Veuillez saisir le sommet d'arrivée : ");
                NomSom somA;
                scanf("%s", somA);
                printf("Veuillez entrer le coût de l'arc : ");
                int cout;
                scanf("%d", &cout);
                ajouterUnArc(graphe, somD, somA, cout);
            }
            else
            {
                printf("Veuillez créer un graphe d'abord.\n");
            }
            break;
        }
        case 5:
        {
            if (graphe) ecrireGraphe(graphe);
            else printf("Veuillez créer un graphe d'abord.\n");
            break;
        }
        case 6:
        {
            if (graphe) parcoursProfond(graphe);
            else printf("Veuillez créer un graphe d'abord.\n");
            break;
        }
        }
    }

    if (graphe)
    {
        detruireGraphe(graphe);
    }

    printf("Programme terminé. À S6 !\n");
    return 0;
}
