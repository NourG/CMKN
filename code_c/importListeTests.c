// Module d'Import des données : Liste des caractéristiques de tests à passer 
// Un maillon = Id test Type de test    Température     Durée   Nb pièces/test


#include <stdio.h>
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
		//int nbpiecetest;
		struct tests *suiv;
	}TST;



TST* Insert_liste(TST* tete_list, TST* test);
TST * Nouveau_test();
TST* test_line(FILE* fic);
void Aff(TST* T);
TST* creerlist_file(FILE* fic);
void Aff_list(TST* T);



int main()
	{
	//TST* test=NULL;
	TST* liste=NULL;
	int f;
	//TST* tete=NULL;
	//tete=Nouveau_test();
	FILE *fp;

   	fp = fopen("listetests.txt","r");
		
	if(fp!=NULL)
	{		//Insere le premier maillon dans la tete de liste
		/*test=test_line(fp);
		liste=Insert_liste(liste,test);	
		tete=Insert_liste(tete,test);
		Aff(liste);*/

		liste=creerlist_file(fp);
		Aff_list(liste);
	}
		
	f=fclose(fp);
	if(f!=0)
	{
		printf("PB fermeture fichier\n");
	}	
	return 0;
	}


TST * Nouveau_test()			//fct permettant la création d'un maillon. Maillon = test
	{ 
		TST * N;
		N=(TST*)malloc(sizeof(TST));
		if( N == NULL)
			{
				printf("\nPb malloc\n");
			}
		else
		{
			printf("Maillon ok\n");
			N->suiv=NULL;
			
		}	
		return N;			
	}


TST* Insert_liste(TST* tete_list, TST* test)
	{
	/* "tete_list" pointeur tête, "test" élément à insérer */
		if(test==NULL)
		{
			printf("PB [Insert_liste]maillon de test\n");
			return NULL;
		}
		else
		{
			if(tete_list==NULL)			/* cas liste vide */
			{
				tete_list=test;
				printf("Insérer en tete de liste\n");
				
				
			}
			else 
			{
				
				test->suiv=tete_list;
				tete_list=test;
				printf("test inséré dans la liste\n");
			}
			

		}
		return tete_list;
		
	}

TST* test_line(FILE* fic)				//fct qui retourne un maillon de type test à partir de la premiere ligne du fichier
	{
		
		TST* test1;
		char ligne[sizedataf];	
		char* tmp;			//pointeur/extracteur  de chaine tampon
		char*pt;			//pointeur 2 de chaine(type test) 
		char*pt2;			//pointeur 3 de chaine(duree test)
		char*pt3;			//pointeur 4 de chaine(temperature test)
		test1=Nouveau_test();
		
		
						fgets(ligne,sizedataf,fic);			//retire la 1ere ligne avec \n
						ligne[strlen(ligne)-1]='\0';			//"		      " sans "
						tmp=strtok_r(ligne," ",&pt);//comme fonction strtok() mais pas à pas pour chaque delimiteur d'espace blanc 
						test1->id=atoi(tmp);			
						tmp=strtok_r(pt," ",&pt2);
						strcpy(test1->type,tmp);
						tmp=strtok_r(pt2," ",&pt3);
						strcpy(test1->duree,tmp);
						tmp=strtok_r(pt3," ",&tmp);
						strcpy(test1->temperature,tmp);	

					
					
		return test1;
	}

void Aff_test1(TST* T)
	{ 
	printf("id=%d\ttypetest=[%s]\tduree=[%s]\ttemperature=[%s]\n",T->id,T->type,T->duree,T->temperature);
}

						
TST* creerlist_file(FILE* fic)			//crée une liste de test à partir de toutes les lignes d'un fichier
	{
	
		TST* test1;
		TST* tete=NULL;
		char ligne[sizedataf];	
		char* tmp;			//pointeur/extracteur  de chaine tampon
		char*pt;			//pointeur 2 de chaine(type test) 
		char*pt2;			//pointeur 3 de chaine(duree test)
		char*pt3;			//pointeur 4 de chaine(temperature test)
				
						while(fgets(ligne,sizedataf,fic)!=NULL)		//retire la 1ere ligne avec \n
						{
						ligne[strlen(ligne)-1]='\0';		//"		      " sans "
						test1=Nouveau_test();
						tmp=strtok_r(ligne," ",&pt);//= fonction strtok() mais pas à pas pour chaque delimiteur d'espace blanc 
						
						test1->id=atoi(tmp);			
						tmp=strtok_r(pt," ",&pt2);
						strcpy(test1->type,tmp);
						tmp=strtok_r(pt2," ",&pt3);
						strcpy(test1->duree,tmp);
						tmp=strtok_r(pt3," ",&tmp);
						strcpy(test1->temperature,tmp);	
						tete=Insert_liste(tete,test1);	
						}
					//Aff_list(tete);
						
	return tete;			//tete = @liste de tests
	}





void Aff_list(TST* T)
	{ int i_cpt = 0;
		printf("***************************LISTE DE TESTS*********************************\n");
	while(T != NULL)
	{ 
		
		printf("id=%d\ttypetest=[%s]\tduree=[%s]\ttemperature=[%s]\n",T->id,T->type,T->duree,T->temperature);
		i_cpt++;
		T = T->suiv;
	}
	if(i_cpt == 0)
	printf("\n Liste vide !!");
	
}



						

