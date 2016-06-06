#include <stdlib.h>
#include <string.h>


#define MAX 15
#define sizedataf 100

typedef struct operateur
	{
		int id;
		char mouv[MAX];
		int heure_arrivee;
		int minute_arrivee;
		int seconde_arrivee;
		int heure_depart;
		int minute_depart;
		int seconde_depart;
		struct operateur *suiv;
	}OPR;


OPR *nouveau_operateur();
OPR* Insert_liste(OPR* tete_list, OPR* operateur);
OPR * cree_operator_list(FILE* fic, OPR* operateur, OPR* tete);
void aff_list(OPR* tete);
