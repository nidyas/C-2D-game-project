#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <stdio.h>
#include <stdlib.h>
#include "uti.h"

void scrolling (SDL_Rect * camera, SDL_Event event){
        switch (event.key.keysym.sym){
	case SDLK_RIGHT:
       camera->x = camera->x + 100;
	break;
	case SDLK_LEFT:
       camera->x = camera->x - 100;
	break;
 }
}

float convertsec(int mill){
  float sec;
  sec = mill/1000;
  return sec;
}


entities gameEntities(){
  entities e;
  e.hearts = IMG_Load("hearts.png");
  e.scorePos.x = 480;
  e.scorePos.y = 10;
    e.posLives.x = 900;
    e.posLives.y = 10;
    e.timePos.x = 10;
    e.timePos.y = 10;
  e.posheart.x = 910;
  e. posheart.y = 10;
   e.posheart.w = e.hearts->w;
   e.posheart.h = e.hearts->h;
   return e;
}

SDL_Surface * refreshGameTime(int *ti){
    unsigned int time = SDL_GetTicks();
    int current = time - *ti;
    char ch[10];
    SDL_Surface *scoring = NULL;
    TTF_Font *police = NULL;
    SDL_Color noir = {255, 255, 255};
    float prin =convertsec(current);
      
    if (TTF_Init() < 0) {
      printf("error\n");
  }else{
    police = TTF_OpenFont("Bebas-Regular.ttf", 32);
    if (police == NULL) {
      printf("error dans open font scorerect\n");
    }else{
      sprintf(ch,"Time: %.2f",prin);
      scoring=TTF_RenderText_Solid(police, ch, noir);
  TTF_CloseFont(police);
  TTF_Quit();
  }
  }
  *ti = current;
    return scoring;
}


SDL_Surface * updateScore(int *score){
  char ch[10];
  SDL_Surface *scoring = NULL;
  TTF_Font *police = NULL;
  SDL_Color noir = {255, 255, 255};
  if (TTF_Init() < 0) {
    printf("error\n");
}else{
  police = TTF_OpenFont("Bebas-Regular.ttf", 32);
  if (police == NULL) {
    printf("error dans open font scorerect\n");
  }else{
    sprintf(ch,"Score: %d",*score);
    scoring=TTF_RenderText_Solid(police, ch, noir);
TTF_CloseFont(police);
TTF_Quit();
}
}
   return scoring;
}



SDL_Surface * updateLives(int *lives){
char ch[10];
  SDL_Rect poslives;
SDL_Surface *livestext;
  poslives.x=900;
  poslives.y=10;
  poslives.w = 0;
  poslives.h = 0;
	if (TTF_Init() < 0) {
    printf("error\n");
}else{
  TTF_Font *police = NULL;
  SDL_Color noir = {255, 255, 255};
  police = TTF_OpenFont("Bebas-Regular.ttf", 32);
  if (police == NULL) {
    printf("error dans open font\n");
  }else{
  sprintf(ch, "LIVES: %d", *lives);
  livestext=TTF_RenderText_Solid(police, ch, noir);
TTF_CloseFont(police);
}
}
}




/*void savegame( ){
 
         printf("do u want to save?- Yes. 1, No. 0\n");
        scanf("%d\n", &u);
        if(u == 1){
          f = fopen("backupgame.bin", "wb");
          if(f == NULL){
            printf("an error occured\n");
          }else{
            bue.camera = camera;
            printf("%p\n", back);
            strcpy(bue.background, "backgroundstage1.png");
            strcpy(bue.perso, "soso.png");
            bue.persoPos = rect1;
            bue.headPos = headPos;
            strcpy(bue.head, "head.png");
            bue.score= score;
            bue.lives =lives;
            bue.t = t;
            fwrite(&bue, 1, sizeof(bue), f);
            done = 1;
            fclose(f);
          }
        }
  break;


}*/


int checklastgame(){
  FILE * f = fopen("backupgame.bin", "rb");
  if(f == NULL){
    printf("no sessions found\n");
    f = fopen("backupgame.bin", "wb");
      fclose(f);
    return 0;
  }else{
    printf("there's a session\n");
      fclose(f);
    return 1;
  }
}
int onplaybutton(){
  int pick, x;
  x = checklastgame();
  if(x == 1){
    printf("1. start a new game\n");
    printf("2. resume previous game\n");
    do{
    printf("give your choice\n");
    scanf("%d", &pick);
  }while ((pick != 1) && (pick !=2));
  }else{
    printf("1. start a new game\n");
    do{
    printf("give your choice\n");
    scanf("%d", &pick);
  }while (pick != 1);
  }
  return pick;
}
