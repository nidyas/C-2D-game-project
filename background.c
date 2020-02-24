#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "background.h"
#include "settings.h"

void initSett(settings * set){
    int per;
    FILE * f = fopen("settings.txt","r");
    if(f == NULL){
        f = fopen("settings.txt", "w");
        fprintf(f, "%d\n", 64);
    }else{
        fscanf(f, "%d\n", &per);
    }
     fclose(f);

    f = fopen("settings.txt","r");
    fscanf(f, "%d\n", &per);
    fclose(f);
    printf("Volume percentage: %d\n", per);
	set->settbackground = IMG_Load("res/backsettings.png");
    set->b[0].img = IMG_Load("res/back.png");
	set->b[1].img  = IMG_Load("res/switchup.png");
	set->b[2].img  = IMG_Load("res/switchdown.png");
	set->b[3].img  = IMG_Load("res/key.png");
	set->b[4].img  = IMG_Load("res/mou.png");

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
        value=TTF_RenderText_Solid(police, ch, color);
        TTF_CloseFont(police);
        TTF_Quit();
      }
      valuePos.x = 96;
      valuePos.y = 20;
    }
    
    set->volumePer = value; // this is volume percent img
    //this is for back button
    set->b[0].pos.x =600; set->b[0].pos.y=60;
	set->b[0].pos.h = set->b[0].img->h;  set->b[0].pos.w = set->b[0].img->w;
	//this is for background paper
	set->setbpos.x = 0; set->setbpos.y=0;
	set->setbpos.h = set->settbackground->h; set->setbpos.w = set->settbackground->w;
    //this is for volume up button
	set->b[1].pos.x = 300; set->b[1].pos.y= 250;
    set->b[1].pos.h = set->b[1].img->h; set->b[1].pos.w = set->b[1].img->w;
    //this is for volume down button
    set->b[2].pos.x = 200; set->b[2].pos.y= 250;
    set->b[2].pos.h = set->b[2].img->h; set->b[2].pos.w = set->b[2].img->w;
    //this for mode button
    set->b[3].pos.x = 200; set->b[3].pos.y=600;
    set->b[4].pos.x = 200; set->b[4].pos.y=600;
    set->b[3].pos.h = set->b[3].img->h; set->b[3].pos.w = set->b[3].img->w;
	set->b[4].pos.h = set->b[4].img->h; set->b[4].pos.w = set->b[4].img->w;

    //init pos of volume percentage
    set->volPos.x = 300; set->volPos.y = 310;
}
int settingsClicks(SDL_Event event, settings *s){
    int ff = 0;
    int x = -1;
    for(ff = 0; ff <= 4; ff++){
        if(((event.motion.x <= s->b[ff].pos.x + s->b[ff].img->w) && 
        (event.motion.x >= s->b[ff].pos.x)) && 
        ((event.motion.y >= s->b[ff].pos.y) && 
        (event.motion.y <= s->b[ff].pos.y + s->b[ff].img->h))) {
            //Mix_PlayChannel(-1, s.b[ff].sClick, 0);
            x = ff;
            printf("%d" ,x);
        }
    }
    switch(x){
        case 0: //go back butt was pressed
            return 0;
        break;
        case 1: // if vol up was pressed
            manageVolume(s,1);
        break;
        case 2: // if vol down was pressed
        printf("rrr");
            manageVolume(s,0);
        break;
        case 3: // if keyboard mode was pressed
            manageMode(0);
        break;
        case 4: // if mouse mode was pressed
            manageMode(1);
        break;
    }
    return -1;
}
void showSett(settings set, SDL_Surface * screen){

    SDL_BlitSurface(set.settbackground,NULL,screen,&(set.setbpos));
    SDL_BlitSurface(set.b[0].img,NULL,screen,&(set.b[0].pos));
    SDL_BlitSurface(set.volumePer,NULL,screen,&(set.volPos));
    SDL_BlitSurface(set.b[1].img,NULL,screen,&(set.b[1].pos));
    SDL_BlitSurface(set.b[2].img,NULL,screen,&(set.b[2].pos));
    SDL_BlitSurface(set.b[3].img,NULL,screen,&(set.b[3].pos));
    SDL_BlitSurface(set.b[4].img,NULL,screen,&(set.b[4].pos));

}
void initMenu(menu * m){
    m->background=IMG_Load("res/background.png");
    m->pos.x = 0; m->pos.y=0;
    m->pos.h = m->background->h;
    m->pos.w = m->background->w;
    if(m->background == NULL){
        printf("unable to load button :%s\n",SDL_GetError());
        return;
    }
    int i ;
    for(i = 0; i<=3; i++){
        m->b[i].sClick = Mix_LoadWAV("res/mousec.wav");
        m->b[i].sHover = Mix_LoadWAV("res/mouseh.wav");
        switch(i){
            case 0: //this is play butt
                m->b[0].img=IMG_Load("res/playbutton.png");
                 m->b[0].hover=IMG_Load("res/playbuttonH.png");
                m->b[0].pos.x=80;
                m->b[0].pos.y=350;
                m->b[0].pos.h=m->b[0].img->h;
                m->b[0].pos.w=m->b[0].img->w;
                 m->b[0].itIsHovered = 0;
            break;
            case 1 : // this is setting butt
            m->b[1].img=IMG_Load("res/settings.png");
            m->b[1].hover=IMG_Load("res/settingsH.png");
                m->b[1].pos.x=80;
                m->b[1].pos.y=400;
                m->b[1].pos.h=m->b[1].img->h;								
                m->b[1].pos.w=m->b[1].img->w;
                 m->b[1].itIsHovered = 0;
            break;
            case 2 ://this is credits
                m->b[2].img=IMG_Load("res/credits.png");
                m->b[2].hover=IMG_Load("res/creditsH.png");
                m->b[2].pos.x=80;
                m->b[2].pos.y=450;
                m->b[2].pos.h=m->b[2].img->h;
                m->b[2].pos.w=m->b[2].img->w;
                 m->b[2].itIsHovered = 0;
            break;
            case 3 : // out
            m->b[3].img=IMG_Load("res/quit.png");
            m->b[3].hover=IMG_Load("res/quitH.png");
                m->b[3].pos.x=80;
                m->b[3].pos.y=500;
                m->b[3].pos.h=m->b[3].img->h;
                m->b[3].pos.w=m->b[3].img->w;
                 m->b[3].itIsHovered = 0;
            break;
        }
    }

}
void showMenu(menu m, SDL_Surface * screen){

     SDL_BlitSurface(m.background,NULL,screen,&(m.pos));
    int i=0;
    for(i = 0; i<=3; i++){
        if(m.b[i].itIsHovered == 0){
            SDL_BlitSurface(m.b[i].img, NULL, screen, &(m.b[i].pos));
        }else{
            SDL_BlitSurface(m.b[i].hover, NULL, screen, &(m.b[i].pos));
        }
    }
}

int mouseKeyboard(SDL_Surface * screen, int *image_courante, menu * m, SDL_Event event){
    if(event.key.keysym.sym==SDLK_DOWN){
        (*image_courante)++;
        if(*(image_courante)>3){ // if the counter by passes the  4 buttons then we should re init it to 0 for the next time u press up/down doesnt bug
            *(image_courante)=0;
        }
    }else{
        if(event.key.keysym.sym==SDLK_UP){
            (*image_courante)--;
            if (*(image_courante)<0){
                *(image_courante)=3;
            }
        }else {
            if(event.key.keysym.sym==SDLK_RETURN){
                Mix_PlayChannel(-1, m->b[*image_courante].sClick, 0);
                return (*image_courante)+1;
            }
        }
    }
    int i;
    for(i=0; i<=3; i++){
        if(i == (*image_courante)){
            m->b[i].itIsHovered = 1;
             Mix_PlayChannel(-1, m->b[*image_courante].sHover, 0);
        }else{
            m->b[i].itIsHovered = 0;
        }
    }
    return 0;
}

void menuMotion(menu * m,SDL_Event event){
    static int alreadyPLayed = 0;
    int ff = 0;
    int test = 0;
    for(ff = 0; ff <= 3; ff++){
        if(((event.motion.x <= m->b[ff].pos.x + m->b[ff].img->w) && 
        (event.motion.x >= m->b[ff].pos.x)) && 
        ((event.motion.y >= m->b[ff].pos.y) && 
        (event.motion.y <= m->b[ff].pos.y + m->b[ff].img->h))) {
            m->b[ff].itIsHovered = 1;
            int j;
            test = 1;
            for(j=0; j<=3; j++){
                if(j != ff ){
                    m->b[j].itIsHovered = 0;
                    if(alreadyPLayed == 0){
                    Mix_PlayChannel(-1, m->b[ff].sHover, 0);
                    alreadyPLayed = 1;
                    }
                }
                alreadyPLayed = 0;
            }
        }

    }
    if(test == 0){
        int j=0;
            for(j=0; j<=3; j++){
                    m->b[j].itIsHovered = 0;
            }
    }
}
int menuClicks(menu m, SDL_Event event){
    int ff = 0;
    for(ff = 0; ff <= 3; ff++){
        if(((event.motion.x <= m.b[ff].pos.x + m.b[ff].img->w) && 
        (event.motion.x >= m.b[ff].pos.x)) && 
        ((event.motion.y >= m.b[ff].pos.y) && 
        (event.motion.y <= m.b[ff].pos.y + m.b[ff].img->h))) {
            Mix_PlayChannel(-1, m.b[ff].sClick, 0);
            return ff+1;
        }
    }
    return 0;
}
void initCredits(credits * c){
 c->img=IMG_Load("res/cred.PNG");
 c->pos.x=0;c->pos.y=0;
 c->pos.h=c->img->h;
 c->pos.w=c->img->w;

}
void showCredits(credits c, SDL_Surface * screen){
    SDL_BlitSurface(c.img, NULL, screen, &c.pos);
}
void initStage(stage *sta)
{
 sta->img=IMG_Load("res/stage.png");
 sta->pos3.x=0;sta->pos3.y=0;
 sta->pos3.h=sta->img->h;
 sta->pos3.w=sta->img->w;
}
void showStage(stage sta,SDL_Surface *screen)
{

    SDL_BlitSurface(sta.img,NULL,screen,&sta.pos3);
}