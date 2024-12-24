#include "GRAPHEMAT.h"

int i,j;

void razMarque(GrapheMat* graphe);

GrapheMat* creerGrapheMat (int nMax, int value){
//allocation de graphe
GrapheMat* graphe = (GrapheMat*)malloc(sizeof(GrapheMat));
graphe->n=0;
graphe->nMax=nMax;
graphe->value=value;
graphe->nomS=(NomSom*)malloc(sizeof(NomSom) *nMax);
graphe->marque=(booleen*) malloc(sizeof(booleen) *nMax);
graphe->element=(int*) malloc(sizeof(int) *nMax *nMax);
graphe->valeur=(int*) malloc(sizeof(int) *nMax *nMax);


 for( i=0;i<nMax;i++)
 {
     for( j=0;j<nMax;j++)
     {
         graphe->element[i*nMax+j]=faux;
         graphe->valeur[i*nMax+j]=INFINI;

     }
 }
 razMarque(graphe);
 return graphe;

}


//remise a faux du tableau marque (pour les parcours de graphe )
void razMarque(GrapheMat* graphe){
    for(int i=0;i<graphe->n;i++) graphe->marque[i]=faux;
}



//desallocation d'un graphe
void detruireGraphe(GrapheMat* graphe)
{
    free(graphe->nomS);
    free(graphe->marque);
     free(graphe->element);
      free(graphe->valeur);
      free(graphe);
}
//ajouter un sommet
static int rang (GrapheMat* graphe, NomSom nom){
i=0;
booleen trouve = faux;
while ((i<graphe->n)&& !trouve){
trouve = strcmp(graphe -> nomS[i],nom) == 0;
if (!trouve) i++;
}
return trouve ? i:-1;
}

void ajouterUnSommet (GrapheMat* graphe, NomSom nom){
    if(rang(graphe,nom)==-1){
        if(graphe->n<graphe->nMax){
            strcpy(graphe->nomS[graphe->n++],nom);
        }
        else{
            printf("\n Nombre de sommets > %d\n",graphe->nMax);
        }
        }else{
            printf("\n%s deja defini \n",nom);
        }


}
// ajouter un arc :

void ajouterUnArc (GrapheMat* graphe, NomSom somD, NomSom somA, int cout){
int nMax=graphe->nMax;
int rd=rang(graphe,somD);
int rg=rang(graphe,somA);
graphe->element[rd*nMax+rg]=vrai;
graphe->valeur[rd*nMax+rg]=cout;
}

void ecrireGraphe (GrapheMat* graphe){
	int nMax = graphe->nMax;

	for( i=0;i<graphe->n;i++) printf("%s ",graphe->nomS[i]);
	printf(";\n");

	for( i=0;i<graphe->n;i++){
		printf("\n%s ",graphe->nomS[i]);
		for( j=0;j<graphe->n;j++){
			if (graphe->element[i*nMax+j] == vrai){
				printf("%s ",graphe->nomS[j]);
				if(graphe->value){
					printf("(%d)",graphe->valeur[i*nMax+j]);
				}
			}
		}
	printf(";");

	}
}

void profondeur(GrapheMat* graphe, int numSommet)
{
    int nMax=graphe->nMax;
    graphe->marque[numSommet]=vrai;
    printf("%s\n",graphe->nomS[numSommet]);
    for(i=0;i<graphe->n;i++)
    {
        if((graphe->element[numSommet*nMax+i]==vrai)
           && !graphe->marque[i])
        {
            profondeur(graphe,i);
        }
    }


}

//parcours profond
void parcoursProfond (GrapheMat* graphe)
{
    razMarque(graphe);
    for(i=0;i<graphe->n;i++)
    {
        if(!graphe->marque[i])
        {
            profondeur(graphe,i);
        }
    }
}
