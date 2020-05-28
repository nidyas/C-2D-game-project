#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "savegame.h"


void savegame( ){
 
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


}
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
