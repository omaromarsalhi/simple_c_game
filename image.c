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

void init(IMAGE i[], int H, int W)
{

    i[0].pos1.x = 100;//W/2-i[0].img->w/2;//200;//W * 0.546021841;
    i[0].pos1.y = 200;//150;//H * 0.208333333;

    i[1].pos1.x =i[0].pos1.x+50;
    i[1].pos1.y = i[0].pos1.y + H * 0.12;//H * 0.222222222;

    i[2].pos1.x = i[0].pos1.x+100;
    i[2].pos1.y = i[1].pos1.y + H * 0.12;//H * 0.222222222;

    i[3].pos1.x = i[0].pos1.x+150;
    i[3].pos1.y = i[2].pos1.y + H * 0.12;//H * 0.222222222;
}

void load(IMAGE img[], IMAGE i[], int H, int W,int o)
{
    char names[2][50][50]={{
    "./jeu/animation2/ASSET_00001.png"
    ,"./jeu/animation2/ASSET_00002.png"
    ,"./jeu/animation2/ASSET_00003.png"
    ,"./jeu/animation2/ASSET_00004.png"
    ,"./jeu/animation2/ASSET_00005.png"
    ,"./jeu/animation2/ASSET_00006.png"
    ,"./jeu/animation2/ASSET_00007.png"
    ,"./jeu/animation2/ASSET_00008.png"
    ,"./jeu/animation2/ASSET_00009.png"
    ,"./jeu/animation2/ASSET_00010.png"
    ,"./jeu/animation2/ASSET_00011.png"
    ,"./jeu/animation2/ASSET_00012.png"
    ,"./jeu/animation2/ASSET_00013.png"
    ,"./jeu/animation2/ASSET_00014.png"
    ,"./jeu/animation2/ASSET_00015.png"
    ,"./jeu/animation2/ASSET_00016.png"
    ,"./jeu/animation2/ASSET_00017.png"
    ,"./jeu/animation2/ASSET_00018.png"
    ,"./jeu/animation2/ASSET_00019.png"
    ,"./jeu/animation2/ASSET_00020.png"
    ,"./jeu/animation2/ASSET_00021.png"
    ,"./jeu/animation2/ASSET_00022.png"
    ,"./jeu/animation2/ASSET_00023.png"
    ,"./jeu/animation2/ASSET_00024.png"
    ,"./jeu/animation2/ASSET_00025.png"
    ,"./jeu/animation2/ASSET_00026.png"
    ,"./jeu/animation2/ASSET_00027.png"
    ,"./jeu/animation2/ASSET_00028.png"
    ,"./jeu/animation2/ASSET_00029.png"
    ,"./jeu/animation2/ASSET_00030.png"
    ,"./jeu/animation2/ASSET_00031.png"
    ,"./jeu/animation2/ASSET_00032.png"
    ,"./jeu/animation2/bk.png"
    ,"./jeu/animation2/bk2.png"
    ,"./jeu/animation2/Plan_de_travail_1.png"
    ,"./jeu/butt1/1.png"
    ,"./jeu/butt1/3.png"
    ,"./jeu/butt1/5.png"
    ,"./jeu/butt1/7.png"
    ,"./jeu/butt1/2.png"
    ,"./jeu/butt1/4.png"
    ,"./jeu/butt1/6.png"
    ,"./jeu/butt1/8.png"
    }};
    img[0].img = IMG_Load(names[o][0]);
    img[1].img = IMG_Load(names[o][1]);
    img[2].img = IMG_Load(names[o][2]);
    img[3].img = IMG_Load(names[o][3]);
    img[4].img = IMG_Load(names[o][4]);
    img[5].img = IMG_Load(names[o][5]);
    img[6].img = IMG_Load(names[o][6]);
    img[7].img = IMG_Load(names[o][7]);
    img[8].img = IMG_Load(names[o][8]);
    img[9].img = IMG_Load(names[o][9]);
    img[10].img = IMG_Load(names[o][10]);
    img[11].img = IMG_Load(names[o][11]);
    img[12].img = IMG_Load(names[o][12]);
    img[13].img = IMG_Load(names[o][13]);
    img[14].img = IMG_Load(names[o][14]);
    img[15].img = IMG_Load(names[o][15]);
    img[16].img = IMG_Load(names[o][16]);
    img[17].img = IMG_Load(names[o][17]);
    img[18].img = IMG_Load(names[o][18]);
    img[19].img = IMG_Load(names[o][19]);
    img[20].img = IMG_Load(names[o][20]);
    img[21].img = IMG_Load(names[o][21]);
    img[22].img = IMG_Load(names[o][22]);
    img[23].img = IMG_Load(names[o][23]);
    img[24].img = IMG_Load(names[o][24]);
    img[25].img = IMG_Load(names[o][25]);
    img[26].img = IMG_Load(names[o][26]);
    img[27].img = IMG_Load(names[o][27]);
    img[28].img = IMG_Load(names[o][28]);
    img[29].img = IMG_Load(names[o][29]);
    img[30].img = IMG_Load(names[o][30]);
    img[31].img = IMG_Load(names[o][31]);
    img[32].img = IMG_Load(names[o][32]);
    img[33].img = IMG_Load(names[o][33]);
    img[34].img = IMG_Load(names[o][34]);
    
    i[0].img = IMG_Load(names[o][35]);
    i[1].img = IMG_Load(names[o][36]);
    i[2].img = IMG_Load(names[o][37]);
    i[3].img = IMG_Load(names[o][38]);

    i[4].img = IMG_Load(names[o][39]);
    i[5].img = IMG_Load(names[o][40]);
    i[6].img = IMG_Load(names[o][41]);
    i[7].img = IMG_Load(names[o][42]);
    init(i, H, W);
}
void SHOWALLIMG(IMAGE *i1, SDL_Surface *wind)
{
    SDL_BlitSurface(i1->img, NULL, wind, &i1->pos1);
}

void opload(IMAGE op[], IMAGE op1[], IMAGE op_kl[],int H, int W,int o)
{

    char names[2][40][50]={{"./jeu/animation2/BG2.png"//0
    ,"./jeu/butt1/ms.png"//1
    ,"./jeu/butt1/ms3.png"//2
    ,"./jeu/butt1/ms5.png"//3
    ,"./jeu/butt1/ms7.png"//4
    ,"./jeu/butt1/ms9.png"//5
    ,"./jeu/butt1/ms2.png"//6
    ,"./jeu/butt1/ms4.png"//7
    ,"./jeu/butt1/ms6.png"//8
    ,"./jeu/butt1/ms8.png"//9
    ,"./jeu/butt1/ms10.png"//10
    ,"./jeu/butt1/qt.png"//11
    ,"./jeu/animation2/mv.png"//12
    ,"./jeu/butt1/mv1.png"//13
    ,"./jeu/animation2/character.png"//14
    ,"./jeu/animation2/2er_carc.png"//15
    ,"./jeu/butt1/right.png"//16
    ,"./jeu/butt1/left.png"//17
    ,"./jeu/animation2/screen_mode.png"//18
    ,"./jeu/butt1/fs.png"//19
    ,"./jeu/butt1/fs4.png"//20
    ,"./jeu/butt1/fs2.png"//21
    ,"./jeu/butt1/fs3.png"//22
    ,"./jeu/animation2/vol5.png"//23
    ,"./jeu/butt1/vol_down.png"//24
    ,"./jeu/butt1/vol_up.png"//25
    ,"./jeu/butt1/vol-.png"//26
    ,"./jeu/butt1/vol.png"//27
    ,"./jeu/butt1/vol1.png"//29
    ,"./jeu/animation2/1er_carc.png"//30
  }};



    op[0].img = IMG_Load(names[o][0]);
    op[1].img = IMG_Load(names[o][1]);
    op[2].img = IMG_Load(names[o][2]);
    op[3].img = IMG_Load(names[o][3]);
    op[4].img = IMG_Load(names[o][4]);
    op[5].img = IMG_Load(names[o][5]);

    
    op[6].img = IMG_Load(names[o][6]);
    op[7].img = IMG_Load(names[o][7]);
    op[8].img = IMG_Load(names[o][8]);
    op[9].img = IMG_Load(names[o][9]);
    op[10].img = IMG_Load(names[o][10]);

    op[11].img = IMG_Load(names[o][11]);

    op[12].img = IMG_Load(names[o][12]);
    op[13].img = IMG_Load(names[o][13]);

    op[14].img = IMG_Load(names[o][14]);
    op[15].img = IMG_Load(names[o][15]);
    op[32].img = IMG_Load(names[o][29]);
    op[16].img = IMG_Load(names[o][16]);
    op[17].img = IMG_Load(names[o][17]);



    op[18].img = IMG_Load(names[o][18]);
    op[19].img = IMG_Load(names[o][19]);
    op[20].img = IMG_Load(names[o][20]);
    op[21].img = IMG_Load(names[o][21]);
    op[22].img = IMG_Load(names[o][22]);


    op[23].img = IMG_Load(names[o][23]);
    op[24].img = IMG_Load(names[o][24]);
    op[25].img = IMG_Load(names[o][25]);
    op[26].img = IMG_Load(names[o][26]);
    op[27].img = IMG_Load(names[o][27]);
    op[28].img = IMG_Load(names[o][28]);
    op[29].img = IMG_Load(names[o][28]);
    op[30].img = IMG_Load(names[o][28]);
    op[31].img = IMG_Load(names[o][28]);


    op[1].pos1.x =260;
    op[1].pos1.y =200;

    op[2].pos1.x = op[1].pos1.x;
    op[2].pos1.y = op[1].pos1.y + H * 0.11;//H * 0.222222222;

    op[3].pos1.x = op[1].pos1.x;
    op[3].pos1.y = op[2].pos1.y + H * 0.11;

    op[4].pos1.x = op[1].pos1.x;
    op[4].pos1.y = op[3].pos1.y + H * 0.11;//H * 0.222222222;


    op[5].pos1.x = op[4].pos1.x+100;
    op[5].pos1.y = op[4].pos1.y + H * 0.11;//H * 0.222222222;

    op[11].pos1.x = op[5].pos1.x-100;
    op[11].pos1.y = op[5].pos1.y+ H * 0.02;


    op[15].pos1.x=W/5;
    op[15].pos1.y=H/3;
    op[16].pos1.x=op[15].pos1.x-op[16].img->w-50;
    op[16].pos1.y=H/2-op[16].img->h/2;
    op[17].pos1.x=op[15].pos1.x+op[15].img->w+50;
    op[17].pos1.y=op[16].pos1.y;


    op[19].pos1.x=W/5;
    op[19].pos1.y=H/2.5;
    op[20].pos1.x=W/5;
    op[20].pos1.y=H/2.5+H*0.12;


    op[24].pos1.x=W/4;
    op[24].pos1.y=H/3.1;
    op[25].pos1.x=W/4+20;
    op[25].pos1.y=op[24].pos1.y+H*0.12;

    op[26].pos1.x=W/13;
    op[26].pos1.y=H/1.8;
    op[27].pos1.x=W/6+op[28].img->w*4;
    op[27].pos1.y=op[26].pos1.y;

    op[28].pos1.x=W/7;
    op[28].pos1.y=op[26].pos1.y+15;
    op[29].pos1.x= W/7+op[28].img->w+3;
    op[29].pos1.y=op[28].pos1.y;
    op[30].pos1.x= W/7+2*op[29].img->w+6;
    op[30].pos1.y=op[28].pos1.y;
    op[31].pos1.x= W/7+3*op[30].img->w+9;
    op[31].pos1.y=op[28].pos1.y;
 

}

void load_cematiques(GLOBAL_VARS *G_V,int o){
    char names[2][200][50]={{
        "./cen_gebes/1.png"
        ,"./cen_gebes/2.png"
        ,"./cen_gebes/3.3.png"
        ,"./cen_gebes/3.3.png"
        ,"./cen_gebes/3.4.png"
        ,"./cen_gebes/3.5.png"
        ,"./cen_gebes/3.6.png"
        ,"./cen_gebes/3.png"
        ,"./cen_gebes/4.png"
        ,"./cen_gebes/5.png"
        ,"./cen_gebes/6.png"
        ,"./cen_gebes/7.png"
        ,"./cen_gebes/8.png"
        ,"./cen_gebes/9.1.png"
        ,"./cen_gebes/9.2.png"
        ,"./cen_gebes/9.3.png"
        ,"./cen_gebes/9.4.png"
        ,"./cen_gebes/9.5.png"
        ,"./cen_gebes/9.png"
        ,"./cen_gebes/10.png"
        ,"./cen_gebes/11.png"
        ,"./cen_gebes/12.png"
        ,"./cen_gebes/13.1.png"
        ,"./cen_gebes/13.2.png"
        ,"./cen_gebes/13.3.png"
        ,"./cen_gebes/13.4.png"
        ,"./cen_gebes/13.5.png"
        ,"./cen_gebes/13.png"
        ,"./cen_gebes/14.png"
        ,"./cen_gebes/15.png"
        ,"./cen_gebes/16.png"
        ,"./cen_gebes/17.png"
        ,"./cen_gebes/18.png"
        ,"./cen_gebes/19.png"
        ,"./cen_gebes/20.1.png"
        ,"./cen_gebes/20.2.png"
        ,"./cen_gebes/20.3.png"
        ,"./cen_gebes/20.4.png"
        ,"./cen_gebes/20.5.png"
        ,"./cen_gebes/20.png"
        ,"./cen_gebes/21.png"
        ,"./cen_gebes/22.png"
        ,"./cen_gebes/23.png"
        ,"./cen_gebes/24.png"
        ,"./cen_gebes/25.png"
        ,"./cen_gebes/26.png"
        ,"./cen_gebes/27.png"
        ,"./cen_gebes/28.png"
        ,"./cen_gebes/29.png"
        ,"./cen_gebes/30.png"
        ,"./cen_gebes/31.png"
        ,"./cen_gebes/32.png"
        ,"./cen_gebes/33.png"
        ,"./cen_gebes/34.png"
        ,"./cen_gebes/35.png"
        ,"./cen_gebes/36.png"
        ,"./cen_gebes/37.png"
        ,"./cen_gebes/38.png"
        ,"./cen_gebes/39.png"
        ,"./cen_gebes/40.png"
        ,"./cen_gebes/41.png"
        ,"./cen_gebes/42.png"
        ,"./cen_gebes/43.png"
        ,"./cen_gebes/44.png"
        ,"./cen_gebes/45.png"
        ,"./cen_gebes/46.png"
        ,"./cen_gebes/47.png"
        ,"./cen_gebes/48.png"
        ,"./cen_gebes/49.png"
        ,"./cen_gebes/50.png"
        ,"./cen_gebes/51.png"
        ,"./cen_gebes/52.png"

        ,"./cen_cafe/1.jpg"
        ,"./cen_cafe/2.jpg"
        ,"./cen_cafe/3.jpg"
        ,"./cen_cafe/4.jpg"
        ,"./cen_cafe/5.jpg"
        ,"./cen_cafe/6.1.jpg"
        ,"./cen_cafe/6.2.jpg"
        ,"./cen_cafe/6.3.jpg"
        ,"./cen_cafe/6.4.jpg"
        ,"./cen_cafe/6.5.jpg"
        ,"./cen_cafe/6.jpg"
        ,"./cen_cafe/7.jpg"
        ,"./cen_cafe/8.jpg"
        ,"./cen_cafe/9.jpg"
        ,"./cen_cafe/10.jpg"
        ,"./cen_cafe/11.jpg"
        ,"./cen_cafe/12.png"
        ,"./cen_cafe/13.1.jpg"
        ,"./cen_cafe/13.2.jpg"
        ,"./cen_cafe/13.3.jpg"
        ,"./cen_cafe/13.4.jpg"
        ,"./cen_cafe/13.5.jpg"
        ,"./cen_cafe/13.jpg"
        ,"./cen_cafe/14.jpg"
        ,"./cen_cafe/15.jpg"
        ,"./cen_cafe/16.jpg"
        ,"./cen_cafe/17.jpg"
        ,"./cen_cafe/18.jpg"
        ,"./cen_cafe/19.jpg"
        ,"./cen_cafe/20.1.jpg"
        ,"./cen_cafe/20.jpg"
        ,"./cen_cafe/21.jpg"
        ,"./cen_cafe/22.jpg"
        ,"./cen_cafe/23.jpg"
        ,"./cen_cafe/24.1.jpg"
        ,"./cen_cafe/24.jpg"
        ,"./cen_cafe/25.jpg"
        ,"./cen_cafe/26.jpg"
        ,"./cen_cafe/27.jpg"
        ,"./cen_cafe/28.jpg"
        ,"./cen_cafe/29.jpg"
        ,"./cen_cafe/30.jpg"
        ,"./cen_market/1.jpg"
        ,"./cen_market/2.jpg"
        ,"./cen_market/3.jpg"
        ,"./cen_market/4.jpg"
        ,"./cen_market/5.jpg"
        ,"./cen_market/6.jpg"
        ,"./cen_market/7.jpg"
        ,"./cen_market/8.jpg"
        ,"./cen_market/9.jpg"
        ,"./cen_market/10.jpg"
        ,"./cen_market/11.jpg"
        ,"./cen_market/12.jpg"
        ,"./cen_market/13.jpg"
        ,"./cen_market/14.jpg"
        ,"./cen_market/15.jpg"
        ,"./cen_market/16.jpg"
        ,"./cen_market/17.jpg"
        ,"./cen_market/18.jpg"
        ,"./cen_market/19.jpg"
        ,"./cen_market/20.jpg"
        ,"./cen_market/21.jpg"
        ,"./cen_market/22.jpg"
        ,"./cen_market/23.jpg"
        ,"./cen_market/24.jpg"
        ,"./cen_market/25.jpg"
        ,"./cen_market/26.jpg"
        ,"./cen_market/27.jpg"
        ,"./cen_market/28.jpg"
        ,"./cen_market/29.jpg"
        ,"./cen_market/30.jpg"
        ,"./cen_market/31.jpg"
        ,"./cen_market/32.jpg"
        ,"./cen_presion/1.png"
        ,"./cen_presion/2.png"
        ,"./cen_presion/3.png"
        ,"./cen_presion/4.png"
        ,"./cen_presion/5.png"
        ,"./cen_presion/6.png"
        ,"./cen_presion/7.png"
        ,"./cen_presion/8.png"
        ,"./cen_presion/9.png"
        ,"./cen_presion/10.png"
        ,"./cen_presion/11.png"
        ,"./cen_presion/12.png"
        ,"./cen_presion/13.png"
        ,"./cen_presion/14.png"
        ,"./cen_presion/15.png"
        ,"./cen_presion/16.png"
        ,"./cen_presion/17.png"
        ,"./cen_presion/18.png"
        ,"./cen_presion/19.png"
        ,"./cen_presion/20.png"
        ,"./cen_presion/21.png"
        ,"./cen_presion/22.png"
        ,"./cen_presion/23.png"
        ,"./cen_presion/24.png"
        ,"./cen_presion/25.png"
        ,"./cen_presion/26.png"
        ,"./cen_presion/27.png"
        ,"./cen_presion/28.png"
        ,"./cen_presion/29.png"
        ,"./cen_presion/30.png"
        ,"./cen_presion/31.png"
        ,"./cen_presion/32.png"
    }};
    for(int i=0;i<177;i++)
        G_V->cematiques[i].img=IMG_Load(names[o][i]);
}




// FULL SCREEN MODE

void fullscreen_new_g_load(IMAGE *new_g, int H, int W)
{
    new_g[0].img = IMG_Load("./ist/fullscreen/BG31.jpg");
    new_g[0].pos1.x = 0;
    new_g[0].pos1.y = 0;
}

