#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

/****** pour installer la bibliothéque SDL taper la commande
sudo apt-get install libsdl1.2debian libsdl1.2-dev sur le 
votre terminal utiliser toujours le PC HP de l'école avec
notre première config de GIT */

//ce premier test de code nous permettra de prendre en main la 
//Biblio SDL ;)



/*tres important!!!!!!! la commande gcc pour compiler un code qui
tourne avec la bibliothéque SDL ==> sudo gcc main.c -lSDL -o main*/

int main(void)
{

	printf("Hello we are CMKN\n"); //petit bonjour x)
	
		SDL_Rect position;

   		position.x = 0;
   		position.y = 0;

	
	if(SDL_Init(SDL_INIT_VIDEO)){ //commande pour l'initialisation vidéo de sdl en prenant en compte la vidéo
			fprintf(stderr,"ERROR SDL : %s \n", SDL_GetError());
		//syteme de gestion des erreur SDL, il va ns permettre de lire nos erreur et de facilement les identifier!!!!
				}
	

		//creation de notre premiere surface
		SDL_Surface *my_screen=NULL; //Iitialisation du pointeur
		SDL_Surface *plan_labo=NULL;
				
			
		SDL_Init(SDL_INIT_VIDEO);
		my_screen=SDL_SetVideoMode(1370,900,32,SDL_HWSURFACE); //L*h+couleur en bits/pixels 
		if(my_screen==NULL){printf("error my_sreen\n");}
		SDL_WM_SetCaption("Chargement de l'image labi en SDL", NULL);
		
		plan_labo=SDL_LoadBMP("salle_3D.bmp");
		
		
		SDL_BlitSurface(plan_labo,NULL,my_screen,NULL);

   		 SDL_Flip(my_screen);
   		    		
		while(1) //boucle "pseudo" infinie
		{
			SDL_Event evenement; //creation d'un evenement geré par SDL
			SDL_WaitEvent(&evenement); //fonction qui gere les evenement
			if(evenement.type==SDL_QUIT){break;}
		}
		SDL_FreeSurface(my_screen);//allocation dynamique de memoire par le pointeur donc ne pas oublier de liberer l'espace!! 
		SDL_Quit(); //fermer SDL important pour ne pas saturer la mémoire !!!!!
	return 0;
}
