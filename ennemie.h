#ifndef UNTITLED_ENNEMIE_H
#define UNTITLED_ENNEMIE_H

#include "structurs.h"



typedef struct{
	IMAGE cafe_img;
	SDL_Rect pos1[20],pos2[20];
	SDL_Surface *img[20];
	int nbr_spsh;
	int nbr_frames[20];
	int ing,evaluation;
	int W,H;
	int spsh;
	int the_chosen;
	int func_num,der_num;
	int coll_BB;
	int coll_PP_ENNEMI;
	int coll;
	int MV_destance[2];
	int coll_derection;
	int stay;
	SDL_Rect real_pos;
	SDL_Rect P_pos1;
	int P_w,P_h,P_img_w;
	int last[8];
	SDL_Rect bk_pos2;
	// deplacement Ai:
	char satete[20];
	int derection;
}Ennemi;




void intitEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e,SDL_Surface *window);
void animerEnnemi(Ennemi *e);

void deplacer(Ennemi *e);
int collisionBB(Ennemi e,Personne p);









void animerEnnemie_pro (Ennemi *e);
void deplacer_pro(Ennemi *e);
void deplacer_pro_1(Ennemi *e);
void afficherEnnemi_pro(Ennemi e, SDL_Surface *window);
int collisionPP_char(Ennemi e, SDL_Surface *Masque,int r,int g,int b);
int collisionBB_pro(Ennemi e, Personne p);
int update_police_attack(Ennemi e,Personne p,SDL_Surface *window);



int render(int state,int i);
int timepassed_pro(int dt);
int collisionPP_Ennemi(Ennemi e, SDL_Surface *Masque);
int collisionPP_ennemy_race(Personne p, SDL_Surface *Masque);




void updateEnnemi (Ennemi* e, SDL_Rect posHero, SDL_Surface *window);
void animateEnnemi(Ennemi *e);


#endif 