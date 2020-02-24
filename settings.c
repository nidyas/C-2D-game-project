#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "settings.h"
#include "SDL/SDL_ttf.h"
#include "background.h"


void manageVolume(settings * s,int x){
    int per = 64;
    FILE * f = fopen("settings.txt","r");
    if(f == NULL){
        f = fopen("settings.txt", "w");
        fprintf(f, "%d\n", per);
    }else{
        fscanf(f, "%d\n", &per);
    }
     fclose(f);
    f = fopen("settings.txt","r");
    if(x == 1){
        per = per + 16;
        if(per > 128){
            per -= 16;
        }
        Mix_VolumeMusic(per);
    }else{
        per = per -16 ;
        if(per < 0){
            per += 16;
        }
        Mix_VolumeMusic(per);
    }
    fclose(f);
    f = fopen("settings.txt","w");
    fprintf(f, "%d\n", per);
        printf("Volume percentage: %d\n", per);
         //this is for text showing and font stuff
	char ch[128];
    SDL_Surface *value = NULL;
    SDL_Rect valuePos;
    TTF_Font *police = NULL;
    SDL_Color color = {220, 20, 60};

    if (TTF_Init() < 0) {
      printf("Error openning ttf\n");
    }else{
      police = TTF_OpenFont("res/font.ttf", 30);
      if (police == NULL) {
        printf("Error in opening font file\n");
      }else{
        sprintf(ch, "%d", per);
        s->volumePer=TTF_RenderText_Solid(police, ch, color);
        TTF_CloseFont(police);
        TTF_Quit();
      }
      valuePos.x = 96;
      valuePos.y = 20;
    }
    fclose(f);
}
void manageMode(int x){
    
}
