#include <stdlib.h>
#include <string.h>


#define MAX 15
#define sizedataf 100

typedef struct test
	{
		int id;
		char prio;			//H=priorité_haute M=priorité_moyenne B=priorité_basse
		char type[MAX];
		char duree[MAX];
		char temperature[MAX];
		char etat[MAX];			//en cours, prêt, fini
		struct test *suiv;
	}TST;



TST* Insert_liste(TST* tete_list, TST* test);
TST * Nouveau_test(TST * N);
TST* creerlist_file(FILE* fic,TST* test1);
void Aff_list(TST* Tete);
TST* tri_list_pr(TST* tete_list);
TST* insBP(TST *T, TST *N);
