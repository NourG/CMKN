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
	SDL_Surface *ecran = NULL , *plan_labo=NULL,*horloge_sdl=NULL,*menu = NULL , *liste = NULL;
	SDL_Event event;
	int Fin = 0,w=640,h=35;
	int tempsActuel = 0, tempsPrecedent = 0, compteur = 0, flag_1=0, flag_1_3=0, flag_2=0, flag_3=0, flag_4=0 , a=0;
	SDL_Rect position_horloge;
	SDL_Rect position_menu;
	SDL_Rect position_liste;
	
	Sprite operateur1;

	TTF_Font *police = NULL;
        SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
        char time[20] = "";
        char list[20] = "";

        TTF_Init();

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "Echec d'initialisation SDL.\n");
		return 1;
	}
	else printf("Initialisation SDL reussie.\n");


	ecran = SDL_SetVideoMode(1370,900, 16, SDL_HWSURFACE);
	SDL_WM_SetCaption("Simulateur a evenements discrets", NULL);
	plan_labo=SDL_LoadBMP("sources_img/labo_tests.bmp");
	menu=SDL_LoadBMP("sources_img/barremenu.bmp");
	
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



	tempsActuel = SDL_GetTicks();
    	
    	sprintf(time," temps : %d s %d min %d heures", notre_temps.seconde, notre_temps.minute, notre_temps.heure);
    	horloge_sdl = TTF_RenderText_Shaded(police, time, couleurNoire, couleurBlanche);
	

	while (!Fin)
	{
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_MOUSEMOTION:

		//if(event.motion.x >= position_menu.x && event.motion.x <= 60 && event.motion.y >= position_menu.y && event.motion.y <= 30)
				if(event.motion.x <= 43 && event.motion.y <= 22)
				{
					menu = SDL_LoadBMP("sources_img/barremenu.fichier.bmp");
					SDL_BlitSurface(menu, NULL, ecran, &position_menu);
				}
				else 
				{
					menu = SDL_LoadBMP("sources_img/barremenu.bmp");
					SDL_BlitSurface(menu, NULL, ecran, &position_menu);
				}
				
				if(event.motion.x >= 43 && event.motion.y <= 22)
				{
					menu = SDL_LoadBMP("sources_img/barremenu.simulation.bmp");
					SDL_BlitSurface(menu, NULL, ecran, &position_menu);
				}
				else 
				{
					menu = SDL_LoadBMP("sources_img/barremenu.bmp");
					SDL_BlitSurface(menu, NULL, ecran, &position_menu);
				}		
			break;
			case SDL_MOUSEBUTTONDOWN:
		
			if(event.motion.x <= 100 && event.motion.y <= 300)
				{
					menu = SDL_LoadBMP("sources_img/barremenu.fichier.bmp");
					SDL_BlitSurface(menu, NULL, ecran, &position_menu);
				
			 	menu = SDL_LoadBMP("sources_img/Menu.bmp");
			 	SDL_BlitSurface(menu, NULL, ecran, &position_menu);
		               }
			break;
			
			
			
			
			case SDL_QUIT:
				Fin = 1;
			break;
			default:
			break;

				
			}	
			
			}
		
			
		tempsActuel = SDL_GetTicks();
		/* On regarde s'il est temps d'effectuer le prochain rendu */
		if (tempsActuel - tempsPrecedent >= 100) /* Si 100ms au moins se sont écoulées */
		{
						
			pthread_mutex_lock(&verrou);
			notre_temps = temps;
			pthread_mutex_unlock(&verrou);
			sprintf(time," temps : %d s %d min %d heures", notre_temps.seconde, notre_temps.minute, notre_temps.heure);
			
			SDL_FreeSurface(horloge_sdl); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
           		horloge_sdl = TTF_RenderText_Shaded(police, time, couleurNoire, couleurBlanche);
			tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */

			if(signaux_sdl.road==1 && flag_1==0 )  // de la zone 1 vers la zone 2 vers la zone 3
			{
			
				printf("hzllo #################################\n");
				if (flag_1==0)
				{
				operateur1.destination.x = 1014  ;
				operateur1.destination.y = 470 ;
				flag_1 = 1;
				}
				a=road_1(&operateur1);
			}

			else if(signaux_sdl.road==1 && a==1 )  // de la zone 1 vers la zone 2 vers la zone 3
			{
			
				
				if (flag_1_3==0)
				{
				operateur1.destination.x =  850 ;
				operateur1.destination.y = 180 ;
				flag_1_3 = 1;
				}
				road_1_3(&operateur1);
			}

		
			if(signaux_sdl.road==2)  // de la zone 5 vers la zone 1
			{
				if (flag_2==0)
				{
				operateur1.destination.x = 360 ;
				operateur1.destination.y = 120 ;
				flag_2 = 1;
				}
				
			
				road_2(&operateur1);
			}
			if(signaux_sdl.road==3)  // de la zone 1 vers la zone 5
			{
				if (flag_3==0)
				{
				operateur1.destination.x = 1014  ;
				operateur1.destination.y = 470 ;
				flag_3 = 1;
				}
				
			
				road_3(&operateur1);
			}
			
			if(signaux_sdl.road==4)  // de la zone 1 vers la zone 3
			{
				if (flag_4==0)
				{
				operateur1.destination.x = 1014  ;
				operateur1.destination.y = 470 ;
				flag_4 = 1;
				}
				
			
				road_4(&operateur1);
			}
	

		}
		
  	position_horloge.x = 1000;
        position_horloge.y = 10;
        
        position_menu.x = 0;
   	position_menu.y = 0;
   	
   	position_menu.x= 10;
   	position_menu.y= 550;

	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
	SDL_BlitSurface(plan_labo,NULL,ecran,NULL);
	SDL_BlitSurface( operateur1.image, &operateur1.source, ecran, &operateur1.destination );
        SDL_BlitSurface(horloge_sdl, NULL, ecran, &position_horloge); /* Blit du horloge_sdl contenant le temps */
        SDL_BlitSurface(menu, NULL, ecran, &position_menu);
       // SDL_BlitSurface(liste, NULL, ecran, &position_liste);
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
	pthread_mutex_init(&sdl1, NULL);
    pthread_mutex_init(&verrou, NULL);
    pthread_mutex_init(&even, NULL);
	temps.seconde = 0;
	temps.minute = -1;
	temps.heure = -1;
	temps.jour =-1;
	temps.mois=-1;
	temps.k=1;
TST *liste1=NULL;

printf("lancement de l'horloge et get_liste---->press 0 \n");
	scanf("%d",&choix);
	if (choix==0)
	{
		pthread_create(&th3, NULL,get_liste,NULL);//recupere la tete de liste des test
		pthread_join(th3,(void*)&liste1 );

        pthread_create(&th1, NULL, horloge,NULL);
		usleep(200000);
    	pthread_create(&th2, NULL, lecture_horloge,NULL);//affiche l'horloge
		usleep(200000);
		pthread_create(&th4, NULL, data_horloge,NULL);//data horloge
		usleep(200000);
		SDL_CreateThread(SDL1, NULL );

	}
signaux_sdl.road = 0;
//lancement d'un test
while(liste1!=NULL)
{
						    if(temps.seconde == 15 && signaux_sdl.road == 0 )
						    {
								sleep(3);
								push_test1(liste1);	//toutes les 15 secondes on récupère un test liste dans la pile envoie un signal
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



