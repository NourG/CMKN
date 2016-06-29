
typedef struct {   // déclaration du type de la donnée partagée
	int heure, minute;
	int jour, mois;
	int seconde;
	int k ;    //coef d'acceleration
} type_temps;

typedef struct EVENTS {   // déclaration du type de la donnée partagée
	int heure, minute;
	int jour, mois;
	int seconde;
	int id ;
	int type;
	struct EVENTS *suiv;
	    //sortie des tests ou horaire operateur
} events;

pthread_cond_t condition = PTHREAD_COND_INITIALIZER; /* Création de la condition */
pthread_cond_t condition1 = PTHREAD_COND_INITIALIZER;
 //déclaration du verrou
 pthread_mutex_t even = PTHREAD_MUTEX_INITIALIZER;
 pthread_mutex_t verrou = PTHREAD_MUTEX_INITIALIZER;
type_temps  temps;
events event ;
//corp des thread*********************************
void ajout_time_test(type_temps* push_temps,int minute,int heure);
int convert_minute_time(type_temps *push_temps);
int convert_heure_time(type_temps *push_temps);
void push_test1(TST* Tete);
events* insBP1(events *T,events *N);
events * Nouv(void);
void Aff_list1(events* Tete);
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

							pthread_mutex_lock(&verrou);
							pthread_cond_wait (&condition1, &verrou);//mettre signal cond si on est pas en phase
							notre_temps = temps;
							pthread_mutex_unlock(&verrou);
						    printf(" %d  -- %d %d  %d \n",notre_temps.jour,notre_temps.heure,notre_temps.minute,notre_temps.seconde);
							//usleep(1000000/temps.k);

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
						pthread_cond_signal (&condition1);
						temps.seconde = temps.seconde + 1;
						pthread_mutex_unlock(&verrou);
						usleep(1000000/temps.k);

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

void* data_horloge(void *arg)
{// déclaration du corps de la tâche qui lit la donnée partagée. On considère qu'elle s'exécute indéfiniment
events* N;
events* T ;
type_temps notre_temps;
events *t1;
int flag ;
flag=1;
event.type=1;
int seconde_t ;
int minute_t ;
while(1)
{

							pthread_mutex_lock(&verrou);
							pthread_cond_wait (&condition1, &verrou);//mettre signal cond si on est pas en phase
							notre_temps = temps;
							pthread_mutex_unlock(&verrou);

							if(event.type==1)//ET quil est en mode availbe push_event
							{
							pthread_mutex_lock(&even);//
							pthread_cond_wait (&condition, &even); // On attend que la condition soit remplie
							N=Nouv();
							T=insBP1(T,N);
							printf(" le ponpon %d  \n",T->id);
							pthread_mutex_unlock(&even);

							if(t1!= T)
							{
								printf("il est passe le con \n");
							t1=T;
							}
							}

							if(event.type==0 && flag==1)//si fin de liste
							{

								Aff_list1(T);
								flag=0;
								t1=T;
								printf("le skud attendu %d minute et %d seconde du ponpon %d" ,t1->minute,t1->seconde,t1->id);

							}


							if(t1!=NULL)
							{
							if(notre_temps.minute>t1->minute && notre_temps.seconde>t1->seconde)
							{
								printf(" le ponpon RATE   %d !!!!!\n",t1->id);
								t1=t1->suiv;
								printf(" le ponpon PASSE suivant   %d !!!!!\n",t1->id);


							}




							if(notre_temps.minute==t1->minute && notre_temps.seconde==t1->seconde)
							{
								seconde_t=t1->seconde;
								minute_t=t1->minute;
								printf(" le ponpon CHOPÉ   %d !!!!!\n",t1->id);
								t1=t1->suiv;
								printf(" CHOPE le ponpon suivant   %d !!!!!\n",t1->id);
								while(t1->minute==minute_t &&t1->seconde==seconde_t)
								{
								printf(" le ponpon  CHOPÉ en meme temps   %d !!!!!\n",t1->id);
								t1=t1->suiv;
								printf(" CHOPE le ponpon m temps suivant   %d !!!!!\n",t1->id);

								}

							}


							}



}


}
/************************************************************************/
/* retourne le pointeur sur le nouvel élément */
events * Nouv(void)
{
events * E;
E=(events *) malloc(sizeof(events));
if( E == NULL)
printf("\nPb malloc");
else
{
printf("\nSaisir nom : ");
//pthread_mutex_lock(&even);//
//pthread_cond_wait (&condition, &even); // On attend que la condition soit remplie
*E = event;
//pthread_mutex_unlock(&even);
E->suiv = NULL;

}
return E;
}
/************************************************************************/
events* insBP1(events *T,events *N)
{

/* Li pointeur tête, Elt élément à insérer */
events *cour=T, *prec=T;
if(T == NULL) T = N; /* cas liste vide */
else /*recherche de l'emplacement d'insertion */
{
	while((cour!=NULL)&& (cour->id < N->id))
	{
	prec= cour; cour= cour->suiv;
	 }

if(cour == T) /* Insertion début de liste */
{ N->suiv = cour; T = N; }
else
/* Insertion milieu et fin de liste */
{ N->suiv= cour; prec->suiv= N; }
}
return T;
}

void Aff_list1(events* Tete)
	{

		printf("***************************LISTE a tonton*********************************\n");
		while(Tete != NULL)
			{
				printf("le magnum est %d, jour--%d  heure --%d  minute %d seconde %d\n",Tete->id,Tete->jour,Tete->heure,Tete->minute,Tete->seconde);
				Tete = Tete->suiv;
			}

	}


void push_test1(TST* Tete)
	{

		printf("***************************LISTE DE TESTS*********************************\n");


		type_temps  push_temps;
		int heure ,minute ;




				push_temps=temps ;
				heure=Tete->heure_proc1;
				minute=Tete->minute_proc1;
				ajout_time_test(&push_temps,minute,heure);
				printf(" le resuslat final temps < %d;jour   %dh  %dm  %ds \n",push_temps.jour,push_temps.heure,push_temps.minute,push_temps.seconde);

				pthread_mutex_lock(&even);//
				event.type=1;
				event.id=Tete->id;
				event.mois=push_temps.mois;
				event.jour=push_temps.jour;
				event.heure=push_temps.heure;
				event.minute=push_temps.minute;
				event.seconde=push_temps.seconde;
				pthread_cond_signal (&condition); /* On délivre le signal : condition remplie */
				pthread_mutex_unlock(&even);
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



