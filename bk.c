#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "structurs.h"

void initBack(Background *b)
{
    int o=0;
    char names[2][20][50]={{"./omar_backgounf/omar1.png"
    ,"./omar_backgounf/omar2.png"
    ,"./omar_backgounf/omar3.png",
    "./omar_backgounf/omar4.png"
    ,"./omar_backgounf/omar111.png"
    ,"./omar_backgounf/omar222.png"
    ,"./omar_backgounf/2 .png",
    "./omar_backgounf/1.png"
    ,"./omar_backgounf/mask_cafe.png"
    ,"./omar_backgounf/market.png"
    ,"./omar_backgounf/marketmasque.png",
    "./omar_backgounf/marketmasque2.png",
    "./omar_backgounf/home_town.png"
    ,"./omar_backgounf/home_town_mask.png",
    "./omar_backgounf/mask_cafe_2.png"}
    ,{"./omar_backgounf/full_screen/omar1.png","./omar_backgounf/full_screen/omar2.png","./omar_backgounf/full_screen/omar3.png",
    "./omar_backgounf/full_screen/omar4.png","./omar_backgounf/full_screen/omar111.png","./omar_backgounf/full_screen/omar222.png","./omar_backgounf/full_screen/2 .png",
    "./omar_backgounf/full_screen/1.png","./omar_backgounf/full_screen/mask_cafe.png","./omar_backgounf/full_screen/market.png","./omar_backgounf/full_screen/marketmasque.png",
    "./omar_backgounf/full_screen/marketmasque2.png","./omar_backgounf/full_screen/home_town.png","./omar_backgounf/full_screen/home_town_mask.png"}};
    if (b->the_chosen == 1)
    {

        b->i = 0;
        b->coll_i = 4;
        b->count = 0;
        b->b_k[0].img = IMG_Load(names[o][0]);
        b->b_k[1].img = IMG_Load(names[o][1]);
        b->b_k[2].img = IMG_Load(names[o][2]);
        b->b_k[3].img = IMG_Load(names[o][3]);
        b->b_k[0].pos1.x = 0;
        b->b_k[0].pos1.y = 0;
        b->b_k[1].pos1 = b->b_k[0].pos1;
        b->b_k[2].pos1 = b->b_k[0].pos1;
        b->b_k[3].pos1 = b->b_k[0].pos1;

        b->b_k[0].pos2.x = 0;
        b->b_k[0].pos2.y = b->b_k[0].img->h - b->H;
        b->b_k[0].pos2.w = b->W;
        b->b_k[0].pos2.h = b->H;

        b->b_k[1].pos2 = b->b_k[0].pos2;
        b->b_k[2].pos2 = b->b_k[0].pos2;
        b->b_k[3].pos2 = b->b_k[0].pos2;

        b->b_k[4].img = IMG_Load(names[o][4]);
        b->b_k[5].img = IMG_Load(names[o][5]);


        b->b_k[4].pos1 = b->b_k[0].pos1;
        b->b_k[5].pos1 = b->b_k[0].pos1;

        b->b_k[4].pos2 = b->b_k[0].pos2;
        b->b_k[5].pos2 = b->b_k[0].pos2;
    }
    else if (b->the_chosen == 2)
    {
        b->i = 0;
        b->coll_i = 5;
        b->count = 0;
        b->b_k[0].img = IMG_Load(names[o][6]);
        b->b_k[1].img = IMG_Load(names[o][7]);
        b->b_k[0].pos1.x = 0;
        b->b_k[0].pos1.y = 0;
        b->b_k[1].pos1 = b->b_k[0].pos1;

        b->b_k[0].pos2.x = 500;
        b->b_k[0].pos2.y = 0;
        b->b_k[0].pos2.w = b->W;
        b->b_k[0].pos2.h = b->H;
        b->b_k[1].pos2 = b->b_k[0].pos2;


        b->b_k[5].img = IMG_Load(names[o][8]);
        b->b_k[6].img = IMG_Load(names[o][14]);

        b->b_k[5].pos1.x = 0;
        b->b_k[5].pos1.y = 0;
        b->b_k[5].pos2.x = 500;
        b->b_k[5].pos2.y = 0;
        b->b_k[5].pos2.w = b->W;
        b->b_k[5].pos2.h = b->H;
    }
    else if (b->the_chosen == 3)
    {
        b->b_k[0].img=IMG_Load(names[o][9]);
        b->b_k[1].img=IMG_Load(names[o][10]);
        b->b_k[2].img=IMG_Load(names[o][11]);

        b->scrolling_speed=2;
        b->b_k[0].pos1.x = 0;
        b->b_k[0].pos1.y = 0;
        b->b_k[0].pos2.x = 0;
        b->b_k[0].pos2.y = 0;
        b->b_k[0].pos2.w = b->W;
        b->b_k[0].pos2.h = b->H;
        b->i = 0;
        b->count = 0;
    }
    else if (b->the_chosen == 4)
    {
        b->i = 0;
        b->coll_i = 5;
        b->count = 0;
        b->b_k[0].img = IMG_Load(names[o][12]);
        b->b_k[0].pos1.x = 0;
        b->b_k[0].pos1.y = 0;

        b->b_k[0].pos2.x = b->b_k[0].img->w-b->W;
        b->b_k[0].pos2.y = b->b_k[0].img->h-b->H;
        b->b_k[0].pos2.w = b->W;
        b->b_k[0].pos2.h = b->H;


        b->b_k[5].img = IMG_Load(names[o][13]);
    }
}

void aficherBack(Background b, SDL_Surface *screen)
{
    SDL_BlitSurface(b.b_k[b.i].img, &b.b_k[b.i].pos2, screen, &b.b_k[b.i].pos1);
}

void animerBackground(Background *b)
{
    b->b_k[0].pos2 = b->b_k[b->i].pos2;
    b->b_k[1].pos2 = b->b_k[b->i].pos2;
    b->b_k[2].pos2 = b->b_k[b->i].pos2;
    b->b_k[3].pos2 = b->b_k[b->i].pos2;

    b->count++;
    if (b->count == 10)
        (b->i) = 1;
    if (b->count == 20)
        (b->i) = 2;
    if (b->count == 30)
        (b->i) = 3;
    if (b->count == 100)
        (b->i) = 2;
    if (b->count == 110)
        (b->i) = 1;
    if (b->count == 120)
    {
        (b->i) = 0;
        b->count = 0;
    }
}
void scrolling(Background *b, int direction, int pasAvancement)
{

    switch (direction)
    {
    case 1:
        b->b_k[b->i].pos2.y += pasAvancement * 2;
        break;
    case 2:
        b->b_k[b->i].pos2.y -= pasAvancement * 2;
        break;
    case 3:
        b->b_k[b->i].pos2.x += pasAvancement * 2;
        break;
    case 4:
        b->b_k[b->i].pos2.x -= pasAvancement * 2;
        break;
    }
  

    if (b->i + 4 < 8)
        b->b_k[b->i + 4].pos2 = b->b_k[b->i].pos2;
    else
        b->b_k[b->i + 1].pos2 = b->b_k[b->i].pos2;
}

SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    SDL_Color color;
    Uint32 col = 0;

    // Determine Pos
    char *pPosition = (char *)pSurface->pixels;
    pPosition += (pSurface->pitch * y);
    pPosition += (pSurface->format->BytesPerPixel * x);
    memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
    // convertir color
    SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);

    return (color);
}

int collisionPP(Personne p, SDL_Surface *Masque)
{
    SDL_Color color;

    int posX = p.image[p.where].pos1.x;
    int posY = p.image[p.where].pos1.y;
    int posX1 = posX + p.image[p.where].img->w / p.nbr_frames[p.where];
    int posY1 = posY + p.image[p.where].img->h / 4;
    if (p.derec == 3 || p.derec == 4)
    {
        for (int i = posY1-30; i <= posY1-10; i++)
        {
            // Right
            //color = GetPixel(Masque, i + p.bk_pos2.x+10, posY1 + p.bk_pos2.y );
            color = GetPixel(Masque, posX1+p.bk_pos2.x, i + p.bk_pos2.y);
            if (color.r == 0 && color.g == 0 && color.b == 255 && p.derec == 3)
                return 1;
            // Left
            //color = GetPixel(Masque, i + p.bk_pos2.x-10, posY1 + p.bk_pos2.y);
            color = GetPixel(Masque, posX+p.bk_pos2.x, i + p.bk_pos2.y);
            if (color.r == 0 && color.g == 0 && color.b == 255 && p.derec == 4)
                return 1;
        }
    }
    else
    {
        for (int i = posX+10; i <= posX1-10; i++)
        {
            // TOP
            //color = GetPixel(Masque, i + p.bk_pos2.x, posY1 + p.bk_pos2.y - 10);
            color = GetPixel(Masque, i + p.bk_pos2.x, posY1 + p.bk_pos2.y - 50);
            if (color.r == 0 && color.g == 0 && color.b == 255 && p.derec == 2)
                return 1;
            // Botom,
            //color = GetPixel(Masque, i + p.bk_pos2.x, posY1 + p.bk_pos2.y + 10);
            color = GetPixel(Masque, i + p.bk_pos2.x, posY1 + p.bk_pos2.y +10);
            if (color.r == 0 && color.g == 0 && color.b == 255 && p.derec == 1)
                return 1;
        }
    }

    return 0;
}
