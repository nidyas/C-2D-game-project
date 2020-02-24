#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>


typedef struct{
    SDL_Surface * img;
    SDL_Surface *hover;
    int itIsHovered;
    Mix_Chunk * sClick;
    Mix_Chunk * sHover;
    SDL_Rect pos;
}button;
typedef struct {
    SDL_Surface* background;
    SDL_Rect pos;
    button b[4];
}menu;
typedef struct{
    SDL_Surface * img;
    SDL_Rect pos;
    SDL_Surface * but;
    SDL_Surface * hover;
    SDL_Rect butpos;

}credits;
typedef struct {
    SDL_Surface *settbackground;
    SDL_Rect setbpos;
    SDL_Surface * volumePer;
    SDL_Rect volPos;
    button b[5];
}settings;
typedef struct 
{   SDL_Surface * img;
    SDL_Rect pos3;
}stage;

void initSett(settings * set);
void showSett(settings set, SDL_Surface * screen);
void initMenu(menu * m);
void showMenu(menu m, SDL_Surface * screen);
int settingsClicks(SDL_Event event, settings *s);
void initCredits(credits * c);
void showCredits(credits c, SDL_Surface * screen);
void initStage(stage *sta);
void showStage(stage sta,SDL_Surface *screen);
int mouseKeyboard(SDL_Surface * screen, int *image_courant, menu * m, SDL_Event event);
void menuMotion(menu * m,SDL_Event event);
int menuClicks(menu m, SDL_Event event);

#endif


