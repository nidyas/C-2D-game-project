#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"malek.h"
#include <time.h>

//scorevie.c

void init_vie(vie *v)
{
 (v->position.x)=0;
 (v->position.y)=0;
 (v->val)=0 ;
 (v->image[1])=IMG_Load("vie1.png") ;
 (v->image[2])=IMG_Load("vie2.png") ;
 (v->image[3])=IMG_Load("vie3.png") ;
 (v->image[4])=IMG_Load("gameover.jpg") ;
}
void affichiervie(personnage p, SDL_Surface *Screen)
{
    SDL_BlitSurface(p.afficher_vie[p.vie],NULL,Screen,&p.pos_vie);
}

int gestionvie(personnage *p, SDL_Surface *Screen)
{
if((p->dharb==1)&&(p->vie!=0))
    {
    p->vie--;
   // affichiervie(*p,Screen);
  //  SDL_Flip(Screen);
 //  usleep(1000000); //Arr�te l'ex�cution durant quelques microsecondes
    p->pos_hero2.y=50;
    }
p->dharb=0;
if (p->vie==0)
return 0;

else
return 1;
}
int gestion_score(int collision,int i)
{
    SDL_Surface *ecran = NULL, *score = NULL;
    SDL_Rect  positionscore;
    SDL_Rect rects[10];
    positionscore.x = 0;
    positionscore.y = 0;
    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    if(collision==1)
    {
            i++;
    if(i>10){i=10;}
    }
    else if(collision==0)
    {
        i--;
    if(i<0){i=0;}
    }
   switch(i){
       case 0:
score=IMG_Load("0.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 1:
score=IMG_Load("1.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 2:
score=IMG_Load("2.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 3:
score=IMG_Load("3.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 4:
score=IMG_Load("4.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 5:
score=IMG_Load("5.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 6:
score=IMG_Load("6.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 7:
score=IMG_Load("7.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 8:
score=IMG_Load("8.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 9:
score=IMG_Load("9.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
        case 10:
score=IMG_Load("10.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
}

    /* Chargement et blittage de Zozor sur la sc�ne */

    SDL_Flip(ecran);
    pause();


    SDL_FreeSurface(score);
    SDL_Quit();

    return i;
}

//scrollinghv.c

SDL_Surface* Charger( char* fic)
{
    SDL_Surface *res;
    SDL_Surface* tmp = SDL_LoadBMP(fic);
    if (tmp==NULL)
    {
        printf("Erreur chargement %s\n",fic);
        return(-1);
    }
    res = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    return res;
}

int negatmodulo(int x,int mod)
{
    if (x>=0)
        return x%mod;
    return (x%mod)+mod;
}

int main(int argc,char** argv)
{
    SDL_Surface* fond,*screen;

    int x,y;
    x=y=0;
    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(IMX,IMY,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
    fond=Charger("fond.bmp");
    do
    {
        SDL_Rect R;
        key = SDL_GetKeyState(NULL);  // on va verifier chaque d�but de boucle quelle touche est en haut, quelle touche est en bas
        SDL_PumpEvents(); // mettre � jour le doc le sp�cifie
        //Je fais �voluer  x et y en fonction des fl�ches
        if (key[SDLK_LEFT])
            x-=SPEED;
        if (key[SDLK_RIGHT])
            x+=SPEED;
        if (key[SDLK_UP])
            y-=SPEED;
        if (key[SDLK_DOWN])
            y+=SPEED;
            // j'en colle quatre photos la fonction de Blit s'occupe du d�coupage.
        R.x = negatmodulo(x,IMX);
        R.y = negatmodulo(y,IMY);
        SDL_BlitSurface(fond,NULL,screen,&R);
        R.x = negatmodulo(x,IMX) - IMX;
        R.y = negatmodulo(y,IMY);
        SDL_BlitSurface(fond,NULL,screen,&R);
        R.x = negatmodulo(x,IMX) - IMX;
        R.y = negatmodulo(y,IMY) - IMY;
        SDL_BlitSurface(fond,NULL,screen,&R);
        R.x = negatmodulo(x,IMX);
        R.y = negatmodulo(y,IMY) - IMY;
        SDL_BlitSurface(fond,NULL,screen,&R);
        SDL_Flip(screen);
        SDL_Delay(3);
    }
    while(!key[SDLK_ESCAPE]);
    SDL_FreeSurface(fond);
    SDL_Quit();
    return 0;
}
