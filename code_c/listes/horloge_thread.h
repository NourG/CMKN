typedef struct {   // déclaration du type de la donnée partagée
	int heure, minute;
	int id;
	int road;
	int k ;    //coef d'acceleration
} type_sdl;

type_sdl signaux_sdl ;




typedef struct {   // déclaration du type de la donnée partagée
	int heure, minute;
	int jour, mois;
	int seconde;
	int k ;    //coef d'acceleration
} type_temps;

typedef struct EVENTS {   // déclaration du type de la donnée partagée
	int total;
	int heure, minute;
	int jour, mois;
	int seconde;
	int id;		//id de l'opérateur
	int type;
	int opr_in_out;		//=1 sortie opr 	=0 entrée opr
    	int flux; 			// 1 pour test 2 pour operateur
	struct EVENTS *suiv;
	    //sortie des tests ou horaire operateur
} events;

pthread_cond_t condition = PTHREAD_COND_INITIALIZER; /* Création de la condition */
pthread_cond_t condition1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t condition2 = PTHREAD_COND_INITIALIZER;
 //déclaration du verrou
 pthread_mutex_t even = PTHREAD_MUTEX_INITIALIZER;
 pthread_mutex_t verrou = PTHREAD_MUTEX_INITIALIZER;
 pthread_mutex_t sdl1 = PTHREAD_MUTEX_INITIALIZER;
type_temps  temps;
events event ;
//corp des thread**********************************
void* get_op(void *arg);
void ajout_time_test(type_temps* push_temps,int minute,int heure);
int convert_minute_time(type_temps *push_temps);
int convert_heure_time(type_temps *push_temps);
void push_test1(TST* Tete);
events* insBP1(events *T,events *N);

events * Nouv(void);
void Aff_list1(events* Tete);
//********FONCTION KEV***********************************
events* nouveau_event();
/*events* events_oprgo_out(OPR* listeOPR, int in_out, events * N);
events* events_oprgo_in(OPR* listeOPR, int in_out, events * N);*/
events* events_opr2go_in(OPR* listeOPR, int in_out, events * N);
events* events_opr2go_out(OPR* listeOPR, int in_out, events * N);
events* insert_list_eve(events* tete_list,events* eve1, events* eve2/*, events* eve3, events* eve4*/);			//fct qui tri la liste d'événements operateur par la duree totale d'ordre croissant 
void affich(events *N);
//****************************************************





void* get_liste(void *arg)	//recupere la tete de liste
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
							usleep(1000000/temps.k);

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
pthread_t th5;
events* N;
events* liste2;
events* T ;
type_temps notre_temps;
events *t1;
int flag ;
flag=1;
event.type=1;
int seconde_t ;
int minute_t ;

	pthread_create(&th5, NULL,get_op,NULL);//recupere la tete de liste des test
	pthread_join(th5,(void*)&liste2 );

			T=liste2;
			t1=liste2;
			//sleep(5);
			printf("ldddddddddddddddddddddddddddddddddddddddddddddddd\n");
			//affich(T);

while(1)
{
							//Rafraichie les temps de l'horloge pour qu'elle soit en phase
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
							printf(" on lance le test correspondant a id %d  \n",T->id);
							pthread_mutex_unlock(&even);
							pthread_mutex_lock(&verrou);//
							signaux_sdl.road = 1;
							pthread_mutex_unlock(&verrou);
							

							if(t1!= T)
							{
							t1=T;
							}

							}

							if(event.type==0 && flag==1)//si fin de liste
							{
								printf("la\n");
								Aff_list1(T);
								flag=0;
								t1=T;
								printf("fin de la liste txt" );

							}


							if(t1!=NULL)
							{
							if(notre_temps.minute>t1->minute && notre_temps.seconde>t1->seconde)
							{
								printf(" nous avons rater la date %d !!!!!\n",t1->id);
								t1=t1->suiv;
								printf(" passons au suivant  qui est id %d !!!!!\n",t1->id);


							}




							if(notre_temps.minute==t1->minute && notre_temps.seconde==t1->seconde)
							{
								seconde_t=t1->seconde;
								minute_t=t1->minute;
								printf(" la date est arrivé  %d !!!!!\n",t1->id);
								t1=t1->suiv;
								printf(" CHOPÉ suivant   %d !!!!!\n",t1->id);
								if(t1->flux==2)//type de test operateur
								{
									if(t1->opr_in_out==1)
									{
													pthread_mutex_lock(&verrou);//
													signaux_sdl.road = 2;
													pthread_mutex_unlock(&verrou);
									}
									if(t1->opr_in_out==0)
									{
													pthread_mutex_lock(&verrou);//
													signaux_sdl.road = 3;
													//printf("
													pthread_mutex_unlock(&verrou);

									}
								}
								if(t1->flux==1)
								{
													pthread_mutex_lock(&verrou);//
													signaux_sdl.road = 4;
													pthread_mutex_unlock(&verrou);

								}
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
*E = event;
E->total= E->seconde +  (59 * (E->minute)) + (59*59* (E->heure))+(59*59*23*(E->jour))+(59*59*23*30* (E->mois)); 
E->flux= 1;
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
		while((cour!=NULL)&& (cour->total < N->total))	//tri liste croissante id
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
				printf("le test est %d, jour--%d  heure --%d  minute %d seconde %d flux =%d in_out=%d total=%d\n",Tete->id,Tete->jour,Tete->heure,Tete->minute,Tete->seconde,Tete->flux,Tete->opr_in_out,Tete->total);
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



void* get_op(void *arg)	//recupere la tete de liste
{


		events* opr1out=NULL, *opr1in=NULL, *opr2out=NULL, *opr2in=NULL, *T=NULL;
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

			}
		fc=fclose(fic);
		//aff_listOPR(tete);
		if(fc!=0)
			{
				printf("PB fermeture du fichier\n");
			}

		opr1out=nouveau_event();
		opr1in=nouveau_event();
		/*opr2out=nouveau_event();
		opr2in=nouveau_event();*/
		//opr 2
		/*opr2out=events_oprgo_out(tete,1,opr2out);
		opr2in=events_oprgo_in(tete,0,opr2in);*/
		// opr 1
		opr1in=events_opr2go_in(tete,0,opr1in);
		opr1out=events_opr2go_out(tete,1,opr1out);


		T=insert_list_eve(T,opr1out,opr1in/*,opr2out,opr2in*/);
		/*T=insert_list_eve(T,opr1in);
		T=insert_list_eve(T,opr2out);
		T=insert_list_eve(T,opr2in);*/




pthread_exit(T);

}



events* nouveau_event()
	{

		events *N=NULL;
		N=(events*)malloc(sizeof(events));
		if( N == NULL)
			{
				printf("\nPb malloc\n");
				return NULL;
			}
		else
		{

			N->suiv=NULL;
			return N;

		}
	}

/*events* events_oprgo_out(OPR* listeOPR, int in_out, events * N)		//affecte data (OPR) dans un maillon
	{
		//events *N2=NULL *T=NULL;

					if(listeOPR!=NULL)
					{
						N->id=listeOPR->id;
						N->opr_in_out=in_out;


								N->heure=listeOPR->heure_depart;
								N->flux=2;
								N->minute=listeOPR->minute_depart;
								N->seconde=listeOPR->seconde_depart;
								N->total= N->seconde +  (59 * (N->minute)) + (59*59* (N->heure));
							
								N->suiv=NULL;
								//printf("operateur out\n");
					}
								return N;

								//T=insert_list_eve(T,N);


	}

events* events_oprgo_in(OPR* listeOPR, int in_out, events * N)
		{
					if(listeOPR!=NULL)
						{
							N->id=listeOPR->id;
							N->opr_in_out=in_out;

								N->heure=listeOPR->heure_arrivee;
								N->flux=2;
								N->minute=listeOPR->minute_arrivee;
								N->seconde=listeOPR->seconde_arrivee;
								N->total= N->seconde +  (59 * (N->minute)) + (59*59* (N->heure));
								N->suiv=NULL;
								//printf("operateur in\n");
								//T=insert_list_eve(T,N);
							}
								return N;

				}*/

events* events_opr2go_in(OPR* listeOPR, int in_out, events * N)
	{
		if(listeOPR->suiv!=NULL)
						{
							N->id=listeOPR->suiv->id;
							N->opr_in_out=in_out;


								N->heure=listeOPR->suiv->heure_arrivee;
								N->flux=2;
								
								N->minute=listeOPR->suiv->minute_arrivee;
								N->seconde=listeOPR->suiv->seconde_arrivee;
								N->total= N->seconde +  (59 * (N->minute)) + (59*59* (N->heure));
								N->suiv=NULL;
								printf("operateur 1 in\n");
								//T=insert_list_eve(T,N);
							}
								printf("opr1 go in = eve2\n");
								affich(N);
								return N;

				}



events* events_opr2go_out(OPR* listeOPR, int in_out, events * N)
	{
		if(listeOPR->suiv!=NULL)
						{
							N->id=listeOPR->suiv->id;
							N->opr_in_out=in_out;


								N->heure=listeOPR->suiv->heure_depart;
								N->flux=2;
								N->minute=listeOPR->suiv->minute_depart;
								N->seconde=listeOPR->suiv->seconde_depart;
								N->total= N->seconde +  (59 * (N->minute)) + (59*59* (N->heure));
								N->suiv=NULL;
								printf("operateur 1 out = eve1\n");
								//T=insert_list_eve(T,N);

							}
						printf("opr1 go out\n");
					affich(N);
						return N;
					

	}


events* insert_list_eve(events* tete_list,events* eve1, events* eve2/*, events* eve3, events* eve4*/)
	{
		/* "tete_list" pointeur tête, "test" élément à insérer */
		if(eve1==NULL&&eve2==NULL /*&& eve3 == NULL && eve4==NULL*/)
			{
				printf("PB [Insert_liste_eve]maillons de tests\n");
				return NULL;
			}
		else
			{

				//cas ou eve1 en tete
				if(          eve1->total <= eve2->total /*&& eve1->suiv==NULL*/ /*&& eve3->total <= eve4->total*/)			
				{
					if(tete_list==NULL)
					{
						
						
						tete_list=eve1;
						//printf("Insérer en tete de liste si cas maillon 1 < 2<3<4\n");
						printf("Insérer en tete de liste si cas maillon eve1 < eve2\n");
						
					
						//insert maillon 2 a 1=tete
						eve1->suiv=eve2;
						eve2=eve1;
						//insert maillon 3 a 2
						/*eve2->suiv=eve3;
						eve3=eve2;
						// insert maillon 4 a 3
						eve3->suiv=eve4;
						eve4=eve3;*/
						//eve2->suiv=NULL;
						//printf("Insérer en tete de liste si cas maillon 1 < 2\n");
											
					}
					return tete_list;
				}
				
 			/*if(tete_list==NULL &&                 eve2->total <= eve1->total*/ /*&& eve2->suiv==NULL*/ /*&&  eve4->total <= eve3->total)*/			if(eve2->total <= eve1->total)
				{
					if(tete_list==NULL)
						{
						/*if(eve2->total < eve1->total)
						{*/
						tete_list=eve2;
						//printf("Insérer en tete de liste si maillon 1 < 2< 4< 3\n");
						printf("Insérer en tete de liste si maillon eve2 < eve1\n");
						
							//insert maillon 
						eve2->suiv=eve1;
						eve1=eve2;
						//insert maillon 
						/*eve2->suiv=eve4;
						eve4=eve2;
						// insert maillon 
						eve4->suiv=eve3;
						eve3=eve4;*/
						//eve1->suiv=NULL;
						//printf("Insérer en tete de liste si maillon 2 < 1\n");
						
						}
					return tete_list;
				}
		}
	}
										//au dessus ok

		
				/*if(tete_list==NULL &&               eve1->total <= eve3->total && eve2->total <= eve4->total)			
					{
						tete_list=eve1;
						printf("Insérer en tete de liste si maillon 1 < 3<2<4\n");

						eve1->suiv=eve3;
						eve3=eve1;
						//insert maillon 
						eve3->suiv=eve2;
						eve2=eve3;
						// insert maillon 
						eve2->suiv=eve4;
						eve4=eve2;
						eve4->suiv=NULL;
						return tete_list;
					}

				if(tete_list==NULL && eve1->total <= eve3->total && eve4->total <= eve2->total)			
					{
						tete_list=eve1;
						printf("Insérer en tete de liste si maillon 1 < 3<4<2\n");

						eve1->suiv=eve3;
						eve3=eve1;
						//insert maillon 
						eve3->suiv=eve4;
						eve4=eve3;
						// insert maillon 
						eve4->suiv=eve2;
						eve2=eve4;
						eve2->suiv=NULL;
						return tete_list;
					}
					//au dessus ok


				if(tete_list==NULL && eve1->total <= eve4->total && eve3->total <= eve2->total)			
					{
						tete_list=eve1;
						printf("Insérer en tete de liste si maillon 1 < 4<3<2\n");

						eve1->suiv=eve4;
						eve4=eve1;
						//insert maillon 
						eve4->suiv=eve3;
						eve3=eve4;
						// insert maillon 
						eve3->suiv=eve2;
						eve2=eve3;
						eve2->suiv=NULL;
					return tete_list;
					}
			// ok
				
				if(tete_list==NULL && eve1->total <= eve4->total && eve2->total <= eve3->total)			
					{
						tete_list=eve1;
						printf("Insérer en tete de liste si maillon 1 < 4<2<3\n");

						eve1->suiv=eve4;
						eve4=eve1;
						//insert maillon 
						eve4->suiv=eve2;
						eve2=eve4;
						// insert maillon 
						eve2->suiv=eve3;
						eve3=eve2;
						eve3->suiv=NULL;
						return tete_list;
					}

	//ok
		
					//eve2 tete liste

				if(tete_list==NULL &&                   eve2->total <= eve1->total && eve3->total <= eve4->total)			
					{
						tete_list=eve2;
						printf("Insérer en tete de liste si maillon 2 < 1<3<4\n");

						eve2->suiv=eve1;
						eve1=eve2;
						//insert maillon 
						eve1->suiv=eve3;
						eve3=eve1;
						// insert maillon 
						eve3->suiv=eve4;
						eve4=eve3;
						eve4->suiv=NULL;
						return tete_list;
					}


//ok
				if(tete_list==NULL &&                      eve2->total <= eve1->total && eve4->total <= eve3->total)			
					{
						tete_list=eve2;
						printf("Insérer en tete de liste si maillon 2 < 1<4<3\n");

						eve2->suiv=eve1;
						eve1=eve2;
						//insert maillon 
						eve1->suiv=eve4;
						eve4=eve1;
						// insert maillon 
						eve4->suiv=eve3;
						eve3=eve4;
						eve3->suiv=NULL;
						return tete_list;
					}


				//ok


				if(tete_list==NULL &&                   eve2->total <= eve3->total && eve4->total <= eve1->total)		
					{
						tete_list=eve2;
						printf("Insérer en tete de liste si maillon 2 < 3<4<1\n");

						eve2->suiv=eve3;
						eve3=eve2;
						//insert maillon 
						eve3->suiv=eve4;
						eve4=eve3;
						// insert maillon 
						eve4->suiv=eve1;
						eve1=eve4;
						eve1->suiv=NULL;
						return tete_list;
					}

//ok


				if(tete_list==NULL &&                       eve2->total <= eve3->total && eve1->total <= eve4->total)		
					{
						tete_list=eve2;
						printf("Insérer en tete de liste si maillon 2 < 3<1<4\n");

						eve2->suiv=eve3;
						eve3=eve2;
						//insert maillon 
						eve3->suiv=eve1;
						eve1=eve3;
						// insert maillon 
						eve1->suiv=eve4;
						eve4=eve1;
						eve4->suiv=NULL;
						return tete_list;
					}

//ok

				if(tete_list==NULL &&                  eve2->total <= eve4->total && eve3->total <= eve1->total)			
					{
					tete_list=eve2;
						printf("Insérer en tete de liste si maillon 2 < 4<3<1\n");

						eve2->suiv=eve4;
						eve4=eve2;
						//insert maillon 
						eve4->suiv=eve3;
						eve3=eve4;
						// insert maillon 
						eve3->suiv=eve1;
						eve1=eve3;
						eve1->suiv=NULL;
						return tete_list;
					}

	//ok
				
				if(tete_list==NULL &&                   eve2->total <= eve4->total && eve1->total <= eve3->total)			
					{
						tete_list=eve2;
						printf("Insérer en tete de liste si maillon 2< 4<1<3\n");

						eve2->suiv=eve4;
						eve4=eve2;
						//insert maillon 
						eve4->suiv=eve1;
						eve1=eve4;
						// insert maillon 
						eve1->suiv=eve3;
						eve3=eve1;
						eve3->suiv=NULL;
						return tete_list;
					}

		//ok
	//evt 3
				if(tete_list==NULL &&                   eve3->total <= eve1->total &&  eve2->total <= eve4->total)			
					{
						tete_list=eve3;
						printf("Insérer en tete de liste si maillon 3< 1<2<4\n");

						eve3->suiv=eve1;
						eve1=eve3;
						//insert maillon 
						eve1->suiv=eve2;
						eve2=eve1;
						// insert maillon 
						eve2->suiv=eve4;
						eve4=eve2;
						eve4->suiv=NULL;
						return tete_list;
					}
		//ok	


			if(tete_list==NULL &&                   eve3->total <= eve1->total && eve4->total <= eve2->total)			
					{
						tete_list=eve3;
						printf("Insérer en tete de liste si maillon 3< 1<4<2\n");

						eve3->suiv=eve1;
						eve1=eve3;
						//insert maillon 
						eve1->suiv=eve4;
						eve4=eve1;
						// insert maillon 
						eve4->suiv=eve2;
						eve2=eve4;
						eve2->suiv=NULL;
						return tete_list;
					}
		//ok
	
	if(tete_list==NULL &&                   eve3->total <= eve2->total && eve1->total <= eve4->total)			
					{
						tete_list=eve3;
						printf("Insérer en tete de liste si maillon 3< 2<1<4\n");

						eve3->suiv=eve2;
						eve2=eve3;
						//insert maillon 
						eve2->suiv=eve1;
						eve1=eve2;
						// insert maillon 
						eve1->suiv=eve4;
						eve4=eve1;
						eve4->suiv=NULL;
						return tete_list;
					}

	//ok

	if(tete_list==NULL &&                   eve3->total <= eve2->total && eve4->total <= eve1->total)			
					{
						tete_list=eve3;
						printf("Insérer en tete de liste si maillon 3< 2<4<1\n");

						eve3->suiv=eve2;
						eve2=eve3;
						//insert maillon 
						eve2->suiv=eve4;
						eve4=eve2;
						// insert maillon 
						eve4->suiv=eve1;
						eve1=eve4;
						eve1->suiv=NULL;
						return tete_list;
					}

//ok

	if(tete_list==NULL &&                   eve3->total <= eve4->total && eve2->total <= eve1->total)			
					{
						tete_list=eve3;
						printf("Insérer en tete de liste ev 3 si maillon 3< 4<2<1\n");

						eve3->suiv=eve4;
						eve4=eve3;
						//insert maillon 
						eve4->suiv=eve2;
						eve2=eve4;
						// insert maillon 
						eve2->suiv=eve1;
						eve1=eve2;
						eve1->suiv=NULL;
						return tete_list;
					}

		//ok

	if(tete_list==NULL &&                   eve3->total <= eve4->total && eve1->total <= eve2->total)			
					{
						tete_list=eve3;
						printf("Insérer en tete de liste si maillon 3< 4<1<2\n");

						eve3->suiv=eve4;
						eve4=eve3;
						//insert maillon 
						eve4->suiv=eve1;
						eve1=eve4;
						// insert maillon 
						eve1->suiv=eve2;
						eve2=eve1;
						eve2->suiv=NULL;
						return tete_list;
					}


//ok

	if(tete_list==NULL &&                   eve4->total <= eve1->total && eve2->total <= eve3->total)			
					{
						tete_list=eve4;
						printf("Insérer en tete de liste si maillon 4< 1<2<3\n");

						eve4->suiv=eve1;
						eve1=eve4;
						//insert maillon 
						eve1->suiv=eve2;
						eve2=eve1;
						// insert maillon 
						eve2->suiv=eve3;
						eve3=eve2;
						eve3->suiv=NULL;
						return tete_list;
					}

//ok


	if(tete_list==NULL &&                   eve4->total <= eve1->total && eve3->total <= eve2->total)			
					{
						tete_list=eve4;
						printf("Insérer en tete de liste si maillon 4< 1<3<2\n");

						eve4->suiv=eve1;
						eve1=eve4;
						//insert maillon 
						eve1->suiv=eve3;
						eve3=eve1;
						// insert maillon 
						eve3->suiv=eve2;
						eve2=eve3;
						eve2->suiv=NULL;
						return tete_list;
					}
//ok

	if(tete_list==NULL &&                   eve4->total <= eve2->total && eve3->total <= eve1->total)				
					{
						tete_list=eve4;
						printf("Insérer en tete de liste si maillon 4< 2<3<1\n");

						eve4->suiv=eve2;
						eve2=eve4;
						//insert maillon 
						eve2->suiv=eve3;
						eve3=eve2;
						// insert maillon 
						eve3->suiv=eve1;
						eve1=eve3;
						eve1->suiv=NULL;
						return tete_list;
					}
		//ok


	if(tete_list==NULL &&                   eve4->total <= eve2->total && eve1->total <= eve3->total)			
					{
						tete_list=eve4;
						printf("Insérer en tete de liste si maillon 4< 2<1<3\n");

						eve4->suiv=eve2;
						eve2=eve4;
						//insert maillon 
						eve2->suiv=eve1;
						eve1=eve2;
						// insert maillon 
						eve1->suiv=eve3;
						eve3=eve1;
						eve3->suiv=NULL;
						return tete_list;
					}

//ok
	if(tete_list==NULL &&                   eve4->total <= eve3->total && eve2->total <= eve1->total) // si compile pas add && à la place du 2e <=			
					{
						tete_list=eve4;
						printf("Insérer en tete de liste si maillon 4< 3<2<1\n");

						eve4->suiv=eve3;
						eve3=eve4;
						//insert maillon 
						eve3->suiv=eve2;
						eve2=eve3;
						// insert maillon 
						eve2->suiv=eve1;
						eve1=eve2;
						eve1->suiv=NULL;
						return tete_list;
					}

//ok

	if(tete_list==NULL &&                   eve4->total <= eve3->total && eve1->total <= eve2->total)			
					{
						tete_list=eve4;
						printf("Insérer en tete de liste si maillon 4< 3<1<2\n");

						eve4->suiv=eve3;
						eve3=eve4;
						//insert maillon 
						eve3->suiv=eve1;
						eve1=eve3;
						// insert maillon 
						eve1->suiv=eve2;
						eve2=eve1;
						eve2->suiv=NULL;
						return tete_list;
					}


		}*/
				 
	

	












/* "tete_list" pointeur tête, "test" élément à insérer
		if(operateur==NULL)
			{
				printf("PB [Insert_liste]maillon de test\n");
				return NULL;
			}
		else
			{
				if(tete_list==NULL)			
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
	
*/

void affich(events *N)
	{
		while(N!=NULL)
			//if(N->suiv!=NULL)
			{
				//printf(" tonton du bled\n");
				printf("id=%d\topr_in_out=%d\tflux=%d\ttotal=%d\theure=%d\tminute=%d\tseconde=%d\n",N->id,N->opr_in_out,N->flux,N->total,N->heure,N->minute,N->seconde);
				N=N->suiv;
			}
	}






