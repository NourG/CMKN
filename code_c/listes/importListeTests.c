// Module d'Import des données : Liste des caractéristiques de tests à passer 
// Un maillon = Id test Type de test    Température     Durée   Nb pièces/test

#include <stdio.h>
#include "LSTtests.h"

int main()
	{

		TST* liste=NULL;		//tete de liste
		TST* test=NULL;
		//TST* lst_tri=NULL;
		int f;
		FILE *fp;

	   	fp = fopen("listetests.txt","r");
		
		if(fp!=NULL)
			{	//Insere le premier maillon dans la tete de liste
				
				liste=creerlist_file(fp,test);
				Aff_list(liste);
			}
		/*lst_tri=tri(liste);
		Aff_list(lst_tri);*/
		f=fclose(fp);
		if(f!=0)
			{
				printf("PB fermeture du fichier\n");
			}	
		return 0;
	}




