// Module d'Import des données : Liste des caractéristiques de tests à passer 
// Un maillon = Id test Type de test    Température     Durée   Nb pièces/test

#include <stdio.h>
#include "headerLST.h"

int main()
	{

		TST* liste=NULL;		//tete de liste
		TST* test=NULL;
		int f;
		FILE *fp;

	   	fp = fopen("listetests.txt","r");
		
		if(fp!=NULL)
			{	//Insere le premier maillon dans la tete de liste
				
				liste=creerlist_file(fp,test);
				Aff_list(liste);
			}
		f=fclose(fp);
		if(f!=0)
			{
				printf("PB fermeture du fichier\n");
			}	
		return 0;
	}

//Création de la liste de tests selon les donnés entrés par l'utilisateur dans le datafile listetests.txt 

TST * Nouveau_test(TST * N)			//fct permettant la création d'un maillon. Maillon = test
	{ 
		
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

						
TST* creerlist_file(FILE* fic,TST* test1)			//crée une liste de test à partir de toutes les lignes d'un fichier
	{
		TST* tete=NULL;
		char ligne[sizedataf];	
		char* tmp;			//pointeur/extracteur  de chaine tampon
		char*pt0;			//pointeur 0 de chaine(type test) 
		char*pt1;			//pointeur 1 de caractère(priorité du test)
		char*pt2;			//pointeur 2 de chaine( duree en heure test)
		char*pt3;			//pointeur 3 de chaine(duree en minute test)
		char*pt4;			//pointeur 4 de chaine(duree en seconde test)
		char*pt5;			//pointeur 5 de chaine(temperature test)
		char*pt6;			//pointeur 6 de chaine(etat test)
				
			while(fgets(ligne,sizedataf,fic)!=NULL)		//retire la 1ere ligne avec \n
				{
					ligne[strlen(ligne)-1]='\0';		
					test1=Nouveau_test(test1);
					//traitement et affectation de chaque chaine séparé d'un espace = donnée d'un test de la liste. 
					//fonction strtok_r() delimiteur d'espace blanc pas à pas return a string in tmp
					//id
					tmp=strtok_r(ligne," ",&pt0);	
					test1->id=atoi(tmp);
					//priorité
					tmp=strtok_r(pt0," ",&pt1);	  
					test1->prio=*tmp;
					//type
					tmp=strtok_r(pt1," ",&pt2);
					strcpy(test1->type,tmp);
					//heure
					tmp=strtok_r(pt2," ",&pt3);
					test1->heure=atoi(tmp);
					//minute
					tmp=strtok_r(pt3," ",&pt4);
					test1->minute=atoi(tmp);
					//seconde
					tmp=strtok_r(pt4," ",&pt5);
					test1->sec=atoi(tmp);
					//temperature
					tmp=strtok_r(pt5," ",&pt6);
					test1->temperature=atoi(tmp);
					//etat
					tmp=strtok_r(pt6," ",&tmp);
					strcpy(test1->etat,tmp);
	
					//insertion de maillon dans la liste
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
				printf("id=%d\tPriorité=[%c]\ttypetest=[%1s]\tduree=[%dh%dm%ds]\ttemperature=[%d°C]\tetat=[%1s]\n",Tete->id,Tete->prio,Tete->type,Tete->heure,Tete->minute,Tete->sec,Tete->temperature,Tete->etat);
				i_cpt++;
				Tete = Tete->suiv;
			}
		if(i_cpt == 0)
			{
				printf("\n Liste vide !!");
			}
	}

//tri liste chainée sert à rien puisque lecture de la liste par l'opérateur juste état test va changer selon l'horloge et la durée de chaque test puis de l'emplacement des type de tests



