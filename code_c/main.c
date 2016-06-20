#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <unistd.h>

#include "sprites/sprites.h"
#include "sprites/fonction.c"
#include "sprites/roads.c"
#include "listes/thread_horloge.c"



int main()
{
	SDL_Surface *ecran;
	SDL_Surface *plan_labo;
	SDL_Event event;
	int bFin = 0;
	Uint32 temps_courant, prochain_rendu = 0;
		
	Sprite operateur1;
	int changement_direction1, changement_direction2;
	
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
		
		/* On recup�re le temps �coul� en mili-secondes */
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
										
			/* On met � jour de la zone d'affichage de la fenetre */
			SDL_UpdateRect(ecran, 0, 0, 0, 0);
		}
		
		
	}
	//SDL_FreeSurface( &operateur1 );
	remove_Sprite( &operateur1);
	SDL_Quit();
	return 0;
}





