//fontion.c

void remove_Sprite( Sprite *sprite )
{
	SDL_FreeSurface( sprite->image );
}

SDL_Surface *loadBmp(const char *fichier)
{
	SDL_Surface *image;

	// Chargement du bitmap "fichier" en memoire dans la surface image 
	image = SDL_LoadBMP(fichier);
	if ( image == NULL )
	{
		fprintf(stderr, "Echec de chargement du fichier %s : %s.\n", fichier, SDL_GetError());
		return NULL;
	}
	
	return image;
}

int load_Sprite( Sprite *sprite, const char *image )
{
	sprite->image = loadBmp( image );
	if ( !sprite->image )
		return 0;
		
	// on fixe la cle de transparance
	SDL_SetColorKey( sprite->image, SDL_SRCCOLORKEY, SDL_MapRGB( sprite->image->format, 255, 255, 255 ) );

		
	// le sprite n'est pas animé par defaut
	sprite->anim = 0;

	// on commence par la première animation
	sprite->anim_courante = 0;

	// le sprite dispose de 12 animations
	sprite->total_anims = 12;

	// chaque animation dure 1 affichages
	sprite->temps_anim = 1;

	// Le temps qu'il reste à afficher l'animation courante est nul
	sprite->temps_anim_courante = 0;

	// On definit ensuite les dimentions du sprite.
	sprite->largeur = 46;
	sprite->hauteur = 77;
	
	//on effectue les reglages dynamiques
	sprite->source.x = sprite->anim_courante * sprite->largeur;
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.w = sprite->largeur;
	sprite->source.h = sprite->hauteur;
	
	sprite->destination.x = 1014;
	sprite->destination.y = 470;

	sprite->destination.w = sprite->largeur;
	sprite->destination.h = sprite->hauteur;
	
	// on definit enfin la vitesse et la direction du sprite
	sprite->vitesse = 30;

	
	return 1;
}






