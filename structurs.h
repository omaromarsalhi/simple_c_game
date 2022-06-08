#ifndef UNTITLED_STRUCTURS_H
#define UNTITLED_STRUCTURS_H
#include "bk.h"
#include "perso.h"
#include "minmap.h"
#include "ing_txt.h"
#include "ing_ph.h"
#include "ennemie.h"


typedef struct{
	int vol,screenmode,wich_character;
    SDLKey tab_settings[4];
}INFO;

typedef struct{
    int casee;
}INFO_2;

typedef struct 
{
    //SDL_Surface *Trailer[2000];
    IMAGE butt[8],img_BK[35],start[900];
    TEXT txt;
    INFO if1;
    INFO_2 if2;
    int back_up;
    SDL_Rect R_Pos[3], R_Pos1[3],R_Pos2[2]; 
}MENUE;
typedef struct
{
    int opstate;
    IMAGE op[40],op1[4],op_kl[10],opp[5];
}OPTION;

typedef struct{ 
    IMAGE  new_g;
    Background b,b_cafe,b_market,b_home;
    Personne p;
    minmap m;
    ing_txt e_txt;
    ing_ph e_ph;
    Ennemi e1,e2,e3,e1_6[12],e_AI,e_cafe[6];
    int plystate,race;
    
}NEW_GAME;

typedef struct 
{
    SDLKey tab_settings[5],tab_settings_2[5];
    IMAGE bubbles[30],cematiques[177],out_presion[2],presion_hart[4];
    MENUE M;
    OPTION O;
    NEW_GAME NG;
    SDL_Surface *window;
    SDL_Event event;
    int W,H,state,x1,y1,i,out,dt, start,end, downup, Is_butt_on[11], fill[10],count,perso_in,test_ing;
    int coll_BB,coll_PP_ennemy_race,coll_PP_ing_ph,in_e_ai;
    Uint32 col1,col2;
    SDL_Rect camera_pos;//,save_pos,resume_pos;
    IMAGE win,sa_or_res[7];
    TEXT txt1;
    int reception[5],j;
    int dt2,start2,end2,presion_count,exit_if[6][3];
}GLOBAL_VARS;

typedef struct 
{
    IMAGE img;
    int realx,realy;
    int animated;

}obstacle;

typedef struct 
{
    IMAGE img;
    int realx,realy;
    int damage;
    int type; // 1 banana
    int thrown;
    int animated;
    Mix_Chunk * bananaSound;
}projectile;

typedef struct
{
    SDL_Surface *img[9];
    SDL_Surface *invinImg[9];
    SDL_Surface *hitImg;
    SDL_Surface *tiredImg;
    SDL_Surface *catching;
    SDL_Surface *resistanceBar,*resistanceIMG;
    SDL_Rect pos1,resistancePos2,resistancePos1;
    int frame;
    int hp;
    int xSpeed,ySpeed;
    int invin;
    int hit;
    int invinWindow;
    int hitTime;
    int stamina;
    int resistance;
    Mix_Chunk *hurt,*stop,*whisle,*needBackUp,*comeHere,*amBack;
    int timeToMoveX;
    int timeToMoveY;
    int inStandBy;
    long int deployTime;
    int tired;

    

} police;

typedef struct 
{
    SDL_Surface *img;
    SDL_Rect pos1;
    int realx;
    int realy;
    int type;
    int recovery;
    int effectDuration;
   
}consumable;

typedef struct structurs
{
    IMAGE img;
    int satisfied;
    int speed;
    int called;
    Mix_Chunk *meaw,*attack,*purr;
    police *target;
    int attacked;


}cat;




// FUNCTIONS 
void detectionkey(GLOBAL_VARS *G_V);
void freesurface(GLOBAL_VARS *G_V);
void blit_all(SDL_Surface *wind,int n,...);
void sauve(INFO *if1,char *chemin);
void reception_info(INFO *if1,char *chemin);
void screen_mode(GLOBAL_VARS *G_V);
int is_in_rect(int x1,int y1,SDL_Rect pos1);


// IMAGE FUNCTIONS
        // ------------>>>>>MEBU IMAGES<<<<<-------------
void init(IMAGE i[],int H,int W);
void load(IMAGE img[], IMAGE i[], int H, int W,int o);
void SHOWALLIMG(IMAGE *i1,SDL_Surface *wind);
void animation(SDL_Surface *wind,IMAGE *img,int *i,int *count);
void initanimation(IMAGE *img);


        //    ------------>>>>>OPTIONS IMAGES+LOAD+INIT<<<<<-------------
void opload(IMAGE op[], IMAGE op1[], IMAGE op_kl[],int H, int W,int o);
void rectinit(SDL_Rect *RectPos,SDL_Rect *RectPos1,SDL_Rect *RectPos2,IMAGE butt[],IMAGE *op,IMAGE *op1);

        //  ------------>>>>>new game images<<<<<-------------
void init_bubble(GLOBAL_VARS *G_V,int o);
void show_bubble(GLOBAL_VARS *G_V,Ennemi e,int n);
void load_trailer(GLOBAL_VARS *G_V);
void load_cematiques(GLOBAL_VARS *G_V,int o);

        //  ------------>>>>>FULL SCREEN MODE <<<<<-------------
void fullscreen_new_g_load(IMAGE *new_g,int H,int W);

// TEXT FUNCTIONS

void inittxt(TEXT *t1,int H,int W);
void SHOWTXT(TEXT *t1,SDL_Surface *wind,char *l);

// aruino functions
int arduinoWriteData(int x);
int arduinoReadData(int *x);


//feres fontions
void randomPosition(int xmin,int xmax,int ymin,int ymax,int *x, int *y);
void animateOnce(IMAGE *i,int *animated,int *x);

#endif 