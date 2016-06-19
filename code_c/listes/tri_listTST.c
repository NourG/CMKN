//import de listetest.txt sous forme de liste chainée récursive trié par priorité et chronologiquement(les tests les + 

#include <stdio.h>
#include "LSTtests.h"



int main()
	{
		
		TST* list_fin=NULL;
		FILE *fp2;
		fp2 = fopen("listetest_triee.txt","r");
		if(fp2!=NULL)
			{
				list_fin=tri_tests_list(fp2);
				
			}
		fclose(fp2);
		Aff_list(list_fin);
		return 0;
	}


TST* insertion_recursive(TST* tete_list,TST* test)
	{
		if(tete_list==NULL)
			{
				printf("liste vide\n");
				return test;
			}
		if(test->prio=='H')
			{
					test->suiv=tete_list;
					printf("test inséré en tete de liste\n");
					return test;
			}
		else
			{
				
				tete_list->suiv=insertion_recursive(tete_list->suiv,test);
				return tete_list;
			}
	}




TST* tri_tests_list(FILE* fp2)
	{
		TST* list=NULL;
		TST* test1=NULL;
		char ligne[sizedataf];	
		char* tmp;			//pointeur/extracteur  de chaine tampon
		char* pt0;			//pointeur 0 de chaine(identifiant test) 
		char* pt1;			//pointeur 1 de chaine(priorité du test)
		char* pt2;			//pointeur 2 de chaine(nom produit)
		char* pt3;			//pointeur 3 de chaine(nombre de produits)
		char* pt4;			//pointeur 4 de chaine(nom de la 1ere etape de test)
		char* pt5;			//pointeur 5 de chaine(nom 2e etape de test)
		char* pt6;			//pointeur 6 de chaine(duree en heure 1e etape)
		char* pt7;			//pointeur 7 de chaine(duree en minute 1e etape)
		char* pt8;			//pointeur 8 de chaine(duree en seconde 1e etape)
		char* pt9;			//pointeur 9 de chaine(duree en heure 2e etape)
		char* pt10;			//pointeur 10 de chaine(duree en minute 2e etape)
		char* pt11;			//pointeur 11 de chaine(temperature1 test)
		char* pt12;			//pointeur 12 de chaine(temperature2 test)
		char* pt13;			//pointeur 13 de chaine(etat test)
				
			while(fgets(ligne,sizedataf,fp2)!=NULL)		//retire la 1ere ligne avec \n
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
					//nom du ou des produit(s)
					tmp=strtok_r(pt1," ",&pt2);
					strcpy(test1->nom_produit,tmp);
					//nombre de produits
					tmp=strtok_r(pt2," ",&pt3);	
					test1->nbr_produit=atoi(tmp);
					//1ere etape de test
					tmp=strtok_r(pt3," ",&pt4);
					strcpy(test1->process1,tmp);
					//2e étape de test
					tmp=strtok_r(pt4," ",&pt5);
					strcpy(test1->process2,tmp);
					//duree en heure de la 1ere etape du test
					tmp=strtok_r(pt5," ",&pt6);
					test1->heure_proc1=atoi(tmp);
					//duree en minute de la 1ere etape du test
					tmp=strtok_r(pt6," ",&pt7);
					test1->minute_proc1=atoi(tmp);
					//duree en seconde de la 1ere etape du test
					tmp=strtok_r(pt7," ",&pt8);
					test1->sec_proc1=atoi(tmp);
					//duree en heure de la 2e etape du test
					tmp=strtok_r(pt8," ",&pt9);
					test1->heure_proc2=atoi(tmp);
					//duree en minute de la 2e etape du test
					tmp=strtok_r(pt9," ",&pt10);
					test1->minute_proc2=atoi(tmp);
					//duree en seconde de la 2e etape du test
					tmp=strtok_r(pt10," ",&pt11);
					test1->sec_proc2=atoi(tmp);
					//temperature etape 1
					tmp=strtok_r(pt11," ",&pt12);
					test1->temperature1=atoi(tmp);
					//temperature etape 2
					tmp=strtok_r(pt12," ",&pt13);
					test1->temperature2=atoi(tmp);
					//etat
					tmp=strtok_r(pt13," ",&tmp);
					strcpy(test1->etat,tmp);

					//insertion de maillon (d'un test) dans la liste
					list=insertion_recursive(list,test1);
				}
					
					return list;
	
	}
