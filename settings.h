#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "background.h"

void manageVolume(settings * s,int x);
void manageMode(int x);
#endif