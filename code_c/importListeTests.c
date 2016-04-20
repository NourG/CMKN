// Module d'Import des données : Liste des caractéristiques de tests à passer 
// Un maillon = Id test Type de test    Température     Durée   Nb pièces/test


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define sizedata 100

typedef struct tests
	{
		int id;
		char Type[MAX];
		int duree;
		int temperature;
		int nbpiecetest;
		struct Tests *suiv;
	}TST;

char* import_data_file(FILE *fic/*,TST *List_p*/);
TST* Nouveau(char * ligne);
void myread(char *data, size_t nb, FILE *fp);
TST* Insert_liste(char* data, TST* maillon);
char* test(char* data);

int main()
	{
		/*TST* nv=NULL;
		TST* liste;*/
		char data[50];
		char* ligne;
		//nv=Nouveau();
		/*if(fich==NULL)
			{
				liste=import_file(fich,nv);	
				printf("id=%d\n",liste->id);
			}
		
				fich = fopen("listetests.txt","r");
				if(fich!=NULL)
					{
						myread(data,2,fich);
						ligne=data;
					}
		printf("ligne = [%s]",ligne);
		fclose(fich);*/
		FILE* fich=NULL;
		import_data_file(fich);		

	return 0;
	}


TST * Nouveau(char * ligne)			//fct permettant la création d'un maillon. Maillon = test
	{ 
		TST * N;
		N=(TST*)malloc(sizeof(TST));
		N->suiv=NULL;
		if( N == NULL)
			{
				printf("\nPb malloc\n");
			}
		return N;				//Sinon on retourne le maillon vide
	}


void myread(char *data, size_t nb, FILE *fp)		//recupere une ligne entière sans le '\n' à la fin
{
    char *pt;
    fgets(data, nb, fp);
    if ((pt=strchr(data, '\n')) != NULL) *pt='\0';
}


char* import_data_file(FILE *fic/*,TST *List_p*/)		//retourne La liste de tests dans une chaine de caractère si OK sinon -1
	{
		int resread;
		char* List_p[sizedata];
		char *lst;
		
				fic = fopen("listetests.txt","r");
				if(fic!=NULL)
					{
												
							resread = fread(List_p,sizeof(TST),10,fic);
							lst=List_p;
							printf("%s\n",lst);
							fclose(fic);
							//myread(
							
							
							if(resread==0)				//si 0 élem retourné par fread alors sortir de la boucle
								{
									fclose(fic);
									return NULL;
								}
						}	
						
						
		return lst;
	}

char* test(char* data)				//fonction qui retourne une ligne de data(de impor_data_file) correspondant à un test particulier pour pouvoir en crée un nouveau maillon dans la liste chainée de tests
	{
		int i,j;
		char *pt;
		for(i=0;i<sizedata;i++)
		{
				
				/*if ((pt=strchr(data, '\n')) != NULL)
				{
					*pt='\0';
					
				}*/
				j=strlen("data");
				printf("longueur=%d\n",j);
		}
	return NULL;
	}

TST* Insert_liste(char* data, TST* maillon)
	{
		return NULL;
	}

						

