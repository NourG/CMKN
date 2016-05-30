#include <stdlib.h>
#include <string.h>


#define MAX 15
#define sizedataf 50

typedef struct tests
	{
		int id;
		char type[MAX];
		char duree[MAX];
		char temperature[MAX];
		struct tests *suiv;
	}TST;



TST* Insert_liste(TST* tete_list, TST* test);
TST * Nouveau_test();
TST* creerlist_file(FILE* fic);
void Aff_list(TST* T);
