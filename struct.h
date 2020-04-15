#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct
{
    int vitesse;
    int score ;
    int vie ;
    SDL_Surface *image ;
    SDL_Rect position;
    SDL_Rect position_absolue;
    SDL_Rect position_relatif;
    int direction ;
    SDL_Mixchunk son;
} personnage ;


typedef struct enemy
{
  SDL_Surface *imaged[5];
  SDL_Surface *imageg[5];
  SDL_Surface *dhrab;
  SDL_Surface *imageactuellle;
  SDL_Rect position ;
  SDL_Rect positionn ;
  int frame;
  int direction;
  int met;

}enemy;




typedef struct
{
    SDL_Surface *image;
    SDL_Rect position;
    SDL_Rect position_absolue;
    SDL_Rect position_relatif;
    int direction ;
    SDL_Mixchunk son;
}entite_secondaire ;

typedef struct
{
    SDL_Surface *image;
    SDL_Rect position;
    SDL_Rect position_absolue;
    SDL_Rect position_relatif;
    int direction ;
    int vie ;
    SDL_Surface *died ;
}vie;

typedef struct
{
    SDL_Surface *image;
    SDL_Rect position;
    SDL_Mixchunk son;
    File * fichier ;
    int type ;
}enigme ;
//personnage.h
void Init_perdo (personnage *p);
void show_perso (personnage *p ; SDL_Surface Screen);
void move_perso (personnage p; int direction );
void move_persomouse (personnage p;SDL_Surface Screen);
void update_scorevie (personnage *p; int x);

//entité_secondaire.h
void Init_entite (entite_secondaire *e);
void Show_entite (entite_secondaire e, SDL_Screen);
void Move_entite (entite_secondaire *e);




#endif // STRUCT_H_INCLUDED

