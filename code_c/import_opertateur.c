// Module qui récolte les données des opérateurs depuis un fichier et se construit sur une liste 
#include <stdio.h>
#include "headerOPR.h"



int main()
	{
		OPR* tete=NULL;
		OPR* operateur=NULL;
		FILE *fic;
		int fc;
		fic = fopen("caracoperateurs.txt","r");
		
		if(fic!=NULL)
			{	//Insere le premier maillon dans la tete de liste
				
				tete=cree_operator_list(fic,operateur,tete);
				aff_list(tete);
			}
		fc=fclose(fic);
		if(fc!=0)
			{
				printf("PB fermeture du fichier\n");
			}	
		return 0;
	}

OPR *nouveau_operateur()
	{
		OPR* N=NULL;
		N=(OPR*)malloc(sizeof(OPR));
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


OPR* Insert_liste(OPR* tete_list, OPR* operateur)
	{
		/* "tete_list" pointeur tête, "test" élément à insérer */
		if(operateur==NULL)
			{
				printf("PB [Insert_liste]maillon de test\n");
				return NULL;
			}
		else
			{
				if(tete_list==NULL)			/* cas liste vide */
					{
						tete_list=operateur;
						printf("Insérer en tete de liste\n");
					}
				else 
					{
				
						operateur->suiv=tete_list;
						tete_list=operateur;
						printf("test inséré dans la liste\n");
					}
			}
		return tete_list;	
	}


OPR * cree_operator_list(FILE* fic,OPR* operateur, OPR* tete)
	{
		char line[sizedataf];
		char *pt0;
		char *pt1;
		char *pt2;
		char *pt3;
		char *pt4;
		char *pt5;
		char *pt6;
		char *tmp;
			while(fgets(line,sizedataf,fic)!=NULL)
				{
					line[strlen(line)-1]='\0';		
					operateur=nouveau_operateur();

					//id
					tmp=strtok_r(line," ",&pt0);	
					operateur->id=atoi(tmp);
						
					tmp=strtok_r(pt0," ",&pt1);
					strcpy(operateur->mouv,tmp);

					tmp=strtok_r(pt1," ",&pt2);	
					operateur->heure_arrivee=atoi(tmp);
	
					tmp=strtok_r(pt2," ",&pt3);	
					operateur->minute_arrivee=atoi(tmp);

					tmp=strtok_r(pt3," ",&pt4);	
					operateur->seconde_arrivee=atoi(tmp);

					tmp=strtok_r(pt4," ",&pt5);	
					operateur->heure_depart=atoi(tmp);

					tmp=strtok_r(pt5," ",&pt6);	
					operateur->minute_depart=atoi(tmp);

					tmp=strtok_r(pt6," ",&tmp);	
					operateur->seconde_depart=atoi(tmp);
	
					tete=Insert_liste(tete,operateur);
				}
			return tete;
	}


void aff_list(OPR* tete)
	{
		int i = 0;
		printf("***************************LISTE D'OPERATEURS*********************************\n");
		while(tete != NULL)
			{ 
				printf("id=%d\tRapidité=[%s]\tArrivée=[%dh%dm%ds]\tDépart=[%dh%dm%ds]\n",tete->id,tete->mouv,tete->heure_arrivee,tete->minute_arrivee,tete->seconde_arrivee,tete->heure_depart,tete->minute_depart,tete->seconde_depart);
				i++;
				tete = tete->suiv;
			}
		if(i == 0)
			{
				printf("\n Liste vide !!");
			}

	}

		
