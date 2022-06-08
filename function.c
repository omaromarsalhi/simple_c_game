#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "structurs.h"
#include <math.h>

// -------->>>>>FUNCTIONS<<<<<<---------------
void detectionkey(GLOBAL_VARS *G_V)
{
	if(G_V->state==1||G_V->state==2){
	switch (G_V->event.type)
	{
	case SDL_KEYDOWN:
		if (G_V->event.key.keysym.sym == SDLK_RIGHT)
			G_V->Is_butt_on[0] = 1;
		if (G_V->event.key.keysym.sym == SDLK_LEFT)
			G_V->Is_butt_on[1] = 1;
		if (G_V->event.key.keysym.sym == SDLK_DOWN)
			G_V->Is_butt_on[2] = 1;
		if (G_V->event.key.keysym.sym == SDLK_UP)
			G_V->Is_butt_on[3] = 1;
		if (G_V->event.key.keysym.sym == SDLK_RETURN)
			G_V->Is_butt_on[4] = 1;
		if (G_V->event.key.keysym.sym == SDLK_ESCAPE)
			G_V->Is_butt_on[5] = 1;
		if (G_V->event.key.keysym.sym == SDLK_SPACE)
			G_V->Is_butt_on[6] = 1;
		break;
	case SDL_KEYUP:
		if (G_V->event.key.keysym.sym == SDLK_RIGHT)
			G_V->Is_butt_on[0] = 0;
		if (G_V->event.key.keysym.sym == SDLK_LEFT)
			G_V->Is_butt_on[1] = 0;
		if (G_V->event.key.keysym.sym == SDLK_DOWN)
			G_V->Is_butt_on[2] = 0;
		if (G_V->event.key.keysym.sym == SDLK_UP)
			G_V->Is_butt_on[3] = 0;
		if (G_V->event.key.keysym.sym == SDLK_RETURN)
			G_V->Is_butt_on[4] = 0;
		if (G_V->event.key.keysym.sym == SDLK_ESCAPE)
			G_V->Is_butt_on[5] = 0;
		if (G_V->event.key.keysym.sym == SDLK_SPACE)
			G_V->Is_butt_on[6] = 0;
		break;
	}
	}
	else{
		switch (G_V->event.type)
	{
	case SDL_KEYDOWN:
		if (G_V->event.key.keysym.sym == G_V->M.if1.tab_settings[2])
			G_V->Is_butt_on[0] = 1;
		if (G_V->event.key.keysym.sym == G_V->M.if1.tab_settings[3])
			G_V->Is_butt_on[1] = 1;
		if (G_V->event.key.keysym.sym == G_V->M.if1.tab_settings[1])
			G_V->Is_butt_on[2] = 1;
		if (G_V->event.key.keysym.sym == G_V->M.if1.tab_settings[0])
			G_V->Is_butt_on[3] = 1;
		if (G_V->event.key.keysym.sym == SDLK_RETURN)
			G_V->Is_butt_on[4] = 1;
		if (G_V->event.key.keysym.sym == SDLK_ESCAPE)
			G_V->Is_butt_on[5] = 1;
		if (G_V->event.key.keysym.sym == SDLK_SPACE)
			G_V->Is_butt_on[6] = 1;
		break;
	case SDL_KEYUP:
		if (G_V->event.key.keysym.sym == G_V->M.if1.tab_settings[2])
			G_V->Is_butt_on[0] = 0;
		if (G_V->event.key.keysym.sym == G_V->M.if1.tab_settings[3])
			G_V->Is_butt_on[1] = 0;
		if (G_V->event.key.keysym.sym ==G_V->M.if1.tab_settings[1])
			G_V->Is_butt_on[2] = 0;
		if (G_V->event.key.keysym.sym == G_V->M.if1.tab_settings[0])
			G_V->Is_butt_on[3] = 0;
		if (G_V->event.key.keysym.sym == SDLK_RETURN)
			G_V->Is_butt_on[4] = 0;
		if (G_V->event.key.keysym.sym == SDLK_ESCAPE)
			G_V->Is_butt_on[5] = 0;
		if (G_V->event.key.keysym.sym == SDLK_SPACE)
			G_V->Is_butt_on[6] = 0;
		break;
	}
	}
}

void freesurface(GLOBAL_VARS *G_V)
{
	SDL_FreeSurface(G_V->NG.new_g.img);
	SDL_FreeSurface(G_V->M.img_BK[0].img);
	SDL_FreeSurface(G_V->M.img_BK[1].img);
	SDL_FreeSurface(G_V->M.img_BK[2].img);
	SDL_FreeSurface(G_V->M.img_BK[3].img);
	SDL_FreeSurface(G_V->M.img_BK[4].img);
	SDL_FreeSurface(G_V->M.img_BK[5].img);
	SDL_FreeSurface(G_V->M.img_BK[6].img);
	SDL_FreeSurface(G_V->M.img_BK[7].img);
	SDL_FreeSurface(G_V->M.img_BK[8].img);
	SDL_FreeSurface(G_V->M.img_BK[9].img);
	SDL_FreeSurface(G_V->M.img_BK[10].img);
	SDL_FreeSurface(G_V->M.img_BK[11].img);
	SDL_FreeSurface(G_V->M.img_BK[12].img);
	SDL_FreeSurface(G_V->M.img_BK[13].img);
	SDL_FreeSurface(G_V->M.img_BK[14].img);
	SDL_FreeSurface(G_V->M.img_BK[15].img);
	SDL_FreeSurface(G_V->M.img_BK[16].img);
	SDL_FreeSurface(G_V->M.img_BK[17].img);
	SDL_FreeSurface(G_V->M.img_BK[18].img);
	SDL_FreeSurface(G_V->M.img_BK[19].img);
	SDL_FreeSurface(G_V->M.img_BK[20].img);
	SDL_FreeSurface(G_V->M.img_BK[21].img);
	SDL_FreeSurface(G_V->M.img_BK[22].img);
	SDL_FreeSurface(G_V->M.img_BK[23].img);
	SDL_FreeSurface(G_V->M.img_BK[24].img);
	SDL_FreeSurface(G_V->M.img_BK[25].img);
	SDL_FreeSurface(G_V->M.img_BK[26].img);
	SDL_FreeSurface(G_V->M.img_BK[27].img);
	SDL_FreeSurface(G_V->M.img_BK[28].img);
	SDL_FreeSurface(G_V->M.img_BK[29].img);
	SDL_FreeSurface(G_V->M.img_BK[30].img);
	SDL_FreeSurface(G_V->M.img_BK[31].img);


	SDL_FreeSurface(G_V->O.op1[3].img);
	SDL_FreeSurface(G_V->O.op1[2].img);
	SDL_FreeSurface(G_V->O.op1[1].img);
	SDL_FreeSurface(G_V->O.op1[0].img);
	SDL_FreeSurface(G_V->O.op[13].img);
	SDL_FreeSurface(G_V->O.op[12].img);
	SDL_FreeSurface(G_V->O.op[11].img);
	SDL_FreeSurface(G_V->O.op[10].img);
	SDL_FreeSurface(G_V->O.op[9].img);
	SDL_FreeSurface(G_V->O.op[8].img);
	SDL_FreeSurface(G_V->O.op[7].img);
	SDL_FreeSurface(G_V->O.op[5].img);
	SDL_FreeSurface(G_V->O.op[4].img);
	SDL_FreeSurface(G_V->O.op[3].img);
	SDL_FreeSurface(G_V->O.op[2].img);
	SDL_FreeSurface(G_V->O.op[1].img);
	SDL_FreeSurface(G_V->O.op[0].img);
	SDL_FreeSurface(G_V->M.butt[0].img);
	SDL_FreeSurface(G_V->M.butt[1].img);
	SDL_FreeSurface(G_V->M.butt[2].img);
	SDL_FreeSurface(G_V->NG.b.b_k[0].img);
	SDL_FreeSurface(G_V->NG.b.b_k[1].img);
	SDL_FreeSurface(G_V->NG.b.b_k[2].img);
	SDL_FreeSurface(G_V->NG.b.b_k[3].img);
	SDL_FreeSurface(G_V->NG.b.b_k[4].img);
	SDL_FreeSurface(G_V->NG.b.b_k[5].img);
	SDL_FreeSurface(G_V->NG.b_cafe.b_k[0].img);
	SDL_FreeSurface(G_V->NG.b_cafe.b_k[1].img);
	SDL_FreeSurface(G_V->NG.b_cafe.b_k[5].img);
	SDL_FreeSurface(G_V->NG.b_home.b_k[0].img);
	SDL_FreeSurface(G_V->NG.b_home.b_k[1].img);
	SDL_FreeSurface(G_V->NG.b_home.b_k[5].img);
	SDL_FreeSurface(G_V->NG.b_market.b_k[0].img);
	SDL_FreeSurface(G_V->NG.b_market.b_k[1].img);
	SDL_FreeSurface(G_V->NG.b_market.b_k[5].img);

	SDL_FreeSurface(G_V->NG.e1.img[0]);
	SDL_FreeSurface(G_V->NG.e1.img[1]);
	SDL_FreeSurface(G_V->NG.e1.img[2]);
	SDL_FreeSurface(G_V->NG.e1.img[3]);
	SDL_FreeSurface(G_V->NG.e1.img[4]);
	SDL_FreeSurface(G_V->NG.e1.img[5]);
	SDL_FreeSurface(G_V->NG.e1.img[6]);
	SDL_FreeSurface(G_V->NG.e1.img[7]);
	SDL_FreeSurface(G_V->NG.e1.img[8]);
	SDL_FreeSurface(G_V->NG.e1.img[9]);
	SDL_FreeSurface(G_V->NG.e1.img[10]);
	SDL_FreeSurface(G_V->NG.e1.img[11]);
	SDL_FreeSurface(G_V->NG.e1.img[12]);
	SDL_FreeSurface(G_V->NG.e1.img[13]);
	SDL_FreeSurface(G_V->NG.e1.img[14]);
	SDL_FreeSurface(G_V->NG.e1.img[15]);
	SDL_FreeSurface(G_V->NG.e_AI.img[0]);
	SDL_FreeSurface(G_V->NG.e_AI.img[1]);
	SDL_FreeSurface(G_V->NG.e_AI.img[2]);
	SDL_FreeSurface(G_V->NG.e_AI.img[3]);
	SDL_FreeSurface(G_V->NG.e_AI.img[4]);
	SDL_FreeSurface(G_V->NG.e_AI.img[5]);
	SDL_FreeSurface(G_V->NG.e_AI.img[6]);
	SDL_FreeSurface(G_V->NG.e_AI.img[7]);
	SDL_FreeSurface(G_V->NG.e_AI.img[8]);
	SDL_FreeSurface(G_V->NG.e_AI.img[9]);
	SDL_FreeSurface(G_V->NG.e_AI.img[10]);
	SDL_FreeSurface(G_V->NG.e_AI.img[11]);
	SDL_FreeSurface(G_V->NG.e_AI.img[12]);
	SDL_FreeSurface(G_V->NG.e_AI.img[13]);
	SDL_FreeSurface(G_V->NG.e_AI.img[14]);
	SDL_FreeSurface(G_V->NG.e_AI.img[15]);
	SDL_FreeSurface(G_V->NG.e_cafe[0].cafe_img.img);
	SDL_FreeSurface(G_V->NG.e_cafe[1].cafe_img.img);
	SDL_FreeSurface(G_V->NG.e_cafe[2].cafe_img.img);
	SDL_FreeSurface(G_V->NG.e_cafe[3].cafe_img.img);
	SDL_FreeSurface(G_V->NG.e_cafe[4].cafe_img.img);

	SDL_FreeSurface(G_V->bubbles[0].img);
	SDL_FreeSurface(G_V->bubbles[1].img);
	SDL_FreeSurface(G_V->bubbles[2].img);
	SDL_FreeSurface(G_V->bubbles[3].img);
	SDL_FreeSurface(G_V->bubbles[4].img);
	SDL_FreeSurface(G_V->bubbles[5].img);
	SDL_FreeSurface(G_V->bubbles[6].img);
	SDL_FreeSurface(G_V->bubbles[7].img);
	SDL_FreeSurface(G_V->bubbles[8].img);
	SDL_FreeSurface(G_V->bubbles[9].img);
	SDL_FreeSurface(G_V->bubbles[10].img);
	SDL_FreeSurface(G_V->bubbles[11].img);

	SDL_FreeSurface(G_V->NG.e_txt.end[0].img);
	SDL_FreeSurface(G_V->NG.e_txt.end[1].img);
	SDL_FreeSurface(G_V->NG.p.image[0].img);
	SDL_FreeSurface(G_V->NG.p.image[1].img);


	for(int i=0;i<173;i++)
		SDL_FreeSurface(G_V->cematiques[i].img);
}

void blit_all(SDL_Surface *wind, int n, ...)
{
	va_list args;
	va_start(args, n);
	IMAGE *s;
	for (int i = 0; i < n; i++)
	{
		s = va_arg(args, IMAGE *);
		SDL_BlitSurface(s->img, NULL, wind, &s->pos1);
	}
	va_end(args);
}

void sauve(INFO *if1, char *chemin)
{
	FILE *file;
	file = fopen(chemin, "w+b");
	fwrite(if1, sizeof(INFO), 1, file);
	fclose(file);
}

void reception_info(INFO *if1, char *chemin)
{
	FILE *file;
	file = fopen(chemin, "r+b");
	while (!feof(file))
	{
		fread(if1, sizeof(INFO), 1, file);
	}
}

void screen_mode(GLOBAL_VARS *G_V)
{
	switch (G_V->M.if1.screenmode)
	{
	case 1:
		G_V->W = 1282;
		G_V->H = 720;

		G_V->NG.b.the_chosen = 1;
		G_V->NG.b.W = G_V->W;
		G_V->NG.b.H = G_V->H;
		
		G_V->NG.b_cafe.the_chosen = 2;
		G_V->NG.b_cafe.W = G_V->W;
		G_V->NG.b_cafe.H = G_V->H;

		G_V->NG.b_market.the_chosen = 3;
		G_V->NG.b_market.W = G_V->W;
		G_V->NG.b_market.H = G_V->H;

		G_V->NG.b_home.the_chosen = 4;
		G_V->NG.b_home.W = G_V->W;
		G_V->NG.b_home.H = G_V->H;

		G_V->NG.m.H = G_V->H;
		G_V->NG.m.W = G_V->W;
		G_V->NG.e_txt.H = G_V->H;
		G_V->NG.e_txt.W = G_V->W;
		G_V->NG.e_ph.H = G_V->H;
		G_V->NG.e_ph.W = G_V->W;
		G_V->NG.e1.H = G_V->H;
		G_V->NG.e1.W = G_V->W;
		G_V->NG.e1.the_chosen = 1;
		G_V->NG.e_AI.H = G_V->H;
		G_V->NG.e_AI.W = G_V->W;
		G_V->NG.e_AI.the_chosen = 4;
		// cafe characters
		G_V->NG.e_cafe[0].the_chosen = 6;
		G_V->NG.e_cafe[0].H = G_V->H;
		G_V->NG.e_cafe[0].W = G_V->W;
		G_V->NG.e_cafe[0].real_pos.x = 550;
		G_V->NG.e_cafe[0].real_pos.y = 525;
		G_V->NG.e_cafe[0].MV_destance[0] = 0;
		G_V->NG.e_cafe[0].MV_destance[1] = 0;
		G_V->NG.e_cafe[0].derection = 3;
		G_V->NG.e_cafe[0].func_num = 1;
		G_V->NG.e_cafe[0].coll_derection = 0;
		G_V->NG.e_cafe[0].stay = 0;

		G_V->NG.e_cafe[1].the_chosen = 7;
		G_V->NG.e_cafe[1].H = G_V->H;
		G_V->NG.e_cafe[1].W = G_V->W;
		G_V->NG.e_cafe[1].real_pos.x = 500;
		G_V->NG.e_cafe[1].real_pos.y = 600;
		G_V->NG.e_cafe[1].MV_destance[0] = 0;
		G_V->NG.e_cafe[1].MV_destance[1] = 0;
		G_V->NG.e_cafe[1].derection = 3;
		G_V->NG.e_cafe[1].func_num = 1;
		G_V->NG.e_cafe[1].coll_derection = 0;
		G_V->NG.e_cafe[1].stay = 0;

		G_V->NG.e_cafe[2].the_chosen = 8;
		G_V->NG.e_cafe[2].H = G_V->H;
		G_V->NG.e_cafe[2].W = G_V->W;
		G_V->NG.e_cafe[2].real_pos.x = 855;
		G_V->NG.e_cafe[2].real_pos.y = 880;
		G_V->NG.e_cafe[2].MV_destance[0] = 0;
		G_V->NG.e_cafe[2].MV_destance[1] = 0;
		G_V->NG.e_cafe[2].derection = 1;
		G_V->NG.e_cafe[2].func_num = 1;
		G_V->NG.e_cafe[2].coll_derection = 0;
		G_V->NG.e_cafe[2].stay = 0;

		G_V->NG.e_cafe[3].the_chosen = 9;
		G_V->NG.e_cafe[3].H = G_V->H;
		G_V->NG.e_cafe[3].W = G_V->W;
		G_V->NG.e_cafe[3].real_pos.x = 1420;
		G_V->NG.e_cafe[3].real_pos.y = 670;
		G_V->NG.e_cafe[3].MV_destance[0] = 0;
		G_V->NG.e_cafe[3].MV_destance[1] = 0;
		G_V->NG.e_cafe[3].derection = 1;
		G_V->NG.e_cafe[3].func_num = 1;
		G_V->NG.e_cafe[3].coll_derection = 0;
		G_V->NG.e_cafe[3].stay = 0;

		G_V->NG.e_cafe[4].the_chosen = 10;
		G_V->NG.e_cafe[4].H = G_V->H;
		G_V->NG.e_cafe[4].W = G_V->W;
		G_V->NG.e_cafe[4].real_pos.x = 1230;
		G_V->NG.e_cafe[4].real_pos.y = 378;
		G_V->NG.e_cafe[4].MV_destance[0] = 0;
		G_V->NG.e_cafe[4].MV_destance[1] = 0;
		G_V->NG.e_cafe[4].derection = 1;
		G_V->NG.e_cafe[4].func_num = 1;
		G_V->NG.e_cafe[4].coll_derection = 0;
		G_V->NG.e_cafe[4].stay = 0;

		G_V->NG.e_cafe[5].the_chosen = 11;
		G_V->NG.e_cafe[5].H = G_V->H;
		G_V->NG.e_cafe[5].W = G_V->W;
		G_V->NG.e_cafe[5].real_pos.x = 850;
		G_V->NG.e_cafe[5].real_pos.y = 600;
		G_V->NG.e_cafe[5].MV_destance[0] = 0;
		G_V->NG.e_cafe[5].MV_destance[1] = 0;
		G_V->NG.e_cafe[5].derection = 1;
		G_V->NG.e_cafe[5].func_num = 1;
		G_V->NG.e_cafe[5].coll_derection = 0;
		G_V->NG.e_cafe[5].stay = 0;

		load(G_V->M.img_BK, G_V->M.butt, G_V->H, G_V->W,0);
		opload(G_V->O.op, G_V->O.op1, G_V->O.op_kl, G_V->H, G_V->W,0);
		//rectinit(G_V->M.R_Pos, G_V->M.R_Pos1, G_V->M.R_Pos2, G_V->M.butt, G_V->O.op, G_V->O.op1);
		load_cematiques(G_V,0);
		initanimation(G_V->M.img_BK);
		inittxt(&G_V->M.txt, G_V->H, G_V->W);
		initBack(&G_V->NG.b);
		initBack(&G_V->NG.b_cafe);
		initBack(&G_V->NG.b_market);
		initBack(&G_V->NG.b_home);
		initPerso(&G_V->NG.p);
		initminimap(&G_V->NG.m);
		InitEnigme(&G_V->NG.e_txt, "ing_txt/answer.txt");
		InitEnigme_ph(&G_V->NG.e_ph, "ing_ph/data.txt");
		intitEnnemi(&G_V->NG.e1);
		intitEnnemi(&G_V->NG.e_AI);
		intitEnnemi(&G_V->NG.e_cafe[0]);
		intitEnnemi(&G_V->NG.e_cafe[1]);
		intitEnnemi(&G_V->NG.e_cafe[2]);
		intitEnnemi(&G_V->NG.e_cafe[3]);
		intitEnnemi(&G_V->NG.e_cafe[4]);
		intitEnnemi(&G_V->NG.e_cafe[5]);
		init_bubble(G_V,0);
		load_trailer(G_V);
		G_V->window = SDL_SetVideoMode(G_V->W, G_V->H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		G_V->M.if1.screenmode = 3333;
		break;
	case 0:
		G_V->W = 1920;
		G_V->H = 1080;
		G_V->NG.b.the_chosen = 1;
		G_V->NG.b.W = G_V->W;
		G_V->NG.b.H = G_V->H;
		G_V->NG.b_cafe.the_chosen = 2;
		G_V->NG.b_cafe.W = G_V->W;
		G_V->NG.b_cafe.H = G_V->H;

		G_V->NG.b_market.the_chosen = 3;
		G_V->NG.b_market.W = G_V->W;
		G_V->NG.b_market.H = G_V->H;

		G_V->NG.b_home.the_chosen = 4;
		G_V->NG.b_home.W = G_V->W;
		G_V->NG.b_home.H = G_V->H;

		G_V->NG.m.H = G_V->H;
		G_V->NG.m.W = G_V->W;
		G_V->NG.e_txt.H = G_V->H;
		G_V->NG.e_txt.W = G_V->W;
		G_V->NG.e_ph.H = G_V->H;
		G_V->NG.e_ph.W = G_V->W;
		G_V->NG.e1.H = G_V->H;
		G_V->NG.e1.W = G_V->W;
		G_V->NG.e1.the_chosen = 1;
		G_V->NG.e_AI.H = G_V->H;
		G_V->NG.e_AI.W = G_V->W;
		G_V->NG.e_AI.the_chosen = 4;
		// cafe characters
		G_V->NG.e_cafe[0].the_chosen = 6;
		G_V->NG.e_cafe[0].H = G_V->H;
		G_V->NG.e_cafe[0].W = G_V->W;
		G_V->NG.e_cafe[0].real_pos.x = 550;
		G_V->NG.e_cafe[0].real_pos.y = 425;
		G_V->NG.e_cafe[0].MV_destance[0] = 0;
		G_V->NG.e_cafe[0].MV_destance[1] = 0;
		G_V->NG.e_cafe[0].derection = 1;
		G_V->NG.e_cafe[0].func_num = 1;
		G_V->NG.e_cafe[0].coll_derection = 0;
		G_V->NG.e_cafe[0].stay = 0;

		G_V->NG.e_cafe[1].the_chosen = 7;
		G_V->NG.e_cafe[1].H = G_V->H;
		G_V->NG.e_cafe[1].W = G_V->W;
		G_V->NG.e_cafe[1].real_pos.x = 500;
		G_V->NG.e_cafe[1].real_pos.y = 500;
		G_V->NG.e_cafe[1].MV_destance[0] = 0;
		G_V->NG.e_cafe[1].MV_destance[1] = 0;
		G_V->NG.e_cafe[1].derection = 1;
		G_V->NG.e_cafe[1].func_num = 1;
		G_V->NG.e_cafe[1].coll_derection = 0;
		G_V->NG.e_cafe[1].stay = 0;

		G_V->NG.e_cafe[2].the_chosen = 8;
		G_V->NG.e_cafe[2].H = G_V->H;
		G_V->NG.e_cafe[2].W = G_V->W;
		G_V->NG.e_cafe[2].real_pos.x = 855;
		G_V->NG.e_cafe[2].real_pos.y = 880;
		G_V->NG.e_cafe[2].MV_destance[0] = 0;
		G_V->NG.e_cafe[2].MV_destance[1] = 0;
		G_V->NG.e_cafe[2].derection = 1;
		G_V->NG.e_cafe[2].func_num = 1;
		G_V->NG.e_cafe[2].coll_derection = 0;
		G_V->NG.e_cafe[2].stay = 0;

		G_V->NG.e_cafe[3].the_chosen = 9;
		G_V->NG.e_cafe[3].H = G_V->H;
		G_V->NG.e_cafe[3].W = G_V->W;
		G_V->NG.e_cafe[3].real_pos.x = 1420;
		G_V->NG.e_cafe[3].real_pos.y = 670;
		G_V->NG.e_cafe[3].MV_destance[0] = 0;
		G_V->NG.e_cafe[3].MV_destance[1] = 0;
		G_V->NG.e_cafe[3].derection = 1;
		G_V->NG.e_cafe[3].func_num = 1;
		G_V->NG.e_cafe[3].coll_derection = 0;
		G_V->NG.e_cafe[3].stay = 0;

		G_V->NG.e_cafe[4].the_chosen = 10;
		G_V->NG.e_cafe[4].H = G_V->H;
		G_V->NG.e_cafe[4].W = G_V->W;
		G_V->NG.e_cafe[4].real_pos.x = 1230;
		G_V->NG.e_cafe[4].real_pos.y = 378;
		G_V->NG.e_cafe[4].MV_destance[0] = 0;
		G_V->NG.e_cafe[4].MV_destance[1] = 0;
		G_V->NG.e_cafe[4].derection = 1;
		G_V->NG.e_cafe[4].func_num = 1;
		G_V->NG.e_cafe[4].coll_derection = 0;
		G_V->NG.e_cafe[4].stay = 0;

		G_V->NG.e_cafe[5].the_chosen = 11;
		G_V->NG.e_cafe[5].H = G_V->H;
		G_V->NG.e_cafe[5].W = G_V->W;
		G_V->NG.e_cafe[5].real_pos.x = 850;
		G_V->NG.e_cafe[5].real_pos.y = 600;
		G_V->NG.e_cafe[5].MV_destance[0] = 0;
		G_V->NG.e_cafe[5].MV_destance[1] = 0;
		G_V->NG.e_cafe[5].derection = 1;
		G_V->NG.e_cafe[5].func_num = 1;
		G_V->NG.e_cafe[5].coll_derection = 0;
		G_V->NG.e_cafe[5].stay = 0;

		load(G_V->M.img_BK, G_V->M.butt, G_V->H, G_V->W,0);
		opload(G_V->O.op, G_V->O.op1, G_V->O.op_kl, G_V->H, G_V->W,0);
		//rectinit(G_V->M.R_Pos, G_V->M.R_Pos1, G_V->M.R_Pos2, G_V->M.butt, G_V->O.op, G_V->O.op1);
		load_cematiques(G_V,0);
		initanimation(G_V->M.img_BK);
		inittxt(&G_V->M.txt, G_V->H, G_V->W);
		initBack(&G_V->NG.b);
		initBack(&G_V->NG.b_cafe);
		initBack(&G_V->NG.b_market);
		initBack(&G_V->NG.b_home);
		initPerso(&G_V->NG.p);
		initminimap(&G_V->NG.m);
		InitEnigme(&G_V->NG.e_txt, "ing_txt/answer.txt");
		InitEnigme_ph(&G_V->NG.e_ph, "ing_ph/data.txt");
		intitEnnemi(&G_V->NG.e1);
		intitEnnemi(&G_V->NG.e_AI);
		intitEnnemi(&G_V->NG.e_cafe[0]);
		intitEnnemi(&G_V->NG.e_cafe[1]);
		intitEnnemi(&G_V->NG.e_cafe[2]);
		intitEnnemi(&G_V->NG.e_cafe[3]);
		intitEnnemi(&G_V->NG.e_cafe[4]);
		intitEnnemi(&G_V->NG.e_cafe[5]);
		init_bubble(G_V,0);
		//load_trailer(G_V);
		G_V->window = SDL_SetVideoMode(G_V->W, G_V->H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		G_V->M.if1.screenmode = 3333;
		break;
	}
}

int is_in_rect(int x1, int y1, SDL_Rect pos1)
{
	if (x1 > pos1.x && x1 < pos1.x + pos1.w && y1 > pos1.y && y1 < pos1.y + pos1.h)
		return 1;
	return 0;
}

void initanimation(IMAGE *img)
{
	img[0].pos1.x = 0;
	img[0].pos1.y = 0;
	img[1].pos1 = img[0].pos1;
}


void animation(SDL_Surface *wind,IMAGE *img,int *i,int *count){
    SHOWALLIMG(&img[*i],wind);
	
	(*count)++;
	if(*count%2==0){
		(*i)++;
		*count=0;
	}
    if((*i)==32) (*i)=0;
    }
// -------->>>>>TEXT<<<<<<---------------

void inittxt(TEXT *t1, int H, int W)
{
	t1->postxt.x = W * 0.54;
	t1->postxt.y = H * 0.86;
	t1->postxt.w = W * 0.08;
	t1->postxt.h = H * 0.14;
	t1->col.r = 0;
	t1->col.g = 0;
	t1->col.b = 0;
}

void SHOWTXT(TEXT *t1, SDL_Surface *wind, char *l)
{
	t1->windtxt = TTF_RenderText_Blended(t1->font, l, t1->col);
	SDL_BlitSurface(t1->windtxt, NULL, wind, &t1->postxt);
}

// -------->>>>>ardouino part <<<<<<---------------

int arduinoWriteData(int x)
{
	char chemin[] = "/dev/ttyUSB0";
	FILE *f;

	f = fopen(chemin, "w");
	if (f == NULL)
		return (-1);

	fprintf(f, "%d", x);
	fclose(f);

	return (0);
}

int arduinoReadData(int *x)
{
	char chemin[] = "/dev/ttyUSB0";
	FILE *f;
	char c;
	f = fopen(chemin, "r");

	if (f == NULL)
		return (-1);

	fscanf(f, "%d", x);
	printf("x %d\n", *x);
	printf("omar\n");

	fclose(f);

	return (0);
}

void init_bubble(GLOBAL_VARS *G_V,int o)
{
	char names[2][30][40]={{
	"./bubble/cafe2/coffe1.png"//0
	,"./bubble/cafe2/coffe2.png"//1
	,"./bubble/cafe2/coffe3.png"//2
	,"./bubble/cafe2/coffe4.png"//3
	,"./bubble/cafe2/coffe5.png"//4
	,"./bubble/cafe2/coffe6.png"//5
	,"./bubble/home2/1.png"//6
	,"./bubble/home2/2.png"//7
	,"./bubble/home2/3.png"//8
	,"./bubble/home2/4.png"//9
	,"./bubble/home2/5.png"//10
	,"./bubble/home2/6.png"//11
	,"./bubble/cafe2/collbb_bbubble/1.png"//12
	,"./bubble/cafe2/collbb_bbubble/2.png"//13
	,"./bubble/cafe2/collbb_bbubble/3.png"//14
	,"./bubble/cafe2/collbb_bbubble/4.png"//15
	,"./bubble/cafe2/collbb_bbubble/5.png"//16
	,"./bubble/cafe2/collbb_bbubble/6.png"//17
	,"./bubble/cafe2/collbb_bbubble/7.png"//18
	,"./bubble/cafe2/collbb_bbubble/8.png"//19
	,"./bubble/cafe2/collbb_bbubble/9.png"//20
	,"./bubble/cafe2/collbb_bbubble/10.png"	//21
	}
	,{"./bubble/cafe_full_screen/coffe1.png","./bubble/cafe_full_screen/coffe2.png","./bubble/cafe_full_screen/coffe3.png","./bubble/cafe_full_screen/coffe4.png"
	"./bubble/cafe_full_screen/coffe5.png","./bubble/cafe_full_screen/coffe6.png","./bubble/home_full_screen/1.png","./bubble/home_full_screen/2.png","./bubble/home_full_screen/3.png",
	"./bubble/home_full_screen/4.png","./bubble/home_full_screen/5.png","./bubble/home_full_screen/6.png"}};
	G_V->bubbles[0].img = IMG_Load(names[o][0]);
	G_V->bubbles[1].img = IMG_Load(names[o][1]);
	G_V->bubbles[2].img = IMG_Load(names[o][2]);
	G_V->bubbles[3].img = IMG_Load(names[o][3]);
	G_V->bubbles[4].img = IMG_Load(names[o][4]);
	G_V->bubbles[5].img = IMG_Load(names[o][5]);

	G_V->bubbles[6].img = IMG_Load(names[o][6]);
	G_V->bubbles[7].img = IMG_Load(names[o][7]);
	G_V->bubbles[8].img = IMG_Load(names[o][8]);
	G_V->bubbles[9].img = IMG_Load(names[o][9]);
	G_V->bubbles[10].img = IMG_Load(names[o][10]);
	G_V->bubbles[11].img = IMG_Load(names[o][11]);

	G_V->bubbles[12].img = IMG_Load(names[o][12]);
	G_V->bubbles[13].img = IMG_Load(names[o][13]);
	G_V->bubbles[14].img = IMG_Load(names[o][14]);
	G_V->bubbles[15].img = IMG_Load(names[o][15]);
	G_V->bubbles[16].img = IMG_Load(names[o][16]);
	G_V->bubbles[17].img = IMG_Load(names[o][17]);

	G_V->bubbles[18].img = IMG_Load(names[o][18]);
	G_V->bubbles[19].img = IMG_Load(names[o][19]);
	G_V->bubbles[20].img = IMG_Load(names[o][20]);
	G_V->bubbles[21].img = IMG_Load(names[o][21]);
	//printf("%s\n",IMG_GetError());
	//G_V->bubbles[22].img = IMG_Load(names[o][22]);
}

void show_bubble(GLOBAL_VARS *G_V, Ennemi e, int n)
{
	static int count=0,z=6;
	int x = 3; // rand()%6+2;
	int y=1;
	if (n == 1)
	{
		G_V->bubbles[y].pos1.x = G_V->NG.e_cafe[5].cafe_img.pos1.x + G_V->NG.e_cafe[5].cafe_img.pos2.w - 30;
		G_V->bubbles[y].pos1.y = G_V->NG.e_cafe[5].cafe_img.pos1.y - 50;
		if (G_V->NG.e_cafe[5].derection == 3){
			y = 0;
			G_V->bubbles[y].pos1.x  = G_V->NG.e_cafe[5].cafe_img.pos1.x -G_V->bubbles[y].img->w+30;
			G_V->bubbles[y].pos1.y = G_V->NG.e_cafe[5].cafe_img.pos1.y - G_V->bubbles[y].img->h+50;
		}
		else if(G_V->NG.e_cafe[5].derection != 3)
			y = 1;
		SDL_BlitSurface(G_V->bubbles[y].img, NULL, G_V->window, &G_V->bubbles[y].pos1);

		G_V->bubbles[x].pos1.x =e.cafe_img.pos1.x - G_V->bubbles[x].img->w;
		G_V->bubbles[x].pos1.y = e.cafe_img.pos1.y - G_V->bubbles[x].img->h + 30;
		if (e.derection == 2 && (x % 2) != 0){
			x++;
			G_V->bubbles[x].pos1.x = e.cafe_img.pos1.x +e.cafe_img.pos2.w;
			G_V->bubbles[x].pos1.y = e.cafe_img.pos1.y - G_V->bubbles[x].img->h+30;	
		}
		else if ((x % 2) == 0)
			x--;
		SDL_BlitSurface(G_V->bubbles[x].img, NULL, G_V->window, &G_V->bubbles[x].pos1);
	}
	else if (n == 2)
	{
		G_V->bubbles[y].pos1.x = G_V->NG.e_cafe[5].cafe_img.pos1.x + G_V->NG.e_cafe[5].cafe_img.pos2.w - 30;
		G_V->bubbles[y].pos1.y = G_V->NG.e_cafe[5].cafe_img.pos1.y - 50;
		if (G_V->NG.e_cafe[5].derection == 3){
			y = 0;
			G_V->bubbles[y].pos1.x  = G_V->NG.e_cafe[5].cafe_img.pos1.x -G_V->bubbles[y].img->w+30;
			G_V->bubbles[y].pos1.y = G_V->NG.e_cafe[5].cafe_img.pos1.y - G_V->bubbles[y].img->h+50;
		}
		else if(G_V->NG.e_cafe[5].derection != 3)
			y = 1;
		SDL_BlitSurface(G_V->bubbles[y].img, NULL, G_V->window, &G_V->bubbles[y].pos1);



		G_V->bubbles[x].pos1.x = G_V->NG.p.image[G_V->NG.p.where].pos1.x - G_V->bubbles[x].img->w;
		G_V->bubbles[x].pos1.y = G_V->NG.p.image[G_V->NG.p.where].pos1.y - G_V->bubbles[x].img->h + 30;
		if (G_V->NG.p.derec == 4 && (x % 2) != 0){
			x++;
			G_V->bubbles[x].pos1.x = G_V->NG.p.image[G_V->NG.p.where].pos1.x +G_V->NG.p.image[G_V->NG.p.where].pos2.w;
			G_V->bubbles[x].pos1.y = G_V->NG.p.image[G_V->NG.p.where].pos1.y - G_V->bubbles[x].img->h+30;	
		}	
		else if ((x % 2) == 0)
			x--;	
		SDL_BlitSurface(G_V->bubbles[x].img, NULL, G_V->window, &G_V->bubbles[x].pos1);
	}
	else if(n==3){
		count++;

		if(count%50==0){
			count=0;
			z+=2;
		}
		if(z+1>11)
			z=6;
		G_V->bubbles[z].pos1.x =e.cafe_img.pos1.x +e.cafe_img.img->w/4;
		G_V->bubbles[z].pos1.y = e.cafe_img.pos1.y - G_V->bubbles[z].img->h + 100;
		SDL_BlitSurface(G_V->bubbles[z].img, NULL, G_V->window, &G_V->bubbles[z].pos1);

		G_V->bubbles[z+1].pos1.x = G_V->NG.p.image[G_V->NG.p.where].pos1.x - G_V->bubbles[z+1].img->w-20;
		G_V->bubbles[z+1].pos1.y = G_V->NG.p.image[G_V->NG.p.where].pos1.y - G_V->bubbles[z+1].img->h + 50;
		SDL_BlitSurface(G_V->bubbles[z+1].img, NULL, G_V->window, &G_V->bubbles[z+1].pos1);
	}
}



void load_trailer(GLOBAL_VARS *G_V){
	FILE *file=NULL;
	char hold[100];
	file=fopen("./ph.txt","r");
	for(int i=0;i<900;i++){
		fscanf(file,"%s\n",hold);
		G_V->M.start[i].img=IMG_Load(hold);
	}
}





//feres fonctions

void randomPosition(int xmin,int xmax,int ymin,int ymax,int *x, int *y)
{ 
    //srand(time(NULL));
    *x=rand()%(xmax-xmin)+xmin;

    *y=rand()%(ymax-ymin)+ymin;

}
void animateOnce(IMAGE *i,int *animated,int *x)
{
    
    if(i->pos2.x>i->pos1.w)
    {
        i->pos2.x=0;
        *animated=1;
        *x=0;
    }
    

    if(!*animated) i->pos2.x+=i->pos2.w;


}

void initObstacle(obstacle *ob,char *path ,int w,int colone,int h,int ligne)
{
	ob->img.img=IMG_Load(path);
	ob->img.pos1.w=w;
	ob->img.pos1.h=h;
	ob->img.pos2.x=0;
	ob->img.pos2.w=w/colone;
	ob->img.pos2.h=h/ligne;

	ob->animated=1;
	ob->realx=0;
	ob->realy=0;
}
void spawnObstacle(obstacle *ob,SDL_Rect camera,int minX,int maxX,int minY,int maxY)
{
	if (camera.x < 14720 - maxX && ob->realx < camera.x || ob->img.pos1.x > maxX)
        {
            randomPosition(camera.x + minX, camera.x + maxX, minY, maxY, &ob->realx, &ob->realy);
        }
                    ob->img.pos1.x = ob->realx - camera.x;
                    ob->img.pos1.y = ob->realy;
					
}

void takeDamage(int x,int y, SDL_Rect pos,obstacle *ob,int *px,int distance,int *invin,int *hitTime,int *hit,int *stamina)
{
	if (is_in_rect(x, y + 35, pos))
                    {
                        if (ob->animated)
                            *px -= distance;
                        ob->animated = 0;
						*hitTime=SDL_GetTicks();
						*invin=1;
						*hit=1;
						*stamina-=500;
                    }
}
void initProjectile(projectile *pr,char *path ,int w,int colone, int h,int type)
{
	pr->img.img=IMG_Load(path);
	pr->img.pos1.w=w;
	pr->img.pos1.h=h;
	pr->img.pos2.x=0;
	pr->img.pos2.w=w/colone;
	pr->img.pos2.h=h;

	pr->animated=1;
	pr->realx=0;
	pr->realy=0;

	pr->type=type;
	pr->thrown=0;
}
void spawnProjectile(projectile *pr,SDL_Rect camera,int minX,int maxX,int minY,int maxY)
{
	if (camera.x < 14720 - maxX && pr->realx < camera.x || pr->img.pos1.x > maxX)
        {
            randomPosition(camera.x + minX, camera.x + maxX, minY, maxY, &pr->realx, &pr->realy);
        }
                    pr->img.pos1.x = pr->realx - camera.x;
                    pr->img.pos1.y = pr->realy;
}
void throwProjectile(Personne *p,projectile *pr)
{
	int x,y;
	static int distancex,distancey,time0,time1=0;
	static float a;
	if(!pr->thrown)
	{
		if(p->panana!=0)
		{
		SDL_GetMouseState(&x,&y);
		distancex=(x-p->image[1].pos1.x);
		distancey=y-p->image[1].pos1.y;
		if(distancey>0) distancex=distancex/2;
		pr->img.pos2.x=0;
		pr->realy=p->image[1].pos1.y+30;
		pr->realx=-distancex;
		pr->img.pos1.x=p->image[1].pos1.x+30;
		pr->img.pos1.y=p->image[1].pos1.y+30;
		
		if (distancex !=0) a=(float)abs(distancey)/(distancex*distancex);
		}else {pr->img.pos1.x=9999;pr->img.pos1.y=9999;}
		
		
	}
	else
	{
		if(!Mix_Playing(1))
		Mix_PlayChannel(1,pr->bananaSound,0);
		if(p->panana>=0){
		if(distancex<0)
		{
			if(pr->img.pos1.y<700&&pr->img.pos1.x<1280&&pr->img.pos1.x>0)
			{   
				if(abs(distancex)>50){
				pr->realx-=3;
				pr->img.pos1.x-=3;
				}else {pr->realx-=1;pr->img.pos1.x-=1;}
				pr->img.pos1.y=pr->realy+a*pr->realx*pr->realx-abs(distancey);
				
			}else 
			{pr->thrown=0;Mix_HaltChannel(1);}
		}
		if(distancex>0&&pr->thrown)
		{
			if(pr->img.pos1.y<700&&pr->img.pos1.x<1280&&pr->img.pos1.x>0)
			{
				if(abs(distancex)>50)
				{
				pr->realx+=3;
				pr->img.pos1.x+=3;
				}else {pr->realx+=1;pr->img.pos1.x+=1;}
				pr->img.pos1.y=pr->realy+a*pr->realx*pr->realx-abs(distancey);
				
			}else 
			{pr->thrown=0;Mix_HaltChannel(1);}
		}

		if(distancex==0) pr->thrown=0;
		//Animation
		time0=SDL_GetTicks();
		if(time0-time1>50){
		if(pr->img.pos2.x<320-40)
		pr->img.pos2.x+=40; else pr->img.pos2.x=0;
		time1=time0;
		}

		}
	}
	
}


void pickUp(Personne *p,projectile *pr)
{
	if(is_in_rect(p->image[1].pos1.x+20,p->image[1].pos1.y+35,pr->img.pos1))
	{
			if(pr->type==1)
			 p->panana++;
			pr->realx=0;
	}
	else
	{
		if(is_in_rect(p->image[1].pos1.x+20,p->image[1].pos1.y,pr->img.pos1))
	{
			if(pr->type==1)
			 p->panana++;
			pr->realx=0;
	}
	else 
	{
		if(is_in_rect(p->image[1].pos1.x+20,p->image[1].pos1.y+70,pr->img.pos1))
	{
			if(pr->type==1)
			 p->panana++;
			pr->realx=0;
	}
	}
	}
}


void initPolice(police *po,int x,int y,int statue,int xSpeed,int ySpeed)
{
	po->img[0] = IMG_Load("./omar_backgounf/policeman/policeman1.png");
    po->img[1] = IMG_Load("./omar_backgounf/policeman/policeman2.png");
    po->img[2] = IMG_Load("./omar_backgounf/policeman/policeman3.png");
    po->img[3] = IMG_Load("./omar_backgounf/policeman/policeman4.png");
    po->img[4] = IMG_Load("./omar_backgounf/policeman/policeman5.png");
    po->img[5] = IMG_Load("./omar_backgounf/policeman/policeman6.png");
    po->img[6] = IMG_Load("./omar_backgounf/policeman/policeman7.png");
    po->img[7] = IMG_Load("./omar_backgounf/policeman/policeman8.png");
    po->img[8] = IMG_Load("./omar_backgounf/policeman/policeman9.png");
	po->invinImg[0]=IMG_Load("omar_backgounf/invins police/policeman1.png");
	po->invinImg[1]=IMG_Load("omar_backgounf/invins police/policeman2.png");
	po->invinImg[2]=IMG_Load("omar_backgounf/invins police/policeman3.png");
	po->invinImg[3]=IMG_Load("omar_backgounf/invins police/policeman4.png");
	po->invinImg[4]=IMG_Load("omar_backgounf/invins police/policeman5.png");
	po->invinImg[5]=IMG_Load("omar_backgounf/invins police/policeman6.png");
	po->invinImg[6]=IMG_Load("omar_backgounf/invins police/policeman7.png");
	po->invinImg[7]=IMG_Load("omar_backgounf/invins police/policeman8.png");
	po->invinImg[8]=IMG_Load("omar_backgounf/invins police/policeman9.png");
	po->hitImg=IMG_Load("omar_backgounf/hitpolice.png");
	po->tiredImg=IMG_Load("omar_backgounf/tired.png");
	po->hit=0;
	po->invin=0;
	po->pos1.x=x;
	po->pos1.y=y;
	po->frame=0;
	po->hp=5;
	po->xSpeed=xSpeed;
	po->ySpeed=ySpeed;
	po->hitTime=0;
	po->invinWindow=1000;
	po->resistanceBar=IMG_Load("omar_backgounf/resistance_0001_Layer-1.png");
	po->resistanceIMG=IMG_Load("omar_backgounf/resistance_0000_Layer-2.png");
	po->resistance=10000;
	po->resistancePos2.h=21;
	po->timeToMoveX=0;	
	po->timeToMoveY=0;
	po->inStandBy=statue;
	po->tired=0;
	po->stamina=2;
	po->catching=IMG_Load("omar_backgounf/police catching.png");
	po->deployTime=-1;


}
void movePolice(police *po,Personne p)
{

	 if(po->timeToMoveX==po->xSpeed){if(po->pos1.x<p.image[1].pos1.x) po->pos1.x++; else po->pos1.x--;po->timeToMoveX=0;}else po->timeToMoveX++;
	 if(po->timeToMoveY==po->ySpeed){if(po->pos1.y<p.image[1].pos1.y) po->pos1.y++; else po->pos1.y--;po->timeToMoveY=0;}else po->timeToMoveY++;
        
        
        
  
}

void callForBackUp(police *po1,police *po2,police *po3,police *po4)
{
	int s;
	if(po1->inStandBy&&po1->deployTime<0)
	{
		po1->deployTime=SDL_GetTicks()+rand()%25000+7000;
	}
	if(po2->inStandBy&&po2->deployTime<0)
	{
		po2->deployTime=SDL_GetTicks()+rand()%25000+7000;
	}
	if(po3->inStandBy&&po3->deployTime<0)
	{
		po3->deployTime=SDL_GetTicks()+rand()%25000+7000;
	}
	if(po4->inStandBy&&po4->deployTime<0)
	{
		po4->deployTime=SDL_GetTicks()+rand()%25000+7000;
	}
	
	if(po1->deployTime>0) 
	{
		s=SDL_GetTicks()-po1->deployTime;
		if(s>=0)
		{
		po1->deployTime=-1;
		po1->inStandBy=0;
		po2->deployTime=-1;
		po3->deployTime=-1;
		po4->deployTime=-1;
		Mix_PlayChannel(-1,po1->amBack,0);
		}
	}

	if(po2->deployTime>0) 
	{
		s=SDL_GetTicks()-po2->deployTime;
		if(s>=0)
		{
		po2->deployTime=-1;
		po2->inStandBy=0;
		po1->deployTime=-1;
		po3->deployTime=-1;
		po4->deployTime=-1;
		if(po2->stamina==2&&(!po1->inStandBy||!po4->inStandBy||!po3->inStandBy)) Mix_PlayChannel(-1,po1->needBackUp,0);
		else {if(po2->stamina!=2) Mix_PlayChannel(-1,po1->amBack,0);}
		}
	}

	if(po3->deployTime>0) 
	{
		s=SDL_GetTicks()-po3->deployTime;
		if(s>=0)
		{
		po3->deployTime=-1;
		po3->inStandBy=0;
		po1->deployTime=-1;
		po2->deployTime=-1;
		po4->deployTime=-1;
		if(po3->stamina==2&&(!po1->inStandBy||!po4->inStandBy||!po2->inStandBy)) Mix_PlayChannel(-1,po1->needBackUp,0);
		else {if(po3->stamina!=2) Mix_PlayChannel(-1,po1->amBack,0);}
		}
	}

	if(po4->deployTime>0) 
	{
		s=SDL_GetTicks()-po4->deployTime;
		if(s>=0)
		{
		po4->deployTime=-1;
		po4->inStandBy=0;
		po1->deployTime=-1;
		po2->deployTime=-1;
		po3->deployTime=-1;
		if(po4->stamina==2&&(!po1->inStandBy||!po2->inStandBy||!po3->inStandBy)) Mix_PlayChannel(-1,po1->needBackUp,0);
		else {if(po4->stamina!=2) Mix_PlayChannel(-1,po1->amBack,0);}
		}
	}
	
}

void animate_printPolice(police *po,SDL_Surface *screen)
{
	if(po->hit&&SDL_GetTicks()-po->hitTime<300){
	SDL_BlitSurface(po->hitImg,NULL,screen,&po->pos1);
	
	
	}
	else {
	po->hit=0;
	if(po->frame>=8) po->frame=0;
	
	else po->frame++;
	if(po->invin)
	SDL_BlitSurface(po->invinImg[po->frame],NULL,screen,&po->pos1);
	else 
	SDL_BlitSurface(po->img[po->frame],NULL,screen,&po->pos1);
	}
	po->resistancePos1.x=po->pos1.x-20;
	po->resistancePos1.y=po->pos1.y-20;
	po->resistancePos2.w=(po->resistance*66/10000)+15;
	SDL_BlitSurface(po->resistanceIMG,&po->resistancePos2,screen,&po->resistancePos1);
	SDL_BlitSurface(po->resistanceBar,NULL,screen,&po->resistancePos1);
	
	
}
void hitPolice(police *po,projectile *pr)
{
	if(!po->invin)
	{
	if(is_in_rect(pr->img.pos1.x,pr->img.pos1.y,po->pos1)&&pr->thrown)
	{
		po->pos1.x-=50;
		pr->thrown=0;
		po->hitTime=SDL_GetTicks();
		po->invin=1;
		po->hit=1;
		po->resistance-=1000;
		if(Mix_GetChunk(1)==pr->bananaSound)Mix_HaltChannel(1);
		Mix_PlayChannel(-1,po->hurt,0);


		
	}
	}
	
}

void isInvin(int *invin,int hitTime,int invinWindow)
{
	if(SDL_GetTicks()-hitTime>invinWindow)
			*invin=0;
}


void initConsumable(consumable *con,int type)
{
	if(type==1)
	{
	con->img=IMG_Load("omar_backgounf/tea.png");
	con->recovery=2000;
	con->type=1;
	}
	if(type==2)
	{
	con->img=IMG_Load("omar_backgounf/coke.png");
	con->effectDuration=5000;
	con->type=2;
	}
	if(type==3)
	{
	con->img=IMG_Load("omar_backgounf/fish.png");
	con->type=3;
	}
	con->realx=0;
	con->realy=0;
}

void spawnConsumable(consumable *con,SDL_Rect camera,int minX,int maxX,int minY,int maxY)
{
	if (camera.x < 14720 - maxX && con->realx < camera.x || con->pos1.x > maxX)
        {
			
            randomPosition(camera.x + minX, camera.x + maxX, minY, maxY, &con->realx, &con->realy);
        }
                    con->pos1.x = con->realx - camera.x;
                    con->pos1.y = con->realy;
}

void pickUpConsumable(Personne *p,consumable *con)
{
	if(is_in_rect(p->image[1].pos1.x+20,p->image[1].pos1.y+35,con->pos1))
	{
			if(con->type==1)
			 p->tea++;
			 if(con->type==2)
			 p->coke++;
			 if(con->type==3)
			 p->fish++;
			 con->realx=0;
	}
	else
	{
		if(is_in_rect(p->image[1].pos1.x+20,p->image[1].pos1.y,con->pos1))
	{
			if(con->type==1)
			 p->tea++;
			 if(con->type==2)
			 p->coke++;
			 if(con->type==3)
			 p->fish++;
			con->realx=0;
	}
	else 
	{
		if(is_in_rect(p->image[1].pos1.x+20,p->image[1].pos1.y+70,con->pos1))
	{		
			if(con->type==1)
			 p->tea++;
			if(con->type==2)
			 p->coke++;
			 if(con->type==3)
			 {
				 
			 p->fish++;
			 }
			con->realx=0;
	}
	}
	}
}

void consume(Personne *p,int selectedCon ,cat *ca)
{
	if(p->consuming)
	{
	if(selectedCon==1&&p->tea>=1)
	{
		Mix_PlayChannel(-1,p->drinkingTea,0);
		p->stamina+=2000;
		if(p->stamina>13000) p->stamina=13000;
		p->tea--;
	}
	if(selectedCon==2&&p->coke>=1)
	{
		Mix_PlayChannel(-1,p->drinkingCoke,0);
		p->recovery+=10000;
		p->coke--;
		p->consumeTime=SDL_GetTicks();
	}
	if(selectedCon==3&&p->fish>=1)
	{
		ca->called=1;
		p->fish--;
	}
	p->consuming=0;
	}
	if(SDL_GetTicks()-p->consumeTime>=p->recovery) p->recovery=0;
}


void speak(police *po)
{
	 static int time,num;
	num=rand()%3+1;
	if(time<=0) time=SDL_GetTicks()+rand()%3000+3000;
	

	else 
	{
		
		int s=SDL_GetTicks()-time;
		if(s>=0) 
		{
			
			if(num==3) Mix_PlayChannel(-1,po->whisle,0);
		
			if(num==2) Mix_PlayChannel(-1,po->stop,0);
		
			if(num==1) Mix_PlayChannel(-1,po->comeHere,0);

			time=-1;
		}
	}

}
void retreat(police *po,SDL_Surface *screen,int distance,float *score)
{
	if(po->tired) 
	{
		
		SDL_BlitSurface(po->tiredImg,NULL,screen,&po->pos1);
		po->pos1.x-=distance;
		
			if(po->stamina!=0&&po->pos1.x<=0)
			{
				*score+=1000;
				po->stamina--;
				po->tired=0;
				po->inStandBy=1;
				po->resistance=10000;
				po->pos1.x=99999;
				
			}
			if(po->stamina==0&&po->pos1.x<=0)
			{
				po->pos1.x=99999;
				
			}
		
	}
}

void initCat(cat *ca)
{
	ca->img.img=IMG_Load("omar_backgounf/cat.png");
	ca->img.pos2.x=0;
	ca->img.pos2.y=0;
	ca->img.pos2.w=420/6;
	ca->img.pos2.h=156/3;
	ca->speed=1;
	ca->img.pos1.y=500;
	ca->img.pos1.x=0;
	ca->called=0;
	ca->attacked=0;
	ca->satisfied=0;
}

void moveCat(cat *ca, SDL_Rect pos1)
{
	if(ca->img.pos1.x<pos1.x-10) ca->img.pos1.x+=ca->speed; else ca->img.pos1.x-=ca->speed;
	if(ca->img.pos1.y<pos1.y) ca->img.pos1.y+=ca->speed; else ca->img.pos1.y-=ca->speed;
}

void animateCat(cat *ca)
{
	static int time0, time1;
	time0=SDL_GetTicks();
	if(time0-time1>50)
	{
	if(!ca->attacked){
	ca->img.pos2.y=156*2/3;
	if(ca->img.pos2.x<420-420/6)
	ca->img.pos2.x+=420/6;
	else ca->img.pos2.x=0;
	}
	else{
		ca->img.pos2.y=0;
		ca->img.pos2.x=420/6;
	}
	time1=time0;
	}
	
}

void track(cat *ca,Personne p,police *po1,police *po2,police *po3,police *po4)
{
	int d1,d2,d3,d4;
	d1=sqrt(abs(p.image[1].pos1.x-po1->pos1.x)+abs(p.image[1].pos1.y-po1->pos1.y));
	d2=sqrt(abs(p.image[1].pos1.x-po2->pos1.x)+abs(p.image[1].pos1.y-po2->pos1.y));
	d3=sqrt(abs(p.image[1].pos1.x-po3->pos1.x)+abs(p.image[1].pos1.y-po3->pos1.y));
	d4=sqrt(abs(p.image[1].pos1.x-po4->pos1.x)+abs(p.image[1].pos1.y-po4->pos1.y));


	if(d1<=d2&&d1<=d3&&d1<=d4) {moveCat(ca,po1->pos1);ca->target=po1;}
	if(d2<=d1&&d2<=d3&&d2<=d4) {moveCat(ca,po2->pos1);ca->target=po2;}
	if(d3<=d2&&d3<=d1&&d3<=d4) {moveCat(ca,po3->pos1);ca->target=po3;}
	if(d4<=d2&&d4<=d3&&d4<=d1) {moveCat(ca,po4->pos1);ca->target=po4;}
}


void feed(Personne *p, cat *ca)
{
	printf("cat X=%d cat Y=%d X =%d Y= %d W=%d H=%d\n",ca->img.pos1.x,ca->img.pos1.y,p->image[1].pos1.x,p->image[1].pos1.y,p->image[1].pos1.w,p->image[1].pos1.h);
	if(ca->img.pos1.x+15>=p->image[1].pos1.x&&ca->img.pos1.x+15<=p->image[1].pos1.x+30&&ca->img.pos1.y>=p->image[1].pos1.y&&ca->img.pos1.y<=p->image[1].pos1.y+50)
	{
	
		if(!ca->satisfied)
		{
			
			ca->satisfied=1;
		}
	}
}

void attack(cat *ca)
{
	if(is_in_rect(ca->img.pos1.x+20,ca->img.pos1.y+10,ca->target->pos1)&&!ca->attacked)
	{
		ca->target->resistance-=2000;
		ca->target->hit=1;
		ca->target->hitTime=SDL_GetTicks();
		ca->satisfied=0;
		
		ca->attacked=1;
		Mix_PlayChannel(-1,ca->attack,0);
	}
	
}

void retreatCat(cat *ca,int distance)
{
	if(ca->attacked)
	{
		//if(ca->img.pos1.x>0) 
		ca->img.pos1.x-=distance;
		if(ca->img.pos1.x<=0)  {ca->attacked=0;ca->called=0;}
	}
}
