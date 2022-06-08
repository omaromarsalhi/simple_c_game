#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "structurs.h"




void InitEnigme(ing_txt *e, char *nomfichier){
    FILE *file;
    file=fopen(nomfichier,"r");
    fscanf(file,"%s %s %s %s %d\n",e->Q[0],e->AN[0],e->AN[1],e->AN[2],&e->true_answer[0]);
    fscanf(file,"%s %s %s %s %d\n",e->Q[1],e->AN[3],e->AN[4],e->AN[5],&e->true_answer[1]);
    fscanf(file,"%s %s %s %s %d\n",e->Q[2],e->AN[6],e->AN[7],e->AN[8],&e->true_answer[2]);
    for(int j=0;j<3;j++)
        for(int i=0;i<strlen(e->Q[j]);i++)
            if(e->Q[j][i]=='/')
                e->Q[j][i]=' ';
    fclose(file);
    e->bg[0].img=IMG_Load("./ing_txt/background/bg0.png");
    e->bg[1].img=IMG_Load("./ing_txt/background/bg1.png");
    e->bg[2].img=IMG_Load("./ing_txt/background/bg2.png");
    e->bg[3].img=IMG_Load("./ing_txt/background/bg3.png");
    e->bg[0].pos1.x=0;//e->W/2-e->bg.img->w/2;
    e->bg[0].pos1.y=0;//e->H/10;
    e->bg[1].pos1=e->bg[0].pos1;
    e->bg[2].pos1=e->bg[0].pos1;
    e->bg[3].pos1=e->bg[0].pos1;

    e->bg[4].img=IMG_Load("./ing_txt/background/blida.png");
    e->bg[4].pos1.x=963;//e->W/2-e->bg.img->w/2;
    e->bg[4].pos1.y=240;//0;//e->H/10;


    e->butt[0][0].img=IMG_Load("./ing_txt/botna/botna1.png");
    e->butt[0][1].img=IMG_Load("./ing_txt/botna/botna2.png");
    e->butt[0][2].img=IMG_Load("./ing_txt/botna/botna3.png");
    e->butt[1][0].img=IMG_Load("./ing_txt/buttonSelected.png");
    e->butt[1][1].img=e->butt[1][0].img;
    e->butt[1][2].img=e->butt[1][0].img;
    e->butt[2][0].img=IMG_Load("./ing_txt/ButtonClicked.png");
    e->butt[2][1].img=e->butt[2][0].img;
    e->butt[2][2].img=e->butt[2][0].img;

    e->butt[0][0].pos1.x=32;//e->W/2-e->butt[0][0].img->w*1.2;
    e->butt[0][0].pos1.y=363;////e->H/1.6;
    e->butt[0][1].pos1.x=514;//e->W/2+e->butt[0][1].img->w*0.2;
    e->butt[0][1].pos1.y=489;//e->H/1.6;
    e->butt[0][2].pos1.x=967;//e->W/2-e->butt[0][2].img->w/2;
    e->butt[0][2].pos1.y=661;//e->H/1.3;

    e->time_txt[0].img=IMG_Load("./ing_txt/c0.png");  
    e->time_txt[1].img=IMG_Load("./ing_txt/c1.png"); 
    e->time_txt[2].img=IMG_Load("./ing_txt/c2.png"); 
    e->time_txt[3].img=IMG_Load("./ing_txt/c3.png"); 
    e->time_txt[4].img=IMG_Load("./ing_txt/c4.png"); 
    e->time_txt[5].img=IMG_Load("./ing_txt/c5.png"); 
    e->time_txt[6].img=IMG_Load("./ing_txt/c6.png"); 
    e->time_txt[7].img=IMG_Load("./ing_txt/c7.png"); 
    e->time_txt[8].img=IMG_Load("./ing_txt/c8.png"); 
    e->time_txt[9].img=IMG_Load("./ing_txt/c9.png"); 
    e->time_txt[10].img=IMG_Load("./ing_txt/c10.png"); 
    e->time_txt[11].img=IMG_Load("./ing_txt/c11.png"); 
    e->time_txt[12].img=IMG_Load("./ing_txt/c12.png"); 
    e->time_txt[0].pos1.x=44;//e->W-e->time_txt[0].img->w*1.6;
    e->time_txt[0].pos1.y=90;//e->H/2-e->time_txt[0].img->h/2;
    for(int i=1;i<13;i++)
        e->time_txt[i].pos1=e->time_txt[0].pos1;

    e->end[1].img=IMG_Load("./ing_txt/End.png");
    e->end[0].img=IMG_Load("./ing_txt/EndSad.png"); 
    e->end[1].pos1.x=0;
    e->end[1].pos1.y=0;
    e->end[0].pos1.x=0;
    e->end[0].pos1.y=0;

    e->t_Q[0].font=TTF_OpenFont("./ing_txt/font.ttf", 29);
    e->t_Q[0].col.r=125;
    e->t_Q[0].col.g=0;
    e->t_Q[0].col.b=0;
    e->t_Q[0].postxt.x=151;//e->W/2-e->W/4.4;
    e->t_Q[0].postxt.y=282;//e->H/3;
    e->t_Q[1]=e->t_Q[0];
    e->t_Q[2]=e->t_Q[0];
    for(int i=0;i<9;i++)
        e->t_AN[i]=e->t_Q[0];
    for(int j=0;j<3;j++){
        e->t_Q[j].windtxt=TTF_RenderText_Blended(e->t_Q[j].font,e->Q[j],e->t_Q[j].col);
        e->t_AN[j].postxt.x=e->butt[0][j].pos1.x+40;
        e->t_AN[j].postxt.y=e->butt[0][j].pos1.y+5;
        e->t_AN[j].windtxt=TTF_RenderText_Blended(e->t_AN[j].font,e->AN[j],e->t_AN[j].col);
        e->t_AN[j+3].postxt.x=e->butt[0][j].pos1.x+40;
        e->t_AN[j+3].postxt.y=e->butt[0][j].pos1.y+5;
        e->t_AN[j+3].windtxt=TTF_RenderText_Blended(e->t_AN[j+3].font,e->AN[j+3],e->t_AN[j+3].col);
        e->t_AN[j+6].postxt.x=e->butt[0][j].pos1.x+40;
        e->t_AN[j+6].postxt.y=e->butt[0][j].pos1.y+5;
        e->t_AN[j+6].windtxt=TTF_RenderText_Blended(e->t_AN[j+6].font,e->AN[j+6],e->t_AN[j+6].col);
    }

}


void animer (ing_txt *e){
    if(timepassed(1000))
        e->i++;
    if(e->i==13)
        e->i=0;
}





void afficherEnigme(ing_txt e, SDL_Surface * screen){
	SDL_BlitSurface(e.end[e.evaluation].img,NULL,screen,&e.end[e.evaluation].pos1);
}




void blit_all_txt(SDL_Surface *wind,int n,...){
    va_list args;
    va_start(args,n);
    TEXT *s;
    for(int i=0;i<n;i++){
        s=va_arg(args,TEXT*);
        SDL_BlitSurface(s->windtxt,NULL,wind,&s->postxt);
    }
    va_end(args);
}

int timepassed(int dt)
{
static int now=0,ex=0;
now=SDL_GetTicks();
if(now-ex>=dt)
{ex=now;return 1;}
else return 0;
}

int collisionPP_ing_txt(Personne p, SDL_Surface *Masque)
{
    SDL_Color color;
    int posX = p.image[p.where].pos1.x;
    int posY = p.image[p.where].pos1.y+3;
    int posX1 = posX + p.image[p.where].img->w/p.nbr_frames[p.where];
    int posY1 = posY + p.image[p.where].img->h/4;
    if(p.derec==2){
    for (int i = posX; i <= posX1; i++)
    {
        color = GetPixel(Masque, i+p.bk_pos2.x, posY1+p.bk_pos2.y);
        if (color.r == 255 && color.g == 0 && color.b == 0)
            return 1;
    }
    }

    return 0;
}