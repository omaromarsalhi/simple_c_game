#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "structurs.h"
#include "perso.h"

// essential part
void intitEnnemi(Ennemi *e)
{
	if (e->the_chosen == 1)
	{
		e->cafe_img.img = IMG_Load("./characters/presion.png");
		e->cafe_img.pos1.x = 350;
		e->cafe_img.pos1.y = 500;

		e->cafe_img.pos2.x = 0;
		e->cafe_img.pos2.y = 0;
		e->cafe_img.pos2.w = e->cafe_img.img->w / 4;
		e->cafe_img.pos2.h = e->cafe_img.img->h / 4;
	
	}

	else if (e->the_chosen == 4)
	{
		// from left to right
		e->nbr_spsh = 8;
		e->spsh = 3;
		e->img[0] = IMG_Load("./Wizard Pack/sp1/Attack1.png");
		e->nbr_frames[0] = 8;
		e->img[1] = IMG_Load("./Wizard Pack/sp1/Attack2.png");
		e->nbr_frames[1] = 8;
		e->img[2] = IMG_Load("./Wizard Pack/sp1/Death.png");
		e->nbr_frames[2] = 7;
		e->img[3] = IMG_Load("./Wizard Pack/sp1/Fall.png");
		e->nbr_frames[3] = 2;
		e->img[4] = IMG_Load("./Wizard Pack/sp1/Hit.png");
		e->nbr_frames[4] = 4;
		e->img[5] = IMG_Load("./Wizard Pack/sp1/Idle.png");
		e->nbr_frames[5] = 6;
		e->img[6] = IMG_Load("./Wizard Pack/sp1/Jump.png");
		e->nbr_frames[6] = 2;
		e->img[7] = IMG_Load("./Wizard Pack/sp1/Run.png");
		e->nbr_frames[7] = 8;
		// from right to left
		e->img[8] = IMG_Load("./Wizard Pack/sp2/1.png");
		e->nbr_frames[8] = 8;
		e->img[9] = IMG_Load("./Wizard Pack/sp2/2.png");
		e->nbr_frames[9] = 8;
		e->img[10] = IMG_Load("./Wizard Pack/sp2/3.png");
		e->nbr_frames[10] = 7;
		e->img[11] = IMG_Load("./Wizard Pack/sp2/4.png");
		e->nbr_frames[11] = 2;
		e->img[12] = IMG_Load("./Wizard Pack/sp2/5.png");
		e->nbr_frames[12] = 4;
		e->img[13] = IMG_Load("./Wizard Pack/sp2/6.png");
		e->nbr_frames[13] = 6;
		e->img[14] = IMG_Load("./Wizard Pack/sp2/7.png");
		e->nbr_frames[14] = 2;
		e->img[15] = IMG_Load("./Wizard Pack/sp2/8.png");
		e->nbr_frames[15] = 8;
		for (int i = 0; i < e->nbr_spsh; i++)
		{
			e->pos1[i].x = 0;
			e->pos1[i].y = 0;
			e->pos2[i].x = 0;
			e->pos2[i].y = 0;
			e->pos2[i].w = e->img[i]->w / e->nbr_frames[i];
			e->pos2[i].h = e->img[i]->h;

			e->pos1[i + 8].x = 0;
			e->pos1[i + 8].y = 0;
			e->pos2[i + 8].x = e->img[i + 8]->w;
			e->pos2[i + 8].y = 0;
			e->pos2[i + 8].w = e->img[i + 8]->w / e->nbr_frames[i];
			e->pos2[i + 8].h = e->img[i + 8]->h;
		}
	}
	else if (e->the_chosen == 6)
	{
		e->cafe_img.img = IMG_Load("./characters/1.png");

		e->cafe_img.pos1.x = 500;
		e->cafe_img.pos1.y = 200;

		e->cafe_img.pos2.x = 0;
		e->cafe_img.pos2.y = 0;
		e->cafe_img.pos2.w = e->cafe_img.img->w / 4;
		e->cafe_img.pos2.h = e->cafe_img.img->h / 4;
	}
	else if (e->the_chosen == 7)
	{
		e->cafe_img.img = IMG_Load("./characters/2.png");
		e->cafe_img.pos1.x = 550;
		e->cafe_img.pos1.y = 300;

		e->cafe_img.pos2.x = 0;
		e->cafe_img.pos2.y = 0;
		e->cafe_img.pos2.w = e->cafe_img.img->w / 4;
		e->cafe_img.pos2.h = e->cafe_img.img->h / 4;
	}
	else if (e->the_chosen == 8)
	{
		e->cafe_img.img = IMG_Load("./characters/3.png");
		e->cafe_img.pos1.x = 600;
		e->cafe_img.pos1.y = 400;

		e->cafe_img.pos2.x = 0;
		e->cafe_img.pos2.y = 0;
		e->cafe_img.pos2.w = e->cafe_img.img->w / 4;
		e->cafe_img.pos2.h = e->cafe_img.img->h / 4;
	}
	else if (e->the_chosen == 9)
	{
		e->cafe_img.img = IMG_Load("./characters/4.png");
		e->cafe_img.pos1.x = 650;
		e->cafe_img.pos1.y = 450;

		e->cafe_img.pos2.x = 0;
		e->cafe_img.pos2.y = 0;
		e->cafe_img.pos2.w = e->cafe_img.img->w / 4;
		e->cafe_img.pos2.h = e->cafe_img.img->h / 4;

	}
	else if (e->the_chosen == 10)
	{
		e->cafe_img.img = IMG_Load("./characters/5.png");
		e->cafe_img.pos1.x = 700;
		e->cafe_img.pos1.y = 420;

		e->cafe_img.pos2.x = 0;
		e->cafe_img.pos2.y = 0;
		e->cafe_img.pos2.w = e->cafe_img.img->w / 4;
		e->cafe_img.pos2.h = e->cafe_img.img->h / 4;
	}
	else if (e->the_chosen == 11)
	{
		e->cafe_img.img = IMG_Load("./characters/25.png");
		e->cafe_img.pos1.x = 350;
		e->cafe_img.pos1.y = 500;

		e->cafe_img.pos2.x = 0;
		e->cafe_img.pos2.y = 0;
		e->cafe_img.pos2.w = e->cafe_img.img->w / 4;
		e->cafe_img.pos2.h = e->cafe_img.img->h / 4;
	}
}




void updateEnnemi(Ennemi *e, SDL_Rect posHero, SDL_Surface *window)
{
	SDL_Rect pos1, pos2, pos3, pos4;
	pos1.x = e->pos1[e->spsh].x;
	pos1.y = e->pos1[e->spsh].y ;
	pos1.w = 130;
	pos1.h = 200;

	pos2.x = e->pos1[e->spsh].x - 100;
	pos2.y = e->pos1[e->spsh].y ;
	pos2.w = 200+pos1.w;
	pos2.h = 200;

	pos3.x = e->pos1[e->spsh].x - 150;
	pos3.y = e->pos1[e->spsh].y ;
	pos3.w = 300+pos1.w;
	pos3.h = 200;

	pos4.x = e->pos1[e->spsh].x;
	pos4.y = e->pos1[e->spsh].y;
	pos4.w = 20;
	pos4.h = 20;
	strcpy(e->satete, "waiting");
	e->spsh = 5;
	if (e->bk_pos2.x >= 2000)
	{
		strcpy(e->satete, "idle");
		e->spsh = 5;
	}
	else
	{
		strcpy(e->satete, "idle");
		e->spsh = 13;
	}
	if (e->derection == 3)
	{
		if (is_in_rect(posHero.x + e->P_w, posHero.y, pos1) || is_in_rect(posHero.x + e->P_w, posHero.y + posHero.h + e->P_h, pos1))
		{
			strcpy(e->satete, "attack");
			e->spsh = 8;
		}
		else if (is_in_rect(posHero.x + e->P_w, posHero.y, pos2) || is_in_rect(posHero.x + e->P_w, posHero.y + posHero.h + e->P_h, pos2))
		{
			strcpy(e->satete, "run");
			e->spsh = 7 + 8;
		}
		else if (is_in_rect(posHero.x + e->P_w, posHero.y, pos3) || is_in_rect(posHero.x + e->P_w, posHero.y + posHero.h + e->P_h, pos3))
		{
			strcpy(e->satete, "idle");
			e->spsh = 13;
		}
	}
	else if (e->derection == 4)
	{

		if (is_in_rect(posHero.x, posHero.y, pos1) || is_in_rect(posHero.x, posHero.y + e->P_h, pos1))
		{
			strcpy(e->satete, "attack");
			e->spsh = 1;
		}
		else if (is_in_rect(posHero.x, posHero.y, pos2) || is_in_rect(posHero.x, posHero.y + e->P_h, pos2))
		{
			strcpy(e->satete, "run");
			e->spsh = 7;
		}
		else if (is_in_rect(posHero.x, posHero.y, pos3) || is_in_rect(posHero.x, posHero.y + e->P_h, pos3))
		{
			strcpy(e->satete, "idle");
			e->spsh = 5;
		}
	}
}

void animateEnnemi(Ennemi *e)
{
	static int count = 0;
	count++;
	if (e->spsh >= 8 && count % 2 == 0)
	{
		count = 0;
		e->pos2[e->spsh].x -= e->img[e->spsh]->w / e->nbr_frames[e->spsh];
		if (e->pos2[e->spsh].x <= 0)
			e->pos2[e->spsh].x = e->img[e->spsh]->w - e->img[e->spsh]->w / e->nbr_frames[e->spsh];
	}
	else if (count % 2 == 0)
	{
		count = 0;
		e->pos2[e->spsh].x += e->img[e->spsh]->w / e->nbr_frames[e->spsh];
		if (e->pos2[e->spsh].x >= e->img[e->spsh]->w)
			e->pos2[e->spsh].x = 0;
	}
}

void animerEnnemi(Ennemi *e)
{
	e->pos2[e->spsh].x += e->img[e->spsh]->w / e->nbr_frames[e->spsh];
	if (e->pos2[e->spsh].x >= e->img[e->spsh]->w)
		e->pos2[e->spsh].x = 0;
}

void animerEnnemie_pro(Ennemi *e)
{
	e->cafe_img.pos2.x += e->cafe_img.pos2.w;
	e->cafe_img.pos2.y=(e->cafe_img.pos2.h)*(e->derection-1);
	if (e->cafe_img.pos2.x+ e->cafe_img.pos2.w >= e->cafe_img.img->w)
		e->cafe_img.pos2.x = 0;
}

void deplacer_pro(Ennemi *e)
{
	static int count = 0, i = 0;
	count++;
	srand(time(NULL));
	if (!e->coll&&count % 100 == 0)
	{
		count = 0;
		e->func_num = rand() % 4 + 1;
		printf("fun %d\n",e->func_num);
	}

	switch (e->func_num)
	{
	case 1:
		e->derection = 3;
		e->MV_destance[0]+=4;
		break;
	case 2:
		e->derection = 2;
		e->MV_destance[0]-=4;
		break;
	case 3:                                                
		e->derection = 1;
		e->MV_destance[1] +=4;
		break;
	case 4:
		e->derection = 4;
		e->MV_destance[1] -=4;
		break;
	}
}


void deplacer_pro_1(Ennemi *e)
{

	switch (e->func_num)
	{
	case 1:
		e->derection = 3;
		e->MV_destance[0]+=4;
		break;
	case 2:
		e->derection = 2;
		e->MV_destance[0]-=4;
		break;
	}
}


void afficherEnnemi_pro(Ennemi e, SDL_Surface *window)
{	
	SDL_BlitSurface(e.cafe_img.img, &e.cafe_img.pos2, window, &e.cafe_img.pos1);
}


int collisionBB_pro(Ennemi e, Personne p)
{
	if ((p.image[p.where].pos1.x + p.image[p.where].pos2.w < e.cafe_img.pos1.x) || (p.image[p.where].pos1.x > e.cafe_img.pos1.x + e.cafe_img.pos2.w) || (p.image[p.where].pos1.y + p.image[p.where].pos2.h < e.cafe_img.pos1.y) || (p.image[p.where].pos1.y > e.cafe_img.pos1.y + e.cafe_img.pos2.h ))
		return 0;
	else
		return 1;
}





int collisionPP_char(Ennemi e, SDL_Surface *Masque,int r,int g,int b)
{
	SDL_Color color;

	int posX = e.cafe_img.pos1.x;
	int posY = e.cafe_img.pos1.y;
	int posX1 = posX +  e.cafe_img.pos2.w;
	int posY1 = posY + e.cafe_img.pos2.h;
	if (e.derection == 3 || e.derection == 2)
	{
		for (int i = posY1-10; i <= posY1-10; i++)
		{
			// Right
			color = GetPixel(Masque, posX1+e.bk_pos2.x, i + e.bk_pos2.y);
			if (color.r == r && color.g == g && color.b == b && e.derection == 3)
				return 1;
			// Left
			color = GetPixel(Masque, posX+e.bk_pos2.x, i + e.bk_pos2.y);
			if (color.r == r && color.g == g && color.b == b && e.derection == 2)
				return 1;
		}
	}
	else
	{
		for (int i = posX+10; i <= posX1-10; i++)
		{
			// TOP
			color = GetPixel(Masque, i + e.bk_pos2.x, posY1 + e.bk_pos2.y - 50);
			if (color.r == r && color.g == g && color.b == b && e.derection == 4)
				return 1;
			// Botom,
			color = GetPixel(Masque, i + e.bk_pos2.x, posY1 + e.bk_pos2.y+20 );
			if (color.r == r && color.g == g && color.b == b && e.derection == 1)
				return 1;
		}
	}

	return 0;
}

void afficherEnnemi(Ennemi e, SDL_Surface *window)
{
	SDL_BlitSurface(e.img[e.spsh], &e.pos2[e.spsh], window, &e.pos1[e.spsh]);
}

int timepassed_pro(int dt)
{
	static int now = 0, ex = 0;
	now = SDL_GetTicks();
	if (now - ex >= dt)
	{
		ex = now;
		return 1;
	}
	else
		return 0;
}

void deplacer(Ennemi *e)
{
	switch (e->func_num)
	{
	case 1:
		e->cafe_img.pos1.x+=5;
		e->derection = 2;
		break;
	case 2:
		e->cafe_img.pos1.x-=5;
		e->derection = 3;
		break;
	case 3:
		e->cafe_img.pos1.y+=5;
		e->derection = 1;
		break;
	case 4:
		e->cafe_img.pos1.y-=5;
		e->derection = 4;
		break;
	}
}

int collisionBB(Ennemi e, Personne p)
{
	if ((p.image[p.where].pos1.x + p.image[p.where].pos2.w < e.pos1[e.spsh].x + 200) || (p.image[p.where].pos1.x > e.pos1[e.spsh].x - 200 + e.pos2[e.spsh].w) || (p.image[p.where].pos1.y + p.image[p.where].pos2.h < e.pos1[e.spsh].y) || (p.image[p.where].pos1.y > e.pos1[e.spsh].y + e.pos2[e.spsh].h - 20))
		return 0;
	else
		return 1;
}
	
	

int collisionPP_Ennemi(Ennemi e, SDL_Surface *Masque)
{
	SDL_Color color;

	int posX = e.pos1[e.spsh].x;
	int posY = e.pos1[e.spsh].y;
	int posX1 = posX + e.img[e.spsh]->w / e.nbr_frames[e.spsh];
	int posY1 = posY;
	for (int i = posY; i <= posY1; i++)
	{
		// Right
		color = GetPixel(Masque, posX1 + e.bk_pos2.x + 20, i + e.bk_pos2.y);
		if (color.r == 0 && color.g == 0 && color.b == 255)
			return 1;
		// Left
		color = GetPixel(Masque, posX + e.bk_pos2.x - 20, i + e.bk_pos2.y);
		if (color.r == 0 && color.g == 0 && color.b == 255)
			return 2;
	}
	for (int i = posX; i <= posX1; i++)
	{
		// TOP
		color = GetPixel(Masque, i + e.bk_pos2.x, posY + e.bk_pos2.y - 20);
		if (color.r == 0 && color.g == 0 && color.b == 255)
			return 4;
		// Botom
		color = GetPixel(Masque, i + e.bk_pos2.x, posY1 + e.bk_pos2.y + 20);
		if (color.r == 0 && color.g == 0 && color.b == 255)
			return 3;
	}
	return 0;
}

int collisionPP_ennemy_race(Personne p, SDL_Surface *Masque)
{
	SDL_Color color;
	int posX = p.image[p.where].pos1.x;
	int posY = p.image[p.where].pos1.y + 3;
	int posX1 = posX + p.image[p.where].img->w / p.nbr_frames[p.where];
	int posY1 = posY + p.image[p.where].img->h / 4;
	if (p.derec == 3)
	{
		for (int i = posY; i <= posY1; i++)
		{
			// Right
			color = GetPixel(Masque, posX1 + p.bk_pos2.x + 20, i + p.bk_pos2.y);
			if (color.r == 255 && color.g == 255 && color.b == 255)
				return 1;
		}
	}
	return 0;
}


int update_police_attack(Ennemi e,Personne p,SDL_Surface *window){
	Uint32 col1;
	col1 = SDL_MapRGB(window->format, 125, 0, 0);
	SDL_Rect pos;
	if(e.derection==1){
		pos.x=e.cafe_img.pos1.x-150;
		pos.y=e.cafe_img.pos1.y+e.cafe_img.pos2.h/2;
		pos.w=300+e.cafe_img.pos2.w;
		pos.h=200;
	}
	else if(e.derection==3){
		pos.w=200;
		pos.h=300;
		pos.x=e.cafe_img.pos1.x-pos.w+e.cafe_img.pos2.w;
		pos.y=e.cafe_img.pos1.y-pos.h/3;

	}
	else if(e.derection==2){
		pos.w=200;
		pos.x=e.cafe_img.pos1.x;
		pos.y=e.cafe_img.pos1.y-100;
		pos.h=200+e.cafe_img.pos2.h;
		
	}
	else if(e.derection==4){
		pos.x=e.cafe_img.pos1.x-150;
		pos.w=300+e.cafe_img.pos2.w;
		pos.h=200;
		pos.y=e.cafe_img.pos1.y-pos.h+e.cafe_img.pos2.h;
		
	}
	//SDL_FillRect(window, &pos, col1);
	if(is_in_rect(p.image[p.where].pos1.x,p.image[p.where].pos1.y,pos))
		return 1;
	if(is_in_rect(p.image[p.where].pos1.x+p.image[p.where].pos2.w,p.image[p.where].pos1.y+p.image[p.where].pos2.h,pos))
		return 1;
	if(is_in_rect(p.image[p.where].pos1.x+p.image[p.where].pos2.w,p.image[p.where].pos1.y,pos))
		return 1;
	if(is_in_rect(p.image[p.where].pos1.x,p.image[p.where].pos1.y+p.image[p.where].pos2.h,pos))
		return 1;
	return 0;
	
}