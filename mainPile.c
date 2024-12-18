#include "PERSONNE.c"
#include "PILE.c"
#include "LISTE_CHAINEE.c"

int menu() {
    printf("\n=== Gestion d'une pile de personnes ===\n");
    printf("\nVeuillez entrer votre choix :\n");
    printf("1. Empiler trois personnes dans la pile\n");
    printf("2. Afficher le contenu de la pile\n");
    printf("3. D\202piler un \202l\202ment de la pile\n"); // é = \202 en octal
    printf("0. Quitter le programme\n\n");
    printf("Votre choix : ");

    int code;
    scanf("%d", &code);
    return code;
}
int main(){ 
    int choix=menu();
    int i=0;
    ch15 Nom;
    ch15 Prenom;
    pile* p = creerPile(0, ecrirePersonne, comparerPersonne);
    do{
        switch(choix){

            case 1 :
                while(i<3){
                printf("veuillez saisir le nom du personne %d a empiler :",i+1);
                scanf("%s",Nom);
                printf("veuillez saisir le prenom du personne %d a empiler :",i+1);
                scanf("%s",Prenom);
                Personne* perso=creerPersonne(Nom,Prenom);
                empiler(p,perso);
                i++;
                }
                break;

            case 2:
                listerPile(p);
                break;

            case 3:
                printf("\nVeuillez saisir le nom de la personne a depiler : \n");
                scanf("%s", Nom);
                printf("\nVeuillez saisir le prenom de la personne a depiler : \n");
                scanf("%s", Prenom);
                if (depiler(p) != NULL) {
                    printf("Personne depilee avec succes.\n");
                } else {
                    printf("Personne introuvable dans la pile.\n");
                }
                break;
        }
        choix=menu();
    }while(choix!=0);
    return 0;
}
