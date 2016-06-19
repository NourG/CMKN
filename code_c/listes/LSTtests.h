#include <stdlib.h>
#include <string.h>


#define MAX 20
#define sizedataf 500

typedef struct test//ou produit ?
	{
		int id;
		char prio;			//H=priorité_haute M=priorité_moyenne B=priorité_basse
		char nom_produit[MAX];		//nom des produits à tester
		int nbr_produit;			
		char process1[MAX];
		char process2[MAX];
		int heure_proc1,minute_proc1,sec_proc1;		// durée du test dans la 1ere étape			
		int heure_proc2,minute_proc2,sec_proc2;		// durée du test dans la 2e étape
		int temperature1,temperature2;		//température pour la 1ere etape et 2e etape
		char etat[MAX];			//en cours, prêt, fini
		struct test *suiv;
	}TST;



TST* Insert_liste(TST* tete_list, TST* test);
TST* Nouveau_test(TST * N);
TST* creerlist_file(FILE* fic,TST* test1);
void Aff_list(TST* Tete);
TST* tri_tests_list(FILE* fp2);
TST* insertion_recursive(TST* tete_list,TST* test);

void* temps_1test(void *arg);
void* lecture_horloge(void *arg);
void* horloge(void *arg);


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
				printf("id=%d\tPriorité=[%c]\tNom Produit=[%s]\tNombre Produit=[%d]\tNom 1er test=[%s]\t Nom 2e test=[%s]\tduree etape1=[%dh%dm%ds]\tduree etape2=[%dh%dm%ds]\ttempérature1=[%d°C]\t température2=[%d°C]\tetat=[%s]\n",
				Tete->id,Tete->prio,Tete->nom_produit,Tete->nbr_produit,
				Tete->process1,Tete->process2,
				Tete->heure_proc1,Tete->minute_proc1,Tete->sec_proc1,
				Tete->heure_proc2,Tete->minute_proc2,Tete->sec_proc2,
				Tete->temperature1,Tete->temperature2,Tete->etat);
				i_cpt++;
				Tete = Tete->suiv;
			}
		if(i_cpt == 0)
			{
				printf("\n Liste vide !!");
			}
	}




