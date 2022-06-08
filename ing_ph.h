#ifndef UNTITLED_ING_PH_H
#define UNTITLED_ING_PH_H

#include "structurs.h"

typedef struct
{
    IMAGE hang_man[7],ing[2][5],end[2];
    char path_hang_man[7][30],path_ing[2][5][30],path_end[2][30];
    int W,H,where,choise,evaluation,x,true_answer[2],i;
    SDL_Rect pos_butt[3];
}ing_ph;

void InitEnigme_ph(ing_ph * e, char *nomfichier);
void afficherEnigme_ph(ing_ph e,SDL_Surface * screen);
void animer_ph (ing_ph * e);

int collisionPP_ing_ph(Personne p, SDL_Surface *Masque);

#endif 