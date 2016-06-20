//fichier h contenant les declarations du main

#define BAS	0
#define GAUCHE	1
#define DROITE	2
#define HAUT	3


#define AUCUNE_DIRECTION	0
#define DIRECTION_HAUT		1
#define DIRECTION_DROITE	2
#define DIRECTION_BAS		4
#define DIRECTION_GAUCHE	8


#define LARGEUR_ECRAN 1370
#define HAUTEUR_ECRAN 900

typedef struct
{
	// pour l'affichage
	
	SDL_Surface *image;
	SDL_Rect source;
	SDL_Rect destination;

	
	// taille du sprite

	int largeur;
	int hauteur;
	
	// pour le déplacement
	
	// direction dans laquelle se deplace le sprite
	int direction;
	
	// vitesse du sprite
	int vitesse;
	
	// pour la gestion des animations
	
	// si le sprite est anime
	int anim;
	
	// direction dans laquelle est orienté le sprite
	int orientation;

	// animation courante du sprite
	int anim_courante;

	// le temps que dure une animation
	int temps_anim;

	// le temps de l'animation courante
	int temps_anim_courante;

	// nombre d'animations du sprite
	int total_anims;

}Sprite;

//declaration des fonctions
SDL_Surface *loadBmp(const char *fichier);
int load_Sprite( Sprite *sprite, const char *image); //chargement de nos operateur dans le labo
void remove_Sprite( Sprite *sprite );   //libere l'escpace sprie
void movement_Sprite( Sprite *sprite, int direction ); //gere les mouvement sprite!!!
void update_Sprite( Sprite *sprite );  //mise a jour du sprite en finction des mouvement
void display_Sprite( Sprite *sprite, SDL_Surface *destination ); //initialisation de l'affichage sprite
int road_1(Sprite *sprite);


