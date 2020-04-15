#ifndef SCOREVIE_H_INCLUDED
#define SCOREVIE_H_INCLUDED

typedef struct vie
{
	SDL_Rect position ;
	int val ;
	SDL_Surface *image[4];
} vie ;

typedef struct score
{
	int nb;
	SDL_Surface *textScore;
	SDL_Rect posScore;

}score;

void initialiserscore(score *score);
void afficherscore(score *score , SDL_Surface *ecran,TTF_Font *police);
void calculerScore(score *score,int d);
vie init_vie(vie v);
void affichiervie(personnage p, SDL_Surface *Screen);
int gestionvie(personnage *p, SDL_Surface *Screen);


#endif // SCOREVIE_H_INCLUDED

