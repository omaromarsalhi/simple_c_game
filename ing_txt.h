#ifndef UNTITLED_ING_TXT_H
#define UNTITLED_ING_TXT_H

#include "structurs.h"



typedef struct
{
    IMAGE bg[5],butt[3][3],time_txt[13],end[2];
    char Q[3][200],AN[9][200];
    int true_answer[3],W,H,i,choise,evaluation,which_gate,animationn,count;
    TEXT t_Q[3],t_AN[9];
}ing_txt;


void InitEnigme(ing_txt * e, char *nomfichier);
void afficherEnigme(ing_txt e, SDL_Surface * screen);
void animer (ing_txt * e);




int timepassed(int dt);
void blit_all_txt(SDL_Surface *wind,int n,...);
int collisionPP_ing_txt(Personne p, SDL_Surface *Masque);

#endif 