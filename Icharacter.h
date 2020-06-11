#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"



typedef struct
{
   SDL_Surface* imaged[7];
   SDL_Surface* imageg[6];
    SDL_Surface* imageh[7];
    SDL_Surface* imageb[6];
    SDL_Surface* imageactuelle;
   //SDL_Rect Position_Absolue;
   //SDL_Rect Position_Relative;
   SDL_Rect Position;
    
    int lives;
    int Direction;
    int frame;
}Character;

typedef struct
{
   SDL_Surface* imaged2[7];
   SDL_Surface* imageg2[6];
    SDL_Surface* imageh2[7];
    SDL_Surface* imageb2[6];
    SDL_Surface* imageactuelle2;
   //SDL_Rect Position_Absolue;
   //SDL_Rect Position_Relative;
   SDL_Rect Position2;
    
    int lives;
    int Direction;
    int frame;
}SCharacter;


//! initialsation du personnage principal
Character Character_Init (Character C ,int x, int y);
//! affichage du personnage principal
void  showChar(Character c, SDL_Surface *screen);
//! animation du personnage principal
Character animChar (Character C );
//! deplacement du personnage principal
Character moveChar ( Character C  );
Character SCharacter_Init (Character C ,int x, int y);
void  showSChar(Character c, SDL_Surface *screen);
Character animSChar (Character C );
Character moveSChar ( Character C  );




#endif // CHARACTER_H_INCLUDED
