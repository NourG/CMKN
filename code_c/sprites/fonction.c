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
	
	/* Verification du format de l'image */
	/*if ( (image->w != 128) || (image->h != 128) )
	if ( image == NULL )
	{
		fprintf(stderr, "L'image du fichier %s doit être de taille 96*128 pixels.\n", fichier);
		SDL_FreeSurface(image);
		return NULL;
	}*/
	
	return image;
}

int load_Sprite( Sprite *sprite, const char *image )
{
	sprite->image = loadBmp( image );
	if ( !sprite->image )
		return 0;
		
	// on fixe la cle de transparance
	SDL_SetColorKey( sprite->image, SDL_SRCCOLORKEY, SDL_MapRGB( sprite->image->format, 255, 255, 255 ) );

	// On definit d'abord les propriétés du sprite :
	
	// le sprite n'est pas animé par defaut
	sprite->anim = 0;

	// on commence par la première animation
	sprite->anim_courante = 0;

	// le sprite dispose de trois animations
	sprite->total_anims = 12;

	// chaque animation dure 1 affichages
	sprite->temps_anim = 1;

	// Le temps qu'il reste à afficher l'animation courante
	sprite->temps_anim_courante = 0;

	// On definit ensuite les dimentions du sprite.
	sprite->largeur = 42;
	sprite->hauteur = 90;
	
	sprite->source.x = sprite->anim_courante * sprite->largeur;
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.w = sprite->largeur;
	sprite->source.h = sprite->hauteur;
	
	sprite->dest.x = 1000;
	sprite->dest.y = 400;

	sprite->dest.w = sprite->largeur;
	sprite->dest.h = sprite->hauteur;
	
	// on definit enfin la vitesse et la direction du sprite
	sprite->vitesse = 15;
	//sprite->direction = AUCUNE_DIRECTION;
	
	return 1;
}

void movement_Sprite( Sprite *sprite, int direction )
{
	// On affecte la direction au sprite
	sprite->direction = direction;
	
if (direction != AUCUNE_DIRECTION)
	{
		sprite->anim = 1;
		switch (direction)
		{
		case DIRECTION_HAUT:
			sprite->orientation = HAUT;
			break;
			
		case DIRECTION_DROITE:
			sprite->orientation = DROITE;
			break;

		case DIRECTION_BAS:
			sprite->orientation = BAS;
			break;

		case DIRECTION_GAUCHE:
			sprite->orientation = GAUCHE;
			break;

		default:
			;
		}
	}
	else
		// si le sprite est areté, on ne l'anime pas
		sprite->anim = 0;

	// on met la première animation
	sprite->anim_courante = 0;
	sprite->temps_anim_courante = 0;

	// on regle la source de l'image à copier
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.x = sprite->anim_courante * sprite->largeur;
}


void display_Sprite( Sprite *sprite, SDL_Surface *destination )
{
	/* si le sprite est animé, on gere l'animation */
	if (sprite->anim)
	{
		// on decremente le temps restant à l'animation courante
		sprite->temps_anim_courante--;
		// et on regarde s'il est temps de changer d'animation
		if ( sprite->temps_anim_courante <= 0 )
		{
			// s'il faut changer, on passe à l'animation suivante
			sprite->anim_courante++;
			// si on était à la dernière animation, on repasse à la première
			if (sprite->anim_courante >= sprite->total_anims)
				sprite->anim_courante = 0;
			
			// on regle la source à copier
			sprite->source.x = sprite->largeur * sprite->anim_courante;
			sprite->temps_anim_courante = sprite->temps_anim;
		}
	}
	
	// enfin, on dessine le sprite à l'ecran
	SDL_BlitSurface( sprite->image, &sprite->source, destination, &sprite->dest );
}



