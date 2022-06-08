#ifndef UNTITLED_PERSO_H
#define UNTITLED_PERSO_H



#include "structurs.h"

typedef struct{
SDL_Rect pos1,pos2;
SDL_Surface *img;
}IMAGE;

typedef struct{
SDL_Rect postxt;
TTF_Font *font;
SDL_Surface *windtxt;
SDL_Color col;
}TEXT;

typedef struct{
    IMAGE image[2];
    int derec,where,nbr_frames[2],still_in,still_in2,i,y,scrolling_on,coll_derection,distance;
    float acc,speed;
    SDL_Rect bk_pos2;
    int initlevel;
    int vj;
    int caught;
    int panana;
    float score;
    int invinWindow;
    int hitTime;
    int invin;
    int stamina;
    SDL_Surface *staminaBar,*staminaImg,*dangerLevelStaBar,*dangerLevelStaImg;
    SDL_Rect staminapos2,dangerLevelStapos2,staminapos1;
    int hit;
    int coke,tea;
    int recovery;
    int consumeTime;
    int consuming;
    Mix_Chunk *drinkingTea,*drinkingCoke,*openTuna;
    int caughtTime;
    int fish;
}Personne;


void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void deplacerPerso (Personne *p,int dt);
void animerPerso (Personne* p);
void saut (Personne* p);



int collisionPP_persone(Personne p, SDL_Surface *Masque,int r,int g,int b);

void initPerso_2(Personne *p);

void verticalJump2(Personne *p);
void verticalJump(Personne *p);
#endif