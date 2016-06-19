





typedef struct {   // déclaration du type de la donnée partagée
	int heure, minute;
	int jour, mois;
	int seconde;
	int k ;    //coef d'acceleration
} type_temps;


pthread_mutex_t verrou; //déclaration du verrou
	type_temps  temps;
//corp des thread*********************************

void* temps_1test(void *arg)
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


		f=fclose(fp);
		if(f!=0)
			{
				printf("PB fermeture du fichier\n");
			}
sleep(5);
(void) arg;
}

void* lecture_horloge(void *arg)
{// déclaration du corps de la tâche qui lit la donnée partagée. On considère qu'elle s'exécute indéfiniment
 type_temps notre_temps;
 pthread_t  th3 ;
 while(1)
 {

							pthread_mutex_lock(&verrou);//
							notre_temps = temps;
							pthread_mutex_unlock(&verrou);
						    printf(" %d  -- %d %d  %d \n",notre_temps.jour,notre_temps.heure,notre_temps.minute,notre_temps.seconde);

						    if(notre_temps.seconde == 30  )
						    {
							printf("c'est la 30 seconde");
							pthread_create(&th3, NULL,temps_1test,NULL);
							pthread_join(th3, NULL);
							printf("fin du test");


							}

							sleep(1/temps.k);

 }
 (void) arg;
}


void* horloge(void * arg)
{ // déclaration du corps de la tâche qui modifie la donnée partagée. On considère qu'elle s'exécute indéfiniment

 int a,z,e,r;
 while(1)
{

			for(r=temps.jour;r<30;r++)
			{
			pthread_mutex_lock(&verrou);
			temps.jour = temps.jour + 1;
			pthread_mutex_unlock(&verrou);

				for(e=temps.heure;e<23;e++)
				{
				pthread_mutex_lock(&verrou);
				temps.heure = temps.heure + 1;
				pthread_mutex_unlock(&verrou);

					for(z=temps.minute;z<59;z++)
					{
					pthread_mutex_lock(&verrou);
					temps.minute = temps.minute + 1;
					
								
					pthread_mutex_unlock(&verrou);


						for(a=temps.seconde;a<59;a++)
						{
						pthread_mutex_lock(&verrou);
						temps.seconde = temps.seconde + 1;
						pthread_mutex_unlock(&verrou);
						sleep(1/temps.k);
							
						}
					pthread_mutex_lock(&verrou);
					temps.seconde =-1;
					pthread_mutex_unlock(&verrou);
				}
				pthread_mutex_lock(&verrou);
				temps.minute =-1;
				pthread_mutex_unlock(&verrou);
				}
			pthread_mutex_lock(&verrou);
			temps.heure =-1;
			pthread_mutex_unlock(&verrou);
			}
	pthread_mutex_lock(&verrou);
	temps.jour =0;
	pthread_mutex_unlock(&verrou);

}
(void) arg;
}
