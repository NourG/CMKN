#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


int creabouton(int positionx, int positiony, int w, int h, SDL_Surface* ecran, SDL_Event  event)
{
    int continuer = 1;

    SDL_Surface *bouton = NULL ;//*degrader = NULL;
    SDL_Rect position;
    position.x = positionx;
    position.y = positiony;
    bouton = IMG_Load("bouton.jpg");
    SDL_BlitSurface(bouton, NULL, ecran, &position);
    SDL_Flip(ecran);
    while(continuer)
    {
     SDL_WaitEvent(&event);
     switch(event.type)
     {
     case SDL_MOUSEBUTTONDOWN:
     if(event.button.x >= positionx && event.button.x <= (positionx + w) && event.button.y >= positiony && event.button.y <= (positiony + h))
     {
     return 1;
     }
     break;
     }
    }
    return 0;
}


int Ecriture (SDL_Surface* ecran, SDL_Event  event)

{

     SDL_Surface* texte=NULL;
	//int loop = 1;
	char *txt_affic = {"VOIla mon texte man"} ;


//Iitialisation du pointeur

	SDL_Rect position ;
// permet de declarer la position des fenetres selon X Y

	TTF_Font *police = NULL;
// ici on déclare un pointeur police qui vas stocker notre police

	SDL_EnableUNICODE(1);
// permet d'activé la fonction UNICODE

        SDL_Color couleurNoire ={200,255,255};
// ici on cree une variable couleur

	SDL_Init(SDL_INIT_VIDEO);
		if(SDL_Init(SDL_INIT_VIDEO))
		     {
			fprintf(stderr,"ERROR SDL : %s \n", SDL_GetError());
	  	     }
//commande pour l'initialisation vidéo de sdl en prenant en compte la vidéo
//syteme de gestion des erreur SDL, il va ns permettre de lire nos erreur et de facilement les identifier!!!!

	TTF_Init();
// ici on demarre notre fonction TTF sans lui passer d'argument elle n'as pas besoin

	if(TTF_Init() == -1)
		{
			fprintf(stderr, "Erreur d'initialisaiton de TTF_Init : %s\n ", TTF_GetError());
			exit(EXIT_FAILURE);
	     	}
// ici on s'assure que cette fonction qui renvoi -1 s'il y a une erreur quelle a bien demarrer */

	//texte=SDL_SetVideoMode(1370,900,32,SDL_HWSURFACE);
//L*h+couleur en bits/pixels

	if(ecran==NULL){printf("error my_sreen\n");}

   		position.x = 20;
   		position.y = 400;
// on initialise les variables de position

		police = TTF_OpenFont("bebas.ttf", 30);  // ici on charge la police dans le pointeur "police" et on donne une taille de police 30

		texte = TTF_RenderText_Blended(police ,,couleurNoire);
		SDL_BlitSurface(texte,NULL,ecran, &position);
   		SDL_Flip(ecran);
		/*
		while(loop) //boucle "pseudo" infinie
		{
			SDL_WaitEvent(&evenement); //fonction qui gere les evenement

			switch(evenement.type)
			{
			  case SDL_QUIT : loop = 0;

			    break;

			   case SDL_KEYDOWN:
			       switch (evenement.key.keysym.sym)
			           {
						   case SDLK_a: strcpy(&txt_affic,"a");
						   texte = TTF_RenderText_Blended(police ,&txt_affic ,couleurNoire);
						   SDL_BlitSurface(texte,NULL,my_screen, &position);
							SDL_Flip(my_screen);
							break;
							case SDLK_LEFT:
							posit_OP.x--;
							SDL_BlitSurface(plan_labo,NULL,my_screen,&posit_OP);
							SDL_Flip(my_screen);
							break;
						        default :
							break;
		                }

	         }


        }*/

		SDL_FreeSurface(texte);//allocation dynamique de memoire par le pointeur donc ne pas oublier de liberer l'espace!!

		TTF_CloseFont(police); // ici on ferme donc fonction qui charge la police
		TTF_Quit(); // Fermer TTF important aussi comme le SDL_Quit question de memoire !!
		//SDL_Quit(); //fermer SDL important pour ne pas saturer la mémoire !!!!!

	return 0;
}



void saisie(SDL_Surface* ecran, SDL_Event  event)
{
int loop = 1;
	char txt_affic = NULL ;
	SDL_Surface *texte = NULL;
//Iitialisation du pointeur

	SDL_Rect position ;
// permet de declarer la position des fenetres selon X Y


	TTF_Font *police = NULL;
// ici on déclare un pointeur police qui vas stocker notre police

	SDL_EnableUNICODE(1);
// permet d'activé la fonction UNICODE


        SDL_Color couleurNoire ={200,255,255};
// ici on cree une variable couleur

	SDL_Init(SDL_INIT_VIDEO);
		if(SDL_Init(SDL_INIT_VIDEO))
		     {
			fprintf(stderr,"ERROR SDL : %s \n", SDL_GetError());
	  	     }
//commande pour l'initialisation vidéo de sdl en prenant en compte la vidéo
//syteme de gestion des erreur SDL, il va ns permettre de lire nos erreur et de facilement les identifier!!!!

	TTF_Init();
// ici on demarre notre fonction TTF sans lui passer d'argument elle n'as pas besoin

	if(TTF_Init() == -1)
		{
			fprintf(stderr, "Erreur d'initialisaiton de TTF_Init : %s\n ", TTF_GetError());
			exit(EXIT_FAILURE);
	     	}
// ici on s'assure que cette fonction qui renvoi -1 s'il y a une erreur quelle a bien demarrer */

	texte=SDL_SetVideoMode(1370,900,32,SDL_HWSURFACE);
//L*h+couleur en bits/pixels

	if(texte==NULL){printf("error my_sreen\n");}


   		position.x = 20;
   		position.y = 400;
// on initialise les variables de position

		police = TTF_OpenFont("bebas.ttf", 30);  // ici on charge la police dans le pointeur "police" et on donne une taille de police 30

		texte = TTF_RenderText_Blended(police ,&txt_affic ,couleurNoire);

		while(loop) //boucle "pseudo" infinie
		{
			SDL_WaitEvent(&event); //fonction qui gere les evenement

			switch(event.type)
			{
			  case SDL_QUIT : loop = 0;

			    break;

			   case SDL_KEYDOWN:
			       switch (event.key.keysym.sym)
			           {
						   case SDLK_a: strcpy(&txt_affic,"a");
						                texte = TTF_RenderText_Blended(police ,&txt_affic ,couleurNoire);
						                SDL_BlitSurface(texte,NULL,ecran, &position);
						                SDL_Flip(ecran);
						                position.x=position.x+20;
						                if(position.x==640)
										{position.x=20;
						                position.y= position.y+30;}

							break;
							/*case SDLK_LEFT:
							posit_OP.x--;
							SDL_BlitSurface(plan_labo,NULL,my_screen,&posit_OP);
							SDL_Flip(my_screen);
							break;*/
						        default :
							break;
					    }
 default : break;

			}


		}


		SDL_FreeSurface(texte);

		TTF_CloseFont(police); // ici on ferme donc fonction qui charge la police
		TTF_Quit(); // Fermer TTF important aussi comme le SDL_Quit question de memoire !!

}

void wait(SDL_Event event)
{

  int continuer=1;
 while(continuer)
    {
     SDL_WaitEvent(&event);
     switch(event.type)
     {
     case SDL_QUIT:
     continuer = 0;
     break;
     }
    }
}
