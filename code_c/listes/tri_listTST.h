//import de listetest.txt sous forme de liste chainée récursive trié par priorité et chronologiquement(les tests les + 

#include <stdio.h>
#include "listes/listesTST_OPR.h"



int main()
	{
		
		TST* list_fin=NULL;
		FILE *fp2;
		fp2 = fopen("source/listetest_triee.txt","r");
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
		TST* tete=NULL;
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
					//nom du ou des produit(s)
					tmp=strtok_r(pt1," ",&pt2);
					strcpy(test1->nom_produit,tmp);
					//nombre de produits
					tmp=strtok_r(pt2," ",&pt3);
					test1->nbr_produit=atoi(tmp);
					//1ere etape de test
					tmp=strtok_r(pt3," ",&pt4);
					strcpy(test1->process1,tmp);
					
					//duree en heure de la 1ere etape du test
					tmp=strtok_r(pt4," ",&pt5);
					test1->heure_proc1=atoi(tmp);
					//duree en minute de la 1ere etape du test
					tmp=strtok_r(pt5," ",&pt6);
					test1->minute_proc1=atoi(tmp);
					
					//temperature etape 1
					tmp=strtok_r(pt6," ",&pt7);
					test1->temperature1=atoi(tmp);
					
					//etat
					tmp=strtok_r(pt7," ",&tmp);
					strcpy(test1->etat,tmp);

					//insertion de maillon (d'un test) dans la liste
					tete=Insert_liste(tete,test1);

				}
		return tete;			//tete = @liste de tests et maillons
	}

