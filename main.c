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

	screen = SDL_SetVideoMode(996,701,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Lost Atlantis", NULL);
    int game_done = 0;
    SDL_Event event;
    while(game_done == 0){ //game loop
		while(SDL_PollEvent(&event) == 1){// o

















        
             }  
      }

    
	SDL_FreeSurface(screen);

	return 0 ;

 }
