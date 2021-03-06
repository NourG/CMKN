#include <stdlib.h>
#include <string.h>
#define MAX 20
#define sizedataf 500
#define MAXI 15
#define sizedata 100

typedef struct test//ou produit ?
	{
		int id;
		char prio;			//H=priorité_haute M=priorité_moyenne B=priorité_basse
		char nom_produit[MAX];		//nom des produits à tester
		int nbr_produit;
		char process1[MAX];
		//char process2[MAX];
		int heure_proc1,minute_proc1;		// durée du test dans la 1ere étape
		//int heure_proc2,minute_proc2,sec_proc2;		// durée du test dans la 2e étape
		int temperature1;		//température pour la 1ere etape et 2e etape
		char etat[MAX];			//en cours, prêt, fini			Aremplir !!
		struct test *suiv;
	}TST;

typedef struct operateur
	{
		int id;
		char mouv[MAXI];
		//char habilite[MAXI];
		int heure_arrivee;
		int minute_arrivee;
		int seconde_arrivee;
		int heure_depart;
		int minute_depart;
		int seconde_depart;
		struct operateur *suiv;
	}OPR;


OPR *nouveau_operateur();
OPR* insert_list(OPR* tete_list, OPR* operateur);
OPR * cree_operator_list(FILE* fic, OPR* operateur, OPR* tete);
void aff_listOPR(OPR* tete);

TST* Insert_liste(TST* tete_list, TST* test);
TST* Nouveau_test(TST * N);
TST* creerlist_file(FILE* fic,TST* test1);
void Aff_list(TST* Tete);
TST* tri_tests_list(FILE* fp2);
TST* insertion_recursive(TST* tete_list,TST* test);
void push_test(TST* Tete);
void* get_liste(void *arg);
void* lecture_horloge(void *arg);
void* horloge(void *arg);
void* sdl(void * arg);

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

				//crée une liste de test à partir de toutes les lignes d'un fichier
TST* creerlist_file(FILE* fic,TST* test1)			
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



void Aff_list(TST* Tete)
	{
		int i_cpt = 0;
		printf("***************************LISTE DE TESTS*********************************\n");
		while(Tete != NULL)
			{
				printf("id=%d\tPriorité=[%c]\tNom Produit=[%s]\tNombre Produit=[%d]\tNom 1er test=[%s]\tduree etape1=[%dh%dm]\ttempérature1=[%d°C]\tetat=[%s]\n",
				Tete->id,Tete->prio,Tete->nom_produit,Tete->nbr_produit,
				Tete->process1,
				Tete->heure_proc1,Tete->minute_proc1,
				
				Tete->temperature1,Tete->etat);
				i_cpt++;
				Tete = Tete->suiv;
			}
		if(i_cpt == 0)
			{
				printf("\n Liste vide !!");
			}
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


OPR* insert_list(OPR* tete_list, OPR* operateur)
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
		char line[sizedata];
		char *pt0;
		char *pt1;
		char *pt2;
		char *pt3;
		char *pt4;
		char *pt5;
		char *pt6;
		char *tmp;
			while(fgets(line,sizedata,fic)!=NULL)
				{
					line[strlen(line)-1]='\0';		
					operateur=nouveau_operateur();

					//id
					tmp=strtok_r(line," ",&pt0);	
					operateur->id=atoi(tmp);
						
					tmp=strtok_r(pt0," ",&pt1);
					strcpy(operateur->mouv,tmp);

					/*tmp=strtok_r(pt1," ",&pt2);
					strcpy(operateur->habilite,tmp);*/

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
	
					tete=insert_list(tete,operateur);
				}
			return tete;
	}


void aff_listOPR(OPR* tete)
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


int main_operator()
	{
		OPR* tete=NULL;
		OPR* operateur=NULL;
		FILE *fic;
		int fc;
		fic = fopen("sources_txt/caracoperateurs.txt","r");
		
		if(fic!=NULL)
			{	//Insere le premier maillon dans la tete de liste
				
				tete=cree_operator_list(fic,operateur,tete);
				
			}
		else
			{	
				printf("Erreur fichier\n");
				return 1;
			}
		fc=fclose(fic);
		aff_listOPR(tete);
		if(fc!=0)
			{
				printf("PB fermeture du fichier\n");
			}	
		return 0;
	}
