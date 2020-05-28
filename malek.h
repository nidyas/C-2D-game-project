#ifndef MALEK_H_INCLUDED
#define MALEK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct vie
{
	SDL_Rect position ;
	int val ;
	SDL_Surface *image[4];
} vie ;
typedef struct
{
   SDL_Surface* imaged[6];
   SDL_Surface* imageg[6];
    SDL_Surface* imageh[6];
    SDL_Surface* imageb[6];
    SDL_Surface* imageactuelle;
   SDL_Rect Position_Absolue;
   SDL_Rect Position_Relative;
   SDL_Rect Position;
   SDL_Rect ScorePosition;
   SDL_Rect LivesPosition;
    int heromove ;
    int score;
    int lives;
    int dharb;
    int Direction;
    int frame;
    int mouvment ;
}character;

typedef struct score
{
	int nb;
	SDL_Surface *textScore;
	SDL_Rect posScore;

}score;

typedef struct background{

	SDL_Surface *afficher_background;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;
}background;



score initialiserscore(score S);
void afficherscore(score S , SDL_Surface *screen,TTF_Font *police);
void calculerScore(score S,int d);
vie init_vie(vie v);
void affichiervie(character c, SDL_Surface *screen);
void afficherbackground (background bckg ,SDL_Surface *screen);
int gestionvie(character *c, SDL_Surface *screen);
void scrolling (character * c,background *bckg,int co );

#endif // MALEK_H_INCLUDED

