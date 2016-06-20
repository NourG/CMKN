//fonctions roads uniquement!!!

int road_1(Sprite *sprite)
{


if(sprite->dest.y > 250 && sprite->dest.x > 770)  // road1 on va en haut
			{
			//deplacement sur y
			sprite->orientation = HAUT;
			sprite->dest.y -= sprite->vitesse;

			//translation de l'animation
			sprite->anim_courante++;
				if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
			
				// on regle la source à copier
				sprite->source.x =  sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;
			}
			
			else if(sprite->dest.y <= 250 && sprite->dest.x > 770) //puis a gauche
			{
				sprite->orientation = GAUCHE;
				sprite->dest.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
					sprite->source.x = sprite->largeur * sprite->anim_courante;
					sprite->source.y = sprite->orientation * sprite->hauteur;
					sprite->temps_anim_courante = sprite->temps_anim;
			}
			
			else if(sprite->dest.x <= 770 && sprite->dest.y <= 350) // puis en bas
			{
				sprite->orientation = BAS;
				sprite->dest.y += sprite->vitesse;
							
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
			
			else if (sprite->dest.y >= 350 && sprite->dest.x >= 230)  // puis a gauche
			{
				sprite->orientation =GAUCHE;
				sprite->dest.x -= sprite->vitesse;
			
				sprite->anim_courante++;
					if (sprite->anim_courante >= sprite->total_anims)
					sprite->anim_courante = 0;
					
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				sprite->temps_anim_courante = sprite->temps_anim;				
			}
			
			else if (sprite->dest.x <= 230) //arret devant les ecrans de la salle des etuves 1
			{
				sprite->orientation = BAS;
				sprite->source.x = sprite->largeur * sprite->anim_courante;
				sprite->source.y = sprite->orientation * sprite->hauteur;
				
			}
	return 1;		
			
}
