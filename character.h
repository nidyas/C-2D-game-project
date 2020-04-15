#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED


typedef struct
{
   SDL_Surface* imaged[6];
   SDL_Surface* imageg[6];
    SDL_Surface* imageh[6];
    SDL_Surface* imageb[6];
    SDL_Surface* imageactuelle;
   SDL_Rect Position_Absolue;
   SDL_Rect Position_Relative;
   SDL_Rect ScorePosition;
   SDL_Rect LivesPosition;
   SDL_Mixchunk son;
    int score;
    int lives;
    int Direction;
    int frame;
}Character;



Character Character_Init (Character C ,int x, int y);
Character showChar(charac c, SDL_Surface * screen);
Character animChar (charac c, SDL_Surface *screen, SDL_Event event);
void moveChar (SDL_Event event, SDL_Rect *posobj, int inWhichDir);
void moveCharByMouse(SDL_Surface *screen,SDL_Rect * persoPos, SDL_Event event);





#endif // CHARACTER_H_INCLUDED
