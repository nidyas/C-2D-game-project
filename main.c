
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "collision.h"
#include <stdio.h>
#include <stdlib.h>
#include"enigme.h"
#include"enemy.h"
#include"background.h"
#include"character.h"
#include "uti.h"





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

	screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Lost Atlantis", NULL);
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
	int settingsSignal = 0;
	initMenu(&m);
	initSett(&set);
	initCredits(&c);
	initStage(&sta);
	charac hero;
	int signal=0;
	int z=0;
    int game_done = 0;
	char r,l;
    // declration du background
    enigme e;
    enigmeData edd;
	int tc;
	timer t;
	SDL_Rect camera;
	camera.x = 0;
    camera.y = 0;
    camera.h = 600;
    camera.w = 960;
    int x=0; //0 -> menu \1 -> jeu 2 \-> enigme
    int R=-1;
    int continuer =1;
	enemy en  = initEnm(); 
	hero =initChar();
	SDL_Surface * tempsdujeu ;
	entities ET ;
	int score=0,lives=0;
	SDL_Surface * scoretext;
	SDL_Surface * livestext;
	FILE *f=NULL;
	unsigned int time = SDL_GetTicks();
	SDL_Rect TimePos;
	TimePos.x = 20; TimePos.y =20;
	SDL_Surface * s ;
	//charscore CH;

		while (game_done==0)
		{
        	if (x==0){
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
					x=1;
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
		 	
		



         else if(x==1)
		 							{  
														
							
							
													SDL_Event e ;
													//tempsdujeu= gameTime(&t);
													SDL_Rect gamtimepos;
													gamtimepos.x=0;
													gamtimepos.y=0;
													showChar(hero, screen, 'r');
													showEnm(en,screen);
													s = refreshGameTime(&time);
													printf("time: %d\n", time);
													scoretext = updateScore(&score);
													//livestext= updateLives(&lives);
													ET=gameEntities();


													while(SDL_PollEvent(&e) ){
														if(camera.x < 0){
															moveChar (e, &hero.positionChar,r);
														}else{
														if((hero.positionChar.x >= 480) && (camera.x < 15984-960)){
															scrolling(&camera, e);
														}else{
															moveChar (e, &hero.positionChar,r);
														}
														}
													

													SDL_BlitSurface(sta.img, &camera, screen, &sta.pos3);
													SDL_BlitSurface(s, NULL, screen, &TimePos);
													/*SDL_BlitSurface(tempsdujeu,NULL,screen,&gamtimepos);  
													SDL_BlitSurface(livestext,NULL, screen, &ET.posLives);
													SDL_BlitSurface(scoretext,NULL, screen, &ET.posheart);*/
													int s;
														s=rand_pos(120,50);
														s=moveEnemy(&en,screen,hero.positionChar);
														animEnm(en,screen,1);
														r= animChar (hero, screen,  e, r);
														
														SDL_Flip(screen); 
													}


                          



									
								

                		
        
                      
					 }
        
        
        
        
        /*else if (x==2)
                    {   
                int R=-1;
                int count = 0;
                int continuer =1;
                        do{
                        e=initEnigme();
                        edd=generateEnigme(e);
                        showEnigme(edd,screen,e);
                        SDL_Flip(screen);
                        R=resolutionEnigme(e,edd,event,screen);
                            if (R==1){
                            printf("correct answer\n");

                        continuer = 0;

                        count++;
                        }else{
                        if(R==0){
                            printf("wrong answer\n");
                            continuer = 1;
                        }else{
                            printf("timer elapsed\n");
                            return 0;
                            continuer = 0;
                        }
                        }

                    if(event.type ==SDL_QUIT){

                                     continuer=0;
                                        }
                             } while((continuer==0 )&&(count<=2));
                    }*/


	             
        
                            
                    

     

      }
		
    
	SDL_FreeSurface(screen);
	Mix_FreeMusic(music);
	Mix_CloseAudio();

	return 0 ;

 }
