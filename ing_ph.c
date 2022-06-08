#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "structurs.h"


void InitEnigme_ph (ing_ph *e, char *nomfichier){
    FILE *file;
    file=fopen(nomfichier,"r");
    for(int i=0;i<7;i++){
        fscanf(file,"%s\n",e->path_hang_man[i]);
        e->hang_man[i].img=IMG_Load(e->path_hang_man[i]);
        e->hang_man[i].pos1.x=0;
        e->hang_man[i].pos1.y=0;
    }  
    for(int i=0;i<5;i++){
        fscanf(file,"%s\n",e->path_ing[0][i]);
        e->ing[0][i].img=IMG_Load(e->path_ing[0][i]);
        e->ing[0][i].pos1.x=e->W/2-e->ing[0][i].img->w/2;
        e->ing[0][i].pos1.y=0;
    }
    for(int i=0;i<5;i++){
        fscanf(file,"%s\n",e->path_ing[1][i]);
        e->ing[1][i].img=IMG_Load(e->path_ing[1][i]);
        e->ing[1][i].pos1.x=e->W/2-e->ing[1][i].img->w/2;
        e->ing[1][i].pos1.y=0;
    }
    fscanf(file,"%s %s\n",e->path_end[1],e->path_end[0]);
    e->end[1].img=IMG_Load(e->path_end[1]);
    e->end[0].img=IMG_Load(e->path_end[0]);
    e->end[0].pos1.x=e->W/2-e->end[0].img->w/2;
    e->end[0].pos1.y=e->H/2-e->end[0].img->h/2;
    e->end[1].pos1.x=e->W/2-e->end[1].img->w/2;
    e->end[1].pos1.y=e->H/2-e->end[1].img->h/2;
    fscanf(file,"%hd %hd %hd %hd\n",&e->pos_butt[0].x,&e->pos_butt[0].y,&e->pos_butt[0].w,&e->pos_butt[0].h);
    fscanf(file,"%hd %hd %hd %hd\n",&e->pos_butt[1].x,&e->pos_butt[1].y,&e->pos_butt[1].w,&e->pos_butt[1].h);
    fscanf(file,"%hd %hd %hd %hd\n",&e->pos_butt[2].x,&e->pos_butt[2].y,&e->pos_butt[2].w,&e->pos_butt[2].h);
    fscanf(file,"%d %d\n",&e->true_answer[0],&e->true_answer[1]);
    fclose(file);

}


void afficherEnigme_ph (ing_ph e, SDL_Surface * screen){
	SDL_BlitSurface(e.ing[e.x][e.where].img,NULL,screen,&e.ing[e.x][e.where].pos1);
}


int collisionPP_ing_ph(Personne p, SDL_Surface *Masque)
{
    SDL_Color color;
    int posX = p.image[p.where].pos1.x;
    int posY = p.image[p.where].pos1.y+3;
    int posX1 = posX + p.image[p.where].img->w/p.nbr_frames[p.where];
    int posY1 = posY + p.image[p.where].img->h/4;
    if(p.derec==1||p.derec==2){
      for (int i = posX; i <= posX1; i++)
    {
        // TOP
        color = GetPixel(Masque, i+p.bk_pos2.x, posY+p.bk_pos2.y-30);
        if (color.r == 0 && color.g == 255 && color.b == 0 && p.derec==2)
            return 2;
        // Botom
        color = GetPixel(Masque, i+p.bk_pos2.x, posY1+p.bk_pos2.y+30);
        if (color.r == 0 && color.g == 255 && color.b == 0 &&p.derec==1)
            return 1;
    }
    }
    return 0;
}