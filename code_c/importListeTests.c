// Module d'Import des données : Liste des caractéristiques de tests à passer 
// Un maillon = Id test Type de test    Température     Durée   Nb pièces/test

#include <stdio.h>
#include "headerLST.h"

int main()
	{

		TST* liste=NULL;		//tete de liste
		int f;
		FILE *fp;

	   	fp = fopen("listetests.txt","r");
		
		if(fp!=NULL)
			{	//Insere le premier maillon dans la tete de liste
				liste=creerlist_file(fp);
				Aff_list(liste);
			}
		//fp=NULL;
		f=fclose(fp);
		if(f!=0)
			{
				printf("PB fermeture du fichier\n");
			}	
		return 0;
	}

//Création de la liste de tests selon les donnés entrés par l'utilisateur dans le datafile listetests.txt 

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

						
TST* creerlist_file(FILE* fic)			//crée une liste de test à partir de toutes les lignes d'un fichier
	{
		TST* test1;
		TST* tete=NULL;
		char ligne[sizedataf];	
		char* tmp;			//pointeur/extracteur  de chaine tampon
		char*pt0;			//pointeur 0 de chaine(type test) 
		char*pt1;			//pointeur 1 de caractère(priorité du test)
		char*pt2;			//pointeur 3 de chaine(duree test)
		char*pt3;			//pointeur 4 de chaine(temperature test)
		char*pt4;			//pointeur 5 de chaine(etat test)
				
			while(fgets(ligne,sizedataf,fic)!=NULL)		//retire la 1ere ligne avec \n
				{
					ligne[strlen(ligne)-1]='\0';		//"		      " sans "
					test1=Nouveau_test();
				//traitement et affectation de chaque chaine séparé d'un espace = donnée d'un test de la liste. 
					tmp=strtok_r(ligne," ",&pt0);	// fonction strtok_r() delimiteur d'espace blanc pas à pas  return a string in tmp
					test1->id=atoi(tmp);
					tmp=strtok_r(pt0," ",&pt1);	  
					test1->prio=*tmp;		
					tmp=strtok_r(pt1," ",&pt2);
					strcpy(test1->type,tmp);
					tmp=strtok_r(pt2," ",&pt3);
					strcpy(test1->duree,tmp);
					tmp=strtok_r(pt3," ",&pt4);
					strcpy(test1->temperature,tmp);	
					tmp=strtok_r(pt4," ",&tmp);
					strcpy(test1->etat,tmp);
	
					tete=Insert_liste(tete,test1);	
				}
						
		return tete;			//tete = @liste de tests
	}



void Aff_list(TST* Tete)
	{
		int i_cpt = 0;
		printf("***************************LISTE DE TESTS*********************************\n");
		while(Tete != NULL)
			{ 
				printf("id=%d\tPriorité=[%c]\ttypetest=[%1s]\tduree=[%1s]\ttemperature=[%1s]\tetat=[%1s]\n",Tete->id,Tete->prio,Tete->type,Tete->duree,Tete->temperature,Tete->etat);
				i_cpt++;
				Tete = Tete->suiv;
			}
		if(i_cpt == 0)
			{
				printf("\n Liste vide !!");
			}
	}


TST* tri_list_pr(TST* tete_list)
	{
		while(tete_list!=NULL)
			{
				
				strcmp(tete_list->



		return NULL;
	}

						

