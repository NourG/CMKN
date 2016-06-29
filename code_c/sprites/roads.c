//fonctions roads uniquement!!!

int road_1(Sprite *sprite)  // DE LA ZONE 1 VERS LA ZONE 3
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


int road_2(Sprite *sprite)  // DE LA ZONE 1 VERS LA ZONE 2
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
			
			else if(sprite->destination.y <= 275 && sprite->destination.x > 880) //puis a gauche
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
			
			else if(sprite->destination.x <= 880 && sprite->destination.y > 180) // puis en haut
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

			else if (sprite->destination.y <= 180) //arret devant l'evier
			{
				sprite->orientation = DROITE;
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				
			}
	return 1;		
			
}




int road_3(Sprite *sprite)  // DE LA ZONE 1 VERS LA ZONE 4
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
			
			else if(sprite->destination.y <= 180 && sprite->destination.x > 500) //puis a gauche
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

			else if (sprite->destination.x <= 500) //arret devant les etuves
			{
				sprite->orientation = HAUT;
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				
			}
	return 1;		
			
}


int road_4(Sprite *sprite)  // DE LA ZONE 1 VERS LA ZONE 5
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
	
					sleep(1);
					sprite->destination.x = -50;
					sprite->destination.y = -50;
			}
	return 1;		
			
}


int road_5(Sprite *sprite)  // DE LA ZONE 2 VERS LA ZONE 3
{
		//sprite->orientation = DROITE;
		//sprite->destination.x = 1000;
		//sprite->destination.y = 180;


			if(sprite->destination.y <= 180 && sprite->destination.x >840) // a gauche
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
			
			else if(sprite->destination.x <= 840 && sprite->destination.y < 340) // puis en bas
			{
				sprite->orientation = GAUCHE;
				sprite->destination.y += sprite->vitesse;
				sprite->destination.x -= sprite->vitesse;			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
			
			else if (sprite->destination.y >= 340 && sprite->destination.x >= 195)  // puis a gauche
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


