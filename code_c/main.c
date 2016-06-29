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
#include <SDL/SDL_ttf.h>





/////////////*******************************
int SDL1(void *arg)//recupere la tete de liste
{

	type_temps notre_temps;
	SDL_Surface *ecran = NULL , *plan_labo=NULL,*horloge_sdl=NULL;
	SDL_Event event;
	int Fin = 0;
	int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
	SDL_Rect position;
	Sprite operateur1;
	 
	TTF_Font *police = NULL;
        SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
        char time[20] = ""; 
        
        TTF_Init();
            	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "Echec d'initialisation SDL.\n");
		return 1;
	}
	else printf("Initialisation SDL reussie.\n");


	ecran = SDL_SetVideoMode(1370,900, 16, SDL_HWSURFACE);
	SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
	plan_labo=SDL_LoadBMP("sources_img/labo_tests.bmp");
	
	police = TTF_OpenFont("angelina.ttf", 30);
	
	if ( ecran == NULL )
	{
		fprintf(stderr, "Echec mode video SDL : %s.\n", SDL_GetError());
		return 1;
	}

	//chargement image operateur
	if ( !load_Sprite( &operateur1, "sources_img/operateur.bmp" ) )
	{
		printf("Erreur SDL \n");
		SDL_Quit();
		//return 1;
	}



	//MODIFICATION DES COORDONEES selon le numero du road
		//road 5	operateur1.destination.x = 1000;
			//operateur1.destination.y = 180;
	
	tempsActuel = SDL_GetTicks();
	
 	tempsActuel = SDL_GetTicks();
    	//sprintf(time, "Temps : %d", compteur);
    	sprintf(time," temps : %d",notre_temps.seconde);
	horloge_sdl = TTF_RenderText_Shaded(police, time, couleurNoire, couleurBlanche);	
	
	while (!Fin)
	{
		while (SDL_PollEvent(&event))
		{

				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					Fin = 1;
					break;


				case SDL_QUIT:
					Fin = 1;
					break;

				default:
				;
				}
		}

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		/* On recupère le temps écoulé en mili-secondes */

		tempsActuel = SDL_GetTicks();
		/* On regarde s'il est temps d'effectuer le prochain rendu */
		if (tempsActuel - tempsPrecedent >= 100) /* Si 100ms au moins se sont écoulées */
		{
			/* un rendu toutes les 100 milli-secondes = 250 images par secondes */
			compteur += 100;
			sprintf(time, "Temps : %d", compteur);
			pthread_mutex_lock(&verrou);
			pthread_cond_wait (&condition1, &verrou);//mettre signal cond si on est pas en phase
			notre_temps = temps;
			pthread_mutex_unlock(&verrou);
			sprintf(time," temps : %d",notre_temps.seconde);
			SDL_FreeSurface(horloge_sdl); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
           		horloge_sdl = TTF_RenderText_Shaded(police, time, couleurNoire, couleurBlanche); 
			tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
	
			// on lance le road 
			road_1(&operateur1); //ZONE 1 VERS ZONE 3
			//road_2(&operateur1);  //ZONE 1 VERS ZONE 2
			//road_3(&operateur1);  //ZONE 1 VERS ZONE 3
			//road_4(&operateur1);  //ZONE 1 VERS ZONE 5
			
						

			//road_5(&operateur1);  //ZONE 2 VERS ZONE 3
			//road_6(&operateur1);  //ZONE 2 VERS ZONE 4
			
			//road_7(&operateur1);  //ZONE 3 VERS ZONE 1
			

		}
  	position.x = 10;
        position.y = 10;
        
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
	SDL_BlitSurface(plan_labo,NULL,ecran,NULL);
	SDL_BlitSurface( operateur1.image, &operateur1.source, ecran, &operateur1.destination );
        SDL_BlitSurface(horloge_sdl, NULL, ecran, &position); /* Blit du horloge_sdl contenant le temps */
        SDL_Flip(ecran);

	}
	TTF_CloseFont(police);
    	TTF_Quit();

    	SDL_FreeSurface(horloge_sdl);
	remove_Sprite( &operateur1);
	SDL_Quit();


return	1;
}




int main(void)
{

	int choix;
    pthread_t th1,th2,th3,th4;

    pthread_mutex_init(&verrou, NULL);
    pthread_mutex_init(&even, NULL);
	temps.seconde = 0;
	temps.minute = -1;
	temps.heure = -1;
	temps.jour =-1;
	temps.mois=-1;
	temps.k=3;
TST *liste1=NULL;

printf("lancement de l'horloge et get_liste---->press 0 \n");
	scanf("%d",&choix);
	if (choix==0)
	{
        pthread_create(&th1, NULL, horloge,NULL);
		usleep(200000);
    	pthread_create(&th2, NULL, lecture_horloge,NULL);//affiche l'horloge
		usleep(200000);
	pthread_create(&th4, NULL, data_horloge,NULL);//data horloge

	pthread_create(&th3, NULL,get_liste,NULL);//recupere la tete de liste des test
	pthread_join(th3,(void*)&liste1 );
	usleep(200000);
	SDL_CreateThread(SDL1, NULL );

	}
	

//lancement d'un test
while(liste1!=NULL)
{
						    if(temps.seconde == 15  )
						    {
								push_test1(liste1);
								sleep(5);
								sleep(3);
								//Aff_list(liste1);
								liste1=liste1->suiv;
							}

}

				pthread_mutex_lock(&even);//
				event.type=0;
				pthread_cond_signal (&condition); /* On délivre le signal : condition remplie */
				pthread_mutex_unlock(&even);
	pthread_join(th1, NULL);
    pthread_join(th2, NULL);
	pthread_join(th4, NULL);
    return 0;
}



