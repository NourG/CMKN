
typedef struct {   // déclaration du type de la donnée partagée
	int heure, minute;
	int jour, mois;
	int seconde;
	int k ;    //coef d'acceleration
} type_temps;

 //déclaration du verrou
 pthread_mutex_t verrou;
type_temps  temps;
//corp des thread*********************************
void ajout_time_test(type_temps* push_temps,int minute,int heure);
int convert_minute_time(type_temps *push_temps);
int convert_heure_time(type_temps *push_temps);

//*******************************************



void* get_liste(void *arg)//recupere la tete de liste
{
printf("***************************getlist*********************************\n");

		TST* liste=NULL;		//tete de liste
		TST* test=NULL;
		//TST* lst_tri=NULL;
		int f;
		FILE *fp;

	   	fp = fopen("listetests.txt","r");
printf("***************************getlist*********************************\n");
		if(fp!=NULL)
			{	//Insere le premier maillon dans la tete de liste

				liste=creerlist_file(fp,test);
			//	Aff_list(liste);
			}


		f=fclose(fp);
		if(f!=0)
			{
				printf("PB fermeture du fichier\n");
			}
			printf("***************************getlist fin*********************************\n");

pthread_exit(liste);

}

void* lecture_horloge(void *arg)
{// déclaration du corps de la tâche qui lit la donnée partagée. On considère qu'elle s'exécute indéfiniment
 type_temps notre_temps;

 while(1)
 {

							pthread_mutex_lock(&verrou);//
							notre_temps = temps;
							pthread_mutex_unlock(&verrou);
						    printf(" %d  -- %d %d  %d \n",notre_temps.jour,notre_temps.heure,notre_temps.minute,notre_temps.seconde);
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


void push_test(TST* Tete)
	{

		printf("***************************LISTE DE TESTS*********************************\n");


		type_temps  push_temps;
		int heure ,minute ;



		while(Tete != NULL)
			{
				push_temps=temps ;
				heure=Tete->heure_proc1;
				minute=Tete->minute_proc1;
				ajout_time_test(&push_temps,minute,heure);
				printf(" le resuslat final temps < %d;jour   %dh  %dm  %ds \n",push_temps.jour,push_temps.heure,push_temps.minute,push_temps.seconde);
				Tete = Tete->suiv;
			}

	}

 void ajout_time_test(type_temps* push_temps,int minute,int heure)
{

    type_temps* result_push ;
    result_push =push_temps;


	   result_push->heure = result_push->heure + heure ;//heure

       if(result_push->heure>23)
       {

		   result_push->jour=result_push->jour + 1;
			convert_heure_time(result_push);
	   }

       result_push->minute = result_push->minute + minute ;//minute

       if(result_push->minute>59)
       {
			result_push->heure=result_push->heure + 1;
			convert_minute_time(result_push);
	   }


	          if(result_push->jour>30)
       {

		   result_push->jour=result_push->jour - 30;

	   }

}

  int convert_minute_time(type_temps* result_push)
 {

		   int diff1=0 ;
		   diff1=result_push->minute-60;

		   if(diff1>=60)
		   {
			 result_push->heure=result_push->heure + 1;
			 result_push->minute=diff1;


			 return convert_minute_time(result_push);
		   }


			 result_push->minute=diff1;

          return 1 ;
 }

 int convert_heure_time(type_temps* result_push)
 {

			int diff ;
		   diff=result_push->heure-24;
		   if(diff>=24)
		   {
			 result_push->jour=result_push->jour + 1;
			 result_push->heure=diff;

			 return convert_heure_time(result_push);
		   }


			 result_push->heure=diff;

			return 1 ;
 }



