int road_1(Sprite *sprite)  // DE LA ZONE 1 VERS LA ZONE 2
{

	
	int temp =0, temp_2=0;
	if (temp == 0)
	{
if(sprite->destination.y > 275 && sprite->destination.x > 750)  // road1 on va en haut


			{
			//deplacement sur y
			sprite->orientation = HAUT;
			sprite->destination.y -= sprite->vitesse;

			//translation de l'animation
			sprite->anim_courante++;
				if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
			
				// on regle la source à copier
				sprite->source.x =  sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;
			}
			
			else if(sprite->destination.y <= 275 && sprite->destination.x > 890) //puis a gauche
			{
				sprite->orientation = GAUCHE;
				sprite->destination.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
					sprite->source.x = sprite->largeur * sprite->anim_courante;
					sprite->source.y = sprite->orientation * sprite->hauteur;
					sprite->temps_anim_courante = sprite->temps_anim;
			}
			
			else if(sprite->destination.x <= 890 && sprite->destination.y > 180) // puis en haut
			{
				sprite->orientation = HAUT;
				sprite->destination.y -= sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
		
		
			else if(sprite->destination.y <= 180 && sprite->destination.x > 850) //puis a gauche
			{
				sprite->orientation = GAUCHE;
				sprite->destination.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
					sprite->source.x = sprite->largeur * sprite->anim_courante;
					sprite->source.y = sprite->orientation * sprite->hauteur;
					sprite->temps_anim_courante = sprite->temps_anim;
			}
			
				
			temp=1;
		}
			
		
			
	return 1;		
			
}


int road_2(Sprite *sprite)  // DE LA ZONE 1 VERS LA ZONE 5
{


if(sprite->destination.y > 275 && sprite->destination.x > 750)  // road1 on va en haut
			{
			//deplacement sur y
			sprite->orientation = HAUT;
			sprite->destination.y -= sprite->vitesse;

			//translation de l'animation
			sprite->anim_courante++;
				if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
			
				// on regle la source à copier
				sprite->source.x =  sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;
			}
			
			else if(sprite->destination.y <= 275 && sprite->destination.x > 770) //puis a gauche
			{
				sprite->orientation = GAUCHE;
				sprite->destination.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
					sprite->source.x = sprite->largeur * sprite->anim_courante;
					sprite->source.y = sprite->orientation * sprite->hauteur;
					sprite->temps_anim_courante = sprite->temps_anim;
			}
			
			else if(sprite->destination.x <= 770 && sprite->destination.y > 180) // puis en haut
			{
				sprite->orientation = HAUT;
				sprite->destination.y -= sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
			
			else if(sprite->destination.y <= 180 && sprite->destination.x > 360) //puis a gauche
			{
				sprite->orientation = GAUCHE;
				sprite->destination.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
					sprite->source.x = sprite->largeur * sprite->anim_courante;
					sprite->source.y = sprite->orientation * sprite->hauteur;
					sprite->temps_anim_courante = sprite->temps_anim;
			}
			else if(sprite->destination.x <= 360 && sprite->destination.y > 100) // puis en haut
			{
				sprite->orientation = HAUT;
				sprite->destination.y -= sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
			else if (sprite->destination.y <= 120) //on le fait disparaitre
			{
	
					usleep(600);
					sprite->destination.x = -50;
					sprite->destination.y = -50;
			}
	return 1;		
			
}



int road_3(Sprite *sprite)  // DE LA ZONE 5 VERS LA ZONE 1
{

		

	if (sprite->destination.x >350 && sprite->destination.y < 180 ) 
			{
				sprite->orientation = BAS;
				sprite->destination.y += sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;

			}
	
	else if(sprite->destination.y <= 180 && sprite->destination.x < 750) //puis a gauche
			{
				sprite->orientation = DROITE;
				sprite->destination.x += sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
					sprite->source.x = sprite->largeur * sprite->anim_courante;
					sprite->source.y = sprite->orientation * sprite->hauteur;
					sprite->temps_anim_courante = sprite->temps_anim;
			}
			
		else if(sprite->destination.x <= 750 && sprite->destination.y < 260) //&& sprite->destination.y <300)
			{ 
	
				sprite->orientation = BAS;
				sprite->destination.y += sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}	
		
		else if(sprite->destination.y >= 260 && sprite->destination.x < 980) //puis a gauche
			{
				sprite->orientation = DROITE;
				sprite->destination.x += sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
					sprite->source.x = sprite->largeur * sprite->anim_courante;
					sprite->source.y = sprite->orientation * sprite->hauteur;
					sprite->temps_anim_courante = sprite->temps_anim;
			}
			
		else if(sprite->destination.x >= 980 && sprite->destination.y < 340) //&& sprite->destination.y <300)
			{ 
	
				sprite->orientation = BAS;
				sprite->destination.y += sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
		else if (sprite->destination.y >= 340) //on le fait disparaitre
			{
	
				sprite->orientation = GAUCHE;
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
			}

		
}

int road_4(Sprite *sprite)  // DE LA ZONE 1 VERS LA ZONE 3
{


		if(sprite->destination.y > 275 && sprite->destination.x > 750)  // road1 on va en haut
			{
			//deplacement sur y
			sprite->orientation = HAUT;
			sprite->destination.y -= sprite->vitesse;

			//translation de l'animation
			sprite->anim_courante++;
				if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
			
				// on regle la source à copier
				sprite->source.x =  sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;
			}
			
			else if(sprite->destination.y <= 275 && sprite->destination.x > 750) //puis a gauche
			{
				sprite->orientation = GAUCHE;
				sprite->destination.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
					sprite->source.x = sprite->largeur * sprite->anim_courante;
					sprite->source.y = sprite->orientation * sprite->hauteur;
					sprite->temps_anim_courante = sprite->temps_anim;
			}
			
			else if(sprite->destination.x <= 750 && sprite->destination.y <= 350) // puis en bas
			{
				sprite->orientation = BAS;
				sprite->destination.y += sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
			
			else if (sprite->destination.y >= 350 && sprite->destination.x >= 195)  // puis a gauche
			{
				sprite->orientation =GAUCHE;
				sprite->destination.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
			
			else if (sprite->destination.x <= 195) //arret devant les ecrans de la salle des etuves 1
			{
				sprite->orientation = GAUCHE;
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				
			}
	return 1;		
			
}

int road_1_3(Sprite *sprite)  // DE LA ZONE 1 VERS LA ZONE 3
{
	int temp=0;
	
	if (temp==0)
	{

		if (sprite->destination.x > 500 && sprite->destination.y < 300 ) 
			{
				sprite->orientation = BAS;
				sprite->destination.y += sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;

			}
		else if (sprite->destination.y >= 300 && sprite->destination.x > 500)  // puis a gauche
			{
				sprite->orientation =GAUCHE;
				sprite->destination.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
			
		else if (sprite->destination.x <= 500) //arret devant les ecrans de la salle des etuves 1
			{
				sprite->orientation = HAUT;
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				
			}
			
		temp =  1;
		}

}



