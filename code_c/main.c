#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "listes/listesTST_OPR.h"
#include "listes/horloge_thread.h"
#include <SDL/SDL.h>
#include "sprites/sprites.h"
#include "sprites/fonction.c"
#include "sprites/roads.c"
#include <time.h>
#include "SDL/SDL_thread.h"



//test






/////////////*******************************
int SDL1(void *arg)//recupere la tete de liste
{

	SDL_Surface *ecran;
	SDL_Surface *plan_labo;
	SDL_Event event;
	int bFin = 0;
	Uint32 temps_courant, prochain_rendu = 0;

	Sprite operateur1;
//	int changement_direction1, changement_direction2;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "Echec d'initialisation SDL.\n");
		return 1;
	}
	else printf("Initialisation SDL reussie.\n");


	ecran = SDL_SetVideoMode(1370,900, 16, SDL_HWSURFACE);
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
	SDL_Flip(ecran);
	plan_labo=SDL_LoadBMP("sources_img/salle_3D.bmp");

	if ( ecran == NULL )
	{
		fprintf(stderr, "Echec mode video SDL : %s.\n", SDL_GetError());
		return 1;
	}

	//chargement image operateur
	if ( !load_Sprite( &operateur1, "sources_img/operateur2.bmp" ) )
	{
		printf("Erreur SDL \n");
		SDL_Quit();
		return 1;
	}


	while (!bFin)
	{
		while (SDL_PollEvent(&event))
		{

				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					bFin = 1;
					break;


				case SDL_QUIT:
					bFin = 1;
					break;

				default:
				;
				}
		}

		/* On recupère le temps écoulé en mili-secondes */
		temps_courant = SDL_GetTicks();

		/* On regarde s'il est temps d'effectuer le prochain rendu */
		if (temps_courant > prochain_rendu)
		{
			/* un rendu toutes les 20 milli-secondes = 50 images par secondes */
			prochain_rendu = temps_courant + 2;


			SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
			SDL_BlitSurface(plan_labo,NULL,ecran,NULL);

			// on lance le road 1
			road_1(&operateur1);


			SDL_BlitSurface( operateur1.image, &operateur1.source, ecran, &operateur1.destination );

			/* On met à jour de la zone d'affichage de la fenetre */
			SDL_UpdateRect(ecran, 0, 0, 0, 0);
		}


	}
	//SDL_FreeSurface( &operateur1 );
	remove_Sprite( &operateur1);
	SDL_Quit();


return	1;
}



















int main(void)
{
	int a ;
	int choix;
    pthread_t th1,th2,th3;//th4
    //SDL_Thread *th5 = NULL;
    pthread_mutex_init(&verrou, NULL);
	temps.seconde = 0;
	temps.minute = -1;
	temps.heure = -1;
	temps.jour =-1;
	temps.mois=-1; //c'est beau
	temps.k=1;
TST *liste1=NULL;

printf("lancement de l'horloge et get_liste---->press 0 \n");
	scanf("%d",&choix);
	if (choix==0)
	{
        pthread_create(&th1, NULL, horloge,NULL);
	usleep(200000);
    	pthread_create(&th2, NULL, lecture_horloge,NULL);//affiche l'horloge

	pthread_create(&th3, NULL,get_liste,NULL);//recupere la tete de liste des test
	pthread_join(th3,(void*)&liste1 );

	}
	printf("affichage sdl ->press 0\n");
	scanf("%d",&choix);
	if (choix==0)
	{

        SDL_CreateThread(SDL1, NULL );
	}
a=1;
//lancement d'un test
while(1)
{
						    if(temps.seconde == 30  )
						    {
								push_test(liste1);
								sleep(5);
								sleep(3);
								Aff_list(liste1);
							}
						    if(temps.seconde == 10 && a==1 )
						    {
								a=0;


							}
}


pthread_join(th1, NULL);
    pthread_join(th2, NULL);
	// pthread_join(th5, NULL);
    return 0;
}



