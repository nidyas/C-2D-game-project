#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "background.h"
#include <stdio.h>
#include <stdlib.h>

int main (void){ 

 	// screen initialization
	SDL_Surface * screen = NULL;
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		printf( "ERROR: Unable to initialize SDL");
		return 1;
	}
	//Initialize SDL SOUND
	if( Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
		printf("ERROR: Unable to initialize SDL SOUNDS" );
	}
	screen = SDL_SetVideoMode(996,701,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Lost Atlantis", NULL);
	//SDL_Surface *curs =IMG_Load("cursor.png");
	//SDL_ShowCursor(0);
	//SDL_Rect ms;
	//ms.w=curs->w;
	//ms.h=curs->h;
    Mix_Music *music;
	music=Mix_LoadMUS("res/music.mp3");
	Mix_PlayMusic(music,-1);
	int img_cour=-1;
	int k;
	//credits init
	stage sta;
	credits c;
	//==============
	//settings init 
	settings set;
	//==============
	SDL_Event event;
    menu m;
	int game_done = 0;
	int settingsSignal = 0;
	initMenu(&m);
	initSett(&set);
	initCredits(&c);
	initStage(&sta);
	int signal=0;
	while(game_done == 0){ //game loop
		while(SDL_PollEvent(&event) == 1){// o
			switch(signal){
				case 0: // official menu
					showMenu(m, screen);
					SDL_Flip(screen);
					switch(event.type){
						case SDL_MOUSEMOTION: //  mouse 
						//ms.x = event.motion.x;
						//ms.y = event.motion.y;
						//SDL_BlitSurface(curs,NULL,screen,&ms);
						//SDL_Flip(screen);
							menuMotion(&m,event);
						break;
						case SDL_QUIT: 
						game_done=1; 
						break;

						case SDL_KEYDOWN:
							signal = mouseKeyboard(screen, &img_cour, &m, event);
							printf("pass to %d\n", signal);
						break;			
						case SDL_MOUSEBUTTONDOWN:
							signal = menuClicks(m,event);
							printf("pass to %d\n", signal);
						break;
					
					}
				break;
				case 1: // play button 
				switch(event.type){
					case SDL_KEYDOWN:
						signal = 0;
					break;
					case SDL_QUIT:
						game_done = 1;
					break;
					}
					showStage(sta,screen);
					SDL_Flip(screen);

				break;
				case 2: // settings button
					switch(event.type){
					case SDL_MOUSEBUTTONDOWN:
						settingsSignal = settingsClicks(event, &set);
						if(settingsSignal == 0){
							signal = 0; //go back to menu 
						}
					break;
					case SDL_KEYDOWN:
						signal = 0;
					break;
					case SDL_QUIT:
						game_done = 1;
					break;
					//case SDL_MOUSEMOTION:
						//ms.x = event.motion.x;
						//ms.y = event.motion.y;
						//SDL_BlitSurface(curs,NULL,screen,&ms);
						//SDL_Flip(screen);
					//break;
					}
					showSett(set, screen);
					SDL_Flip(screen);
				break;
				case 3: //credits button
					switch(event.type){
					case SDL_KEYDOWN:
						signal = 0;
					break;
					case SDL_QUIT:
						game_done = 1;
					break;
					}
					showCredits(c, screen);
					SDL_Flip(screen);
				break;
				case 4: //quit button
				game_done=1;
				break;
			}
		while(SDL_PollEvent(&event) == 1); //for lag
		}
	}
	//SDL_FreeSurface(curs);
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	SDL_FreeSurface(screen);

	return 0 ;
}

