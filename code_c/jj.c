/*
 * jj.c
 *
 * Copyright 2016 isen <isen@isen-VirtualBox>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <stdio.h>
typedef struct eve  {   // déclaration du type de la donnée partagée
	int heure, minute;
	int jour, mois;
	int seconde;
	int id ;
	int type_event;
	eve *suiv    //sortie des tests ou horaire operateur
} events;

typedef struct maillon
{
char info[NMAX] ;
struct maillon* suiv;
} MAIL;

events* CreerMaillon1(void);
events* insBP(events *T,events *N);


int main(int argc, char **argv)
{

	return 0;
}

MAIL* CreerMaillon1(void)
{
MAIL* N=(MAIL *)malloc(sizeof(MAIL));
if (N == NULL)
{ printf("\nErreur allocation memoire");
return NULL;
}
printf("\nDonner un mot : ");
scanf("%s", N->info);
N->suiv = NULL;
return N;
}



MAIL* insBP1(MAIL *T, MAIL *N)
{
if (T == NULL) return N;
if (strcmp(N->info,T->info)<0)
{ N->suiv = T;
return N;
}
else
{ T->suiv= insBP(T->suiv,N);
return T;
}
}



