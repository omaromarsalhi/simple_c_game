#ifndef UNTITLED_BK_H
#define UNTITLED_BK_H
#include "structurs.h"
#include "perso.h"

typedef struct 
{
    IMAGE b_k[10];
    int i,count,W,H,coll_i,do_anim,the_chosen,scrolling_speed;
}Background;

void initBack(Background * b);
void aficherBack(Background b, SDL_Surface * screen);
void animerBackground( Background * e);
int collisionPP(Personne p, SDL_Surface * Masque);
void scrolling (Background * b, int direction, int pasAvancement); 
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);

#endif 