#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

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
	printf("test by momo\n");
	
	
		SDL_Rect position;

   		position.x = 500;
   		position.y = 250;
		
		//creation de notre premiere surface
		SDL_Surface *my_screen = NULL;// *texte =NULL ; //Iitialisation du pointeur
		SDL_Surface *plan_labo=NULL;
		//TTF_Font * police = NULL; // ici on déclare un pointeur police qui vas stocker notre police que etait telecharger		
		//SDL_Color couleurNoire ={0,0,0};	// ici on cree une variable couleur 
		
		//TTF_Init(); // ici on demarre notre fonction TTF sans lui passer d'argument elle n'as pas besoin
	
		/*if(TTF_Init() == -1)
		{
			fprintf(stderr, "Erreur d'initialisaiton de TTF_Init : %s\n ", TTF_GetError());
			exit(EXIT_FAILURE);
	     } // ici on s'assure que cette fonction qui renvoi -1 s'il y a une erreur quelle a bien demarrer */
	     
		SDL_Init(SDL_INIT_VIDEO);
		if(SDL_Init(SDL_INIT_VIDEO)){ //commande pour l'initialisation vidéo de sdl en prenant en compte la vidéo
			fprintf(stderr,"ERROR SDL : %s \n", SDL_GetError());
		//syteme de gestion des erreur SDL, il va ns permettre de lire nos erreur et de facilement les identifier!!!!
				}	
				
		my_screen=SDL_SetVideoMode(1370,900,32,SDL_HWSURFACE); //L*h+couleur en bits/pixels 
		if(my_screen==NULL){printf("error my_sreen\n");}
		SDL_WM_SetCaption("Chargement de l'image labi en SDL", NULL);
		
		plan_labo=SDL_LoadBMP("salle_3D.bmp");
		
		// police = TTF_OpenFont("bebas.ttf", 30);  // ici on charge la police dans le pointeur "police" et on donne une taille de police 30 
		
		//texte = TTF_RenderText_Blended(police ,"Salut le monde" ,couleurNoire);
		
		SDL_BlitSurface(plan_labo,NULL,my_screen,NULL);
		//SDL_BlitSurface(texte,NULL,my_screen, &position);
   		 SDL_Flip(my_screen);
   		    		
		while(1) //boucle "pseudo" infinie
		{
			SDL_Event evenement; //creation d'un evenement geré par SDL
			SDL_WaitEvent(&evenement); //fonction qui gere les evenement
			if(evenement.type==SDL_QUIT){break;}
		}
		SDL_FreeSurface(my_screen);//allocation dynamique de memoire par le pointeur donc ne pas oublier de liberer l'espace!! 
		SDL_Quit(); //fermer SDL important pour ne pas saturer la mémoire !!!!!
		//TTF_CloseFont(police); // ici on ferme donc fonction qui charge la police
		//TTF_Quit(); // Fermer TTF important aussi comme le SDL_Quit question de memoire !!
	return 0;
}

