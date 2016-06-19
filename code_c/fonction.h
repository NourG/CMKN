#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

int creabouton(int positionx, int positiony, int w, int h, SDL_Surface* ecran, SDL_Event  event);
int Ecriture (SDL_Surface* ecran, SDL_Event  event);
void saisie(SDL_Surface* ecran, SDL_Event  event);
void wait(SDL_Event event);
