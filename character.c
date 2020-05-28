#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

charac initChar (){
  charac c;
  char ch[512];
  int i;
  for (i = 0; i < 12; i++) {
      sprintf(ch, "Resources/azizsprite/%d.png", i+1);
    c.spriteright[i] = IMG_Load(ch);
  }
  for (i = 0; i < 11; i++) {
      sprintf(ch, "Resources/azizspriteleft/%d.png", i+1);
    c.spriteleft[i] = IMG_Load(ch);
  }
  c.shoot = IMG_Load("Resources/azizsprite/aziz-shoot.png");
  c.jump = IMG_Load("Resources/azizsprite/aziz-jump.png");
  c.shoot_left = IMG_Load("Resources/azizsprite/aziz-shoot-left.png");
  c.jump_left = IMG_Load("Resources/azizsprite/aziz-jump-left.png");
  c.positionChar.x = 150;
  c.positionChar.y = 350;
  return c;
}
void showChar(charac c, SDL_Surface * screen, char whichDirection){
  if(whichDirection == 'r'){
c.positionChar.h = c.spriteright[0]->h;
c.positionChar.w = c.spriteright[0]->w;
 SDL_BlitSurface(c.spriteright[0], NULL, screen, &c.positionChar);
}else{
  if(whichDirection == 'l'){
  c.positionChar.h = c.spriteleft[0]->h;
  c.positionChar.w = c.spriteleft[0]->w;
   SDL_BlitSurface(c.spriteleft[0], NULL, screen, &c.positionChar);
}
}
}
char animChar (charac c, SDL_Surface *screen, SDL_Event event, char whichDirection){
  static int right = 0, left = 0;
  if (event.key.keysym.sym == SDLK_RIGHT) {
      left=13;
      if (right > 12){
          right = 0;
        SDL_BlitSurface(c.spriteright[right], NULL, screen, &c.positionChar);
        whichDirection = 'r';
        return whichDirection;
      }else{
        SDL_BlitSurface(c.spriteright[right], NULL, screen, &c.positionChar);
          right++;
        whichDirection = 'r';
        return whichDirection;
      } 
  }else{
    if (event.key.keysym.sym == SDLK_LEFT) {
      right=13;
    if (left > 12){
       left = 0;
     SDL_BlitSurface(c.spriteleft[left], NULL, screen, &c.positionChar);
     whichDirection = 'l';
     return whichDirection;
    }else{
        SDL_BlitSurface(c.spriteleft[left], NULL, screen, &c.positionChar);
      left++;
        whichDirection = 'l';
        return whichDirection;
      }
    }else{
      if(event.key.keysym.sym == SDLK_SPACE){
        if(whichDirection == 'l'){
          SDL_BlitSurface(c.jump_left, NULL, screen, &c.positionChar);
        }else{
        SDL_BlitSurface(c.jump, NULL, screen, &c.positionChar);
      }
      }
    }
  }
  return whichDirection;
}
void moveChar (SDL_Event event, SDL_Rect *posobj, int inWhichDir){
switch (event.key.keysym.sym){
  case SDLK_SPACE:
  if(inWhichDir != 1){
    posobj->y -=10;
  }
  break;
  case SDLK_RIGHT:
    if(inWhichDir != 2){
      posobj->x +=10;
    }
  break;
  case SDLK_LEFT:
    if(inWhichDir != 3){
        posobj->x -= 10;
      }
   break;
   case SDLK_DOWN:
     if(inWhichDir != 4){
         posobj->y += 10;
       }
    break;
  }

}
void moveCharByMouse(SDL_Surface *screen,SDL_Rect * persoPos, SDL_Event event, char whichDirection){
  switch(event.type){
         case SDL_MOUSEBUTTONDOWN:
             if(event.button.button == SDL_BUTTON_LEFT){
              persoPos->x += 10;
           }
         break;
   }
}
