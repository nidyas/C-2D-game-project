#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "character.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"






Character Character_Init (Character C ,int x, int y)
{   C.imageactuelle= NULL ;
  C.Position.x=x;
  C.Position.y=y;


  C.imaged[0]=IMG_Load("1d.png");
  C.imaged[1]=IMG_Load("2d.png");
  C.imaged[2]=IMG_Load("3d.png");
  C.imaged[3]=IMG_Load("4d.png");
  C.imaged[4]=IMG_Load("5d.png");
  C.imaged[5]=IMG_Load("6d.png");

  C.imageg[0]=IMG_Load("1g.png");
  C.imageg[1]=IMG_Load("2g.png");
  C.imageg[2]=IMG_Load("3g.png");
  C.imageg[3]=IMG_Load("4g.png");
  C.imageg[4]=IMG_Load("5g.png");
  C.imageg[5]=IMG_Load("6g.png");

  C.imageh[0]=IMG_Load("1h.png");
  C.imageh[1]=IMG_Load("2h.png");
  C.imageh[2]=IMG_Load("3h.png");
  C.imageh[3]=IMG_Load("4h.png");
  C.imageh[4]=IMG_Load("5h.png");
  C.imageh[5]=IMG_Load("6h.png");

    C.imageb[0]=IMG_Load("1b.png");
    C.imageb[1]=IMG_Load("2b.png");
    C.imageb[2]=IMG_Load("3b.png");
    C.imageb[3]=IMG_Load("4b.png");
    C.imageb[4]=IMG_Load("5b.png");
    C.imageb[5]=IMG_Load("6b.png");

  C.imageactuelle=C.imaged[0];
  C.frame=0;
  C.Direction=0;
  return C ;
}  



void showChar(Character C, SDL_Surface *screen)
{
   
    SDL_BlitSurface(C.imageactuelle,NULL,screen,&C.Position);
}






Character animChar (Character C )
{

if (C.frame==5) {C.frame=0 ;}

        else C.frame ++ ;
        switch (C.Direction)
        {
    case 1 :
        C.imageactuelle=C.imaged[C.frame];

        break;

    case 2 :
          C.imageactuelle=C.imageg[C.frame];
          break;

    case 3 :
        C.imageactuelle=C.imageh[C.frame];
        break;

    case 4 :
        C.imageactuelle=C.imageb[C.frame];
        break;
}


            return C ;
}





Character moveChar(Character C )
 {  

 if (C.Direction = 1) {C.Position.x =C.Position.x +5 ;}
 if (C.Direction = 2) {C.Position.x =C.Position.x -5 ;}
 if (C.Direction = 3) {C.Position.x =C.Position.y +5 ;}
 if (C.Direction = 4) {C.Position.x =C.Position.y -5 ;}


 return  C ;

}



SCharacter SCharacter_Init (SCharacter SC ,int x, int y)
{   C.imageactuelle= NULL ;
  C.Position.x=x;
  C.Position.y=y;


  C.imaged2[0]=IMG_Load("1d.png");
  C.imaged2[1]=IMG_Load("2d.png");
  C.imaged2[2]=IMG_Load("3d.png");
  C.imaged2[3]=IMG_Load("4d.png");
  C.imaged2[4]=IMG_Load("5d.png");
  C.imaged2[5]=IMG_Load("6d.png");

  C.imageg2[0]=IMG_Load("1g.png");
  C.imageg2[1]=IMG_Load("2g.png");
  C.imageg2[2]=IMG_Load("3g.png");
  C.imageg2[3]=IMG_Load("4g.png");
  C.imageg2[4]=IMG_Load("5g.png");
  C.imageg2[5]=IMG_Load("6g.png");

  C.imageh2[0]=IMG_Load("1h.png");
  C.imageh2[1]=IMG_Load("2h.png");
  C.imageh2[2]=IMG_Load("3h.png");
  C.imageh2[3]=IMG_Load("4h.png");
  C.imageh2[4]=IMG_Load("5h.png");
  C.imageh2[5]=IMG_Load("6h.png");

    C.imageb2[0]=IMG_Load("1b.png");
    C.imageb2[1]=IMG_Load("2b.png");
    C.imageb2[2]=IMG_Load("3b.png");
    C.imageb2[3]=IMG_Load("4b.png");
    C.imageb2[4]=IMG_Load("5b.png");
    C.imageb2[5]=IMG_Load("6b.png");

  C.imageactuelle2=C.imaged2[0];
  C.frame2=0;
  C.Direction2=0;
  return SC ;
}  



void showSChar(Character C, SDL_Surface *screen)
{
   
    SDL_BlitSurface(C.imageactuelle2,NULL,screen,&C.Position2);
}






SCharacter animChar (SCharacter SC )
{

if (SC.frame==5) {SC.frame=0 ;}

        else SC.frame ++ ;
        switch (SC.Direction)
        {
    case 1 :
        SC.imageactuelle=SC.imaged[SC.frame];

        break;

    case 2 :
          SC.imageactuelle=SC.imageg[SC.frame];
          break;

    case 3 :
        SC.imageactuelle=SC.imageh[SC.frame];
        break;

    case 4 :
        SC.imageactuelle=SC.imageb[SC.frame];
        break;
}


            return SC ;
}





SCharacter moveChar(Character SC )
 {  

 if (SC.Direction = 1) {SC.Position.x =SC.Position.x +5 ;}
 if (SC.Direction = 2) {SC.Position.x =SC.Position.x -5 ;}
 if (SC.Direction = 3) {SC.Position.x =SC.Position.y +5 ;}
 if (SC.Direction = 4) {SC.Position.x =SC.Position.y -5 ;}


 return  SC ;

}




