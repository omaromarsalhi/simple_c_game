#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "structurs.h"
#include "bk.h"
#include "perso.h"
#include "minmap.h"



void initminimap( minmap * m){
    SDL_Rect tab[4];
    tab[0].x=220;
    tab[0].y=0;
    tab[0].w=220;
    tab[0].h=160;


    m->shape.x=m->W-tab[0].x;
    m->shape.y=tab[0].y;
	m->shape.w=tab[0].w;
	m->shape.h=tab[0].h;
	m->redemtion[0]=14;
	m->redemtion[1]=0.15;
    m->redemtion[2]=10;
    m->redemtion[3]=7.14;
	m->map[0].img=IMG_Load("./omar_minmap/omar1.png");
    m->map[2].img=IMG_Load("./omar_minmap/home_town.png");
	m->map[2].pos1.x=m->shape.x+(m->shape.w-m->map[2].img->w)/2;
    m->map[2].pos1.y=(m->shape.h-m->map[2].img->h)/2;
    m->map[3].img=IMG_Load("./omar_minmap/1.png");
	m->map[3].pos1.x=m->shape.x+(m->shape.w-m->map[3].img->w)/2;
    m->map[3].pos1.y=(m->shape.h-m->map[3].img->h)/2;
}

void afficherminimap (minmap m, SDL_Surface * screen){
    SDL_FillRect(screen,&m.shape,m.col);
	SDL_BlitSurface(m.map[m.where].img,NULL,screen,&m.map[m.where].pos1);
}


SDL_Rect MAJMinimap(SDL_Rect posJoueur , minmap * m, SDL_Rect camera, int r1){
	camera.x=m->shape.x+ ((posJoueur.x+m->bk_pos2.x)*r1)/100+10;
	camera.y=m->shape.y+ ((posJoueur.y+m->bk_pos2.y)*r1)/100+4;
	camera.h=10;
	camera.w=10;
	return camera;
}









/*
void timer_jeu(SDL_Surface * screen, TTF_Font * police ){
SDL_Surface * texte;
char s[30];
SDL_Rect pos;
SDL_Color textColor={125,0,0};
pos.x=0;
pos.y=0;

int minutes;
int seconds=0;

  seconds=SDL_GetTicks() /1000 ;
    minutes=seconds/60;
    seconds=seconds-minutes*60; 
sprintf(s,"%02d:%02d",minutes,seconds);
texte=TTF_RenderText_Blended(police,s,textColor);
SDL_BlitSurface(texte,NULL,screen,&pos);

}*/







void sauvegarder( int score, char nomjoueur[], char nomfichier[]){
int a;
char b[30];
FILE * f=NULL;
f=fopen(nomfichier,"a+");
fscanf(f,"player: %s his score is:%d \n",b,&a);
if(f!=NULL && strcmp(nomjoueur,b)!=0){
fprintf(f,"player: %s his score is: %d \n",nomjoueur,score);
fclose(f);
}
};



void meilleur( char nomfichier[], int *score, char nomjoueur[]){
FILE * f=NULL;
int a;
char b[30];
f=fopen(nomfichier,"r+");
fscanf(f,"player: %s his score is:%d \n",nomjoueur,score);
if(f!=NULL){

            {  fscanf(f,"player: %s his score is:%d \n",b,&a);
                          
                if (*score<a){
                   *score=a;
                  strcpy(nomjoueur,b);
                  printf("%d \n",a);
                             };
            };
fclose(f);

}
}






void timer_enigme(SDL_Surface * screen,TTF_Font * police ){
SDL_Surface * texte;
char s[30];
SDL_Rect pos;
pos.x=20;
pos.y=20;
int seconds=0;
SDL_Color textColor={255,255,255};
seconds=SDL_GetTicks()/1000 ;  
sprintf(s,"%d",seconds);
texte=TTF_RenderText_Blended(police,s,textColor);
SDL_BlitSurface(texte,NULL,screen,&pos);
};





void timer_jeu(SDL_Surface * screen, TTF_Font * police ){
SDL_Surface * texte;
char s[30];
SDL_Rect pos;
SDL_Color textColor={125,0,0};
pos.x=0;
pos.y=0;

int minutes;
int seconds=0;

  seconds=SDL_GetTicks() /1000 ;
    minutes=seconds/60;
    seconds=seconds-minutes*60; 
sprintf(s,"%02d:%02d",minutes,seconds);
texte=TTF_RenderText_Blended(police,s,textColor);
SDL_BlitSurface(texte,NULL,screen,&pos);

}

void clavier(SDL_Event event,char nomjoueur[]){
char ch[30],ch1[3];
int yes;
if(event.type==SDL_KEYDOWN){
    if(event.key.keysym.sym==SDLK_SPACE)
      strcat(nomjoueur," ");
 else if(event.key.keysym.sym==SDLK_BACKSPACE){
 strcpy(&nomjoueur[strlen(nomjoueur)-1],"");

 }
    else if (event.key.keysym.sym==SDLK_RETURN)
 {
 
 }
 else{  
    sprintf(ch,"%s",SDL_GetKeyName(event.key.keysym.sym));  
    strncpy(ch1,ch,2);
   
    strcat(nomjoueur,ch1);
}
}

};









/*

void timer_enigme(SDL_Surface * screen,TTF_Font * police,int W,int H){
SDL_Surface * texte;
char s[30];
SDL_Rect pos;
pos.x=W/2;
pos.y=H-H/100;
int seconds=0;
SDL_Color textColor={255,255,255};
seconds=SDL_GetTicks()/1000 ;  
sprintf(s,"%d",seconds);
texte=TTF_RenderText_Blended(police,s,textColor);
SDL_BlitSurface(texte,NULL,screen,&pos);
};


*/



void initialiserTic (tic * t,int W,int H) {

 t->x=IMG_Load("./tic/x.png"); 
 t->o=IMG_Load("./tic/o.png"); 
  t->b=IMG_Load("./tic/b.png"); 
   t->l=IMG_Load("./tic/l.jpg"); 

for(int i=0;i<9;i++){
  
    t->tab[i]=0;
}

t->posx1.x=W/4;t->posx1.y=H/4;
t->postxt.x=W/2;t->postxt.y=H/2;
t->joueur=0 ;
t->nbtour=0;

t->T = TTF_OpenFont ("times.ttf", 105);
SDL_Color couleur;
};



void afficherTic(tic t,SDL_Surface* ecran,int w){
int i,j,ta[4][4];
float a,b;
SDL_Rect posB,pos,posB1;

posB.x=w;
posB.y=0;

ta[0][0]=t.tab[0];
ta[0][1]=t.tab[3];
ta[0][2]=t.tab[6];
ta[1][0]=t.tab[1];
ta[1][1]=t.tab[4];
ta[1][2]=t.tab[7];
ta[2][0]=t.tab[2];
ta[2][1]=t.tab[5];
ta[2][2]=t.tab[8];


SDL_BlitSurface(t.b,NULL,ecran,&posB);


for( i=0;i<3;i++){
  for( j=0;j<3;j++){
if(ta[i][j]==1){

a=i;
b=j;
pos.x=(t.b->w*(a/3))+(1/4)*t.o->w+w;
pos.y=(t.b->w*(b/3))+(1/4)*t.o->w;
SDL_BlitSurface(t.x,NULL,ecran,&pos);
}
else if(ta[i][j]==-1){

a=i;
b=j;
pos.x=(t.b->w*(a/3))+(1/4)*t.o->w+w;
pos.y=(t.b->w*(b/3))+(1/4)*t.o->w;
SDL_BlitSurface(t.o,NULL,ecran,&pos);

}}};


};



int atilgagne(int tabsuivi[]){
int lignes_gagnantes[8][3] = {{0,1,2},{0,4,8},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{2,4,6}},i=0,q=0;

for(i=0;i<8;i++){
int a,b,c;
a=lignes_gagnantes[i][0];
b=lignes_gagnantes[i][1];
c=lignes_gagnantes[i][2];

 if (tabsuivi[a]==tabsuivi[b]&&tabsuivi[a]==tabsuivi[c]&&tabsuivi[a]!=0){
   if(tabsuivi[a]==-1)
    q=-1;
   else if (tabsuivi[a]==1)
    q=1;
   }
}
  return q;
};


void Resultat (SDL_Surface* ecran,tic t,int w,int h){

SDL_Surface * texte;
char s[30];
SDL_Rect pos;
pos.x=w/2;
pos.y=h/2;
SDL_Color textColor={255,0,127};

if(atilgagne(t.tab)==-1){
texte=TTF_RenderText_Blended(t.T,"WON",textColor);
SDL_BlitSurface(texte,NULL,ecran,&pos);
}
else if (atilgagne(t.tab)==1) {
texte=TTF_RenderText_Blended(t.T,"DEFEAT",textColor);
SDL_BlitSurface(texte,NULL,ecran,&pos);
};
};




 void liberer( tic t){
 
 SDL_FreeSurface(t.o);
 SDL_FreeSurface(t.b);
 SDL_FreeSurface(t.x);
 TTF_CloseFont (t.T); 
 
 };
 
 
 int minmax(int tabsuivi[], int joueur){
 int gagnant=atilgagne(tabsuivi);
 if(gagnant!=0)
   return gagnant*joueur;
 int coup=-1;
 int score =-2;
 int i;
 for(i=0;i<9;i++){
  
  
    if(tabsuivi[i]==0){
          {
             tabsuivi[i]=joueur;
             int mmscore=-minmax(tabsuivi,joueur*-1);
             if(mmscore>score)
             {
             score==mmscore;
             coup=i;
             }
             tabsuivi[i]=0;
             }
             }
             }
             if(coup==-1)
             return 0;
             return score;
             
             
 
 };
void calcul_coup(int tabsuivi[]){
int coup=-1;
int score=-2;
int i;
for(i=0;i<9;i++){
       if(tabsuivi[i]==0){
       tabsuivi[i]=1;
       int mmscore=-minmax(tabsuivi,-1);
       tabsuivi[i]=0;
       if(mmscore>score)
       {
       
       score=mmscore;
       coup=i;
       }}}
       tabsuivi[coup]=1;
};
 
 
 
 void chargeranim(SDL_Surface*  T[]){
         
         
                T[1] = IMG_Load("./tic/animation/01.jpg");
		T[2] = IMG_Load("./tic/animation/02.jpg");
		T[3] = IMG_Load("./tic/animation/03.jpg");
		T[4] = IMG_Load("./tic/animation/04.jpg");
		T[5] = IMG_Load("./tic/animation/05.jpg");
		T[6] = IMG_Load("./tic/animation/06.jpg");
		T[7] = IMG_Load("./tic/animation/07.jpg");
		T[8] = IMG_Load("./tic/animation/08.jpg");
		T[9] = IMG_Load("./tic/animation/09.jpg");
		T[10]= IMG_Load("./tic/animation/10.jpg");
		T[11]= IMG_Load("./tic/animation/11.jpg");
		T[12]= IMG_Load("./tic/animation/12.jpg");
		T[13]= IMG_Load("./tic/animation/13.jpg");
		T[14]= IMG_Load("./tic/animation/14.jpg");
		T[15]= IMG_Load("./tic/animation/15.jpg");
		T[16]= IMG_Load("./tic/animation/16.jpg");
		T[17]= IMG_Load("./tic/animation/17.jpg");
		T[18]= IMG_Load("./tic/animation/18.jpg");
		T[19]= IMG_Load("./tic/animation/19.jpg");
		T[20]= IMG_Load("./tic/animation/20.jpg");
		T[21]= IMG_Load("./tic/animation/21.jpg");
		T[22]= IMG_Load("./tic/animation/22.jpg");
		T[23]= IMG_Load("./tic/animation/23.jpg");
		T[24]= IMG_Load("./tic/animation/24.jpg");
		T[25]= IMG_Load("./tic/animation/25.jpg");
		T[26]= IMG_Load("./tic/animation/26.jpg");
		T[27]= IMG_Load("./tic/animation/27.jpg");
		T[28]= IMG_Load("./tic/animation/28.jpg");
		T[29]= IMG_Load("./tic/animation/29.jpg");
		T[30]= IMG_Load("./tic/animation/30.jpg");
		T[31]= IMG_Load("./tic/animation/31.jpg");
		T[32]= IMG_Load("./tic/animation/32.jpg");
	        T[33]= IMG_Load("./tic/animation/33.jpg");
		T[34]= IMG_Load("./tic/animation/34.jpg");
		T[35] =IMG_Load("./tic/animation/35.jpg");
		T[36] =IMG_Load("./tic/animation/36.jpg");
		T[37] =IMG_Load("./tic/animation/37.jpg");
		T[38] =IMG_Load("./tic/animation/38.jpg");
		T[39] =IMG_Load("./tic/animation/39.jpg");
		T[40] =IMG_Load("./tic/animation/40.jpg");
		T[41] =IMG_Load("./tic/animation/41.jpg");
		T[42] =IMG_Load("./tic/animation/42.jpg");
		T[43] =IMG_Load("./tic/animation/43.jpg");
		T[44] =IMG_Load("./tic/animation/44.jpg");
		T[45] =IMG_Load("./tic/animation/45.jpg");
		T[46] =IMG_Load("./tic/animation/46.jpg");
		T[47] =IMG_Load("./tic/animation/47.jpg");
		T[48] =IMG_Load("./tic/animation/48.jpg");
		T[49] =IMG_Load("./tic/animation/49.jpg");
		T[50] =IMG_Load("./tic/animation/50.jpg");
 }
 
 void annimertic(SDL_Surface* ecran,int ani,SDL_Surface*  T[]){
 
 int i=0;
 SDL_Rect pos;
pos.x=0;
pos.y=0;
 SDL_BlitSurface(T[ani],NULL,ecran,&pos);
  //printf("%d \n",ani);
 
 };
 