#ifndef UTI_H
#define UTI_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"

typedef struct 
{
    int x;

}utilities;

typedef struct {
int sec;
int min;
int ticker;
}timer;
typedef struct {
  SDL_Surface *hearts;
  SDL_Rect posLives;
  SDL_Surface *livestext;
  SDL_Surface *timestext;
  SDL_Surface *scoretext;
  SDL_Rect scorePos;
  SDL_Rect posheart;
  SDL_Rect timePos;
}entities;
typedef struct 

{  int score ;
    int lives;
 } charscore;



void scrolling (SDL_Rect * camera, SDL_Event event);
float convertsec(int mill);
float convertmin( int sec);

SDL_Surface * gameTime (timer *t) ;
SDL_Surface * refreshGameTime(int *ti);

entities gameEntities();
SDL_Surface * updateScore(int *score);
SDL_Surface * updateLives(int *lives);
//void savegame(SDL_Event event );
int checklastgame();
int onplaybutton();

#endif // FONCTIONS_H_INCLUDED
