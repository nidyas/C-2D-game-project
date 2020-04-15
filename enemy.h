
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct hero
{
	int mouvment;
	SDL_Rect pos_hero[5];
	SDL_Surface *afficher_herog[5];
	SDL_Surface *afficher_herod[5];
	SDL_Rect pos_hero2;
	int vie;
	SDL_Surface *afficher_vie[5];
	int score;
	SDL_Surface *afficher_score;
	SDL_Rect pos_vie;
	int dhrab;
	int movehero;
	float vx;
	float vy;
	float x;
	float y;

}hero;


typedef struct enemy
{
  SDL_Surface *imaged[6];
  SDL_Surface *imageg[6];
  SDL_Surface *dhrab;
  SDL_Surface *imageactuelle;
  SDL_Rect position ;
  SDL_Rect positionn ;
  int frame;
  int direction;
  int met;

}enemy;

enemy intialisation_ennemie(enemy ennemie,int x, int y) ;
void  afficher_ennemie(enemy ennemie,SDL_Surface *screen);
enemy animation_ennemie(enemy ennemie ,int z);
enemy deplacement_aleatoire ( enemy ennemie , int posmax, int posmin , int *z);
int mouvment(hero evan,SDL_Event *event);





#endif // STRUCTURE_H_INCLUDED
