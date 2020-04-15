#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "youssef.h"







enemy intialisation_ennemie(enemy ennemie,int x, int y)
{   
  ennemie.position.x=x;
ennemie.position.y=y;

  ennemie.imaged[0]=IMG_Load("d1.png");
  ennemie.imaged[1]=IMG_Load("d2.png");
  ennemie.imaged[2]=IMG_Load("d3.png");
  ennemie.imaged[3]=IMG_Load("d4.png");
  ennemie.imaged[4]=IMG_Load("d5.png");
  ennemie.imaged[5]=IMG_Load("d6.png");
  
  
  ennemie.imageg[0]=IMG_Load("g1.png");
  ennemie.imageg[1]=IMG_Load("g2.png");
  ennemie.imageg[2]=IMG_Load("g3.png");
  ennemie.imageg[3]=IMG_Load("g4.png");
  ennemie.imageg[4]=IMG_Load("g5.png");
  ennemie.imageg[5]=IMG_Load("g6.png");
  



  ennemie.imageactuelle=ennemie.imaged[0];
   
  //ennemie.dhrab=IMG_Load(".png");

  ennemie.positionn =ennemie.position ;
  ennemie.frame=0;
  ennemie.direction=0;
  ennemie.met=0;
  return ennemie;
}





void  afficher_ennemie(enemy ennemie,SDL_Surface *screen)
{
  SDL_BlitSurface(ennemie.imageactuelle,NULL,screen,&ennemie.position);
}




enemy animation_ennemie(enemy ennemie ,int z)
{ if (z==1)
  {
      ennemie.imageactuelle=ennemie.dhrab;
  }
  else { if  (ennemie.frame==5) {ennemie.frame=0 ; }
        else ennemie.frame++ ; 

    if (ennemie.direction==1) {ennemie.imageactuelle=ennemie.imaged[ennemie.frame] ;  }
    else if (ennemie.direction==2){ennemie.imageactuelle=ennemie.imageg[ennemie.frame] ;  }  }
 printf ("%d  | %d | %d  | %p | \n ",ennemie.position.x,ennemie.direction,ennemie.frame,ennemie.imaged[ennemie.frame]) ;
printf ("||| %p |%p |%p |%p |%p |%p |||| \n",ennemie.imaged[0],ennemie.imaged[1],ennemie.imaged[2],ennemie.imaged[3],ennemie.imaged[4],ennemie.imaged[5]) ;
printf ("||| %p |%p |%p |%p |%p |%p |||| \n",ennemie.imageg[0],ennemie.imageg[1],ennemie.imageg[2],ennemie.imageg[3],ennemie.imageg[4],ennemie.imageg[5]) ;
printf ("\n");
  return ennemie ;



}




enemy deplacement_aleatoire ( enemy ennemie , int posmax, int posmin , int *z)
{  int distance ;


    if (ennemie.position.x <= posmax)  { ennemie.direction =1 ; }
   if (ennemie.position.x > posmin)  { ennemie.direction =2  ; }

   if (ennemie.direction==1) {ennemie.position.x=ennemie.position.x + 5 ;  }
   if (ennemie.direction==2) {ennemie.position.x=ennemie.position.x - 5 ; }


return ennemie ;

}







 int mouvment(hero evan,SDL_Event *event )
 {

 	int mouvment;

SDL_PollEvent(event);
switch (event->type)
        {
            case SDL_QUIT:
               mouvment=0; 
               break;
            case SDL_KEYDOWN:
                 switch (event->key.keysym.sym)
                {
                  case SDLK_ESCAPE:
                      mouvment=6;
                      break;
                  case SDLK_RIGHT:
				      mouvment=1;
                      break;
                  case SDLK_LEFT:
            	      mouvment=2;
                      break;
                  case SDLK_UP:
                      mouvment=3;
                      break;
                  case (SDLK_SPACE):
                      mouvment=5;
                      break;
               }
              break;

 }

 return mouvment;

}




































