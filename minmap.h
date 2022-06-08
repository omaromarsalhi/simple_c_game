#ifndef UNTITLED_MINMAP_H
#define UNTITLED_MINMAP_H
#include "structurs.h"
#include "perso.h"

typedef struct
{
    IMAGE map[8];
    SDL_Rect shape,bk_pos2;
    int W,H,where,redemtion[8];
    Uint32 col;
    int score,time;
    char nomjoueur[30];
    char nomfichier[30] ;
    char c[300];
}minmap;



typedef struct{
SDL_Surface     *x,*o,*b,*l;
int tab[100];
SDL_Rect posx1,postxt;
int joueur ;
int nbtour;
TTF_Font *T;
SDL_Color couleur;
} tic;



void initminimap( minmap * m);
SDL_Rect MAJMinimap(SDL_Rect posJoueur , minmap * m, SDL_Rect camera, int r1);
void afficherminimap (minmap m, SDL_Surface * screen);
void timer_enigme(SDL_Surface * screen,TTF_Font * police );
void timer_jeu(SDL_Surface * screen, TTF_Font * police );
void clavier(SDL_Event event,char ch[]);
void sauvegarder( int score, char nomjoueur[], char nomfichier[]);
void meilleur( char nomfichier[], int *score, char nomjoueur[]);





void initialiserTic (tic * t,int W,int H) ;
void afficherTic(tic t,SDL_Surface* ecran,int w);
int atilgagne(int tabsuivi[]);
void Resultat (SDL_Surface* ecran,tic t,int w,int h);
void liberer( tic t);
int minmax(int tabsuivi[], int joueur);
void calcul_coup(int tabsuivi[]);
void chargeranim(SDL_Surface*  T[]);
void annimertic(SDL_Surface* ecran,int ani,SDL_Surface*  T[]);
#endif 