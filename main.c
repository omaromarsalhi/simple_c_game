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
#include "ing_txt.h"
#include "ing_ph.h"
#include "ennemie.h"

void main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    // ---------->>>>>>>>NEW DECLARATION<<<<<<<<-------------
    GLOBAL_VARS G_V;
    int x1, y1;

    // feres variables
    /// INPUT Controll
    int spaceWasPressed = 0, rightMousePressed = 0, rWasPressed = 0, spaceWasPressed2 = 0, rightMousePressed2 = 0, rWasPressed2 = 0,tutoDisplayed=1;;
    ///
    SDL_Surface *tuto;
    tuto = IMG_Load("omar_backgounf/tuto.png");
    int time0 = 0, time1 = 0, timee0, timee1;
    float dt = 120, dt2, dt22, tt0, tt1;
    SDL_Surface *caught;
    caught = IMG_Load("omar_backgounf/Plan_de_travail_1-100.jpg");
    SDL_Rect posGO;
    posGO.x = 1280 / 2 - 300;
    posGO.y = 200;
    Background market2;
    Personne p2;
    //////////// Player1
    int jarani0, jarani1;
    obstacle ob1, ob2, ob3, car;
    projectile pr, pr1;
    IMAGE panana, score;
    TEXT pananat, coket, teat, scoret, fisht;
    char pananatext[20], coketext[20], teatext[20], scoretext[20], fishtext[20];
    pananat.font = TTF_OpenFont("Minecraft.ttf", 20);
    pananat.col.b = 0;
    pananat.col.r = 0;
    pananat.col.g = 0;
    fisht.font = TTF_OpenFont("Minecraft.ttf", 20);
    fisht.col.b = 0;
    fisht.col.r = 0;
    fisht.col.g = 0;
    scoret.font = TTF_OpenFont("Minecraft.ttf", 50);
    scoret.col.b = 0;
    scoret.col.r = 0;
    scoret.col.g = 0;
    coket.font = TTF_OpenFont("Minecraft.ttf", 20);
    coket.col.b = 153;
    coket.col.r = 255;
    coket.col.g = 255;
    teat.font = TTF_OpenFont("Minecraft.ttf", 20);
    teat.col.b = 153;
    teat.col.r = 255;
    teat.col.g = 255;
    panana.img = IMG_Load("omar_backgounf/pananaicon.png");
    pananat.postxt.x = 1280 - 15;
    pananat.postxt.y = 20;
    scoret.postxt.x = 1280 - 150;
    scoret.postxt.y = 70;
    coket.postxt.x = 1280 - 75;
    coket.postxt.y = 20;
    fisht.postxt.x = 1280 - 195;
    fisht.postxt.y = 20;
    teat.postxt.x = 1280 - 135;
    teat.postxt.y = 20;
    panana.pos1.x = 1280 - 40;
    panana.pos1.y = 5;
    score.pos1.x = 1280 - 300;
    score.pos1.y = 70;
    score.img = IMG_Load("omar_backgounf/score.png");
    int animated = 1, animated1 = 1, animated2 = 1, singleplayer = 1;
    initObstacle(&ob1, "omar_backgounf/breakable_pots_gray_3.png", 256, 4, 256, 4);
    initObstacle(&ob2, "omar_backgounf/breakable_pots_gray_3.png", 256, 4, 256, 4);
    initObstacle(&ob3, "omar_backgounf/breakable_pots_gray_3.png", 256, 4, 256, 4);
    initObstacle(&car, "omar_backgounf/car (1).png", 140, 1, 70, 1);

    initProjectile(&pr1, "omar_backgounf/panana.png", 320, 8, 40, 1);
    initProjectile(&pr, "omar_backgounf/panana.png", 320, 8, 40, 1);

    consumable tea, coke, fish;
    SDL_Surface *teaIcon, *cokeIcon, *selectedTeaIcon, *selectedCokeIcon, *fishIcon, *selectedFishIcon;
    SDL_Rect cokePos, teaPos, fishPos;
    int selectedCon = 1;
    cokePos.x = 1280 - 100;
    cokePos.y = 5;
    fishPos.x = 1280 - 220;
    fishPos.y = 5;
    teaPos.x = 1280 - 160;
    teaPos.y = 5;
    teaIcon = IMG_Load("omar_backgounf/nonselectedTea.png");
    cokeIcon = IMG_Load("omar_backgounf/nonselectedCoke.png");
    fishIcon = IMG_Load("omar_backgounf/nonselectedfish.png");
    selectedTeaIcon = IMG_Load("omar_backgounf/selectedTea.png");
    selectedCokeIcon = IMG_Load("omar_backgounf/selectedCoke.png");
    selectedFishIcon = IMG_Load("omar_backgounf/selectedFish.png");
    initConsumable(&tea, 1);
    initConsumable(&coke, 2);
    initConsumable(&fish, 3);
    SDL_Rect poss;
    poss.x = 0;
    poss.y = 0;

    ob1.img.pos2.y = 256 * 2 / 4;
    ob2.img.pos2.y = 256 * 2 / 4;
    ob3.img.pos2.y = 256 * 2 / 4;
    ////////////// Player2
    int jarani02, jarani12;
    obstacle ob12, ob22, ob32, car2;
    projectile pr2, pr12;
    IMAGE panana2, score2;
    TEXT pananat2, coket2, teat2, scoret2, fisht2;
    char pananatext2[20], coketext2[20], teatext2[20], scoretext2[20], fishtext2[20];
    pananat2.font = TTF_OpenFont("Minecraft.ttf", 20);
    pananat2.col.b = 0;
    pananat2.col.r = 0;
    pananat2.col.g = 0;
    fisht2.font = TTF_OpenFont("Minecraft.ttf", 20);
    fisht2.col.b = 0;
    fisht2.col.r = 0;
    fisht2.col.g = 0;
    scoret2.font = TTF_OpenFont("Minecraft.ttf", 50);
    scoret2.col.b = 0;
    scoret2.col.r = 0;
    scoret2.col.g = 0;
    coket2.font = TTF_OpenFont("Minecraft.ttf", 20);
    coket2.col.b = 153;
    coket2.col.r = 255;
    coket2.col.g = 255;
    teat2.font = TTF_OpenFont("Minecraft.ttf", 20);
    teat2.col.b = 153;
    teat2.col.r = 255;
    teat2.col.g = 255;
    panana2.img = IMG_Load("omar_backgounf/pananaicon.png");
    pananat2.postxt.x = 1280 - 15;
    pananat2.postxt.y = 380;
    scoret2.postxt.x = 1280 - 150;
    scoret2.postxt.y = 380;
    coket2.postxt.x = 1280 - 75;
    coket2.postxt.y = 380;
    fisht2.postxt.x = 1280 - 195;
    fisht2.postxt.y = 380;
    teat2.postxt.x = 1280 - 135;
    teat2.postxt.y = 380;
    panana2.pos1.x = 1280 - 40;
    panana2.pos1.y = 365;
    score2.pos1.x = 1280 - 300;
    score2.pos1.y = 400;
    score2.img = IMG_Load("omar_backgounf/score.png");
    int animated02 = 1, animated12 = 1, animated22 = 1;
    initObstacle(&ob12, "omar_backgounf/breakable_pots_gray_3.png", 256, 4, 256, 4);
    initObstacle(&ob22, "omar_backgounf/breakable_pots_gray_3.png", 256, 4, 256, 4);
    initObstacle(&ob32, "omar_backgounf/breakable_pots_gray_3.png", 256, 4, 256, 4);
    initObstacle(&car2, "omar_backgounf/car (1).png", 140, 1, 70, 1);

    initProjectile(&pr12, "omar_backgounf/panana.png", 320, 8, 40, 1);
    initProjectile(&pr2, "omar_backgounf/panana.png", 320, 8, 40, 1);

    consumable tea2, coke2, fish2;
    // SDL_Surface *teaIcon,*cokeIcon,*selectedTeaIcon,*selectedCokeIcon,*fishIcon,*selectedFishIcon;
    SDL_Rect cokePos2, teaPos2, fishPos2;
    int selectedCon2 = 1;
    cokePos2.x = 1280 - 100;
    cokePos2.y = 365;
    fishPos2.x = 1280 - 220;
    fishPos2.y = 365;
    teaPos2.x = 1280 - 160;
    teaPos2.y = 365;
    /*
    teaIcon=IMG_Load("omar_backgounf/nonselectedTea.png");
    cokeIcon=IMG_Load("omar_backgounf/nonselectedCoke.png");
    fishIcon=IMG_Load("omar_backgounf/nonselectedfish.png");
    selectedTeaIcon=IMG_Load("omar_backgounf/selectedTea.png");
    selectedCokeIcon=IMG_Load("omar_backgounf/selectedCoke.png");
    selectedFishIcon=IMG_Load("omar_backgounf/selectedFish.png");
    */
    initConsumable(&tea2, 1);
    initConsumable(&coke2, 2);
    initConsumable(&fish2, 3);

    ob1.img.pos2.y = 256 * 2 / 4;
    ob2.img.pos2.y = 256 * 2 / 4;
    ob3.img.pos2.y = 256 * 2 / 4;
    ob12.img.pos2.y = 256 * 2 / 4;
    ob22.img.pos2.y = 256 * 2 / 4;
    ob32.img.pos2.y = 256 * 2 / 4;

    //////////
    police po1, po2, po3, po4, po12, po22, po32, po42;
    SDL_Surface *police1[9], *police2[9], *police3[9], *police4[9];
    SDL_Rect pospolice1, pospolice2, pospolice3, pospolice4, pos;
    int moved = 0;
    initPolice(&po1, 0, 460, 0, 1, 2);
    initPolice(&po2, 99999, 460 + 52, 1, 1, 2);
    initPolice(&po3, 99999, 460 + 52 * 2, 1, 1, 3);
    initPolice(&po4, 99999, 460 + 52 * 3, 1, 1, 3);

    initPolice(&po12, 0, 460, 460, 1, 2);
    initPolice(&po22, 99999, 460 + 52, 1, 1, 2);
    initPolice(&po32, 99999, 460 + 52 * 2, 1, 1, 3);
    initPolice(&po42, 99999, 460 + 52 * 3, 1, 1, 3);
    int stupidPolice = 0;
    int QTE;

    cat ca, ca2;
    initCat(&ca);
    initCat(&ca2);
    Uint8 *keystate;
    // omar part
    IMAGE letter[15], password[3];
    int letter_i = 0, letter_count = 0;
    ;
    letter[0].img = IMG_Load("./ist/1_.png");
    letter[1].img = IMG_Load("./ist/doura2.png");
    letter[2].img = IMG_Load("./ist/doura3.png");
    letter[3].img = IMG_Load("./ist/doura3 (1).png");
    letter[4].img = IMG_Load("./ist/doura4.png");
    letter[5].img = IMG_Load("./ist/doura5.png");
    letter[6].img = IMG_Load("./ist/doura6.png");
    letter[7].img = IMG_Load("./ist/doura7.png");
    letter[8].img = IMG_Load("./ist/doura8.png");
    letter[9].img = IMG_Load("./ist/11_.png");
    letter[10].img = IMG_Load("./ist/2_.png");
    letter[11].img = IMG_Load("./ist/3_.png");
    letter[12].img = IMG_Load("./ist/4_.png");

    password[0].img = IMG_Load("./decrepting/unknown.png");
    password[1].img = IMG_Load("./decrepting/botnawahadha.png");
    password[2].img = IMG_Load("./decrepting/unknown (1).png");

    int bubb_i[10] = {13, 15, 17, 19, 21, 12, 14, 16, 18, 20};

    G_V.O.opstate = 1;
    G_V.state = 0;
    G_V.out = 0;
    G_V.dt = 0;
    G_V.end = 0;
    G_V.downup = -1;
    for (int i = 0; i < 10; i++)
        G_V.Is_butt_on[i] = 0;
    G_V.Is_butt_on[10] = 1;
    for (int i = 0; i < 10; i++)
        G_V.fill[i] = 0;
    G_V.count = 0;
    G_V.i = 10;

    G_V.M.txt.font = TTF_OpenFont("./ist/28 Days Later.ttf", 85);
    // ---------->>>>>>>>reception of information<<<<<<<<-------------
    reception_info(&G_V.M.if1, "save.bin");
    /*G_V.M.if1.screenmode = 1;
    G_V.M.if1.vol=20;
    G_V.M.if1.tab_settings[0]=SDLK_UP ;
    G_V.M.if1.tab_settings[1]=SDLK_DOWN ;
    G_V.M.if1.tab_settings[2]=SDLK_RIGHT;
    G_V.M.if1.tab_settings[3]=SDLK_LEFT;
    G_V.M.if1.wich_character=15;*/

    // ---------->>>>>>>>setting the screen mode<<<<<<<<-------------
    screen_mode(&G_V);
    // belongs to feres
    market2 = G_V.NG.b_market;
    market2.b_k[0].pos1.y = 0;
    market2.b_k[0].pos2.h = G_V.H / 2;
    p2 = G_V.NG.p;

    // belongs to omar
    password[0].pos1.x = G_V.W / 2 - password[0].img->w / 2;
    password[0].pos1.y = G_V.H / 2 - password[0].img->h / 2;
    password[1].pos1.x = password[0].pos1.x + password[0].img->w - password[1].img->w * 1.2;
    password[1].pos1.y = password[0].pos1.y + password[0].img->h - password[1].img->h * 1.2;
    password[2].pos1.x = G_V.W / 2 - password[2].img->w / 2;
    password[2].pos1.y = G_V.H / 2 - password[2].img->h / 2;

    G_V.window = SDL_SetVideoMode(G_V.W, G_V.H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    // ---------->>>>>>>>music<<<<<<<<-------------
    Mix_Music *ms, *start_ms, *typewriter1, *typewriter2,*typewriter3, *kahwa, *sahara, *death_means_death, *chase;
    Mix_Chunk *effect;
    int playingEscapeMusic = 0;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    pr.bananaSound = Mix_LoadWAV("omar_backgounf/boomerang.wav");
    G_V.NG.p.drinkingTea = Mix_LoadWAV("omar_backgounf/Sipping Tea Sound Effect-YoutubeConvert.cc.wav");
    G_V.NG.p.drinkingCoke = Mix_LoadWAV("omar_backgounf/Fallout 3 - Nuka Cola drink soda bottle caps sound effect FX-YoutubeConvert.cc.wav");
    G_V.NG.p.openTuna = Mix_LoadWAV("omar_backgounf/opentuna.wav");
    ca.attack = Mix_LoadWAV("omar_backgounf/Angry cat meow (sound effect)-YoutubeConvert.cc.wav");
    po1.hurt = Mix_LoadWAV("omar_backgounf/Male Hurt - Sound Effect-YoutubeConvert.cc.wav");
    po2.hurt = Mix_LoadWAV("omar_backgounf/Male Hurt - Sound Effect-YoutubeConvert.cc.wav");
    po3.hurt = Mix_LoadWAV("omar_backgounf/Male Hurt - Sound Effect-YoutubeConvert.cc.wav");
    po4.hurt = Mix_LoadWAV("omar_backgounf/Male Hurt - Sound Effect-YoutubeConvert.cc.wav");
    po1.stop = Mix_LoadWAV("omar_backgounf/39;Stop39; Sound Effect-YoutubeConvert.cc.wav");
    po1.comeHere = Mix_LoadWAV("omar_backgounf/COME HERE Sound Effect-YoutubeConvert.cc.wav");
    po1.whisle = Mix_LoadWAV("omar_backgounf/British police whistle-YoutubeConvert.cc.wav");
    po1.needBackUp = Mix_LoadWAV("omar_backgounf/39;i need backup39; (Cop7 Voice Lines)-YoutubeConvert.cc.wav");
    po2.needBackUp = Mix_LoadWAV("omar_backgounf/39;i need backup39; (Cop7 Voice Lines)-YoutubeConvert.cc.wav");
    po3.needBackUp = Mix_LoadWAV("omar_backgounf/39;i need backup39; (Cop7 Voice Lines)-YoutubeConvert.cc.wav");
    po4.needBackUp = Mix_LoadWAV("omar_backgounf/39;i need backup39; (Cop7 Voice Lines)-YoutubeConvert.cc.wav");
    po1.amBack = Mix_LoadWAV("omar_backgounf/39;Gentlemen. I39;m back39; (Spy Voice Lines)-YoutubeConvert.cc.wav");
    ca.meaw = Mix_LoadWAV("omar_backgounf/Meow - Sound Effect-YoutubeConvert.cc.wav");
    chase = Mix_LoadMUS("♩♫ Epic Chase Music ♪♬ - Run (Copyright and Royalty Free).mp3");
    // ms = Mix_LoadMUS("./ist/backgroundmusic.mp3");
    start_ms = Mix_LoadMUS("./MONUMENT - Cinematic Trailer Sound Effects.mp3");
    effect = Mix_LoadWAV("./ist/slect.wav");
    Mix_VolumeMusic(G_V.M.if1.vol);
    Mix_PlayMusic(ms, -1);
    G_V.test_ing = 1;

    G_V.col1 = SDL_MapRGB(G_V.window->format, 255, 255, 255);
    G_V.col2 = SDL_MapRGB(G_V.window->format, 0, 0, 0);

    typewriter1 = Mix_LoadMUS("./ist/r.mp3");
    typewriter2 = Mix_LoadMUS("./ist/r2.mp3");
    typewriter3 = Mix_LoadMUS("./ist/typer3.mp3");
    kahwa = Mix_LoadMUS("./ist/kahwa.mp3");
    ms = Mix_LoadMUS("./ist/backgroundmusic.mp3");
    start_ms = Mix_LoadMUS("./MONUMENT - Cinematic Trailer Sound Effects.mp3");
    sahara = Mix_LoadMUS("./ist/stage1.mp3");
    death_means_death = Mix_LoadMUS("./ist/race.mp3");

    p2 = G_V.NG.p;
    ca2 = ca;
    // ---------->>>>>>>>init Link with arduino<<<<<<<<-------------
    system("stty -F /dev/ttyUSB0 9600 -parenb cs8 -cstopb");
    char received;
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    int arduino;

    // ---------->>>>>>>>integration tache background<<<<<<<<-------------
    int k, k1, k2, k3 = 0;
    // ---------->>>>>>>>integration tache perso<<<<<<<<-------------
    G_V.NG.p.acc = 0;
    G_V.NG.p.derec = 1;
    G_V.NG.p.where = 0;
    G_V.NG.plystate = 1;
    G_V.perso_in = 1;
    G_V.NG.p.still_in = 0;
    G_V.NG.p.scrolling_on = 0;
    G_V.NG.p.coll_derection = 0;
    G_V.NG.p.speed = 0.001;
    G_V.NG.p.distance = 0;

    // ---------->>>>>>>>integration tache minmap<<<<<<<<-------------
    G_V.NG.m.col = SDL_MapRGB(G_V.window->format, 0, 0, 0);
    G_V.txt1.font = TTF_OpenFont("./omar_minmap/times.ttf", 35);
    G_V.txt1.postxt.x = G_V.W / 4;
    G_V.txt1.postxt.y = G_V.H / 4;
    G_V.txt1.col.r = 125;
    G_V.txt1.col.g = 0;
    G_V.txt1.col.b = 0;
    strcpy(G_V.NG.m.nomfichier, "best scores");

    // ---------->>>>>>>>integration tache ing_txt<<<<<<<<-------------
    G_V.NG.e_txt.i = 0;
    G_V.NG.e_txt.choise = -15;
    int x;
    G_V.NG.e_txt.which_gate = 2;
    G_V.NG.e_txt.evaluation = 0;
    G_V.NG.e_txt.animationn = 0;
    G_V.NG.e_txt.count = 0;
    // ---------->>>>>>>>integration tache ing_ph<<<<<<<<-------------
    G_V.NG.e_ph.where = 0;
    G_V.NG.e_ph.choise = -15;
    G_V.NG.e_ph.evaluation = 0;
    G_V.coll_PP_ing_ph = 0;
    // ---------->>>>>>>>integration tache entitee secondere<<<<<<<<-------------
    G_V.NG.e1.func_num = 2;
    G_V.NG.e1.coll_PP_ENNEMI = 0;
    int s = 0;
    for (int i = 0; i < 12; i++)
        G_V.NG.e1_6[i] = G_V.NG.e1;

    G_V.NG.e1_6[0].cafe_img.pos1.x = 500;
    G_V.NG.e1_6[0].cafe_img.pos1.y = 0;
    G_V.NG.e1_6[0].func_num = 3;

    G_V.NG.e1_6[1].cafe_img.pos1.x = 800;
    G_V.NG.e1_6[1].cafe_img.pos1.y = G_V.H / 2 - G_V.NG.e1_6[5].cafe_img.pos2.h / 2;
    G_V.NG.e1_6[1].func_num = 3;

    G_V.NG.e1_6[2].cafe_img.pos1.x = 1200;
    G_V.NG.e1_6[2].cafe_img.pos1.y = G_V.H - G_V.NG.e1_6[5].cafe_img.pos2.h;
    G_V.NG.e1_6[2].func_num = 2;

    G_V.NG.e1_6[3].cafe_img.pos1.x = 800;
    G_V.NG.e1_6[3].cafe_img.pos1.y = 100;
    G_V.NG.e1_6[3].func_num = 2;

    G_V.NG.e1_6[4].cafe_img.pos1.x = 1000;
    G_V.NG.e1_6[4].cafe_img.pos1.y = G_V.H / 2 - G_V.NG.e1_6[5].cafe_img.pos2.h / 2;
    G_V.NG.e1_6[4].func_num = 2;

    G_V.NG.e1_6[5].cafe_img.pos1.x = 1200;
    G_V.NG.e1_6[5].cafe_img.pos1.y = G_V.H - G_V.NG.e1_6[5].cafe_img.pos2.h - 100;
    G_V.NG.e1_6[5].func_num = 2;

    G_V.NG.e1_6[6].cafe_img.pos1.x = 800;
    G_V.NG.e1_6[6].cafe_img.pos1.y = 100;
    G_V.NG.e1_6[6].func_num = 2;

    G_V.NG.e1_6[7].cafe_img.pos1.x = 1000;
    G_V.NG.e1_6[7].cafe_img.pos1.y = G_V.H / 2 - G_V.NG.e1_6[5].cafe_img.pos2.h / 2;
    G_V.NG.e1_6[7].func_num = 2;

    G_V.NG.e1_6[8].cafe_img.pos1.x = 1200;
    G_V.NG.e1_6[8].cafe_img.pos1.y = G_V.H - G_V.NG.e1_6[5].cafe_img.pos2.h - 100;
    G_V.NG.e1_6[8].func_num = 2;

    G_V.NG.e1_6[9].cafe_img.pos1.x = 1100;
    G_V.NG.e1_6[9].cafe_img.pos1.y = 100;
    G_V.NG.e1_6[9].func_num = 2;

    G_V.NG.e1_6[10].cafe_img.pos1.x = 1100;
    G_V.NG.e1_6[10].cafe_img.pos1.y = G_V.H / 2 - G_V.NG.e1_6[5].cafe_img.pos2.h / 2;
    G_V.NG.e1_6[10].func_num = 2;

    G_V.NG.e1_6[11].cafe_img.pos1.x = 1100;
    G_V.NG.e1_6[11].cafe_img.pos1.y = G_V.H - G_V.NG.e1_6[5].cafe_img.pos2.h - 100;
    G_V.NG.e1_6[11].func_num = 2;

    G_V.NG.e_AI.ing = 0;
    G_V.NG.e_AI.evaluation = 0;

    G_V.coll_BB = 0;
    G_V.coll_PP_ennemy_race = 0;
    G_V.win.img = IMG_Load("./quit_or_resume/won3.png");
    G_V.NG.race = 0;
    G_V.in_e_ai = 1;

    int aoug = 0, in = 1;
    int selected = 2;
    G_V.j = 0;
    for (int j = 0; j < 5; j++)
        G_V.reception[j] = -1;
    // tache blanche oussema

    G_V.sa_or_res[0].img = IMG_Load("./quit_or_resume/bg.png");
    G_V.sa_or_res[1].img = IMG_Load("./quit_or_resume/resume1.png");
    G_V.sa_or_res[2].img = IMG_Load("./quit_or_resume/resume2.png");
    G_V.sa_or_res[3].img = IMG_Load("./quit_or_resume/save1.png");
    G_V.sa_or_res[4].img = IMG_Load("./quit_or_resume/save2.png");
    G_V.sa_or_res[5].img = IMG_Load("./quit_or_resume/options1.png");
    G_V.sa_or_res[6].img = IMG_Load("./quit_or_resume/options2.png");
    G_V.sa_or_res[0].pos1.x = G_V.W / 2 - G_V.sa_or_res[0].img->w / 2;
    G_V.sa_or_res[0].pos1.y = G_V.H / 2 - G_V.sa_or_res[0].img->h / 2;

    G_V.sa_or_res[1].pos1.x = G_V.W / 2 - G_V.sa_or_res[1].img->w / 2;
    G_V.sa_or_res[1].pos1.y = G_V.sa_or_res[0].pos1.y + 150;
    G_V.sa_or_res[2].pos1 = G_V.sa_or_res[1].pos1;

    G_V.sa_or_res[3].pos1.x = G_V.W / 2 - G_V.sa_or_res[3].img->w / 2;
    G_V.sa_or_res[3].pos1.y = G_V.sa_or_res[0].pos1.y + 250;
    G_V.sa_or_res[4].pos1 = G_V.sa_or_res[3].pos1;

    G_V.sa_or_res[5].pos1.x = G_V.W / 2 - G_V.sa_or_res[5].img->w / 2;
    G_V.sa_or_res[5].pos1.y = G_V.sa_or_res[0].pos1.y + 350;
    G_V.sa_or_res[6].pos1 = G_V.sa_or_res[5].pos1;

    int d = 0;
    char om[3] = " a ";
    for (int i = 0; i < 6; i++)
    {
        G_V.exit_if[i][0] = 1;
        G_V.exit_if[i][1] = 1;
        G_V.exit_if[i][2] = 1;
    }

    SDLKey tab_sdl1[27] = {
        SDLK_BACKSPACE,
        SDLK_a,
        SDLK_b,
        SDLK_c,
        SDLK_d,
        SDLK_e,
        SDLK_f,
        SDLK_g,
        SDLK_h,
        SDLK_i,
        SDLK_j,
        SDLK_k,
        SDLK_l,
        SDLK_m,
        SDLK_n,
        SDLK_o,
        SDLK_p,
        SDLK_q,
        SDLK_r,
        SDLK_s,
        SDLK_t,
        SDLK_u,
        SDLK_v,
        SDLK_w,
        SDLK_x,
        SDLK_y,
        SDLK_z};
    TEXT t_password, t_setting[5];
    SDL_Rect pos_pass;
    char pass[10], MV[5][3] = {{'u', 'p', '\0'}, {'d', 'n', '\0'}, {'r', 'g', '\0'}, {'l', 'f', '\0'}, {'s', 'p', '\0'}};
    int i_pass = 0, width, hight, i_MV[5] = {2, 2, 2, 2, 2}, place = 0, trailer = 0, pss_in = 0;
    ;
    t_password.col.r = 125;
    t_password.col.g = 0;
    t_password.col.b = 0;
    t_password.font = TTF_OpenFont("./ist/28 Days Later.ttf", 35);
    for (int j = 0; j < 5; j++)
    {
        t_setting[j].font = TTF_OpenFont("./ist/28 Days Later.ttf", 35);
        t_setting[j].col.r = 125;
        t_setting[j].col.g = 0;
        t_setting[j].col.b = 0;
    }
    G_V.presion_count = 0;
    G_V.out_presion[0].img = IMG_Load("./omar_backgounf/omarrrr_1.png");
    G_V.out_presion[1].img = IMG_Load("./omar_backgounf/omarrrr_1_mask.png");
    G_V.presion_hart[0].img = IMG_Load("./presion_hearts/1.png");
    G_V.presion_hart[1].img = IMG_Load("./presion_hearts/2.png");
    G_V.presion_hart[2].img = IMG_Load("./presion_hearts/3.png");
    G_V.presion_hart[3].img = IMG_Load("./presion_hearts/4.png");
    int preions_i = 6;

    // cenematique part
    int cenem = 0;

    // arduino
    int innn = 0;

    // tiktakto
    tic t;
    int tiktak = 1, X, Y, coup, county = 0;
    SDL_Surface *texte;
    SDL_Rect posRESULT;
    posRESULT.x = G_V.W / 4;
    posRESULT.y = G_V.H / 2;
    SDL_Color textColor = {255, 0, 0};
    initialiserTic(&t, G_V.W, G_V.H);
    int ani = 1;

    SDL_Surface *T[51];
    chargeranim(T);

    while (!G_V.out)
    {
        SDL_PollEvent(&G_V.event);
        detectionkey(&G_V);
        switch (G_V.state)
        {
        case 0:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 80)
            {

                animation(G_V.window, G_V.M.img_BK, &G_V.i, &G_V.count);
                G_V.M.img_BK[33].pos1.x = 45;
                G_V.M.img_BK[33].pos1.y = G_V.H / 2 - G_V.M.img_BK[33].img->h / 2;
                SDL_BlitSurface(G_V.M.img_BK[33].img, NULL, G_V.window, &G_V.M.img_BK[33].pos1);
                SDL_BlitSurface(G_V.M.img_BK[32].img, NULL, G_V.window, NULL);
                SDL_BlitSurface(G_V.M.img_BK[34].img, NULL, G_V.window, NULL);
                blit_all(G_V.window, 4, G_V.M.butt, G_V.M.butt + 1, G_V.M.butt + 2, G_V.M.butt + 3);
                switch (G_V.event.type)
                {
                case SDL_QUIT:
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.out = 1;
                    break;

                case SDL_MOUSEMOTION:
                    G_V.x1 = G_V.event.motion.x;
                    G_V.y1 = G_V.event.motion.y;
                    if (is_in_rect(G_V.x1, G_V.y1, G_V.M.butt[0].pos1))
                        SDL_BlitSurface(G_V.M.butt[4].img, NULL, G_V.window, &G_V.M.butt[0].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.M.butt[1].pos1))
                        SDL_BlitSurface(G_V.M.butt[5].img, NULL, G_V.window, &G_V.M.butt[1].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.M.butt[2].pos1))
                        SDL_BlitSurface(G_V.M.butt[6].img, NULL, G_V.window, &G_V.M.butt[2].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.M.butt[3].pos1))
                        SDL_BlitSurface(G_V.M.butt[7].img, NULL, G_V.window, &G_V.M.butt[3].pos1);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    G_V.x1 = G_V.event.button.x;
                    G_V.y1 = G_V.event.button.y;
                    if (is_in_rect(G_V.x1, G_V.y1, G_V.M.butt[0].pos1))
                    {
                        G_V.state = 10;
                        Mix_PlayMusic(start_ms, 0);
                    }
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.M.butt[1].pos1))
                    {
                        reception_info(&G_V.M.if2, "save_pro.bin");
                        G_V.state = G_V.M.if2.casee;
                    }
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.M.butt[2].pos1))
                        G_V.state = 2;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.M.butt[3].pos1))
                        G_V.state = 1;
                    if (G_V.state != 0)
                        Mix_PlayChannel(-1, effect, 0);
                    break;
                }
                G_V.end = SDL_GetTicks();
            }
            break;
        case 1:
            G_V.out = 1;
            break;
        case 2:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 60)
            {
                animation(G_V.window, G_V.M.img_BK, &G_V.i, &G_V.count);
                SDL_BlitSurface(G_V.M.img_BK[32].img, NULL, G_V.window, NULL);
                SDL_BlitSurface(G_V.M.img_BK[34].img, NULL, G_V.window, NULL);

                switch (G_V.O.opstate)
                {
                case 0:
                    G_V.state = 0;
                    G_V.O.opstate = 1;
                    break;
                    // first case
                case 1:

                    G_V.M.img_BK[33].pos1.x = 45;
                    G_V.M.img_BK[33].pos1.y = G_V.H / 2 - G_V.M.img_BK[33].img->h / 2;
                    SDL_BlitSurface(G_V.O.op[0].img, NULL, G_V.window, &G_V.M.img_BK[33].pos1);
                    blit_all(G_V.window, 6, G_V.O.op + 1, G_V.O.op + 2, G_V.O.op + 3, G_V.O.op + 4, G_V.O.op + 5, G_V.O.op + 11);
                    break;
                // setting the music
                case 2:
                    SDL_BlitSurface(G_V.O.op[23].img, NULL, G_V.window, &G_V.M.img_BK[33].pos1);
                    SDL_BlitSurface(G_V.O.op[24].img, NULL, G_V.window, &G_V.O.op[24].pos1);
                    SDL_BlitSurface(G_V.O.op[25].img, NULL, G_V.window, &G_V.O.op[25].pos1);
                    SDL_BlitSurface(G_V.O.op[26].img, NULL, G_V.window, &G_V.O.op[26].pos1);
                    SDL_BlitSurface(G_V.O.op[27].img, NULL, G_V.window, &G_V.O.op[27].pos1);
                    G_V.O.op[5].pos1.y -= G_V.H * 0.05;
                    G_V.O.op[11].pos1.y -= G_V.H * 0.05;
                    SDL_BlitSurface(G_V.O.op[5].img, NULL, G_V.window, &G_V.O.op[5].pos1);
                    SDL_BlitSurface(G_V.O.op[11].img, NULL, G_V.window, &G_V.O.op[11].pos1);
                    G_V.O.op[5].pos1.y += G_V.H * 0.05;
                    G_V.O.op[11].pos1.y += G_V.H * 0.05;
                    if (G_V.Is_butt_on[0])
                    {
                        G_V.M.if1.vol += 8;
                        SDL_Delay(80);
                        if (G_V.M.if1.vol > 128)
                        {
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.M.if1.vol = 128;
                            G_V.Is_butt_on[0] = 0;
                        }
                    }
                    else if (G_V.Is_butt_on[1])
                    {
                        G_V.M.if1.vol -= 8;
                        SDL_Delay(80);
                        if (G_V.M.if1.vol < 0)
                        {
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.M.if1.vol = 0;
                            G_V.Is_butt_on[1] = 0;
                        }
                    }
                    Mix_VolumeMusic(G_V.M.if1.vol);
                    Mix_VolumeChunk(effect,G_V.M.if1.vol);
                    Mix_VolumeChunk(G_V.NG.p.drinkingCoke,G_V.M.if1.vol);
                    Mix_VolumeChunk(G_V.NG.p.drinkingTea,G_V.M.if1.vol);
                    Mix_VolumeChunk(G_V.NG.p.openTuna,G_V.M.if1.vol);
                    Mix_VolumeChunk(po1.stop,G_V.M.if1.vol);
                    Mix_VolumeChunk(po1.whisle,G_V.M.if1.vol);
                    Mix_VolumeChunk(po1.amBack,G_V.M.if1.vol);
                    Mix_VolumeChunk(po1.comeHere,G_V.M.if1.vol);
                    Mix_VolumeChunk(po1.needBackUp,G_V.M.if1.vol);
                    if (G_V.M.if1.vol >= 8 && G_V.M.if1.vol <= 40)
                        blit_all(G_V.window, 1, G_V.O.op + 28);
                    else if (G_V.M.if1.vol >= 41 && G_V.M.if1.vol <= 80)
                        blit_all(G_V.window, 2, G_V.O.op + 28, G_V.O.op + 29);
                    else if (G_V.M.if1.vol >= 81 && G_V.M.if1.vol < 128)
                        blit_all(G_V.window, 3, G_V.O.op + 28, G_V.O.op + 29, G_V.O.op + 30);
                    else if (G_V.M.if1.vol == 128)
                        blit_all(G_V.window, 4, G_V.O.op + 28, G_V.O.op + 29, G_V.O.op + 30, G_V.O.op + 31);
                    break;

                // setting the screen mode
                case 3:
                    SDL_BlitSurface(G_V.O.op[18].img, NULL, G_V.window, &G_V.M.img_BK[33].pos1);
                    SDL_BlitSurface(G_V.O.op[19].img, NULL, G_V.window, &G_V.O.op[19].pos1);
                    SDL_BlitSurface(G_V.O.op[20].img, NULL, G_V.window, &G_V.O.op[20].pos1);
                    G_V.O.op[5].pos1.y -= G_V.H * 0.05;
                    G_V.O.op[11].pos1.y -= G_V.H * 0.05;
                    SDL_BlitSurface(G_V.O.op[5].img, NULL, G_V.window, &G_V.O.op[5].pos1);
                    SDL_BlitSurface(G_V.O.op[11].img, NULL, G_V.window, &G_V.O.op[11].pos1);
                    G_V.O.op[5].pos1.y += G_V.H * 0.05;
                    G_V.O.op[11].pos1.y += G_V.H * 0.05;
                    break;

                // saving the information of the settings
                case 4:
                    if (G_V.W == 1920)
                    {
                        G_V.M.if1.screenmode = 0;
                        sauve(&G_V.M.if1, "save.bin");
                        G_V.M.if1.screenmode = 3333;
                    }
                    else
                    {
                        G_V.M.if1.screenmode = 1;
                        sauve(&G_V.M.if1, "save.bin");
                        G_V.M.if1.screenmode = 3333;
                    }
                    G_V.O.opstate = 1;
                    break;
                case 8:
                    keystate = SDL_GetKeyState(NULL);
                    G_V.O.op[13].pos1.x = G_V.W * 0.3;
                    G_V.O.op[13].pos1.y = G_V.H * 0.292;
                    SDL_BlitSurface(G_V.O.op[12].img, NULL, G_V.window, &G_V.M.img_BK[33].pos1);
                    G_V.O.opp[0] = G_V.O.op[13];
                    SDL_BlitSurface(G_V.O.op[13].img, NULL, G_V.window, &G_V.O.op[13].pos1);
                    G_V.O.op[13].pos1.y += G_V.O.op[13].img->h - 2;
                    G_V.O.opp[1] = G_V.O.op[13];
                    SDL_BlitSurface(G_V.O.op[13].img, NULL, G_V.window, &G_V.O.op[13].pos1);
                    G_V.O.op[13].pos1.y += G_V.O.op[13].img->h - 2;
                    G_V.O.opp[2] = G_V.O.op[13];
                    SDL_BlitSurface(G_V.O.op[13].img, NULL, G_V.window, &G_V.O.op[13].pos1);
                    G_V.O.op[13].pos1.y += G_V.O.op[13].img->h - 2;
                    G_V.O.opp[3] = G_V.O.op[13];
                    SDL_BlitSurface(G_V.O.op[13].img, NULL, G_V.window, &G_V.O.op[13].pos1);
                    G_V.O.op[13].pos1.y += G_V.O.op[13].img->h - 2;
                    G_V.O.opp[4] = G_V.O.op[13];
                    SDL_BlitSurface(G_V.O.op[13].img, NULL, G_V.window, &G_V.O.op[13].pos1);
                    G_V.O.op[5].pos1.y -= G_V.H * 0.05;
                    G_V.O.op[11].pos1.y -= G_V.H * 0.05;
                    SDL_BlitSurface(G_V.O.op[5].img, NULL, G_V.window, &G_V.O.op[5].pos1);
                    SDL_BlitSurface(G_V.O.op[11].img, NULL, G_V.window, &G_V.O.op[11].pos1);
                    G_V.O.op[5].pos1.y += G_V.H * 0.05;
                    G_V.O.op[11].pos1.y += G_V.H * 0.05;

                    for (int l = 0; l < 27; l++)
                    {
                        if (keystate[tab_sdl1[l]] && tab_sdl1[l] == SDLK_BACKSPACE && i_MV[place] > 0)
                        {
                            i_MV[place]--;
                            if (i_MV[place] == -1)
                                i_MV[place] = 0;
                            MV[place][i_MV[place]] = '\0';
                            break;
                        }
                        else if (keystate[SDLK_UP])
                        {
                            MV[place][0] = 'u';
                            MV[place][1] = 'p';
                            MV[place][2] = '\0';
                            i_MV[place] = 2;
                            if (place < 4)
                                G_V.M.if1.tab_settings[place] = SDLK_UP;
                        }
                        else if (keystate[SDLK_DOWN])
                        {
                            MV[place][0] = 'd';
                            MV[place][1] = 'n';
                            MV[place][2] = '\0';
                            i_MV[place] = 2;
                            if (place < 4)
                                G_V.M.if1.tab_settings[place] = SDLK_DOWN;
                        }
                        else if (keystate[SDLK_RIGHT])
                        {
                            MV[place][0] = 'r';
                            MV[place][1] = 'g';
                            MV[place][2] = '\0';
                            i_MV[place] = 2;
                            if (place < 4)
                                G_V.M.if1.tab_settings[place] = SDLK_RIGHT;
                        }
                        else if (keystate[SDLK_LEFT])
                        {
                            MV[place][0] = 'l';
                            MV[place][1] = 'f';
                            MV[place][2] = '\0';
                            i_MV[place] = 2;
                            if (place < 4)
                                G_V.M.if1.tab_settings[place] = SDLK_LEFT;
                        }
                        else if (keystate[SDLK_SPACE])
                        {
                            MV[place][0] = 's';
                            MV[place][1] = 'p';
                            MV[place][2] = '\0';
                            i_MV[place] = 2;
                        }
                        else if (keystate[tab_sdl1[l]] && i_MV[place] <= 0)
                        {
                            MV[place][i_MV[place]] = (char)tab_sdl1[l];
                            if (place < 4)
                                G_V.M.if1.tab_settings[place] = tab_sdl1[l];
                            i_MV[place]++;
                            MV[place][i_MV[place]] = '\0';
                            break;
                        }
                    }
                    for (int ls = 0; ls < 5; ls++)
                    {
                        TTF_SizeText(t_setting[ls].font, MV[ls], &width, &hight);
                        t_setting[ls].postxt.x = G_V.O.opp[ls].pos1.x + G_V.O.opp[ls].img->w / 2 - width / 2;
                        t_setting[ls].postxt.y = G_V.O.opp[ls].pos1.y + G_V.O.opp[ls].img->h / 2 - hight / 2;
                        t_setting[ls].windtxt = TTF_RenderText_Blended(t_setting[ls].font, MV[ls], t_setting[ls].col);
                        SDL_BlitSurface(t_setting[ls].windtxt, NULL, G_V.window, &t_setting[ls].postxt);
                    }
                    break;
                case 9:
                    SDL_BlitSurface(G_V.O.op[14].img, NULL, G_V.window, &G_V.M.img_BK[33].pos1);
                    SDL_BlitSurface(G_V.O.op[G_V.M.if1.wich_character].img, NULL, G_V.window, &G_V.O.op[15].pos1);
                    SDL_BlitSurface(G_V.O.op[16].img, NULL, G_V.window, &G_V.O.op[16].pos1);
                    SDL_BlitSurface(G_V.O.op[17].img, NULL, G_V.window, &G_V.O.op[17].pos1);
                    G_V.O.op[5].pos1.y -= G_V.H * 0.05;
                    G_V.O.op[11].pos1.y -= G_V.H * 0.05;
                    SDL_BlitSurface(G_V.O.op[5].img, NULL, G_V.window, &G_V.O.op[5].pos1);
                    SDL_BlitSurface(G_V.O.op[11].img, NULL, G_V.window, &G_V.O.op[11].pos1);
                    G_V.O.op[5].pos1.y += G_V.H * 0.05;
                    G_V.O.op[11].pos1.y += G_V.H * 0.05;

                    break;
                }
                if (G_V.Is_butt_on[5])
                {
                    if (G_V.O.opstate == 1)
                        G_V.state = 0;
                    else
                        G_V.O.opstate = 1;
                }

                switch (G_V.event.type)
                {
                case SDL_QUIT:
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.out = 1;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    G_V.x1 = G_V.event.motion.x;
                    G_V.y1 = G_V.event.motion.y;
                    Mix_PlayChannel(-1, effect, 0);
                    // chosing the option
                    G_V.O.op[11].pos1.y -= G_V.H * 0.05;
                    if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[11].pos1) && G_V.O.opstate != 1)
                        G_V.O.opstate = 1;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[1].pos1) && G_V.O.opstate == 1)
                        G_V.O.opstate = 8;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[2].pos1) && G_V.O.opstate == 1)
                        G_V.O.opstate = 9;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[3].pos1) && G_V.O.opstate == 1)
                        G_V.O.opstate = 3;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[4].pos1) && G_V.O.opstate == 1)
                        G_V.O.opstate = 2;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[5].pos1))
                        G_V.O.opstate = 4;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[24].pos1) && G_V.O.opstate == 2)
                        G_V.M.if1.vol = 0;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[25].pos1) && G_V.O.opstate == 2)
                        G_V.M.if1.vol = 50;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.opp[0].pos1) && G_V.O.opstate == 8)
                        place = 0;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.opp[1].pos1) && G_V.O.opstate == 8)
                        place = 1;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.opp[2].pos1) && G_V.O.opstate == 8)
                        place = 2;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.opp[3].pos1) && G_V.O.opstate == 8)
                        place = 3;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.opp[4].pos1) && G_V.O.opstate == 8)
                        place = 4;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[16].pos1) && G_V.O.opstate == 9)
                        if (G_V.M.if1.wich_character == 15)
                            G_V.M.if1.wich_character = 32;
                        else
                            G_V.M.if1.wich_character = 15;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[17].pos1) && G_V.O.opstate == 9)
                        if (G_V.M.if1.wich_character == 15)
                            G_V.M.if1.wich_character = 32;
                        else
                            G_V.M.if1.wich_character = 15;
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[19].pos1) && G_V.O.opstate == 3)
                        
                        {
                            G_V.window = SDL_SetVideoMode(G_V.W, G_V.H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_FULLSCREEN);
                        }
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[20].pos1) && G_V.O.opstate == 3)
                            
                            {
                                G_V.window = SDL_SetVideoMode(G_V.W, G_V.H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                            }
                    G_V.O.op[11].pos1.y += G_V.H * 0.05;
                    break;
                case SDL_MOUSEMOTION:
                    G_V.x1 = G_V.event.motion.x;
                    G_V.y1 = G_V.event.motion.y;
                    if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[1].pos1) && G_V.O.opstate == 1)
                        SDL_BlitSurface(G_V.O.op[6].img, NULL, G_V.window, &G_V.O.op[1].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[2].pos1) && G_V.O.opstate == 1)
                        SDL_BlitSurface(G_V.O.op[7].img, NULL, G_V.window, &G_V.O.op[2].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[3].pos1) && G_V.O.opstate == 1)
                        SDL_BlitSurface(G_V.O.op[8].img, NULL, G_V.window, &G_V.O.op[3].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[4].pos1) && G_V.O.opstate == 1)
                        SDL_BlitSurface(G_V.O.op[9].img, NULL, G_V.window, &G_V.O.op[4].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[5].pos1) && G_V.O.opstate == 1)
                        SDL_BlitSurface(G_V.O.op[10].img, NULL, G_V.window, &G_V.O.op[5].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[19].pos1) && G_V.O.opstate == 3)
                        SDL_BlitSurface(G_V.O.op[21].img, NULL, G_V.window, &G_V.O.op[19].pos1);
                    else if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[20].pos1) && G_V.O.opstate == 3)
                        SDL_BlitSurface(G_V.O.op[22].img, NULL, G_V.window, &G_V.O.op[20].pos1);
                    else if (G_V.O.opstate == 8 || G_V.O.opstate == 9 || G_V.O.opstate == 3)
                    {
                        G_V.O.op[5].pos1.y -= G_V.H * 0.05;
                        if (is_in_rect(G_V.x1, G_V.y1, G_V.O.op[5].pos1))
                            SDL_BlitSurface(G_V.O.op[10].img, NULL, G_V.window, &G_V.O.op[5].pos1);
                        G_V.O.op[5].pos1.y += G_V.H * 0.05;
                    }
                    break;
                }
                G_V.end = SDL_GetTicks();
            }
            break;
        case 3:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 40)
            {
                if (G_V.Is_butt_on[5])
                {
                    for (int kk = 0; kk < 900; kk++)
                        SDL_FreeSurface(G_V.M.start[kk].img);
                    G_V.state = 4;
                }
                else
                {
                    switch (G_V.event.type)
                    {
                    case SDL_QUIT:
                        Mix_PlayChannel(-1, effect, 0);
                        G_V.out = 1;
                        break;
                    }
                    if (trailer < 900)
                        SDL_BlitSurface(G_V.M.start[trailer].img, NULL, G_V.window, NULL);
                    trailer++;
                    if (trailer > 950)
                    {
                        for (int kk = 0; kk < 900; kk++)
                            SDL_FreeSurface(G_V.M.start[kk].img);
                        G_V.state = 4;
                    }
                }
                G_V.end = G_V.start;
            }
            break;
        case 4:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 120)
            {
                switch (G_V.event.type)
                {
                case SDL_QUIT:
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.out = 1;
                    break;
                }
                if (cenem <= 71)
                {
                    SDL_BlitSurface(G_V.cematiques[cenem].img, NULL, G_V.window, NULL);
                    Mix_PlayMusic(typewriter1, -1);
                }
                cenem++;
                if (cenem >= 80)
                {
                    Mix_PlayMusic(sahara, -1);
                    cenem = 0;
                    G_V.state = 5;
                }
                G_V.end = SDL_GetTicks();
            }
            break;
        case 5:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 80)
            {
                G_V.NG.m.where = 2;
                switch (G_V.event.type)
                {
                case SDL_QUIT:
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.out = 1;
                    break;
                }
                if (G_V.Is_butt_on[5])
                {
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.state = 12;
                    G_V.M.back_up = 5;
                }
                // shosing the right state of the caratere
                if (G_V.NG.p.acc == 0)
                    G_V.NG.p.where = 0;
                if (G_V.NG.p.acc != 0)
                    G_V.NG.p.where = 1;
                // shosing the derection of runing
                if (G_V.NG.p.acc < 0)
                    G_V.NG.p.acc = 0;
                if (G_V.Is_butt_on[0])
                    G_V.NG.p.derec = 3;
                if (G_V.Is_butt_on[1])
                    G_V.NG.p.derec = 4;
                if (G_V.Is_butt_on[2])
                    G_V.NG.p.derec = 1;
                if (G_V.Is_butt_on[3])
                    G_V.NG.p.derec = 2;
                // giving the 2 bk ph the same pos
                G_V.NG.p.bk_pos2 = G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2;
                G_V.NG.e_cafe[4].cafe_img.pos1.x = 750 - G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2.x;
                G_V.NG.e_cafe[4].cafe_img.pos1.y = 200 - G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2.y;
                G_V.NG.e_cafe[4].cafe_img.pos2.x = 0;
                G_V.NG.e_cafe[4].cafe_img.pos2.y = 0;
                // detection of the collusion
                k = collisionPP(G_V.NG.p, G_V.NG.b_home.b_k[G_V.NG.b_home.coll_i].img);
                if (G_V.NG.p.image[G_V.NG.p.where].pos1.x >= 630 && G_V.NG.p.image[G_V.NG.p.where].pos1.x <= 660 && G_V.NG.p.image[G_V.NG.p.where].pos1.y <= 320)
                {
                    k = 1;
                    k3++;
                }
                if (k)
                {
                    G_V.NG.p.coll_derection = G_V.NG.p.derec;
                    G_V.NG.p.acc = 0;
                    if (G_V.NG.p.still_in)
                        G_V.NG.p.still_in2 = 1;
                }
                // decreasing the acceleration
                if (G_V.Is_butt_on[0] == 0 && G_V.Is_butt_on[1] == 0 && G_V.Is_butt_on[2] == 0 && G_V.Is_butt_on[3] == 0 && G_V.NG.p.acc > 0)
                    G_V.NG.p.acc -= 0.005;
                // increasing the acceleration
                else if (((G_V.Is_butt_on[0] || G_V.Is_butt_on[1] || G_V.Is_butt_on[2] || G_V.Is_butt_on[3])) && G_V.NG.p.coll_derection != G_V.NG.p.derec && G_V.NG.p.acc < 0.1)
                    G_V.NG.p.acc += 0.01;
                // turning on the scrolling
                if (G_V.NG.p.image[G_V.NG.p.where].pos1.x >= G_V.W / 2 && G_V.NG.p.derec == 3 && G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2.x + G_V.W < G_V.NG.b_home.b_k[G_V.NG.b_home.i].img->w && G_V.NG.p.acc > 0)
                    G_V.NG.p.scrolling_on = 1;
                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.x <= G_V.W / 2 && G_V.NG.p.derec == 4 && G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2.x > 0 && G_V.NG.p.acc > 0)
                    G_V.NG.p.scrolling_on = 1;
                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y >= G_V.H / 2 && G_V.NG.p.derec == 1 && G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2.y + G_V.H < G_V.NG.b_home.b_k[G_V.NG.b_home.i].img->h && G_V.NG.p.acc > 0)
                    G_V.NG.p.scrolling_on = 1;
                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y <= G_V.H / 2 && G_V.NG.p.derec == 2 && G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2.y > 0 && G_V.NG.p.acc > 0)
                    G_V.NG.p.scrolling_on = 1;
                // the jump
                printf("%d %d\n", G_V.NG.p.still_in, G_V.NG.p.still_in2);
                if (G_V.NG.p.still_in2)
                {
                    G_V.NG.p.still_in = 0;
                    G_V.NG.p.image[G_V.NG.p.where].pos1.y += 10;
                    if (G_V.NG.p.image[G_V.NG.p.where].pos1.y >= G_V.NG.p.y)
                        G_V.NG.p.still_in2 = 0;
                }
                if (G_V.NG.p.still_in2)
                {
                    G_V.NG.p.still_in = 0;
                    G_V.NG.p.image[G_V.NG.p.where].pos1.y += 10;
                    if (G_V.NG.p.image[G_V.NG.p.where].pos1.y >= G_V.NG.p.y)
                        G_V.NG.p.still_in2 = 0;
                }
                if (G_V.NG.p.still_in)
                    saut(&G_V.NG.p);
                else if (G_V.Is_butt_on[6])
                {
                    G_V.NG.p.y = G_V.NG.p.image[G_V.NG.p.where].pos1.y;
                    G_V.NG.p.still_in = 1;
                    G_V.NG.p.i = -60;
                }
                if (G_V.NG.p.scrolling_on)
                {
                    scrolling(&G_V.NG.b_home, G_V.NG.p.derec, 0.5 * G_V.NG.p.acc * 17 * 17 + G_V.NG.p.speed * 17);
                    G_V.NG.p.scrolling_on = 0;
                }
                else
                    deplacerPerso(&G_V.NG.p, 17);
                animerPerso(&G_V.NG.p);
                aficherBack(G_V.NG.b_home, G_V.window);
                afficherPerso(G_V.NG.p, G_V.window);
                G_V.NG.m.where = 2;
                afficherminimap(G_V.NG.m, G_V.window);
                //  detecting the position of the caratere in the minmap
                G_V.NG.m.bk_pos2 = G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2;
                G_V.camera_pos = MAJMinimap(G_V.NG.p.image->pos1, &G_V.NG.m, G_V.camera_pos, G_V.NG.m.redemtion[G_V.NG.m.where]);
                SDL_FillRect(G_V.window, &G_V.camera_pos, G_V.NG.m.col);

                afficherEnnemi_pro(G_V.NG.e_cafe[4], G_V.window);
                if (k3)
                    show_bubble(&G_V, G_V.NG.e_cafe[4], 3);
                if (k3 >= 140)
                {
                    G_V.state = 6;
                    k3 = 0;
                }
                G_V.end = SDL_GetTicks();
            }
            break;
        case 6:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 120)
            {
                switch (G_V.event.type)
                {
                case SDL_QUIT:
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.out = 1;
                    break;
                }
                if (cenem == 19)
                    cenem = 72;
                if (cenem <= 19)
                {
                    SDL_BlitSurface(G_V.cematiques[cenem].img, NULL, G_V.window, NULL);
                    Mix_PlayMusic(typewriter2, -1);
                }
                if (cenem >= 72 && cenem <= 113)
                {
                    SDL_BlitSurface(G_V.cematiques[cenem].img, NULL, G_V.window, NULL);
                }
                cenem++;
                if (cenem >= 120)
                {
                    cenem = 0;
                    G_V.state = 7;
                    G_V.NG.p.image[0].pos1.x = 100;
                    G_V.NG.p.image[0].pos1.y = 600;
                    G_V.NG.p.image[1].pos1.x = 100;
                    G_V.NG.p.image[1].pos1.y = 600;
                    G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.x = 0;
                    G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.y = G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].img->h - G_V.NG.b_cafe.H;
                    G_V.NG.p.acc = 0;
                    k = 0;
                    k3 = 0;
                    Mix_PlayMusic(kahwa, -1);
                }
                G_V.end = SDL_GetTicks();
            }
            break;
        case 7:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 80)
            {
                keystate = SDL_GetKeyState(NULL);
                if (keystate[SDLK_a] && keystate[SDLK_p])
                    G_V.state = 6;

                if (G_V.Is_butt_on[5])
                {
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.state = 12;
                    G_V.M.back_up = 7;
                }
                // shosing the right state of the caratere
                if (G_V.NG.p.acc == 0)
                    G_V.NG.p.where = 0;
                if (G_V.NG.p.acc != 0)
                    G_V.NG.p.where = 1;
                // shosing the derection of runing
                if (G_V.NG.p.acc < 0)
                    G_V.NG.p.acc = 0;
                if (G_V.Is_butt_on[0])
                    G_V.NG.p.derec = 3;
                if (G_V.Is_butt_on[1])
                    G_V.NG.p.derec = 4;
                if (G_V.Is_butt_on[2])
                    G_V.NG.p.derec = 1;
                if (G_V.Is_butt_on[3])
                    G_V.NG.p.derec = 2;
                // giving the 2 bk ph the same pos
                G_V.NG.p.bk_pos2 = G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2;
                // detection of the collusion
                k = collisionPP_persone(G_V.NG.p, G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 0);
                if (!k)
                    k = collisionPP(G_V.NG.p, G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img);

                if (k)
                {
                    G_V.NG.p.coll_derection = G_V.NG.p.derec;
                    G_V.NG.p.acc = 0;
                    if (G_V.NG.p.still_in)
                        G_V.NG.p.still_in2 = 1;
                }
                // decreasing the acceleration
                if (G_V.Is_butt_on[0] == 0 && G_V.Is_butt_on[1] == 0 && G_V.Is_butt_on[2] == 0 && G_V.Is_butt_on[3] == 0 && G_V.NG.p.acc > 0)
                    G_V.NG.p.acc -= 0.005;
                // increasing the acceleration
                else if (((G_V.Is_butt_on[0] || G_V.Is_butt_on[1] || G_V.Is_butt_on[2] || G_V.Is_butt_on[3])) && G_V.NG.p.coll_derection != G_V.NG.p.derec && G_V.NG.p.acc < 0.07)
                    G_V.NG.p.acc += 0.01;
                // turning on the scrolling
                if (G_V.NG.p.image[G_V.NG.p.where].pos1.x >= G_V.W / 2 && G_V.NG.p.derec == 3 && G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.x + G_V.W < G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].img->w && G_V.NG.p.acc > 0)
                    G_V.NG.p.scrolling_on = 1;
                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.x <= G_V.W / 2 && G_V.NG.p.derec == 4 && G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.x > 0 && G_V.NG.p.acc > 0)
                    G_V.NG.p.scrolling_on = 1;
                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y >= G_V.H / 2 && G_V.NG.p.derec == 1 && G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.y + G_V.H < G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].img->h && G_V.NG.p.acc > 0)
                    G_V.NG.p.scrolling_on = 1;
                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y <= G_V.H / 2 && G_V.NG.p.derec == 2 && G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.y > 0 && G_V.NG.p.acc > 0)
                    G_V.NG.p.scrolling_on = 1;
                // the jump
                if (G_V.NG.p.still_in2)
                {
                    G_V.NG.p.still_in = 0;
                    G_V.NG.p.image[G_V.NG.p.where].pos1.y += 10;
                    if (G_V.NG.p.image[G_V.NG.p.where].pos1.y >= G_V.NG.p.y)
                        G_V.NG.p.still_in2 = 0;
                }
                if (G_V.NG.p.still_in)
                    saut(&G_V.NG.p);
                else if (G_V.Is_butt_on[6])
                {
                    G_V.NG.p.y = G_V.NG.p.image[G_V.NG.p.where].pos1.y;
                    G_V.NG.p.still_in = 1;
                    G_V.NG.p.i = -60;
                }
                if (G_V.NG.p.scrolling_on)
                {
                    scrolling(&G_V.NG.b_cafe, G_V.NG.p.derec, 0.5 * G_V.NG.p.acc * 17 * 17 + G_V.NG.p.speed * 17);
                    G_V.NG.p.scrolling_on = 0;
                }
                else
                    deplacerPerso(&G_V.NG.p, 17);
                animerPerso(&G_V.NG.p);
                aficherBack(G_V.NG.b_cafe, G_V.window);
                afficherPerso(G_V.NG.p, G_V.window);

                if (county > 0 && county < 30)
                {
                    county++;
                    if (ani < 51)
                    {
                        ani++;
                        annimertic(G_V.window, ani, T);
                    }
                    if (ani == 50)
                        ani = 1;
                    Resultat(G_V.window, t, G_V.W, G_V.H);
                }
                else
                {
                    county = 0;
                    if (!k3)
                        k3 = collisionPP_persone(G_V.NG.p, G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 255, 0);
                    if (k3)
                    {
                        if (ani < 51)
                        {
                            ani++;
                            annimertic(G_V.window, ani, T);
                        }
                        if (ani == 50)
                            ani = 1;

                        if (tiktak == 1)
                        {

                            afficherTic(t, G_V.window, G_V.W / 4);
                            if (t.nbtour < 9 && atilgagne(t.tab) == 0)
                            {

                                if ((t.nbtour + t.joueur) % 2 == 0)
                                {
                                    calcul_coup(t.tab);
                                    t.nbtour++;
                                }
                                else
                                {
                                    SDL_WaitEvent(&G_V.event);

                                    if (G_V.event.type == SDL_MOUSEBUTTONUP && G_V.event.motion.x < (t.b->w + G_V.W / 4) && G_V.event.motion.x > G_V.W / 4)
                                    {
                                        X = (G_V.event.button.x - G_V.W / 4) / ((t.b->w / 3));
                                        Y = (G_V.event.button.y) / ((t.b->w / 3));
                                        coup = 3 * Y + X;
                                        t.tab[coup] = -1;
                                        // printf("%d \n", t.nbtour);
                                        t.nbtour++;
                                    }
                                }
                            }
                            else if (atilgagne(t.tab) == 0)
                            {

                                texte = TTF_RenderText_Blended(t.T, "DRAW", textColor);
                                SDL_BlitSurface(texte, NULL, G_V.window, &posRESULT);
                                k3 = 0;
                                tiktak = 0;
                                G_V.NG.b_cafe.coll_i = 6;
                            }
                            else
                            {
                                county = 1;
                                k3 = 0;
                                tiktak = 0;
                                G_V.NG.b_cafe.coll_i = 6;
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < 6; i++)
                        {

                            G_V.NG.e_cafe[i].bk_pos2 = G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2;
                            if (collisionBB_pro(G_V.NG.e_cafe[i], G_V.NG.p) && i != 5)
                            {
                                if (G_V.NG.p.derec == 4)
                                {
                                    G_V.NG.e_cafe[i].cafe_img.pos2.x = 0;
                                    G_V.NG.e_cafe[i].cafe_img.pos2.y = 0;
                                    G_V.bubbles[bubb_i[i]].pos1.x = G_V.NG.e_cafe[i].cafe_img.pos1.x - G_V.bubbles[bubb_i[i]].img->w;
                                    G_V.bubbles[bubb_i[i]].pos1.y = G_V.NG.e_cafe[i].cafe_img.pos1.y - G_V.bubbles[bubb_i[i]].img->h + 50;
                                    SDL_BlitSurface(G_V.bubbles[bubb_i[i]].img, NULL, G_V.window, &G_V.bubbles[bubb_i[i]].pos1);
                                }
                                else if (G_V.NG.p.derec == 3)
                                {
                                    G_V.NG.e_cafe[i].cafe_img.pos2.x = 0;
                                    G_V.NG.e_cafe[i].cafe_img.pos2.y = 0;
                                    G_V.bubbles[bubb_i[i + 5]].pos1.x = G_V.NG.e_cafe[i].cafe_img.pos1.x + G_V.NG.e_cafe[i].cafe_img.img->w / 4;
                                    G_V.bubbles[bubb_i[i + 5]].pos1.y = G_V.NG.e_cafe[i].cafe_img.pos1.y - G_V.bubbles[bubb_i[i + 5]].img->h + 100;
                                    SDL_BlitSurface(G_V.bubbles[bubb_i[i + 5]].img, NULL, G_V.window, &G_V.bubbles[bubb_i[i + 5]].pos1);
                                }
                            }
                            else
                            {
                                k1 = collisionPP_persone(G_V.NG.p, G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 0);
                                G_V.NG.e_cafe[i].coll = collisionPP_char(G_V.NG.e_cafe[i], G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 0);
                                if (G_V.NG.e_cafe[5].stay == 4 && !k1)
                                {
                                    G_V.NG.e_cafe[5].stay = 0;
                                    G_V.NG.e_cafe[5].coll_derection = 0;
                                    G_V.NG.e_cafe[5].coll = 0;
                                    G_V.exit_if[0][0] = 1;
                                    G_V.exit_if[0][1] = 1;
                                    G_V.exit_if[0][2] = 1;
                                    G_V.exit_if[1][0] = 1;
                                    G_V.exit_if[1][1] = 1;
                                    G_V.exit_if[1][2] = 1;
                                    G_V.exit_if[2][0] = 1;
                                    G_V.exit_if[2][1] = 1;
                                    G_V.exit_if[2][2] = 1;
                                }
                                else if (k1)
                                {
                                    if (G_V.NG.p.derec == 2)
                                    {
                                        if (G_V.NG.p.image[G_V.NG.p.where].pos1.y > G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[0][0])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 3;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] += 2;
                                            G_V.NG.e_cafe[5].derection = 1;
                                        }
                                        else if (G_V.NG.p.image[G_V.NG.p.where].pos1.x > G_V.NG.e_cafe[5].cafe_img.pos1.x && G_V.exit_if[0][1])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 1;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[0] += 2;
                                            G_V.NG.e_cafe[5].derection = 3;
                                            G_V.exit_if[0][0] = 0;
                                        }
                                        else if (G_V.NG.p.image[G_V.NG.p.where].pos1.x < G_V.NG.e_cafe[5].cafe_img.pos1.x && G_V.exit_if[0][2])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 2;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[0] -= 2;
                                            G_V.NG.e_cafe[5].derection = 2;
                                            G_V.exit_if[0][1] = 0;
                                        }
                                        else
                                        {
                                            G_V.exit_if[0][2] = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.x = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.y = 0;
                                            G_V.NG.e_cafe[5].stay = 4;
                                            G_V.NG.e_cafe[5].derection = 1;
                                        }
                                        if (collisionPP_char(G_V.NG.e_cafe[5], G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 255))
                                        {
                                            if (G_V.exit_if[0][0])
                                                G_V.exit_if[0][0] = 0;
                                            else if (G_V.exit_if[0][1])
                                                G_V.exit_if[0][1] = 0;
                                            else if (G_V.exit_if[0][2])
                                                G_V.exit_if[0][2] = 0;
                                        }
                                    }
                                    else if (G_V.NG.p.derec == 4)
                                    {
                                        if (G_V.NG.p.image[G_V.NG.p.where].pos1.y + G_V.NG.p.image[G_V.NG.p.where].pos2.h > G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[1][0])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 3;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] += 2;
                                            G_V.NG.e_cafe[5].derection = 1;
                                        }
                                        else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y + G_V.NG.p.image[G_V.NG.p.where].pos2.h < G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[1][1])
                                        {
                                            G_V.exit_if[1][0] = 0;
                                            // G_V.NG.e_cafe[5].func_num = 4;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] -= 2;
                                            G_V.NG.e_cafe[5].derection = 4;
                                        }
                                        else if (G_V.NG.e_cafe[5].cafe_img.pos1.x + G_V.NG.e_cafe[5].cafe_img.pos2.w < G_V.NG.p.image[G_V.NG.p.where].pos1.x && G_V.exit_if[1][2])
                                        {

                                            G_V.exit_if[1][1] = 0;
                                            // G_V.NG.e_cafe[5].func_num = 1;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[0] += 2;
                                            G_V.NG.e_cafe[5].derection = 3;
                                        }
                                        else
                                        {
                                            G_V.exit_if[1][2] = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.x = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.y = 2 * G_V.NG.e_cafe[5].cafe_img.pos2.h;
                                            G_V.NG.e_cafe[5].stay = 4;
                                            G_V.NG.e_cafe[5].derection = 3;
                                        }
                                        if (collisionPP_char(G_V.NG.e_cafe[5], G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 255))
                                        {
                                            if (G_V.exit_if[1][0])
                                                G_V.exit_if[1][0] = 0;
                                            else if (G_V.exit_if[1][1])
                                                G_V.exit_if[1][1] = 0;
                                            else if (G_V.exit_if[1][2])
                                                G_V.exit_if[1][2] = 0;
                                        }
                                        // printf("exit %d %d %d\n",G_V.exit_if[1][0],G_V.exit_if[1][1],G_V.exit_if[1][2]);
                                    }
                                    else if (G_V.NG.p.derec == 3)
                                    {

                                        if (G_V.NG.p.image[G_V.NG.p.where].pos1.y + G_V.NG.p.image[G_V.NG.p.where].pos2.h > G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[2][0])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 3;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] += 2;
                                            G_V.NG.e_cafe[5].derection = 1;
                                        }
                                        else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y + G_V.NG.p.image[G_V.NG.p.where].pos2.h < G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[2][1])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 4;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] -= 2;
                                            G_V.NG.e_cafe[5].derection = 4;
                                            G_V.exit_if[2][0] = 0;
                                        }
                                        else if (G_V.NG.e_cafe[5].cafe_img.pos1.x > G_V.NG.p.image[G_V.NG.p.where].pos1.x + G_V.NG.p.image[G_V.NG.p.where].pos2.w && G_V.exit_if[2][2])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 2;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[0] -= 2;
                                            G_V.NG.e_cafe[5].derection = 2;
                                            G_V.exit_if[2][1] = 0;
                                        }
                                        else
                                        {
                                            G_V.exit_if[2][2] = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.x = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.y = G_V.NG.e_cafe[5].cafe_img.pos2.h;
                                            G_V.NG.e_cafe[5].stay = 4;
                                            G_V.NG.e_cafe[5].derection = 4;
                                        }
                                        if (collisionPP_char(G_V.NG.e_cafe[5], G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 255))
                                        {
                                            if (G_V.exit_if[2][0])
                                                G_V.exit_if[2][0] = 0;
                                            else if (G_V.exit_if[2][1])
                                                G_V.exit_if[2][1] = 0;
                                            else if (G_V.exit_if[2][2])
                                                G_V.exit_if[2][2] = 0;
                                        }
                                    }
                                    if (G_V.NG.e_cafe[5].stay == 2)
                                        animerEnnemie_pro(&G_V.NG.e_cafe[5]);
                                }
                                if (G_V.NG.e_cafe[i].coll && i != 5)
                                {
                                    for (G_V.j = 0; G_V.j < 5; G_V.j++)
                                        if (G_V.reception[G_V.j] == i)
                                            break;
                                        else if (G_V.reception[G_V.j] == -1)
                                        {
                                            G_V.reception[G_V.j] = i;
                                            G_V.NG.e_cafe[i].stay++;
                                            break;
                                        }
                                    if (G_V.NG.e_cafe[G_V.reception[0]].derection == 4 && !k1 && G_V.NG.e_cafe[5].stay != 3)
                                    {

                                        if (G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.y > G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[3][0])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 3;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] += 4;
                                            G_V.NG.e_cafe[5].derection = 1;
                                        }
                                        else if (G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.x > G_V.NG.e_cafe[5].cafe_img.pos1.x && G_V.exit_if[3][1])
                                        {
                                            G_V.exit_if[3][0] = 0;
                                            // G_V.NG.e_cafe[5].func_num = 1;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[0] += 4;
                                            G_V.NG.e_cafe[5].derection = 3;
                                        }
                                        else if (G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.x < G_V.NG.e_cafe[5].cafe_img.pos1.x && G_V.exit_if[3][2])
                                        {
                                            G_V.exit_if[3][1] = 0;
                                            // G_V.NG.e_cafe[5].func_num = 2;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[0] -= 4;
                                            G_V.NG.e_cafe[5].derection = 2;
                                        }
                                        else
                                        {
                                            G_V.exit_if[3][2] = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.x = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.y = 0;
                                            G_V.NG.e_cafe[5].stay = 3;
                                            G_V.NG.e_cafe[5].derection = 1;
                                        }
                                        if (collisionPP_char(G_V.NG.e_cafe[5], G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 255))
                                        {
                                            if (G_V.exit_if[3][0])
                                                G_V.exit_if[3][0] = 0;
                                            else if (G_V.exit_if[3][1])
                                                G_V.exit_if[3][1] = 0;
                                            else if (G_V.exit_if[3][2])
                                                G_V.exit_if[3][2] = 0;
                                        }
                                    }
                                    else if (G_V.NG.e_cafe[G_V.reception[0]].derection == 2 && !k1 && G_V.NG.e_cafe[5].stay != 3)
                                    {
                                        if (G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.y + G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos2.h > G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[4][0])
                                        {

                                            // G_V.NG.e_cafe[5].func_num = 3;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] += 4;
                                            G_V.NG.e_cafe[5].derection = 1;
                                        }
                                        else if (G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.y + G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos2.h < G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[4][1])
                                        {
                                            G_V.exit_if[4][0] = 0;
                                            // G_V.NG.e_cafe[5].func_num = 4;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] -= 4;
                                            G_V.NG.e_cafe[5].derection = 4;
                                        }
                                        else if (G_V.NG.e_cafe[5].cafe_img.pos1.x + G_V.NG.e_cafe[5].cafe_img.pos2.w < G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.x && G_V.exit_if[4][2])
                                        {
                                            G_V.exit_if[4][1] = 0;
                                            // G_V.NG.e_cafe[5].func_num = 1;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[0] += 4;
                                            G_V.NG.e_cafe[5].derection = 3;
                                        }
                                        else
                                        {
                                            G_V.exit_if[4][2] = 2;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.x = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.y = 2 * G_V.NG.e_cafe[5].cafe_img.pos2.h;
                                            G_V.NG.e_cafe[5].stay = 3;
                                            G_V.NG.e_cafe[5].derection = 3;
                                        }
                                        if (collisionPP_char(G_V.NG.e_cafe[5], G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 255))
                                        {
                                            if (G_V.exit_if[4][0])
                                                G_V.exit_if[4][0] = 0;
                                            else if (G_V.exit_if[4][1])
                                                G_V.exit_if[4][1] = 0;
                                            else if (G_V.exit_if[4][2])
                                                G_V.exit_if[4][2] = 0;
                                        }
                                    }
                                    else if (G_V.NG.e_cafe[G_V.reception[0]].derection == 3 && !k1 && G_V.NG.e_cafe[5].stay != 3)
                                    {

                                        if (G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.y + G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos2.h > G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[5][0])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 3;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] += 4;
                                            G_V.NG.e_cafe[5].derection = 1;
                                        }
                                        else if (G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.y + G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos2.h < G_V.NG.e_cafe[5].cafe_img.pos1.y + G_V.NG.e_cafe[5].cafe_img.pos2.h && G_V.exit_if[5][1])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 4;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[1] -= 4;
                                            G_V.NG.e_cafe[5].derection = 4;
                                            G_V.exit_if[5][0] = 0;
                                        }
                                        else if (G_V.NG.e_cafe[5].cafe_img.pos1.x > G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos1.x + G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos2.w && G_V.exit_if[5][2])
                                        {
                                            // G_V.NG.e_cafe[5].func_num = 2;
                                            G_V.NG.e_cafe[5].stay = 2;
                                            G_V.NG.e_cafe[5].MV_destance[0] -= 4;
                                            G_V.NG.e_cafe[5].derection = 2;
                                            G_V.exit_if[5][1] = 0;
                                        }
                                        else
                                        {
                                            G_V.exit_if[5][2] = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.x = 0;
                                            G_V.NG.e_cafe[5].cafe_img.pos2.y = G_V.NG.e_cafe[5].cafe_img.pos2.h;
                                            G_V.NG.e_cafe[5].stay = 3;
                                            G_V.NG.e_cafe[5].derection = 2;
                                        }
                                        if (collisionPP_char(G_V.NG.e_cafe[5], G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 255))
                                        {
                                            if (G_V.exit_if[5][0])
                                                G_V.exit_if[5][0] = 0;
                                            else if (G_V.exit_if[5][1])
                                                G_V.exit_if[5][1] = 0;
                                            else if (G_V.exit_if[5][2])
                                                G_V.exit_if[5][2] = 0;
                                        }
                                    }
                                    if (G_V.NG.e_cafe[5].stay == 2 && !k1)
                                        animerEnnemie_pro(&G_V.NG.e_cafe[5]);
                                    G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos2.x = 0;
                                    G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos2.y = (G_V.NG.e_cafe[G_V.reception[0]].cafe_img.pos2.h) * (G_V.NG.e_cafe[G_V.reception[0]].derection - 1);
                                    G_V.NG.e_cafe[G_V.reception[0]].stay++;
                                    if (G_V.NG.e_cafe[G_V.reception[0]].stay >= 80)
                                    {
                                        if (G_V.NG.e_cafe[G_V.reception[0]].derection == 3)
                                            G_V.NG.e_cafe[G_V.reception[0]].func_num = 2;
                                        else if (G_V.NG.e_cafe[G_V.reception[0]].derection == 2)
                                            G_V.NG.e_cafe[G_V.reception[0]].func_num = 1;
                                        else if (G_V.NG.e_cafe[G_V.reception[0]].derection == 3)
                                            G_V.NG.e_cafe[G_V.reception[0]].func_num = 4;
                                        else if (G_V.NG.e_cafe[G_V.reception[0]].derection == 4)
                                            G_V.NG.e_cafe[G_V.reception[0]].func_num = 3;

                                        G_V.NG.e_cafe[G_V.reception[0]].stay = 0;
                                        G_V.NG.e_cafe[5].stay = 0;
                                        if (i == 0 || i == 1)
                                            deplacer_pro_1(&G_V.NG.e_cafe[G_V.reception[0]]);
                                        else
                                            deplacer_pro(&G_V.NG.e_cafe[G_V.reception[0]]);
                                        deplacer_pro(&G_V.NG.e_cafe[5]);
                                        G_V.NG.e_cafe[G_V.reception[0]].coll_derection = 0;
                                        animerEnnemie_pro(&G_V.NG.e_cafe[G_V.reception[0]]);
                                        animerEnnemie_pro(&G_V.NG.e_cafe[5]);
                                        for (G_V.j = 0; G_V.j < 4; G_V.j++)
                                            G_V.reception[G_V.j] = G_V.reception[G_V.j + 1];
                                        G_V.reception[4] = -1;
                                        G_V.NG.e_cafe[G_V.reception[0]].coll = 0;

                                        G_V.exit_if[3][0] = 1;
                                        G_V.exit_if[3][1] = 1;
                                        G_V.exit_if[3][2] = 1;
                                        G_V.exit_if[4][0] = 1;
                                        G_V.exit_if[4][1] = 1;
                                        G_V.exit_if[4][2] = 1;
                                        G_V.exit_if[5][0] = 1;
                                        G_V.exit_if[5][1] = 1;
                                        G_V.exit_if[5][2] = 1;
                                    }
                                }
                                if (G_V.NG.e_cafe[i].stay == 0)
                                {
                                    G_V.NG.e_cafe[i].bk_pos2 = G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2;
                                    G_V.NG.e_cafe[i].coll = collisionPP_char(G_V.NG.e_cafe[i], G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 0, 0, 255);
                                    if (G_V.NG.e_cafe[i].coll && G_V.NG.e_cafe[i].coll_derection != G_V.NG.e_cafe[i].derection)
                                    {
                                        G_V.NG.e_cafe[i].coll_derection = G_V.NG.e_cafe[i].derection;
                                        if (G_V.NG.e_cafe[i].derection == 3)
                                            G_V.NG.e_cafe[i].func_num = 2;
                                        else if (G_V.NG.e_cafe[i].derection == 2)
                                            G_V.NG.e_cafe[i].func_num = 1;
                                        else if (G_V.NG.e_cafe[i].derection == 1)
                                            G_V.NG.e_cafe[i].func_num = 4;
                                        else if (G_V.NG.e_cafe[i].derection == 4)
                                            G_V.NG.e_cafe[i].func_num = 3;
                                    }
                                    else
                                        G_V.NG.e_cafe[i].coll_derection = 0;
                                    if (i == 0 || i == 1)
                                        deplacer_pro_1(&G_V.NG.e_cafe[i]);
                                    else
                                        deplacer_pro(&G_V.NG.e_cafe[i]);
                                    animerEnnemie_pro(&G_V.NG.e_cafe[i]);
                                }
                                if (G_V.reception[0] != -1 && G_V.NG.e_cafe[5].stay == 3 && !k1)
                                    show_bubble(&G_V, G_V.NG.e_cafe[G_V.reception[0]], 1);
                                else if (G_V.NG.e_cafe[5].stay == 4 && k1)
                                    show_bubble(&G_V, G_V.NG.e_cafe[G_V.reception[0]], 2);
                            }
                            G_V.NG.e_cafe[i].cafe_img.pos1.x = G_V.NG.e_cafe[i].real_pos.x - G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.x + G_V.NG.e_cafe[i].MV_destance[0];
                            G_V.NG.e_cafe[i].cafe_img.pos1.y = G_V.NG.e_cafe[i].real_pos.y - G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.y + G_V.NG.e_cafe[i].MV_destance[1];
                            afficherEnnemi_pro(G_V.NG.e_cafe[i], G_V.window);
                            // printf("omar detection %d %d %d %d %d %d %d\n",i,G_V.reception[0],G_V.NG.e_cafe[5].stay,G_V.NG.e_cafe[i].stay,G_V.NG.e_cafe[5].coll,k1,G_V.NG.e_cafe[i].coll);
                        }
                        //  detecting the position of the caratere in the minmap
                        G_V.NG.m.bk_pos2 = G_V.NG.b.b_k[G_V.NG.b.i].pos2;
                        G_V.camera_pos = MAJMinimap(G_V.NG.p.image->pos1, &G_V.NG.m, G_V.camera_pos, G_V.NG.m.redemtion[G_V.NG.m.where]);

                        letter[0].pos1.x = G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].img->w / 2 - G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.x + 30;
                        letter[0].pos1.y = G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].img->h / 2 - G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.y;
                        if (letter_count == 0)
                            SDL_BlitSurface(letter[0].img, NULL, G_V.window, &letter[0].pos1);
                        letter[0].pos1.x -= 150;
                        letter[0].pos1.y -= 75;
                        letter[0].pos1.w += 400;
                        letter[0].pos1.h += 200;
                        // SDL_FillRect(G_V.window,&letter[0].pos1,G_V.col1);
                        if (is_in_rect(G_V.NG.p.image[G_V.NG.p.where].pos1.x, G_V.NG.p.image[G_V.NG.p.where].pos1.y, letter[0].pos1))
                        {
                            letter[letter_i].pos1.x = G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].img->w / 2 - G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.x;
                            letter[letter_i].pos1.y = G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].img->h / 2 - G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.i].pos2.y;
                            SDL_BlitSurface(letter[letter_i].img, NULL, G_V.window, &letter[letter_i].pos1);
                            if (letter_i < 9)
                                letter_i++;
                            letter_count++;
                            if (letter_i >= 9 && letter_count % 5 == 0 && letter_i < 12)
                                letter_i++;
                        }
                        else
                        {
                            letter_i = 0;
                            letter_count = 0;
                        }

                        if (collisionPP_persone(G_V.NG.p, G_V.NG.b_cafe.b_k[G_V.NG.b_cafe.coll_i].img, 255, 0, 0) && i_pass <= 10)
                        {
                            SDL_BlitSurface(password[0].img, NULL, G_V.window, &password[0].pos1);
                            SDL_BlitSurface(password[1].img, NULL, G_V.window, &password[1].pos1);
                            for (int l = 0; l < 27; l++)
                            {
                                if (keystate[tab_sdl1[l]] && tab_sdl1[l] == SDLK_BACKSPACE && i_pass > 0)
                                {
                                    pass[i_pass - 1] = '\0';
                                    i_pass--;
                                    break;
                                }
                                else if (keystate[tab_sdl1[l]])
                                {
                                    pass[i_pass] = (char)tab_sdl1[l];
                                    i_pass++;
                                    pass[i_pass] = '\0';
                                    break;
                                }
                            }
                            TTF_SizeText(t_password.font, pass, &width, &hight);
                            t_password.postxt.x = G_V.W / 2 - width / 2;
                            t_password.postxt.y = G_V.H / 2 - hight / 2;
                            t_password.windtxt = TTF_RenderText_Blended(t_password.font, pass, t_password.col);
                            SDL_BlitSurface(t_password.windtxt, NULL, G_V.window, &t_password.postxt);
                        }
                        switch (G_V.event.type)
                        {
                        case SDL_QUIT:
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.out = 1;
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            G_V.x1 = G_V.event.motion.x;
                            G_V.y1 = G_V.event.motion.y;
                            /*pos_pass.x = 683;
                            pos_pass.y = 425;
                            pos_pass.w = 101;
                            pos_pass.h = 25;*/
                            if (is_in_rect(G_V.x1, G_V.y1, password[1].pos1) && G_V.state == 7 && strcmp(pass, "resist") == 0)
                            {
                                Mix_PlayChannel(-1, effect, 0);
                                G_V.state = 8;
                            }
                            if (is_in_rect(G_V.x1, G_V.y1, password[1].pos1) && G_V.state == 7 && strcmp(pass, "resist") != 0)
                            {
                                Mix_PlayChannel(-1, effect, 0);
                                pss_in = 1;
                                // SDL_BlitSurface(password[2].img, NULL, G_V.window, &password[2].pos1);
                            }
                        }
                        if (pss_in)
                        {
                            SDL_BlitSurface(password[2].img, NULL, G_V.window, &password[2].pos1);
                            pss_in++;
                        }
                        if (pss_in > 10)
                            pss_in = 0;
                    }
                }
                // G_V.state = 6;
                G_V.NG.m.where = 3;
                afficherminimap(G_V.NG.m, G_V.window);
                //  detecting the position of the caratere in the minmap
                G_V.NG.m.bk_pos2 = G_V.NG.b_home.b_k[G_V.NG.b_home.i].pos2;
                G_V.camera_pos = MAJMinimap(G_V.NG.p.image->pos1, &G_V.NG.m, G_V.camera_pos, G_V.NG.m.redemtion[G_V.NG.m.where]);
                SDL_FillRect(G_V.window, &G_V.camera_pos, G_V.NG.m.col);
                G_V.end = SDL_GetTicks();
            }
            break;
        case 8:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 120)
            {
                switch (G_V.event.type)
                {
                case SDL_QUIT:
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.out = 1;
                    break;
                }
                if (cenem == 19)
                    cenem = 114;
                if (cenem <= 19)
                {
                    SDL_BlitSurface(G_V.cematiques[cenem].img, NULL, G_V.window, NULL);
                    Mix_PlayMusic(typewriter3, -1);
                }
                else if (cenem >= 114 && cenem < 146)
                    SDL_BlitSurface(G_V.cematiques[cenem].img, NULL, G_V.window, NULL);
                cenem++;
                if (cenem >= 180)
                {
                    cenem = 0;
                    G_V.state = 9;
                    G_V.NG.p.image[0].pos1.x = 100;
                    G_V.NG.p.image[0].pos1.y = 300;
                    G_V.NG.p.image[1].pos1.x = 100;
                    G_V.NG.p.image[1].pos1.y = 300;
                }
                G_V.end = SDL_GetTicks();
            }
            break;
        case 9:
            if (!playingEscapeMusic)
            {
                Mix_PlayMusic(chase, -1);
                playingEscapeMusic = 1;
            }
            keystate = SDL_GetKeyState(NULL);
            if (keystate[SDLK_a] == 1 && keystate[SDLK_p] == 1)
            {
                G_V.state = 8;
                printf("i am in\n");
            }
            if (singleplayer)
            {
                if (!tutoDisplayed)
                {
                    switch (G_V.event.type)
                    {

                    case SDL_QUIT:
                        Mix_PlayChannel(-1, effect, 0);
                        G_V.out = 1;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (G_V.event.button.button == SDL_BUTTON_RIGHT)
                        {
                            if (!pr.thrown && G_V.NG.p.panana > 0 && !rightMousePressed && G_V.NG.p.stamina > 3200)
                            {
                                pr.thrown = 1;
                                G_V.NG.p.panana--;
                                rightMousePressed = 1;
                                if (G_V.NG.p.recovery == 0)
                                    G_V.NG.p.stamina -= 200;
                            }
                        }
                        break;
                    default:
                        rightMousePressed = 0;
                        break;
                    }

                    posGO.y = 200;
                    if (!G_V.NG.p.initlevel)
                    {
                        G_V.NG.p.image[0].pos1.x = 200;
                        G_V.NG.p.image[0].pos1.y = 530;
                        G_V.NG.p.image[1].pos1.x = 200;
                        G_V.NG.p.image[1].pos1.y = 530;
                        G_V.NG.p.initlevel = 1;
                    }
                    if (G_V.NG.p.stamina > 0)
                    {
                        if (keystate[SDLK_z])
                        {
                            G_V.NG.p.derec = 2;
                            if (!collisionPP(G_V.NG.p, G_V.NG.b_market.b_k[2].img))
                            {
                                G_V.NG.p.image[0].pos1.y--;
                                G_V.NG.p.image[1].pos1.y--;
                            }
                        }
                        if (keystate[SDLK_s])
                        {
                            G_V.NG.p.derec = 1;
                            if (!collisionPP(G_V.NG.p, G_V.NG.b_market.b_k[2].img))
                            {
                                G_V.NG.p.image[0].pos1.y++;
                                G_V.NG.p.image[1].pos1.y++;
                            }
                        }
                        if (keystate[SDLK_d])
                        {
                            G_V.NG.p.derec = 3;
                            if (!collisionPP(G_V.NG.p, G_V.NG.b_market.b_k[2].img))
                            {
                                G_V.NG.p.image[0].pos1.x++;
                                G_V.NG.p.image[1].pos1.x++;
                            }
                        }
                        if (keystate[SDLK_q])
                        {
                            G_V.NG.p.derec = 4;
                            if (!collisionPP(G_V.NG.p, G_V.NG.b_market.b_k[2].img))
                            {
                                G_V.NG.p.image[0].pos1.x--;
                                G_V.NG.p.image[1].pos1.x--;
                            }
                        }
                    }

                    if (keystate[SDLK_c])
                        selectedCon = 1;
                    if (keystate[SDLK_v])
                        selectedCon = 2;
                    if (keystate[SDLK_b])
                        selectedCon = 3;
                    if (keystate[SDLK_r])
                    {
                        if (!rWasPressed)
                        {

                            if (!ca.attacked && !ca.called && selectedCon == 3)
                            {
                                G_V.NG.p.consuming = 1;
                                Mix_PlayChannel(-1, G_V.NG.p.openTuna, 0);
                            }

                            if (selectedCon != 3)
                                G_V.NG.p.consuming = 1;
                        }
                        rWasPressed = 1;
                    }
                    else
                        rWasPressed = 0;

                    if (keystate[SDLK_SPACE])
                    {
                        if (!spaceWasPressed)
                        {
                            if (G_V.NG.p.stamina > 3500)
                            {
                                G_V.NG.p.vj = 1;
                                if (G_V.NG.p.recovery == 0)
                                    G_V.NG.p.stamina -= 500;
                            }
                        }
                        spaceWasPressed = 1;
                    }
                    else
                        spaceWasPressed = 0;
                    if (keystate[SDLK_e])
                        singleplayer = 0;

                    G_V.NG.p.derec = 3;

                    G_V.NG.p.where = 1;

                    G_V.NG.b_market.scrolling_speed = 0.003 * G_V.NG.p.image[1].pos1.x + 1.85;
                    if (G_V.NG.p.stamina > 0)
                    {
                        scrolling(&G_V.NG.b_market, G_V.NG.p.derec, G_V.NG.b_market.scrolling_speed);
                    }
                    // scrolling(&market2, G_V.NG.p.derec, G_V.NG.b_market.scrolling_speed);
                    if (G_V.NG.b_market.b_k[0].pos2.x >= 14720)
                        G_V.NG.b_market.b_k[0].pos2.x = 1920;

                    dt = 20000 / G_V.NG.p.image[1].pos1.x + 22;
                    G_V.NG.p.acc = 0.007;

                    time0 = SDL_GetTicks();
                    /*if (time0 - time1 >= 150)
                    {

                        deplacerPerso(&G_V.NG.p, 17);
                        time1 = time0;
                    }*/

                    G_V.start = SDL_GetTicks();
                    G_V.dt = G_V.start - G_V.end;
                    if (G_V.dt > dt)
                    {
                        animerPerso(&G_V.NG.p);

                        G_V.end = G_V.start;
                    }

                    aficherBack(G_V.NG.b_market, G_V.window);
                    // aficherBack(market2, G_V.window);

                    verticalJump(&G_V.NG.p);
                    afficherPerso(G_V.NG.p, G_V.window);
                    //////// OBSTACLE
                    // Spawn and move obstacles
                    spawnObstacle(&ob1, G_V.NG.b_market.b_k[0].pos2, 1280, 1600, 400, 600);
                    spawnObstacle(&ob2, G_V.NG.b_market.b_k[0].pos2, 1350, 1750, 400, 600);
                    spawnObstacle(&ob3, G_V.NG.b_market.b_k[0].pos2, 1450, 1900, 400, 600);
                    spawnObstacle(&car, G_V.NG.b_market.b_k[0].pos2, 1280, 1600, 400, 600);
                    car.realx--;
                    // Collision character - obstacle
                    if (!G_V.NG.p.invin)
                    {

                        takeDamage(G_V.NG.p.image[1].pos1.x + G_V.NG.p.image[1].pos2.w, G_V.NG.p.image[1].pos1.y, ob1.img.pos1, &ob1, &G_V.NG.p.image[1].pos1.x, 70, &G_V.NG.p.invin, &G_V.NG.p.hitTime, &G_V.NG.p.hit, &G_V.NG.p.stamina);
                        takeDamage(G_V.NG.p.image[1].pos1.x + G_V.NG.p.image[1].pos2.w, G_V.NG.p.image[1].pos1.y, ob2.img.pos1, &ob2, &G_V.NG.p.image[1].pos1.x, 70, &G_V.NG.p.invin, &G_V.NG.p.hitTime, &G_V.NG.p.hit, &G_V.NG.p.stamina);
                        takeDamage(G_V.NG.p.image[1].pos1.x + G_V.NG.p.image[1].pos2.w, G_V.NG.p.image[1].pos1.y, ob3.img.pos1, &ob3, &G_V.NG.p.image[1].pos1.x, 70, &G_V.NG.p.invin, &G_V.NG.p.hitTime, &G_V.NG.p.hit, &G_V.NG.p.stamina);
                        takeDamage(G_V.NG.p.image[1].pos1.x + G_V.NG.p.image[1].pos2.w, G_V.NG.p.image[1].pos1.y, car.img.pos1, &car, &G_V.NG.p.image[1].pos1.x, 150, &G_V.NG.p.invin, &G_V.NG.p.hitTime, &G_V.NG.p.hit, &G_V.NG.p.stamina);
                    }
                    // Collision police 1 - obstacle
                    if (!po1.invin)
                    {
                        takeDamage(po1.pos1.x + 55, po1.pos1.y + 20, ob1.img.pos1, &ob1, &po1.pos1.x, 70, &po1.invin, &po1.hitTime, &po1.hit, &po1.resistance);
                        takeDamage(po1.pos1.x + 55, po1.pos1.y + 20, ob2.img.pos1, &ob2, &po1.pos1.x, 70, &po1.invin, &po1.hitTime, &po1.hit, &po1.resistance);
                        takeDamage(po1.pos1.x + 55, po1.pos1.y + 20, ob3.img.pos1, &ob3, &po1.pos1.x, 70, &po1.invin, &po1.hitTime, &po1.hit, &po1.resistance);
                        takeDamage(po1.pos1.x + 55, po1.pos1.y + 20, car.img.pos1, &car, &po1.pos1.x, 150, &po1.invin, &po1.hitTime, &po1.hit, &po1.resistance);
                    }
                    // Collision police 2 - obstacle
                    if (!po2.invin)
                    {
                        takeDamage(po2.pos1.x + 55, po2.pos1.y + 20, ob1.img.pos1, &ob1, &po2.pos1.x, 70, &po2.invin, &po2.hitTime, &po2.hit, &po2.resistance);
                        takeDamage(po2.pos1.x + 55, po2.pos1.y + 20, ob2.img.pos1, &ob2, &po2.pos1.x, 70, &po2.invin, &po2.hitTime, &po2.hit, &po2.resistance);
                        takeDamage(po2.pos1.x + 55, po2.pos1.y + 20, ob3.img.pos1, &ob3, &po2.pos1.x, 70, &po2.invin, &po2.hitTime, &po2.hit, &po2.resistance);
                        takeDamage(po2.pos1.x + 55, po2.pos1.y + 20, car.img.pos1, &car, &po2.pos1.x, 150, &po2.invin, &po2.hitTime, &po2.hit, &po2.resistance);
                    }
                    // Collision police 3 - obstacle
                    if (!po3.invin)
                    {
                        takeDamage(po3.pos1.x + 55, po3.pos1.y + 20, ob1.img.pos1, &ob1, &po3.pos1.x, 70, &po3.invin, &po3.hitTime, &po3.hit, &po3.resistance);
                        takeDamage(po3.pos1.x + 55, po3.pos1.y + 20, ob2.img.pos1, &ob2, &po3.pos1.x, 70, &po3.invin, &po3.hitTime, &po3.hit, &po3.resistance);
                        takeDamage(po3.pos1.x + 55, po3.pos1.y + 20, ob3.img.pos1, &ob3, &po3.pos1.x, 70, &po3.invin, &po3.hitTime, &po3.hit, &po3.resistance);
                        takeDamage(po3.pos1.x + 55, po3.pos1.y + 20, car.img.pos1, &car, &po3.pos1.x, 150, &po3.invin, &po3.hitTime, &po3.hit, &po3.resistance);
                    }
                    // Collision police 4 - obstacle
                    if (!po4.invin)
                    {
                        takeDamage(po4.pos1.x + 55, po4.pos1.y + 20, ob1.img.pos1, &ob1, &po4.pos1.x, 70, &po4.invin, &po4.hitTime, &po4.hit, &po4.resistance);
                        takeDamage(po4.pos1.x + 55, po4.pos1.y + 20, ob2.img.pos1, &ob2, &po4.pos1.x, 70, &po4.invin, &po4.hitTime, &po4.hit, &po4.resistance);
                        takeDamage(po4.pos1.x + 55, po4.pos1.y + 20, ob3.img.pos1, &ob3, &po4.pos1.x, 70, &po4.invin, &po4.hitTime, &po4.hit, &po4.resistance);
                        takeDamage(po4.pos1.x + 55, po4.pos1.y + 20, car.img.pos1, &car, &po4.pos1.x, 150, &po4.invin, &po4.hitTime, &po4.hit, &po4.resistance);
                    }
                    car.animated = 1;
                    // Spawn and move Projectiles
                    spawnProjectile(&pr1, G_V.NG.b_market.b_k[0].pos2, 1280, 1600, 400, 600);

                    // Spawn and move Consumable
                    spawnConsumable(&coke, G_V.NG.b_market.b_k[0].pos2, 9000, 9500, 400, 600);
                    spawnConsumable(&tea, G_V.NG.b_market.b_k[0].pos2, 5500, 6000, 400, 600);
                    spawnConsumable(&fish, G_V.NG.b_market.b_k[0].pos2, 4000, 5000, 400, 600);
                    // Pick Item
                    pickUp(&G_V.NG.p, &pr1);
                    pickUpConsumable(&G_V.NG.p, &coke);
                    pickUpConsumable(&G_V.NG.p, &tea);
                    pickUpConsumable(&G_V.NG.p, &fish);

                    consume(&G_V.NG.p, selectedCon, &ca);

                    jarani0 = SDL_GetTicks();
                    if (jarani0 - jarani1 > 100)
                    {
                        animateOnce(&ob1.img, &ob1.animated, &ob1.realx);
                        animateOnce(&ob2.img, &ob2.animated, &ob2.realx);
                        animateOnce(&ob3.img, &ob3.animated, &ob3.realx);
                        jarani1 = jarani0;
                    }

                    throwProjectile(&G_V.NG.p, &pr);
                    ////////// Police

                    if (!po1.inStandBy && !po1.tired)
                    {
                        po1.resistance--;
                        if (po1.resistance <= 0)
                            po1.tired = 1;
                        if (po1.resistance < 0)
                            po1.resistance = 0;
                        if (po1.resistancePos1.x < 15)
                            po1.resistancePos1.x = 15;
                        movePolice(&po1, G_V.NG.p);
                        hitPolice(&po1, &pr);
                        animate_printPolice(&po1, G_V.window);
                    }
                    if (!po2.inStandBy && !po2.tired)
                    {
                        po2.resistance--;
                        if (po2.resistance <= 0)
                            po2.tired = 1;
                        if (po2.resistance < 0)
                            po2.resistance = 0;
                        if (po2.resistancePos1.x < 15)
                            po2.resistancePos1.x = 15;
                        movePolice(&po2, G_V.NG.p);
                        hitPolice(&po2, &pr);
                        animate_printPolice(&po2, G_V.window);
                    }
                    if (!po3.inStandBy && !po3.tired)
                    {
                        po3.resistance--;
                        if (po3.resistance <= 0)
                            po3.tired = 1;
                        if (po3.resistance < 0)
                            po3.resistance = 0;
                        if (po3.resistancePos1.x < 15)
                            po3.resistancePos1.x = 15;
                        movePolice(&po3, G_V.NG.p);
                        hitPolice(&po3, &pr);
                        animate_printPolice(&po3, G_V.window);
                    }
                    if (!po4.inStandBy && !po4.tired)
                    {
                        po4.resistance--;
                        if (po4.resistance <= 0)
                            po4.tired = 1;
                        if (po4.resistance < 0)
                            po4.resistance = 0;
                        if (po4.resistancePos1.x < 15)
                            po4.resistancePos1.x = 15;
                        movePolice(&po4, G_V.NG.p);
                        hitPolice(&po4, &pr);
                        animate_printPolice(&po4, G_V.window);
                    }
                    retreat(&po1, G_V.window, G_V.NG.b_market.scrolling_speed, &G_V.NG.p.score);
                    retreat(&po2, G_V.window, G_V.NG.b_market.scrolling_speed, &G_V.NG.p.score);
                    retreat(&po3, G_V.window, G_V.NG.b_market.scrolling_speed, &G_V.NG.p.score);
                    retreat(&po4, G_V.window, G_V.NG.b_market.scrolling_speed, &G_V.NG.p.score);

                    callForBackUp(&po1, &po2, &po3, &po4);

                    ////Invinsibilitie
                    isInvin(&po1.invin, po1.hitTime, po1.invinWindow);
                    isInvin(&po2.invin, po2.hitTime, po2.invinWindow);
                    isInvin(&po3.invin, po3.hitTime, po3.invinWindow);
                    isInvin(&po4.invin, po4.hitTime, po4.invinWindow);
                    isInvin(&G_V.NG.p.invin, G_V.NG.p.hitTime, G_V.NG.p.invinWindow);
                    /////
                    ////CAT
                    if (ca.called)
                    {
                        if (!ca.satisfied && !ca.attacked)
                        {
                            moveCat(&ca, G_V.NG.p.image[1].pos1);
                            feed(&G_V.NG.p, &ca);
                        }
                        if (ca.satisfied)
                        {
                            track(&ca, G_V.NG.p, &po1, &po2, &po3, &po4);
                            attack(&ca);
                        }
                        retreatCat(&ca, G_V.NG.b_market.scrolling_speed);
                        animateCat(&ca);
                        SDL_BlitSurface(ca.img.img, &ca.img.pos2, G_V.window, &ca.img.pos1);
                    }

                    else
                        ca.img.pos1.x = 0;
                    ////

                    /// Stamina
                    if (G_V.NG.p.stamina > 0)
                        if (G_V.NG.p.recovery == 0)
                            G_V.NG.p.stamina--;
                    G_V.NG.p.staminapos1.x = G_V.NG.p.image[1].pos1.x - 20;
                    G_V.NG.p.staminapos1.y = G_V.NG.p.image[1].pos1.y - 20;
                    G_V.NG.p.staminapos2.w = ((G_V.NG.p.stamina - 3000) * 66 / 10000) + 14;
                    G_V.NG.p.dangerLevelStapos2.w = (G_V.NG.p.stamina * 66 / 3000) + 14;

                    if (G_V.NG.p.stamina > 3000)
                    {
                        SDL_BlitSurface(G_V.NG.p.staminaImg, &G_V.NG.p.staminapos2, G_V.window, &G_V.NG.p.staminapos1);
                        SDL_BlitSurface(G_V.NG.p.staminaBar, NULL, G_V.window, &G_V.NG.p.staminapos1);
                    }
                    else
                    {
                        SDL_BlitSurface(G_V.NG.p.dangerLevelStaImg, &G_V.NG.p.dangerLevelStapos2, G_V.window, &G_V.NG.p.staminapos1);
                        SDL_BlitSurface(G_V.NG.p.dangerLevelStaBar, NULL, G_V.window, &G_V.NG.p.staminapos1);
                    }

                    ///
                    switch (G_V.NG.b_market.scrolling_speed)
                    {
                    case 1:
                        G_V.NG.p.score += 0.05;
                        break;
                    case 2:
                        G_V.NG.p.score += 0.1;
                        break;
                    case 3:
                        G_V.NG.p.score += 0.15;
                        break;
                    case 4:
                        G_V.NG.p.score += 0.4;
                        break;
                    }

                    if ((!po1.inStandBy && !po1.tired) || (!po2.inStandBy && !po2.tired) || (!po3.inStandBy && !po3.tired) || (!po4.inStandBy && !po4.tired))
                        speak(&po1);
                    printf("called=%d\n", ca.called);
                    SDL_BlitSurface(coke.img, NULL, G_V.window, &coke.pos1);
                    SDL_BlitSurface(tea.img, NULL, G_V.window, &tea.pos1);
                    SDL_BlitSurface(fish.img, NULL, G_V.window, &fish.pos1);
                    SDL_BlitSurface(pr1.img.img, &pr1.img.pos2, G_V.window, &pr1.img.pos1);
                    SDL_BlitSurface(pr.img.img, &pr.img.pos2, G_V.window, &pr.img.pos1);
                    sprintf(pananatext, "%d", G_V.NG.p.panana);
                    pananat.windtxt = TTF_RenderText_Blended(pananat.font, pananatext, pananat.col);
                    SDL_BlitSurface(panana.img, NULL, G_V.window, &panana.pos1);
                    SDL_BlitSurface(pananat.windtxt, NULL, G_V.window, &pananat.postxt);

                    sprintf(scoretext, "%d", (int)G_V.NG.p.score);
                    scoret.windtxt = TTF_RenderText_Blended(scoret.font, scoretext, scoret.col);
                    SDL_BlitSurface(score.img, NULL, G_V.window, &score.pos1);
                    SDL_BlitSurface(scoret.windtxt, NULL, G_V.window, &scoret.postxt);

                    if (selectedCon == 1)
                    {
                        SDL_BlitSurface(selectedTeaIcon, NULL, G_V.window, &teaPos);
                    }
                    else
                        SDL_BlitSurface(teaIcon, NULL, G_V.window, &teaPos);

                    if (selectedCon == 2)
                    {
                        SDL_BlitSurface(selectedCokeIcon, NULL, G_V.window, &cokePos);
                    }
                    else
                        SDL_BlitSurface(cokeIcon, NULL, G_V.window, &cokePos);

                    if (selectedCon == 3)
                    {
                        SDL_BlitSurface(selectedFishIcon, NULL, G_V.window, &fishPos);
                    }
                    else
                        SDL_BlitSurface(fishIcon, NULL, G_V.window, &fishPos);
                    sprintf(coketext, "%d", G_V.NG.p.coke);
                    coket.windtxt = TTF_RenderText_Blended(coket.font, coketext, coket.col);
                    sprintf(teatext, "%d", G_V.NG.p.tea);
                    teat.windtxt = TTF_RenderText_Blended(teat.font, teatext, teat.col);
                    sprintf(fishtext, "%d", G_V.NG.p.fish);
                    fisht.windtxt = TTF_RenderText_Blended(fisht.font, fishtext, fisht.col);
                    SDL_BlitSurface(fisht.windtxt, NULL, G_V.window, &fisht.postxt);
                    SDL_BlitSurface(coket.windtxt, NULL, G_V.window, &coket.postxt);
                    SDL_BlitSurface(teat.windtxt, NULL, G_V.window, &teat.postxt);

                    SDL_BlitSurface(car.img.img, &car.img.pos2, G_V.window, &car.img.pos1);
                    SDL_BlitSurface(ob1.img.img, &ob1.img.pos2, G_V.window, &ob1.img.pos1);
                    SDL_BlitSurface(ob2.img.img, &ob2.img.pos2, G_V.window, &ob2.img.pos1);
                    SDL_BlitSurface(ob3.img.img, &ob3.img.pos2, G_V.window, &ob3.img.pos1);
                    if (is_in_rect(G_V.NG.p.image[1].pos1.x + 20, G_V.NG.p.image[1].pos1.y, po1.pos1))
                    {
                        /* printf("HEREEEEEEEEEEEEEEE\n");
                         G_V.NG.p.caught = 1;
                         stupidPolice=1;
                         G_V.NG.p.caughtTime=SDL_GetTicks();*/
                        G_V.NG.p.stamina -= 15;
                        if (G_V.NG.p.stamina < 0)
                            G_V.NG.p.stamina = 0;
                    }
                    if (is_in_rect(G_V.NG.p.image[1].pos1.x + 20, G_V.NG.p.image[1].pos1.y, po2.pos1))
                    {
                        /* G_V.NG.p.caught = 1;
                         stupidPolice=2;
                         G_V.NG.p.caughtTime=SDL_GetTicks();*/
                        G_V.NG.p.stamina -= 15;
                        if (G_V.NG.p.stamina < 0)
                            G_V.NG.p.stamina = 0;
                    }
                    if (is_in_rect(G_V.NG.p.image[1].pos1.x + 20, G_V.NG.p.image[1].pos1.y, po3.pos1))
                    {
                        /* G_V.NG.p.caught = 1;
                         stupidPolice=3;
                         G_V.NG.p.caughtTime=SDL_GetTicks();*/
                        G_V.NG.p.stamina -= 15;
                        if (G_V.NG.p.stamina < 0)
                            G_V.NG.p.stamina = 0;
                    }
                    if (is_in_rect(G_V.NG.p.image[1].pos1.x + 20, G_V.NG.p.image[1].pos1.y, po4.pos1))
                    {
                        /* G_V.NG.p.caught = 1;
                         stupidPolice=4;
                         G_V.NG.p.caughtTime=SDL_GetTicks();*/
                        G_V.NG.p.stamina -= 15;
                        if (G_V.NG.p.stamina < 0)
                            G_V.NG.p.stamina = 0;
                    }
                }
                else
                {
                        SDL_BlitSurface(tuto,NULL,G_V.window,NULL);
                    if(keystate[SDLK_ESCAPE])
                    tutoDisplayed=0;
                    
                    
                }
                if (G_V.NG.p.stamina <= 0)
                    G_V.state = 10;
            }
            else
            {
                if (!G_V.NG.p.caught)
                {
                    switch (G_V.event.type)
                    {

                    case SDL_QUIT:
                        Mix_PlayChannel(-1, effect, 0);
                        G_V.out = 1;
                        break;
                    }

                    if (!p2.initlevel)
                    {
                        market2.b_k[0].pos1.y = 360;
                        market2.b_k[0].pos1.x = 0;

                        market2.b_k[0].pos2.x = 0;
                        market2.b_k[0].pos2.y = 360;
                        market2.b_k[0].pos2.w = 1280;
                        market2.b_k[0].pos2.h = 360;

                        G_V.NG.b_market.b_k[0].pos1.y = 0;
                        G_V.NG.b_market.b_k[0].pos1.x = 0;

                        G_V.NG.b_market.b_k[0].pos2.x = 0;
                        G_V.NG.b_market.b_k[0].pos2.y = 360;
                        G_V.NG.b_market.b_k[0].pos2.w = 1280;
                        G_V.NG.b_market.b_k[0].pos2.h = 360;
                        G_V.NG.p.image[0].pos1.x = 200;
                        G_V.NG.p.image[0].pos1.y = 100;
                        G_V.NG.p.image[1].pos1.x = 200;
                        G_V.NG.p.image[1].pos1.y = 100;

                        p2.image[0].pos1.x = 530;
                        p2.image[0].pos1.y = 530;
                        p2.image[1].pos1.x = 530;
                        p2.image[1].pos1.y = 530;

                        pananat2.postxt.x = 1280 - 15;
                        pananat2.postxt.y = 380;
                        scoret2.postxt.x = 1280 - 150;
                        scoret2.postxt.y = 430;
                        coket2.postxt.x = 1280 - 75;
                        coket2.postxt.y = 380;
                        fisht2.postxt.x = 1280 - 195;
                        fisht2.postxt.y = 380;
                        teat2.postxt.x = 1280 - 135;
                        teat2.postxt.y = 380;
                        panana2.pos1.x = 1280 - 40;
                        panana2.pos1.y = 365;
                        score2.pos1.x = 1280 - 300;
                        score2.pos1.y = 430;
                        cokePos2.x = 1280 - 100;
                        cokePos2.y = 365;
                        fishPos2.x = 1280 - 220;
                        fishPos2.y = 365;
                        teaPos2.x = 1280 - 160;
                        teaPos2.y = 365;

                        po1.pos1.y = 130;
                        po2.pos1.y = 130;
                        po3.pos1.y = 130;
                        po4.pos1.y = 130;

                        coke.realx = 0;
                        coke.realy = 0;
                        tea.pos1.x = 0;
                        tea.pos1.y = 0;
                        fish.pos1.x = 0;
                        fish.pos1.y = 0;

                        p2.initlevel = 1;
                    }
                    // P1 Input
                    if (G_V.NG.p.stamina > 0)
                    {
                        if (keystate[SDLK_z])
                        {
                            G_V.NG.p.derec = 2;
                            if (!collisionPP(G_V.NG.p, G_V.NG.b_market.b_k[2].img))
                            {
                                G_V.NG.p.image[0].pos1.y--;
                                G_V.NG.p.image[1].pos1.y--;
                            }
                        }
                        if (keystate[SDLK_s])
                        {
                            G_V.NG.p.derec = 1;
                            if (!collisionPP(G_V.NG.p, G_V.NG.b_market.b_k[2].img))
                            {
                                G_V.NG.p.image[0].pos1.y++;
                                G_V.NG.p.image[1].pos1.y++;
                            }
                        }
                        if (keystate[SDLK_d])
                        {
                            G_V.NG.p.derec = 3;
                            if (!collisionPP(G_V.NG.p, G_V.NG.b_market.b_k[2].img))
                            {
                                G_V.NG.p.image[0].pos1.x++;
                                G_V.NG.p.image[1].pos1.x++;
                            }
                        }
                        if (keystate[SDLK_q])
                        {
                            G_V.NG.p.derec = 4;
                            if (!collisionPP(G_V.NG.p, G_V.NG.b_market.b_k[2].img))
                            {
                                G_V.NG.p.image[0].pos1.x--;
                                G_V.NG.p.image[1].pos1.x--;
                            }
                        }
                    }

                    if (keystate[SDLK_c])
                        selectedCon = 1;
                    if (keystate[SDLK_v])
                        selectedCon = 2;
                    if (keystate[SDLK_b])
                        selectedCon = 3;
                    if (keystate[SDLK_r])
                    {
                        if (!rWasPressed)
                        {

                            if (!ca.attacked && !ca.called && selectedCon == 3)
                            {
                                G_V.NG.p.consuming = 1;
                                Mix_PlayChannel(-1, G_V.NG.p.openTuna, 0);
                            }

                            if (selectedCon != 3)
                                G_V.NG.p.consuming = 1;
                        }
                        rWasPressed = 1;
                    }
                    else
                        rWasPressed = 0;

                    if (keystate[SDLK_SPACE])
                    {
                        if (!spaceWasPressed)
                        {
                            if (G_V.NG.p.stamina > 3500)
                            {
                                G_V.NG.p.vj = 1;
                                if (G_V.NG.p.recovery == 0)
                                    G_V.NG.p.stamina -= 500;
                            }
                        }
                        spaceWasPressed = 1;
                    }
                    else
                        spaceWasPressed = 0;
                    if (keystate[SDLK_e])
                        singleplayer = 0;

                    G_V.NG.p.derec = 3;

                    G_V.NG.p.where = 1;

                    // G_V.NG.b_market.scrolling_speed = 0.003 * G_V.NG.p.image[1].pos1.x + 1.85;
                    ///
                    //// P2 INPUT
                    if (p2.stamina > 0)
                    {
                        if (keystate[SDLK_UP])
                        {
                            p2.derec = 2;
                            if (!collisionPP(p2, market2.b_k[2].img))
                            {
                                p2.image[0].pos1.y--;
                                p2.image[1].pos1.y--;
                            }
                        }
                        if (keystate[SDLK_DOWN])
                        {
                            p2.derec = 1;
                            if (!collisionPP(p2, market2.b_k[2].img))
                            {
                                p2.image[0].pos1.y++;
                                p2.image[1].pos1.y++;
                            }
                        }
                        if (keystate[SDLK_RIGHT])
                        {
                            p2.derec = 3;
                            if (!collisionPP(p2, market2.b_k[2].img))
                            {
                                p2.image[0].pos1.x++;
                                p2.image[1].pos1.x++;
                            }
                        }
                        if (keystate[SDLK_LEFT])
                        {
                            p2.derec = 4;
                            if (!collisionPP(p2, market2.b_k[2].img))
                            {
                                p2.image[0].pos1.x--;
                                p2.image[1].pos1.x--;
                            }
                        }
                    }

                    if (keystate[SDLK_l])
                        selectedCon2 = 1;
                    if (keystate[SDLK_k])
                        selectedCon2 = 2;
                    if (keystate[SDLK_j])
                        selectedCon2 = 3;

                    if (keystate[SDLK_i])
                    {
                        if (!rWasPressed2)
                        {

                            if (!ca2.attacked && !ca2.called && selectedCon2 == 3)
                            {
                                p2.consuming = 1;
                                Mix_PlayChannel(-1, G_V.NG.p.openTuna, 0);
                            }

                            if (selectedCon2 != 3)
                                p2.consuming = 1;
                        }
                        rWasPressed2 = 1;
                    }
                    else
                        rWasPressed2 = 0;

                    if (keystate[SDLK_m])
                    {
                        if (!spaceWasPressed2)
                        {
                            if (p2.stamina > 3500)
                            {
                                p2.vj = 1;
                                if (p2.recovery == 0)
                                    p2.stamina -= 500;
                            }
                        }
                        spaceWasPressed2 = 1;
                    }
                    else
                        spaceWasPressed2 = 0;
                    if (keystate[SDLK_e])
                        singleplayer = 0;

                    p2.derec = 3;

                    p2.where = 1;

                    market2.scrolling_speed = 0.003 * p2.image[1].pos1.x + 1.85;
                    G_V.NG.b_market.scrolling_speed = 0.003 * G_V.NG.p.image[1].pos1.x + 1.85;
                    ////
                    if (G_V.NG.p.stamina > 0)
                    {
                        scrolling(&G_V.NG.b_market, G_V.NG.p.derec, G_V.NG.b_market.scrolling_speed);
                    }
                    if (p2.stamina > 0)
                    {
                        scrolling(&market2, p2.derec, market2.scrolling_speed);
                    }
                    if (G_V.NG.b_market.b_k[0].pos2.x >= 14720)
                        G_V.NG.b_market.b_k[0].pos2.x = 1920;

                    if (market2.b_k[0].pos2.x >= 14720)
                        market2.b_k[0].pos2.x = 1920;

                    dt = 20000 / G_V.NG.p.image[1].pos1.x + 22;
                    dt22 = 20000 / p2.image[1].pos1.x + 22;
                    // G_V.NG.p.acc = 0.007;

                    time0 = SDL_GetTicks();
                    /*if (time0 - time1 >= 150)
                    {

                        deplacerPerso(&G_V.NG.p, 17);
                        time1 = time0;
                    }*/

                    G_V.start = SDL_GetTicks();
                    G_V.dt = G_V.start - G_V.end;
                    if (G_V.dt > dt)
                    {
                        animerPerso(&G_V.NG.p);

                        G_V.end = G_V.start;
                    }
                    tt0 = SDL_GetTicks();
                    if (tt0 - tt1 > dt22)
                    {

                        animerPerso(&p2);
                        tt1 = tt0;
                    }

                    aficherBack(G_V.NG.b_market, G_V.window);
                    aficherBack(market2, G_V.window);

                    verticalJump(&G_V.NG.p);
                    verticalJump2(&p2);
                    afficherPerso(G_V.NG.p, G_V.window);
                    afficherPerso(p2, G_V.window);
                    //////// OBSTACLE
                    // Spawn and move obstacles
                    spawnObstacle(&ob1, G_V.NG.b_market.b_k[0].pos2, 1280, 1600, 30, 300);
                    spawnObstacle(&ob2, G_V.NG.b_market.b_k[0].pos2, 1350, 1750, 30, 300);
                    spawnObstacle(&ob3, G_V.NG.b_market.b_k[0].pos2, 1450, 1900, 30, 300);
                    spawnObstacle(&car, G_V.NG.b_market.b_k[0].pos2, 1280, 1600, 30, 300);
                    car.realx--;
                    //
                    spawnObstacle(&ob12, market2.b_k[0].pos2, 1280, 1600, 400, 600);
                    spawnObstacle(&ob22, market2.b_k[0].pos2, 1350, 1750, 400, 600);
                    spawnObstacle(&ob32, market2.b_k[0].pos2, 1450, 1900, 400, 600);
                    spawnObstacle(&car2, market2.b_k[0].pos2, 1280, 1600, 400, 600);
                    car2.realx--;
                    // Collision character - obstacle
                    if (!G_V.NG.p.invin)
                    {

                        takeDamage(G_V.NG.p.image[1].pos1.x + G_V.NG.p.image[1].pos2.w, G_V.NG.p.image[1].pos1.y, ob1.img.pos1, &ob1, &G_V.NG.p.image[1].pos1.x, 70, &G_V.NG.p.invin, &G_V.NG.p.hitTime, &G_V.NG.p.hit, &G_V.NG.p.stamina);
                        takeDamage(G_V.NG.p.image[1].pos1.x + G_V.NG.p.image[1].pos2.w, G_V.NG.p.image[1].pos1.y, ob2.img.pos1, &ob2, &G_V.NG.p.image[1].pos1.x, 70, &G_V.NG.p.invin, &G_V.NG.p.hitTime, &G_V.NG.p.hit, &G_V.NG.p.stamina);
                        takeDamage(G_V.NG.p.image[1].pos1.x + G_V.NG.p.image[1].pos2.w, G_V.NG.p.image[1].pos1.y, ob3.img.pos1, &ob3, &G_V.NG.p.image[1].pos1.x, 70, &G_V.NG.p.invin, &G_V.NG.p.hitTime, &G_V.NG.p.hit, &G_V.NG.p.stamina);
                        takeDamage(G_V.NG.p.image[1].pos1.x + G_V.NG.p.image[1].pos2.w, G_V.NG.p.image[1].pos1.y, car.img.pos1, &car, &G_V.NG.p.image[1].pos1.x, 150, &G_V.NG.p.invin, &G_V.NG.p.hitTime, &G_V.NG.p.hit, &G_V.NG.p.stamina);
                    }
                    // Collision character2 - obstacle
                    if (!p2.invin)
                    {

                        takeDamage(p2.image[1].pos1.x + p2.image[1].pos2.w, p2.image[1].pos1.y, ob12.img.pos1, &ob12, &p2.image[1].pos1.x, 70, &p2.invin, &p2.hitTime, &p2.hit, &p2.stamina);
                        takeDamage(p2.image[1].pos1.x + p2.image[1].pos2.w, p2.image[1].pos1.y, ob22.img.pos1, &ob22, &p2.image[1].pos1.x, 70, &p2.invin, &p2.hitTime, &p2.hit, &p2.stamina);
                        takeDamage(p2.image[1].pos1.x + p2.image[1].pos2.w, p2.image[1].pos1.y, ob32.img.pos1, &ob32, &p2.image[1].pos1.x, 70, &p2.invin, &p2.hitTime, &p2.hit, &p2.stamina);
                        takeDamage(p2.image[1].pos1.x + p2.image[1].pos2.w, p2.image[1].pos1.y, car2.img.pos1, &car2, &p2.image[1].pos1.x, 150, &p2.invin, &p2.hitTime, &p2.hit, &p2.stamina);
                    }
                    /////////P1
                    // Collision police 1 - obstacle
                    if (!po1.invin)
                    {
                        takeDamage(po1.pos1.x + 55, po1.pos1.y + 20, ob1.img.pos1, &ob1, &po1.pos1.x, 70, &po1.invin, &po1.hitTime, &po1.hit, &po1.resistance);
                        takeDamage(po1.pos1.x + 55, po1.pos1.y + 20, ob2.img.pos1, &ob2, &po1.pos1.x, 70, &po1.invin, &po1.hitTime, &po1.hit, &po1.resistance);
                        takeDamage(po1.pos1.x + 55, po1.pos1.y + 20, ob3.img.pos1, &ob3, &po1.pos1.x, 70, &po1.invin, &po1.hitTime, &po1.hit, &po1.resistance);
                        takeDamage(po1.pos1.x + 55, po1.pos1.y + 20, car.img.pos1, &car, &po1.pos1.x, 150, &po1.invin, &po1.hitTime, &po1.hit, &po1.resistance);
                    }
                    // Collision police 2 - obstacle
                    if (!po2.invin)
                    {
                        takeDamage(po2.pos1.x + 55, po2.pos1.y + 20, ob1.img.pos1, &ob1, &po2.pos1.x, 70, &po2.invin, &po2.hitTime, &po2.hit, &po2.resistance);
                        takeDamage(po2.pos1.x + 55, po2.pos1.y + 20, ob2.img.pos1, &ob2, &po2.pos1.x, 70, &po2.invin, &po2.hitTime, &po2.hit, &po2.resistance);
                        takeDamage(po2.pos1.x + 55, po2.pos1.y + 20, ob3.img.pos1, &ob3, &po2.pos1.x, 70, &po2.invin, &po2.hitTime, &po2.hit, &po2.resistance);
                        takeDamage(po2.pos1.x + 55, po2.pos1.y + 20, car.img.pos1, &car, &po2.pos1.x, 150, &po2.invin, &po2.hitTime, &po2.hit, &po2.resistance);
                    }
                    // Collision police 3 - obstacle
                    if (!po3.invin)
                    {
                        takeDamage(po3.pos1.x + 55, po3.pos1.y + 20, ob1.img.pos1, &ob1, &po3.pos1.x, 70, &po3.invin, &po3.hitTime, &po3.hit, &po3.resistance);
                        takeDamage(po3.pos1.x + 55, po3.pos1.y + 20, ob2.img.pos1, &ob2, &po3.pos1.x, 70, &po3.invin, &po3.hitTime, &po3.hit, &po3.resistance);
                        takeDamage(po3.pos1.x + 55, po3.pos1.y + 20, ob3.img.pos1, &ob3, &po3.pos1.x, 70, &po3.invin, &po3.hitTime, &po3.hit, &po3.resistance);
                        takeDamage(po3.pos1.x + 55, po3.pos1.y + 20, car.img.pos1, &car, &po3.pos1.x, 150, &po3.invin, &po3.hitTime, &po3.hit, &po3.resistance);
                    }
                    // Collision police 4 - obstacle
                    if (!po4.invin)
                    {
                        takeDamage(po4.pos1.x + 55, po4.pos1.y + 20, ob1.img.pos1, &ob1, &po4.pos1.x, 70, &po4.invin, &po4.hitTime, &po4.hit, &po4.resistance);
                        takeDamage(po4.pos1.x + 55, po4.pos1.y + 20, ob2.img.pos1, &ob2, &po4.pos1.x, 70, &po4.invin, &po4.hitTime, &po4.hit, &po4.resistance);
                        takeDamage(po4.pos1.x + 55, po4.pos1.y + 20, ob3.img.pos1, &ob3, &po4.pos1.x, 70, &po4.invin, &po4.hitTime, &po4.hit, &po4.resistance);
                        takeDamage(po4.pos1.x + 55, po4.pos1.y + 20, car.img.pos1, &car, &po4.pos1.x, 150, &po4.invin, &po4.hitTime, &po4.hit, &po4.resistance);
                    }
                    car.animated = 1;
                    //////////
                    //////////P2
                    // Collision police 1 - obstacle
                    if (!po12.invin)
                    {
                        takeDamage(po12.pos1.x + 55, po12.pos1.y + 20, ob12.img.pos1, &ob12, &po12.pos1.x, 70, &po12.invin, &po12.hitTime, &po12.hit, &po12.resistance);
                        takeDamage(po12.pos1.x + 55, po12.pos1.y + 20, ob22.img.pos1, &ob22, &po12.pos1.x, 70, &po12.invin, &po12.hitTime, &po12.hit, &po12.resistance);
                        takeDamage(po12.pos1.x + 55, po12.pos1.y + 20, ob32.img.pos1, &ob32, &po12.pos1.x, 70, &po12.invin, &po12.hitTime, &po12.hit, &po12.resistance);
                        takeDamage(po12.pos1.x + 55, po12.pos1.y + 20, car2.img.pos1, &car2, &po12.pos1.x, 150, &po12.invin, &po12.hitTime, &po12.hit, &po12.resistance);
                    }
                    // Collision police 2 - obstacle
                    if (!po22.invin)
                    {
                        takeDamage(po22.pos1.x + 55, po22.pos1.y + 20, ob12.img.pos1, &ob12, &po22.pos1.x, 70, &po22.invin, &po22.hitTime, &po22.hit, &po22.resistance);
                        takeDamage(po22.pos1.x + 55, po22.pos1.y + 20, ob22.img.pos1, &ob22, &po22.pos1.x, 70, &po22.invin, &po22.hitTime, &po22.hit, &po22.resistance);
                        takeDamage(po22.pos1.x + 55, po22.pos1.y + 20, ob32.img.pos1, &ob32, &po22.pos1.x, 70, &po22.invin, &po22.hitTime, &po22.hit, &po22.resistance);
                        takeDamage(po22.pos1.x + 55, po22.pos1.y + 20, car2.img.pos1, &car2, &po22.pos1.x, 150, &po22.invin, &po22.hitTime, &po22.hit, &po22.resistance);
                    }
                    // Collision police 3 - obstacle
                    if (!po32.invin)
                    {
                        takeDamage(po32.pos1.x + 55, po32.pos1.y + 20, ob12.img.pos1, &ob12, &po32.pos1.x, 70, &po32.invin, &po32.hitTime, &po32.hit, &po32.resistance);
                        takeDamage(po32.pos1.x + 55, po32.pos1.y + 20, ob22.img.pos1, &ob22, &po32.pos1.x, 70, &po32.invin, &po32.hitTime, &po32.hit, &po32.resistance);
                        takeDamage(po32.pos1.x + 55, po32.pos1.y + 20, ob32.img.pos1, &ob32, &po32.pos1.x, 70, &po32.invin, &po32.hitTime, &po32.hit, &po32.resistance);
                        takeDamage(po32.pos1.x + 55, po32.pos1.y + 20, car2.img.pos1, &car2, &po32.pos1.x, 150, &po32.invin, &po32.hitTime, &po32.hit, &po32.resistance);
                    }
                    // Collision police 4 - obstacle
                    if (!po42.invin)
                    {
                        takeDamage(po42.pos1.x + 55, po42.pos1.y + 20, ob12.img.pos1, &ob12, &po42.pos1.x, 70, &po42.invin, &po42.hitTime, &po42.hit, &po42.resistance);
                        takeDamage(po42.pos1.x + 55, po42.pos1.y + 20, ob22.img.pos1, &ob22, &po42.pos1.x, 70, &po42.invin, &po42.hitTime, &po42.hit, &po42.resistance);
                        takeDamage(po42.pos1.x + 55, po42.pos1.y + 20, ob32.img.pos1, &ob32, &po42.pos1.x, 70, &po42.invin, &po42.hitTime, &po42.hit, &po42.resistance);
                        takeDamage(po42.pos1.x + 55, po42.pos1.y + 20, car2.img.pos1, &car2, &po42.pos1.x, 150, &po42.invin, &po42.hitTime, &po42.hit, &po42.resistance);
                    }
                    car2.animated = 1;

                    ///////////
                    // Spawn and move Projectiles
                    spawnProjectile(&pr1, G_V.NG.b_market.b_k[0].pos2, 1280, 1600, 30, 330);
                    spawnProjectile(&pr12, market2.b_k[0].pos2, 1280, 1600, 400, 600);

                    // Spawn and move Consumable
                    spawnConsumable(&coke, G_V.NG.b_market.b_k[0].pos2, 9000, 9500, 100, 300);
                    spawnConsumable(&tea, G_V.NG.b_market.b_k[0].pos2, 5500, 6000, 100, 300);
                    spawnConsumable(&fish, G_V.NG.b_market.b_k[0].pos2, 4000, 5000, 100, 300);

                    printf("coke.x=%d coke.y=%d\n", coke.pos1.x, coke.pos1.y);

                    spawnConsumable(&coke2, market2.b_k[0].pos2, 9000, 9500, 400, 600);
                    spawnConsumable(&tea2, market2.b_k[0].pos2, 5500, 6000, 400, 600);
                    spawnConsumable(&fish2, market2.b_k[0].pos2, 4000, 5000, 400, 600);
                    // Pick Item
                    pickUp(&G_V.NG.p, &pr1);
                    pickUpConsumable(&G_V.NG.p, &coke);
                    pickUpConsumable(&G_V.NG.p, &tea);
                    pickUpConsumable(&G_V.NG.p, &fish);

                    pickUp(&p2, &pr12);
                    pickUpConsumable(&p2, &coke2);
                    pickUpConsumable(&p2, &tea2);
                    pickUpConsumable(&p2, &fish2);

                    consume(&G_V.NG.p, selectedCon, &ca);
                    consume(&p2, selectedCon2, &ca2);

                    jarani0 = SDL_GetTicks();
                    if (jarani0 - jarani1 > 100)
                    {
                        animateOnce(&ob12.img, &ob12.animated, &ob12.realx);
                        animateOnce(&ob22.img, &ob22.animated, &ob22.realx);
                        animateOnce(&ob32.img, &ob32.animated, &ob32.realx);
                        animateOnce(&ob1.img, &ob1.animated, &ob1.realx);
                        animateOnce(&ob2.img, &ob2.animated, &ob2.realx);
                        animateOnce(&ob3.img, &ob3.animated, &ob3.realx);
                        jarani1 = jarani0;
                    }

                    throwProjectile(&G_V.NG.p, &pr);
                    throwProjectile(&p2, &pr2);

                    /////////P1
                    ////////// Police

                    if (!po1.inStandBy && !po1.tired)
                    {
                        po1.resistance--;
                        if (po1.resistance <= 0)
                            po1.tired = 1;
                        if (po1.resistance < 0)
                            po1.resistance = 0;
                        if (po1.resistancePos1.x < 15)
                            po1.resistancePos1.x = 15;
                        movePolice(&po1, G_V.NG.p);
                        hitPolice(&po1, &pr);
                        animate_printPolice(&po1, G_V.window);
                    }
                    if (!po2.inStandBy && !po2.tired)
                    {
                        po2.resistance--;
                        if (po2.resistance <= 0)
                            po2.tired = 1;
                        if (po2.resistance < 0)
                            po2.resistance = 0;
                        if (po2.resistancePos1.x < 15)
                            po2.resistancePos1.x = 15;
                        movePolice(&po2, G_V.NG.p);
                        hitPolice(&po2, &pr);
                        animate_printPolice(&po2, G_V.window);
                    }
                    if (!po3.inStandBy && !po3.tired)
                    {
                        po3.resistance--;
                        if (po3.resistance <= 0)
                            po3.tired = 1;
                        if (po3.resistance < 0)
                            po3.resistance = 0;
                        if (po3.resistancePos1.x < 15)
                            po3.resistancePos1.x = 15;
                        movePolice(&po3, G_V.NG.p);
                        hitPolice(&po3, &pr);
                        animate_printPolice(&po3, G_V.window);
                    }
                    if (!po4.inStandBy && !po4.tired)
                    {
                        po4.resistance--;
                        if (po4.resistance <= 0)
                            po4.tired = 1;
                        if (po4.resistance < 0)
                            po4.resistance = 0;
                        if (po4.resistancePos1.x < 15)
                            po4.resistancePos1.x = 15;
                        movePolice(&po4, G_V.NG.p);
                        hitPolice(&po4, &pr);
                        animate_printPolice(&po4, G_V.window);
                    }
                    retreat(&po1, G_V.window, G_V.NG.b_market.scrolling_speed, &G_V.NG.p.score);
                    retreat(&po2, G_V.window, G_V.NG.b_market.scrolling_speed, &G_V.NG.p.score);
                    retreat(&po3, G_V.window, G_V.NG.b_market.scrolling_speed, &G_V.NG.p.score);
                    retreat(&po4, G_V.window, G_V.NG.b_market.scrolling_speed, &G_V.NG.p.score);

                    callForBackUp(&po1, &po2, &po3, &po4);
                    ///////
                    /////////P2
                    ////////// Police

                    if (!po12.inStandBy && !po12.tired)
                    {
                        po12.resistance--;
                        if (po12.resistance <= 0)
                            po12.tired = 1;
                        if (po12.resistance < 0)
                            po12.resistance = 0;
                        if (po12.resistancePos1.x < 15)
                            po12.resistancePos1.x = 15;
                        movePolice(&po12, p2);
                        hitPolice(&po12, &pr2);
                        animate_printPolice(&po12, G_V.window);
                    }
                    if (!po22.inStandBy && !po22.tired)
                    {
                        po22.resistance--;
                        if (po22.resistance <= 0)
                            po22.tired = 1;
                        if (po22.resistance < 0)
                            po22.resistance = 0;
                        if (po22.resistancePos1.x < 15)
                            po22.resistancePos1.x = 15;
                        movePolice(&po22, p2);
                        hitPolice(&po22, &pr2);
                        animate_printPolice(&po22, G_V.window);
                    }
                    if (!po32.inStandBy && !po32.tired)
                    {
                        po32.resistance--;
                        if (po32.resistance <= 0)
                            po32.tired = 1;
                        if (po32.resistance < 0)
                            po32.resistance = 0;
                        if (po32.resistancePos1.x < 15)
                            po32.resistancePos1.x = 15;
                        movePolice(&po32, p2);
                        hitPolice(&po32, &pr2);
                        animate_printPolice(&po32, G_V.window);
                    }
                    if (!po42.inStandBy && !po42.tired)
                    {
                        po42.resistance--;
                        if (po42.resistance <= 0)
                            po42.tired = 1;
                        if (po42.resistance < 0)
                            po42.resistance = 0;
                        if (po42.resistancePos1.x < 15)
                            po42.resistancePos1.x = 15;
                        movePolice(&po42, p2);
                        hitPolice(&po42, &pr2);
                        animate_printPolice(&po42, G_V.window);
                    }
                    retreat(&po12, G_V.window, market2.scrolling_speed, &p2.score);
                    retreat(&po22, G_V.window, market2.scrolling_speed, &p2.score);
                    retreat(&po32, G_V.window, market2.scrolling_speed, &p2.score);
                    retreat(&po42, G_V.window, market2.scrolling_speed, &p2.score);

                    callForBackUp(&po12, &po22, &po32, &po42);

                    /////////

                    ////Invinsibilitie
                    isInvin(&po1.invin, po1.hitTime, po1.invinWindow);
                    isInvin(&po2.invin, po2.hitTime, po2.invinWindow);
                    isInvin(&po3.invin, po3.hitTime, po3.invinWindow);
                    isInvin(&po4.invin, po4.hitTime, po4.invinWindow);
                    isInvin(&G_V.NG.p.invin, G_V.NG.p.hitTime, G_V.NG.p.invinWindow);

                    isInvin(&po12.invin, po12.hitTime, po12.invinWindow);
                    isInvin(&po22.invin, po22.hitTime, po22.invinWindow);
                    isInvin(&po32.invin, po32.hitTime, po32.invinWindow);
                    isInvin(&po42.invin, po42.hitTime, po42.invinWindow);
                    isInvin(&p2.invin, p2.hitTime, p2.invinWindow);
                    /////
                    ////CAT
                    if (ca.called)
                    {
                        if (!ca.satisfied && !ca.attacked)
                        {
                            moveCat(&ca, G_V.NG.p.image[1].pos1);
                            feed(&G_V.NG.p, &ca);
                        }
                        if (ca.satisfied)
                        {
                            track(&ca, G_V.NG.p, &po1, &po2, &po3, &po4);
                            attack(&ca);
                        }
                        retreatCat(&ca, G_V.NG.b_market.scrolling_speed);
                        animateCat(&ca);
                        SDL_BlitSurface(ca.img.img, &ca.img.pos2, G_V.window, &ca.img.pos1);
                    }

                    else
                        ca.img.pos1.x = 0;

                    ////
                    ////CAT2
                    if (ca2.called)
                    {
                        if (!ca2.satisfied && !ca2.attacked)
                        {
                            moveCat(&ca2, p2.image[1].pos1);
                            feed(&p2, &ca2);
                        }
                        if (ca2.satisfied)
                        {
                            track(&ca2, p2, &po12, &po22, &po32, &po42);
                            attack(&ca2);
                        }
                        retreatCat(&ca2, market2.scrolling_speed);
                        animateCat(&ca2);
                        SDL_BlitSurface(ca2.img.img, &ca2.img.pos2, G_V.window, &ca2.img.pos1);
                    }

                    else
                        ca2.img.pos1.x = 0;

                    ////

                    /// Stamina P1
                    if (G_V.NG.p.stamina > 0)
                        if (G_V.NG.p.recovery == 0)
                            G_V.NG.p.stamina--;
                    G_V.NG.p.staminapos1.x = G_V.NG.p.image[1].pos1.x - 20;
                    G_V.NG.p.staminapos1.y = G_V.NG.p.image[1].pos1.y - 20;
                    G_V.NG.p.staminapos2.w = ((G_V.NG.p.stamina - 3000) * 66 / 10000) + 14;
                    G_V.NG.p.dangerLevelStapos2.w = (G_V.NG.p.stamina * 66 / 3000) + 14;

                    if (G_V.NG.p.stamina > 3000)
                    {
                        SDL_BlitSurface(G_V.NG.p.staminaImg, &G_V.NG.p.staminapos2, G_V.window, &G_V.NG.p.staminapos1);
                        SDL_BlitSurface(G_V.NG.p.staminaBar, NULL, G_V.window, &G_V.NG.p.staminapos1);
                    }
                    else
                    {
                        SDL_BlitSurface(G_V.NG.p.dangerLevelStaImg, &G_V.NG.p.dangerLevelStapos2, G_V.window, &G_V.NG.p.staminapos1);
                        SDL_BlitSurface(G_V.NG.p.dangerLevelStaBar, NULL, G_V.window, &G_V.NG.p.staminapos1);
                    }

                    ///
                    /// Stamina P2
                    if (p2.stamina > 0)
                        if (p2.recovery == 0)
                            p2.stamina--;
                    p2.staminapos1.x = p2.image[1].pos1.x - 20;
                    p2.staminapos1.y = p2.image[1].pos1.y - 20;
                    p2.staminapos2.w = ((p2.stamina - 3000) * 66 / 10000) + 14;
                    p2.dangerLevelStapos2.w = (p2.stamina * 66 / 3000) + 14;

                    if (p2.stamina > 3000)
                    {
                        SDL_BlitSurface(p2.staminaImg, &p2.staminapos2, G_V.window, &p2.staminapos1);
                        SDL_BlitSurface(p2.staminaBar, NULL, G_V.window, &p2.staminapos1);
                    }
                    else
                    {
                        SDL_BlitSurface(p2.dangerLevelStaImg, &p2.dangerLevelStapos2, G_V.window, &p2.staminapos1);
                        SDL_BlitSurface(p2.dangerLevelStaBar, NULL, G_V.window, &p2.staminapos1);
                    }

                    ///
                    ////// score P1
                    switch (G_V.NG.b_market.scrolling_speed)
                    {
                    case 1:
                        G_V.NG.p.score += 0.05;
                        break;
                    case 2:
                        G_V.NG.p.score += 0.1;
                        break;
                    case 3:
                        G_V.NG.p.score += 0.15;
                        break;
                    case 4:
                        G_V.NG.p.score += 0.4;
                        break;
                    }

                    //////

                    ////// score P2
                    switch (market2.scrolling_speed)
                    {
                    case 1:
                        p2.score += 0.05;
                        break;
                    case 2:
                        p2.score += 0.1;
                        break;
                    case 3:
                        p2.score += 0.15;
                        break;
                    case 4:
                        p2.score += 0.4;
                        break;
                    }

                    //////

                    ////////// BIG MESSY BLOCK 1
                    if ((!po1.inStandBy && !po1.tired) || (!po2.inStandBy && !po2.tired) || (!po3.inStandBy && !po3.tired) || (!po4.inStandBy && !po4.tired))
                        speak(&po1);

                    SDL_BlitSurface(coke.img, NULL, G_V.window, &coke.pos1);
                    SDL_BlitSurface(tea.img, NULL, G_V.window, &tea.pos1);
                    SDL_BlitSurface(fish.img, NULL, G_V.window, &fish.pos1);
                    SDL_BlitSurface(pr1.img.img, &pr1.img.pos2, G_V.window, &pr1.img.pos1);
                    SDL_BlitSurface(pr.img.img, &pr.img.pos2, G_V.window, &pr.img.pos1);
                    sprintf(pananatext, "%d", G_V.NG.p.panana);
                    pananat.windtxt = TTF_RenderText_Blended(pananat.font, pananatext, pananat.col);
                    SDL_BlitSurface(panana.img, NULL, G_V.window, &panana.pos1);
                    SDL_BlitSurface(pananat.windtxt, NULL, G_V.window, &pananat.postxt);

                    sprintf(scoretext, "%d", (int)G_V.NG.p.score);
                    scoret.windtxt = TTF_RenderText_Blended(scoret.font, scoretext, scoret.col);
                    SDL_BlitSurface(score.img, NULL, G_V.window, &score.pos1);
                    SDL_BlitSurface(scoret.windtxt, NULL, G_V.window, &scoret.postxt);

                    if (selectedCon == 1)
                    {
                        SDL_BlitSurface(selectedTeaIcon, NULL, G_V.window, &teaPos);
                    }
                    else
                        SDL_BlitSurface(teaIcon, NULL, G_V.window, &teaPos);

                    if (selectedCon == 2)
                    {
                        SDL_BlitSurface(selectedCokeIcon, NULL, G_V.window, &cokePos);
                    }
                    else
                        SDL_BlitSurface(cokeIcon, NULL, G_V.window, &cokePos);

                    if (selectedCon == 3)
                    {
                        SDL_BlitSurface(selectedFishIcon, NULL, G_V.window, &fishPos);
                    }
                    else
                        SDL_BlitSurface(fishIcon, NULL, G_V.window, &fishPos);
                    sprintf(coketext, "%d", G_V.NG.p.coke);
                    coket.windtxt = TTF_RenderText_Blended(coket.font, coketext, coket.col);
                    sprintf(teatext, "%d", G_V.NG.p.tea);
                    teat.windtxt = TTF_RenderText_Blended(teat.font, teatext, teat.col);
                    sprintf(fishtext, "%d", G_V.NG.p.fish);
                    fisht.windtxt = TTF_RenderText_Blended(fisht.font, fishtext, fisht.col);
                    SDL_BlitSurface(fisht.windtxt, NULL, G_V.window, &fisht.postxt);
                    SDL_BlitSurface(coket.windtxt, NULL, G_V.window, &coket.postxt);
                    SDL_BlitSurface(teat.windtxt, NULL, G_V.window, &teat.postxt);

                    SDL_BlitSurface(car.img.img, &car.img.pos2, G_V.window, &car.img.pos1);
                    SDL_BlitSurface(ob1.img.img, &ob1.img.pos2, G_V.window, &ob1.img.pos1);
                    SDL_BlitSurface(ob2.img.img, &ob2.img.pos2, G_V.window, &ob2.img.pos1);
                    SDL_BlitSurface(ob3.img.img, &ob3.img.pos2, G_V.window, &ob3.img.pos1);
                    ///////////////////////////////
                    ////////// BIG MESSY BLOCK 2
                    if ((!po12.inStandBy && !po12.tired) || (!po22.inStandBy && !po22.tired) || (!po32.inStandBy && !po32.tired) || (!po42.inStandBy && !po42.tired))
                        speak(&po12);

                    SDL_BlitSurface(coke2.img, NULL, G_V.window, &coke2.pos1);
                    SDL_BlitSurface(tea2.img, NULL, G_V.window, &tea2.pos1);
                    SDL_BlitSurface(fish2.img, NULL, G_V.window, &fish2.pos1);
                    SDL_BlitSurface(pr12.img.img, &pr12.img.pos2, G_V.window, &pr12.img.pos1);
                    SDL_BlitSurface(pr2.img.img, &pr2.img.pos2, G_V.window, &pr2.img.pos1);
                    sprintf(pananatext2, "%d", p2.panana);
                    pananat2.windtxt = TTF_RenderText_Blended(pananat2.font, pananatext2, pananat2.col);
                    SDL_BlitSurface(panana2.img, NULL, G_V.window, &panana2.pos1);
                    SDL_BlitSurface(pananat2.windtxt, NULL, G_V.window, &pananat2.postxt);

                    sprintf(scoretext2, "%d", (int)p2.score);
                    scoret2.windtxt = TTF_RenderText_Blended(scoret2.font, scoretext2, scoret2.col);
                    SDL_BlitSurface(score2.img, NULL, G_V.window, &score2.pos1);
                    SDL_BlitSurface(scoret2.windtxt, NULL, G_V.window, &scoret2.postxt);

                    if (selectedCon2 == 1)
                    {
                        SDL_BlitSurface(selectedTeaIcon, NULL, G_V.window, &teaPos2);
                    }
                    else
                        SDL_BlitSurface(teaIcon, NULL, G_V.window, &teaPos2);

                    if (selectedCon2 == 2)
                    {
                        SDL_BlitSurface(selectedCokeIcon, NULL, G_V.window, &cokePos2);
                    }
                    else
                        SDL_BlitSurface(cokeIcon, NULL, G_V.window, &cokePos2);

                    if (selectedCon2 == 3)
                    {
                        SDL_BlitSurface(selectedFishIcon, NULL, G_V.window, &fishPos2);
                    }
                    else
                        SDL_BlitSurface(fishIcon, NULL, G_V.window, &fishPos2);
                    sprintf(coketext2, "%d", p2.coke);
                    coket2.windtxt = TTF_RenderText_Blended(coket2.font, coketext2, coket2.col);
                    sprintf(teatext2, "%d", p2.tea);
                    teat2.windtxt = TTF_RenderText_Blended(teat2.font, teatext2, teat2.col);
                    sprintf(fishtext2, "%d", p2.fish);
                    fisht2.windtxt = TTF_RenderText_Blended(fisht2.font, fishtext2, fisht2.col);
                    SDL_BlitSurface(fisht2.windtxt, NULL, G_V.window, &fisht2.postxt);
                    SDL_BlitSurface(coket2.windtxt, NULL, G_V.window, &coket2.postxt);
                    SDL_BlitSurface(teat2.windtxt, NULL, G_V.window, &teat2.postxt);

                    SDL_BlitSurface(car2.img.img, &car2.img.pos2, G_V.window, &car2.img.pos1);
                    SDL_BlitSurface(ob12.img.img, &ob12.img.pos2, G_V.window, &ob12.img.pos1);
                    SDL_BlitSurface(ob22.img.img, &ob22.img.pos2, G_V.window, &ob22.img.pos1);
                    SDL_BlitSurface(ob32.img.img, &ob32.img.pos2, G_V.window, &ob32.img.pos1);
                    ///////////////////////////////

                    if (is_in_rect(G_V.NG.p.image[1].pos1.x + 20, G_V.NG.p.image[1].pos1.y, po1.pos1))
                    {
                        /* printf("HEREEEEEEEEEEEEEEE\n");
                         G_V.NG.p.caught = 1;
                         stupidPolice=1;
                         G_V.NG.p.caughtTime=SDL_GetTicks();*/
                        G_V.NG.p.stamina -= 5;
                        if (G_V.NG.p.stamina < 0)
                            G_V.NG.p.stamina = 0;
                    }
                    if (is_in_rect(G_V.NG.p.image[1].pos1.x + 20, G_V.NG.p.image[1].pos1.y, po2.pos1))
                    {
                        /* G_V.NG.p.caught = 1;
                         stupidPolice=2;
                         G_V.NG.p.caughtTime=SDL_GetTicks();*/
                        G_V.NG.p.stamina -= 5;
                        if (G_V.NG.p.stamina < 0)
                            G_V.NG.p.stamina = 0;
                    }
                    if (is_in_rect(G_V.NG.p.image[1].pos1.x + 20, G_V.NG.p.image[1].pos1.y, po3.pos1))
                    {
                        /* G_V.NG.p.caught = 1;
                         stupidPolice=3;
                         G_V.NG.p.caughtTime=SDL_GetTicks();*/
                        G_V.NG.p.stamina -= 5;
                        if (G_V.NG.p.stamina < 0)
                            G_V.NG.p.stamina = 0;
                    }
                    if (is_in_rect(G_V.NG.p.image[1].pos1.x + 20, G_V.NG.p.image[1].pos1.y, po4.pos1))
                    {
                        /* G_V.NG.p.caught = 1;
                         stupidPolice=4;
                         G_V.NG.p.caughtTime=SDL_GetTicks();*/
                        G_V.NG.p.stamina -= 5;
                        if (G_V.NG.p.stamina < 0)
                            G_V.NG.p.stamina = 0;
                    }
                    // SDL_BlitSurface(G_V.NG.b_market.b_k[0].img,NULL,G_V.window,NULL);
                }
                else
                {

                    if (keystate[SDLK_r])
                    {
                        G_V.NG.p.initlevel = 0;
                        G_V.NG.p.caught = 0;
                    }
                }
            }
            break;
        case 10:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 120)
            {

                switch (G_V.event.type)
                {
                case SDL_QUIT:
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.out = 1;
                    break;
                }
                if (cenem == 19)
                    cenem = 146;
                if (cenem <= 19){
                    SDL_BlitSurface(G_V.cematiques[cenem].img, NULL, G_V.window, NULL);
                    Mix_PlayMusic(typewriter3, -1);
                }
                else if (cenem >= 146 && cenem < 177)
                    SDL_BlitSurface(G_V.cematiques[cenem].img, NULL, G_V.window, NULL);
                cenem++;
                if (cenem >= 200)
                {
                    cenem = 0;
                    G_V.NG.p.image[0].pos1.x = (8 * G_V.W) / 100;
                    G_V.NG.p.image[0].pos1.y = (47 * G_V.W) / 100;
                    G_V.NG.p.image[1].pos1.x = (8 * G_V.W) / 100; // 100;
                    G_V.NG.p.image[1].pos1.y = (24 * G_V.W) / 100;
                    G_V.NG.plystate = 1;
                    G_V.state = 11;
                    G_V.NG.m.shape.x = G_V.W - 220;
                    G_V.NG.m.shape.y = 0;
                    G_V.NG.m.shape.w = 220;
                    G_V.NG.m.shape.h = 220;
                    G_V.NG.m.map[0].pos1.x = G_V.NG.m.shape.x + (G_V.NG.m.shape.w - G_V.NG.m.map[0].img->w) / 2;
                    G_V.NG.m.map[0].pos1.y = (G_V.NG.m.shape.h - G_V.NG.m.map[0].img->h) / 2;
                }
                G_V.end = SDL_GetTicks();
            }
            break;
        case 11:
            G_V.start = SDL_GetTicks();
            G_V.dt = G_V.start - G_V.end;
            if (G_V.dt > 100)
            {

                if (G_V.Is_butt_on[5])
                {
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.state = 12;
                    G_V.M.back_up = 11;
                }
                switch (G_V.event.type)
                {
                case SDL_QUIT:
                    Mix_PlayChannel(-1, effect, 0);
                    G_V.out = 1;
                    break;
                }
                if (G_V.NG.b.i == 8)
                    G_V.NG.m.where = 1;
                else
                    G_V.NG.m.where = 0;
                if (timepassed(10000))
                    G_V.test_ing = 1;
                if (G_V.test_ing && collisionPP_ing_txt(G_V.NG.p, G_V.NG.b.b_k[G_V.NG.b.coll_i].img) && !G_V.NG.race && G_V.NG.plystate != 6)
                {
                    srand(time(0));
                    x = rand() % 3 + 1;
                    G_V.NG.plystate = 2;
                    G_V.test_ing = 0;
                }
                else if (G_V.test_ing && G_V.coll_PP_ing_ph && !G_V.NG.race && G_V.NG.plystate != 6)
                {
                    srand(time(0));
                    G_V.NG.e_ph.x = rand() % 2;
                    G_V.NG.plystate = 4;
                    G_V.test_ing = 0;
                }
                else
                {
                    // shosing the right state of the caratere
                    if (G_V.NG.p.acc == 0 && G_V.perso_in == 1)
                    {
                        G_V.NG.p.where = 0;
                        G_V.perso_in = 2;
                    }
                    if (G_V.NG.p.acc != 0 && G_V.perso_in == 2)
                    {
                        G_V.NG.p.where = 1;
                        G_V.perso_in = 1;
                    }


                    // shosing the derection of runing
                    if (G_V.NG.p.acc < 0)
                        G_V.NG.p.acc = 0;
                    if (G_V.Is_butt_on[0])
                        G_V.NG.p.derec = 3;
                    if (G_V.Is_butt_on[1])
                        G_V.NG.p.derec = 4;
                    if (G_V.Is_butt_on[2])
                        G_V.NG.p.derec = 1;
                    if (G_V.Is_butt_on[3])
                        G_V.NG.p.derec = 2;

                    // printf("derection %d\n",G_V.NG.p.derec);
                    //   giving the 2 bk ph the same pos
                    G_V.NG.p.bk_pos2 = G_V.NG.b.b_k[G_V.NG.b.i].pos2;
                    // detection of the collusion
                    if (G_V.NG.plystate != 6)
                        k = collisionPP(G_V.NG.p, G_V.NG.b.b_k[G_V.NG.b.coll_i].img);
                    else if (G_V.NG.plystate == 6)
                    {
                        G_V.NG.p.bk_pos2.x = 0;
                        G_V.NG.p.bk_pos2.y = 0;
                        k = collisionPP(G_V.NG.p, G_V.out_presion[1].img);
                    }
                    if (k)
                    {
                        G_V.NG.p.coll_derection = G_V.NG.p.derec;
                        G_V.NG.p.acc = 0;
                        if (G_V.NG.p.still_in)
                            G_V.NG.p.still_in2 = 1;
                        /*switch (G_V.NG.p.derec)
                         {
                         case 1:
                             arduinoWriteData(3);
                             break;
                         case 2:
                             arduinoWriteData(4);
                             break;
                         case 3:
                             arduinoWriteData(1);
                             break;
                         case 4:
                             arduinoWriteData(2);
                             break;
                         }
                         innn=0;*/
                    }
                    /*else if(k==0&&innn==0){
                        arduinoWriteData(0);
                        switch (G_V.NG.p.derec)
                         {
                         case 1:
                            G_V.NG.p.image[G_V.NG.p.where].pos1.y-=40;
                             break;
                         case 2:
                            G_V.NG.p.image[G_V.NG.p.where].pos1.y+=40;
                             break;
                         case 3:
                            G_V.NG.p.image[G_V.NG.p.where].pos1.x-=40;
                             break;
                         case 4:
                            G_V.NG.p.image[G_V.NG.p.where].pos1.x+=40;
                             break;
                         }
                        innn=1;
                    }
                    else if(innn=1&&k==0)  {
                        arduinoReadData(&received);
                    }
                    switch (received)
                    {
                    case 1:
                        G_V.NG.p.derec = 3;
                        G_V.NG.p.acc = 0.05;
                        break;
                    case 2:
                        G_V.NG.p.derec = 4;
                        G_V.NG.p.acc = 0.05;

                        break;
                    case 3:
                        G_V.NG.p.derec = 1;
                        G_V.NG.p.acc = 0.05;

                        break;
                    case 4:
                        G_V.NG.p.derec = 2;
                        G_V.NG.p.acc = 0.05;
                        break;
                    }*/

                    if (G_V.NG.plystate != 6)
                        G_V.coll_PP_ing_ph = collisionPP_ing_ph(G_V.NG.p, G_V.NG.b.b_k[G_V.NG.b.coll_i].img);
                    if (G_V.coll_PP_ing_ph && !k)
                    {
                        G_V.NG.p.acc = 0;
                        G_V.NG.p.coll_derection = G_V.coll_PP_ing_ph;
                    }
                    // decreasing the acceleration
                    if (G_V.Is_butt_on[0] == 0 && G_V.Is_butt_on[1] == 0 && G_V.Is_butt_on[2] == 0 && G_V.Is_butt_on[3] == 0 && G_V.NG.p.acc > 0)
                        G_V.NG.p.acc -= 0.005;
                    // increasing the acceleration
                    else if (((G_V.Is_butt_on[0] || G_V.Is_butt_on[1] || G_V.Is_butt_on[2] || G_V.Is_butt_on[3])) && G_V.NG.p.coll_derection != G_V.NG.p.derec && G_V.NG.p.acc < 0.05)
                        G_V.NG.p.acc += 0.01;
                    // turning on the scrolling
                    if (G_V.NG.p.image[G_V.NG.p.where].pos1.x >= G_V.W / 2 && G_V.NG.p.derec == 3 && G_V.NG.b.b_k[G_V.NG.b.i].pos2.x + G_V.W < G_V.NG.b.b_k[G_V.NG.b.i].img->w && G_V.NG.p.acc > 0)
                        G_V.NG.p.scrolling_on = 1;
                    else if (G_V.NG.p.image[G_V.NG.p.where].pos1.x <= G_V.W / 2 && G_V.NG.p.derec == 4 && G_V.NG.b.b_k[G_V.NG.b.i].pos2.x > 0 && G_V.NG.p.acc > 0)
                        G_V.NG.p.scrolling_on = 1;
                    else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y >= G_V.H / 2 && G_V.NG.p.derec == 1 && G_V.NG.b.b_k[G_V.NG.b.i].pos2.y + G_V.H < G_V.NG.b.b_k[G_V.NG.b.i].img->h && G_V.NG.p.acc > 0)
                        G_V.NG.p.scrolling_on = 1;
                    else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y <= G_V.H / 2 && G_V.NG.p.derec == 2 && G_V.NG.b.b_k[G_V.NG.b.i].pos2.y > 0 && G_V.NG.p.acc > 0)
                        G_V.NG.p.scrolling_on = 1;

                    if (G_V.Is_butt_on[6] && G_V.NG.plystate == 6)
                        G_V.NG.p.acc = 0.1;
                    //  the jump
                    if (G_V.NG.plystate != 6)
                    {
                        if (G_V.NG.p.still_in2)
                        {
                            G_V.NG.p.still_in = 0;
                            G_V.NG.p.image[G_V.NG.p.where].pos1.y += 10;
                            if (G_V.NG.p.image[G_V.NG.p.where].pos1.y >= G_V.NG.p.y)
                                G_V.NG.p.still_in2 = 0;
                        }
                        if (G_V.NG.p.still_in)
                            saut(&G_V.NG.p);
                        else if (G_V.Is_butt_on[6])
                        {
                            G_V.NG.p.y = G_V.NG.p.image[G_V.NG.p.where].pos1.y;
                            G_V.NG.p.still_in = 1;
                            G_V.NG.p.i = -60;
                        }
                        if (G_V.NG.p.scrolling_on)
                        {
                            scrolling(&G_V.NG.b, G_V.NG.p.derec, 0.5 * G_V.NG.p.acc * 17 * 17 + G_V.NG.p.speed * 17);
                            G_V.NG.p.scrolling_on = 0;
                        }
                        else
                            deplacerPerso(&G_V.NG.p, 17);
                        if (G_V.NG.e_ph.evaluation && G_V.NG.b.do_anim)
                        {
                            animerBackground(&G_V.NG.b);
                            if (G_V.NG.b.count == 0)
                                G_V.NG.e_ph.evaluation = 0;
                            G_V.NG.b.coll_i = 5;
                        }
                        else
                            G_V.NG.b.coll_i = 4;
                    }
                    else if (G_V.NG.plystate == 6)
                        deplacerPerso(&G_V.NG.p, 17);

                    animerPerso(&G_V.NG.p);
                    aficherBack(G_V.NG.b, G_V.window);
                    afficherPerso(G_V.NG.p, G_V.window);
                    G_V.NG.m.where = 0;
                    afficherminimap(G_V.NG.m, G_V.window);
                    // detecting the position of the caratere in the minmap
                    G_V.NG.m.bk_pos2 = G_V.NG.b.b_k[G_V.NG.b.i].pos2;
                    G_V.camera_pos = MAJMinimap(G_V.NG.p.image->pos1, &G_V.NG.m, G_V.camera_pos, G_V.NG.m.redemtion[G_V.NG.m.where]);
                    SDL_FillRect(G_V.window, &G_V.camera_pos, G_V.NG.m.col);
                    // dealing with the ennemy
                    if (G_V.NG.b.i != 8)
                    {
                        G_V.coll_PP_ennemy_race = collisionPP_ennemy_race(G_V.NG.p, G_V.NG.b.b_k[G_V.NG.b.coll_i].img);
                        if (G_V.coll_PP_ennemy_race && G_V.NG.plystate != 6)
                        {
                            G_V.NG.plystate = 6;
                            G_V.NG.p.image[G_V.NG.p.where].pos1.x = 0;
                            G_V.NG.p.image[G_V.NG.p.where].pos1.y = G_V.H / 2;
                            G_V.NG.race = 1;
                            Mix_PlayMusic(death_means_death, -1);
                        }
                        else
                            G_V.NG.race = 0;
                    }
                }
                switch (G_V.NG.plystate)
                {
                case 2:
                    // bliting the bakground of the reddle
                    blit_all(G_V.window, 4, &G_V.NG.e_txt.bg[G_V.NG.e_txt.animationn], &G_V.NG.e_txt.butt[0][0], &G_V.NG.e_txt.butt[0][1], &G_V.NG.e_txt.butt[0][2]);
                    G_V.NG.e_txt.count++;
                    if (G_V.NG.e_txt.count % 5 == 0)
                    {
                        G_V.NG.e_txt.animationn++;
                        G_V.NG.e_txt.count = 0;
                    }
                    if (G_V.NG.e_txt.animationn > 3)
                        G_V.NG.e_txt.animationn = 0;
                    switch (G_V.event.type)
                    {
                    case SDL_QUIT:
                        Mix_PlayChannel(-1, effect, 0);
                        G_V.NG.plystate = 1;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        G_V.x1 = G_V.event.motion.x;
                        G_V.y1 = G_V.event.motion.y;
                        // chosing the option
                        if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_txt.butt[0][0].pos1) && G_V.NG.plystate == 2)
                        {
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.NG.e_txt.choise = 1;
                        }
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_txt.butt[0][1].pos1) && G_V.NG.plystate == 2)
                        {
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.NG.e_txt.choise = 2;
                        }
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_txt.butt[0][2].pos1) && G_V.NG.plystate == 2)
                        {
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.NG.e_txt.choise = 3;
                        }
                        break;
                    case SDL_MOUSEMOTION:
                        G_V.x1 = G_V.event.motion.x;
                        G_V.y1 = G_V.event.motion.y;
                        // chosing the option
                        if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_txt.butt[0][0].pos1) && G_V.NG.plystate == 2)
                        {
                            SDL_BlitSurface(G_V.NG.e_txt.bg[4].img, NULL, G_V.window, &G_V.NG.e_txt.bg[4].pos1);
                        }
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_txt.butt[0][1].pos1) && G_V.NG.plystate == 2)
                        {
                            SDL_BlitSurface(G_V.NG.e_txt.bg[4].img, NULL, G_V.window, &G_V.NG.e_txt.bg[4].pos1);
                        }
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_txt.butt[0][2].pos1) && G_V.NG.plystate == 2)
                        {
                            SDL_BlitSurface(G_V.NG.e_txt.bg[4].img, NULL, G_V.window, &G_V.NG.e_txt.bg[4].pos1);
                        }
                        break;
                    }
                    animer(&G_V.NG.e_txt);

                    // bliting the chosen riddle
                    switch (x)
                    {
                    case 1:
                        blit_all_txt(G_V.window, 4, &G_V.NG.e_txt.t_Q[0], &G_V.NG.e_txt.t_AN[0], &G_V.NG.e_txt.t_AN[1], &G_V.NG.e_txt.t_AN[2]);
                        break;
                    case 2:
                        blit_all_txt(G_V.window, 4, &G_V.NG.e_txt.t_Q[1], &G_V.NG.e_txt.t_AN[3], &G_V.NG.e_txt.t_AN[4], &G_V.NG.e_txt.t_AN[5]);
                        break;
                    case 3:
                        blit_all_txt(G_V.window, 4, &G_V.NG.e_txt.t_Q[2], &G_V.NG.e_txt.t_AN[6], &G_V.NG.e_txt.t_AN[7], &G_V.NG.e_txt.t_AN[8]);
                        break;
                    }
                    SDL_BlitSurface(G_V.NG.e_txt.time_txt[G_V.NG.e_txt.i].img, NULL, G_V.window, &G_V.NG.e_txt.time_txt[G_V.NG.e_txt.i].pos1);
                    if (G_V.NG.e_txt.choise == G_V.NG.e_txt.true_answer[x - 1] && G_V.NG.e_txt.i < 12)
                    {
                        G_V.NG.e_txt.evaluation = 1;
                        G_V.NG.plystate = 3;
                        if (G_V.NG.e_txt.which_gate == 2)
                            G_V.NG.e_txt.which_gate = 1;
                        else
                            G_V.NG.e_txt.which_gate = 2;
                    }
                    else if (G_V.NG.e_txt.i >= 12 || (G_V.NG.e_txt.choise != G_V.NG.e_txt.true_answer[x - 1] && G_V.NG.e_txt.choise != -15))
                    {
                        G_V.NG.e_txt.evaluation = 0;
                        G_V.NG.plystate = 3;
                    }

                    break;
                case 3:
                    afficherEnigme(G_V.NG.e_txt, G_V.window);
                    if (timepassed(1000))
                    {
                        // reinitiallising my variables
                        G_V.NG.plystate = 1;
                        G_V.NG.e_txt.choise = -15;
                        G_V.NG.e_txt.i = 0;
                        // shosing wich gate the caractere is going to go to
                        if (G_V.NG.e_txt.evaluation == 1 && G_V.NG.e_txt.which_gate == 1)
                        {
                            G_V.NG.p.image[1].pos1.x = G_V.W / 5;
                            G_V.NG.p.image[1].pos1.y = G_V.H / 3;
                            G_V.NG.b.b_k[G_V.NG.b.i].pos2.x = 0;
                            G_V.NG.b.b_k[G_V.NG.b.i].pos2.y = 0;
                        }
                        else if (G_V.NG.e_txt.evaluation == 1 && G_V.NG.e_txt.which_gate == 2)
                        {
                            G_V.NG.p.image[1].pos1.x = G_V.W / 3.7;
                            G_V.NG.p.image[1].pos1.y = G_V.H / 3.2;
                            G_V.NG.p.image[0].pos1 = G_V.NG.p.image[1].pos1;
                            G_V.NG.b.b_k[G_V.NG.b.i].pos2.x = 0;
                            G_V.NG.b.b_k[G_V.NG.b.i].pos2.y = G_V.NG.b.b_k[G_V.NG.b.i].img->h - G_V.H * 1.5;
                        }
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.w = G_V.W;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.h = G_V.H;
                        G_V.NG.p.derec = 1;
                        G_V.NG.p.acc = 0.05;
                    }
                    break;
                case 4:
                    G_V.NG.b.do_anim = 0;
                    switch (G_V.event.type)
                    {
                    case SDL_QUIT:
                        Mix_PlayChannel(-1, effect, 0);
                        G_V.NG.plystate = 1;
                        break;
                    case SDL_MOUSEMOTION:
                        G_V.x1 = G_V.event.motion.x;
                        G_V.y1 = G_V.event.motion.y;
                        if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_ph.pos_butt[0]) && G_V.NG.plystate == 4)
                            G_V.NG.e_ph.where = 2;
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_ph.pos_butt[1]) && G_V.NG.plystate == 4)
                            G_V.NG.e_ph.where = 3;
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_ph.pos_butt[2]) && G_V.NG.plystate == 4)
                            G_V.NG.e_ph.where = 4;
                        else
                            G_V.NG.e_ph.where = 0;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        G_V.x1 = G_V.event.motion.x;
                        G_V.y1 = G_V.event.motion.y;
                        // chosing the option
                        if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_ph.pos_butt[0]) && G_V.NG.plystate == 4)
                        {
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.NG.e_ph.choise = 1;
                            G_V.NG.e_ph.where = 1;
                        }
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_ph.pos_butt[1]) && G_V.NG.plystate == 4)
                        {
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.NG.e_ph.choise = 2;
                            G_V.NG.e_ph.where = 1;
                        }
                        else if (is_in_rect(G_V.x1, G_V.y1, G_V.NG.e_ph.pos_butt[2]) && G_V.NG.plystate == 4)
                        {
                            Mix_PlayChannel(-1, effect, 0);
                            G_V.NG.e_ph.choise = 3;
                            G_V.NG.e_ph.where = 1;
                        }
                        break;
                    }
                    animer(&G_V.NG.e_txt);
                    SDL_FillRect(G_V.window, NULL, G_V.col1);
                    afficherEnigme_ph(G_V.NG.e_ph, G_V.window);
                    SDL_BlitSurface(G_V.NG.e_txt.time_txt[G_V.NG.e_txt.i].img, NULL, G_V.window, &G_V.NG.e_txt.time_txt[G_V.NG.e_txt.i].pos1);
                    if (G_V.NG.e_ph.choise == G_V.NG.e_ph.true_answer[G_V.NG.e_ph.x] && G_V.NG.e_txt.i < 12)
                    {
                        G_V.NG.e_ph.evaluation = 1;
                        G_V.NG.plystate = 5;
                        G_V.coll_PP_ing_ph = 0;
                    }
                    else if (G_V.NG.e_txt.i >= 12 || (G_V.NG.e_ph.choise != G_V.NG.e_ph.true_answer[G_V.NG.e_ph.x] && G_V.NG.e_ph.choise != -15))
                    {
                        G_V.NG.e_ph.evaluation = 0;
                        G_V.NG.plystate = 5;
                        G_V.coll_PP_ing_ph = 0;
                        G_V.NG.e_ph.evaluation = 0;
                    }
                    break;
                case 5:
                    SDL_BlitSurface(G_V.NG.e_ph.end[G_V.NG.e_ph.evaluation].img, NULL, G_V.window, NULL);
                    if (timepassed(1000))
                    {
                        // reinitiallising my variables
                        G_V.NG.plystate = 1;
                        G_V.NG.e_ph.choise = -15;
                        G_V.NG.e_ph.i = 0;
                        if (G_V.NG.e_AI.ing && G_V.NG.e_ph.evaluation)
                        {
                            G_V.NG.plystate = 8;
                            G_V.NG.e_AI.ing = 0;
                            G_V.NG.e_AI.evaluation = 1;
                            strcmp(G_V.NG.e_AI.satete, "bla");
                        }
                        else if (G_V.NG.e_AI.ing && !G_V.NG.e_ph.evaluation)
                        {
                            G_V.NG.plystate = 9;
                            G_V.NG.e_AI.evaluation = 0;
                        }
                        else if (G_V.NG.p.derec == 1)
                        {
                            G_V.NG.p.image[0].pos1.y -= 30;
                            G_V.NG.p.image[1].pos1.y -= 30;
                            G_V.NG.b.do_anim = 1;
                        }
                        else if (G_V.NG.p.derec == 2)
                        {
                            G_V.NG.p.image[0].pos1.y += 30;
                            G_V.NG.p.image[1].pos1.y += 30;
                            G_V.NG.b.do_anim = 1;
                        }
                    }
                    break;
                case 6:
                    G_V.presion_hart[G_V.presion_count].pos1.x = G_V.NG.p.image[G_V.NG.p.where].pos1.x - G_V.presion_hart[G_V.presion_count].img->w / 2 + G_V.NG.p.image[G_V.NG.p.where].pos2.w / 2;
                    G_V.presion_hart[G_V.presion_count].pos1.y = G_V.NG.p.image[G_V.NG.p.where].pos1.y - G_V.presion_hart[G_V.presion_count].img->h;
                    SDL_BlitSurface(G_V.out_presion[0].img, NULL, G_V.window, NULL);
                    SDL_BlitSurface(G_V.presion_hart[G_V.presion_count].img, NULL, G_V.window, &G_V.presion_hart[G_V.presion_count].pos1);
                    // SDL_FillRect(G_V.window, NULL, G_V.col2);
                    if (G_V.NG.p.image[G_V.NG.p.where].pos1.x > G_V.W / 2&&preions_i<9)
                    {
                        preions_i = 9;
                        Mix_PlayChannel(-1,po1.needBackUp,0);
                    }
                    /*if (G_V.NG.p.image[G_V.NG.p.where].pos1.x > G_V.W / 1.5&&preions_i<12)
                    {
                        preions_i = 12;
                    }*/
                    for (int i = 0; i < preions_i; i++)
                    {
                        if (collisionBB_pro(G_V.NG.e1_6[i], G_V.NG.p))
                        {
                            G_V.coll_BB = 1;
                            G_V.presion_count++;
                            break;
                        }
                        deplacer(&G_V.NG.e1_6[i]);
                        if (G_V.NG.e1_6[i].cafe_img.pos1.x + G_V.NG.e1_6[i].cafe_img.pos2.w >= G_V.W)
                        {
                            G_V.NG.e1_6[i].func_num = 2;
                            G_V.NG.e1_6[i].derection = 1;
                        }
                        else if (G_V.NG.e1_6[i].cafe_img.pos1.y + G_V.NG.e1_6[i].cafe_img.pos2.h >= G_V.H)
                        {
                            G_V.NG.e1_6[i].func_num = 4;
                            G_V.NG.e1_6[i].derection = 4;
                        }
                        else if (G_V.NG.e1_6[i].cafe_img.pos1.x <= 200)
                        {
                            G_V.NG.e1_6[i].func_num = 1;
                            G_V.NG.e1_6[i].derection = 2;
                        }
                        else if (G_V.NG.e1_6[i].cafe_img.pos1.y <= 0)
                        {
                            G_V.NG.e1_6[i].func_num = 3;
                            G_V.NG.e1_6[i].derection = 3;
                        }
                        animerEnnemie_pro(&G_V.NG.e1_6[i]);
                        // printf("police attack %d\n", update_police_attack(G_V.NG.e1_6[i], G_V.NG.p, G_V.window));
                        if (update_police_attack(G_V.NG.e1_6[i], G_V.NG.p, G_V.window))
                        {
                            if (G_V.NG.p.derec == 2)
                            {
                                if (G_V.NG.p.image[G_V.NG.p.where].pos1.y - G_V.NG.e1_6[i].cafe_img.pos1.y - G_V.NG.e1_6[i].cafe_img.pos2.h > 10)
                                {
                                    G_V.NG.e1_6[i].func_num = 3;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.x - G_V.NG.e1_6[i].cafe_img.pos1.x > 10)
                                {
                                    G_V.NG.e1_6[i].func_num = 1;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.x - G_V.NG.e1_6[i].cafe_img.pos1.x < 0)
                                {
                                    G_V.NG.e1_6[i].func_num = 2;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                            }
                            else if (G_V.NG.p.derec == 4)
                            {
                                if (G_V.NG.p.image[G_V.NG.p.where].pos1.y + G_V.NG.p.image[G_V.NG.p.where].pos2.h - G_V.NG.e1_6[i].cafe_img.pos1.y - G_V.NG.e1_6[i].cafe_img.pos2.h > 10)
                                {
                                    G_V.NG.e1_6[i].func_num = 3;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y + G_V.NG.p.image[G_V.NG.p.where].pos2.h - G_V.NG.e1_6[i].cafe_img.pos1.y - G_V.NG.e1_6[i].cafe_img.pos2.h < 0)
                                {
                                    G_V.NG.e1_6[i].func_num = 4;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                                else if (G_V.NG.e1_6[i].cafe_img.pos1.x + G_V.NG.e1_6[i].cafe_img.pos2.w + 50 < G_V.NG.p.image[G_V.NG.p.where].pos1.x)
                                {
                                    G_V.NG.e1_6[i].func_num = 1;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                            }
                            else if (G_V.NG.p.derec == 3)
                            {

                                if (G_V.NG.p.image[G_V.NG.p.where].pos1.y + G_V.NG.p.image[G_V.NG.p.where].pos2.h - G_V.NG.e1_6[i].cafe_img.pos1.y - G_V.NG.e1_6[i].cafe_img.pos2.h > 10)
                                {
                                    G_V.NG.e1_6[i].func_num = 3;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                                else if (G_V.NG.p.image[G_V.NG.p.where].pos1.y + G_V.NG.p.image[G_V.NG.p.where].pos2.h - G_V.NG.e1_6[i].cafe_img.pos1.y - G_V.NG.e1_6[i].cafe_img.pos2.h < 0)
                                {
                                    G_V.NG.e1_6[i].func_num = 4;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                                else if (G_V.NG.e1_6[i].cafe_img.pos1.x - 30 > G_V.NG.p.image[G_V.NG.p.where].pos1.x + G_V.NG.p.image[G_V.NG.p.where].pos2.w + 30)
                                {
                                    G_V.NG.e1_6[i].func_num = 2;
                                    G_V.NG.e1_6[i].stay = 2;
                                }
                            }
                            if (G_V.NG.e1_6[i].stay == 2)
                            {
                                deplacer(&G_V.NG.e1_6[i]);
                            }
                        }
                        else
                        {
                            G_V.NG.e1_6[i].MV_destance[1] = 0;
                            G_V.NG.e1_6[i].MV_destance[0] = 0;
                            G_V.NG.e1_6[i].stay = 0;
                        }
                        afficherEnnemi_pro(G_V.NG.e1_6[i], G_V.window);
                    }
                    if (G_V.coll_BB && G_V.presion_count < 3)
                    {
                        G_V.coll_BB = 0;
                        G_V.NG.p.image[0].pos1.x = 50;
                        G_V.NG.p.image[0].pos1.y = G_V.H / 2;
                        G_V.NG.p.image[1].pos1.x = 50;
                        G_V.NG.p.image[1].pos1.y = G_V.H / 2;
                        G_V.NG.race = 1;
                        G_V.NG.plystate = 6;
                        G_V.NG.p.acc = 0;
                        G_V.NG.e1_6[0].cafe_img.pos1.x = 500;
                        G_V.NG.e1_6[0].cafe_img.pos1.y = 0;
                        G_V.NG.e1_6[0].func_num = 3;

                        G_V.NG.e1_6[1].cafe_img.pos1.x = 800;
                        G_V.NG.e1_6[1].cafe_img.pos1.y = G_V.H / 2 - G_V.NG.e1_6[5].cafe_img.pos2.h / 2;
                        G_V.NG.e1_6[1].func_num = 3;

                        G_V.NG.e1_6[2].cafe_img.pos1.x = 1200;
                        G_V.NG.e1_6[2].cafe_img.pos1.y = G_V.H - G_V.NG.e1_6[5].cafe_img.pos2.h;
                        G_V.NG.e1_6[2].func_num = 2;

                        G_V.NG.e1_6[3].cafe_img.pos1.x = 800;
                        G_V.NG.e1_6[3].cafe_img.pos1.y = 100;
                        G_V.NG.e1_6[3].func_num = 2;

                        G_V.NG.e1_6[4].cafe_img.pos1.x = 1000;
                        G_V.NG.e1_6[4].cafe_img.pos1.y = G_V.H / 2 - G_V.NG.e1_6[5].cafe_img.pos2.h / 2;
                        G_V.NG.e1_6[4].func_num = 2;

                        G_V.NG.e1_6[5].cafe_img.pos1.x = 1200;
                        G_V.NG.e1_6[5].cafe_img.pos1.y = G_V.H - G_V.NG.e1_6[5].cafe_img.pos2.h - 100;
                        G_V.NG.e1_6[5].func_num = 2;

                       G_V.NG.e1_6[9].cafe_img.pos1.x = 1100;
                        G_V.NG.e1_6[9].cafe_img.pos1.y = 100;
                        G_V.NG.e1_6[9].func_num = 2;

                        G_V.NG.e1_6[10].cafe_img.pos1.x = 1100;
                        G_V.NG.e1_6[10].cafe_img.pos1.y = G_V.H / 2 - G_V.NG.e1_6[5].cafe_img.pos2.h / 2;
                        G_V.NG.e1_6[10].func_num = 2;

                        G_V.NG.e1_6[11].cafe_img.pos1.x = 1100;
                        G_V.NG.e1_6[11].cafe_img.pos1.y = G_V.H - G_V.NG.e1_6[5].cafe_img.pos2.h - 100;
                        G_V.NG.e1_6[11].func_num = 2;
                    }
                    else if (G_V.coll_BB && G_V.presion_count == 3)
                    {
                        G_V.NG.plystate = 1;
                        G_V.NG.p.image[0].pos1.x = (8 * G_V.W) / 100;
                        G_V.NG.p.image[0].pos1.y = (40 * G_V.W) / 100;
                        G_V.NG.p.image[1].pos1.x = (8 * G_V.W) / 100;
                        G_V.NG.p.image[1].pos1.y = (40 * G_V.W) / 100;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.x = 0;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.y = G_V.NG.b.b_k[G_V.NG.b.i].img->h - G_V.H;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.w = G_V.W;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.h = G_V.H;
                        G_V.coll_BB = 0;
                        G_V.coll_PP_ennemy_race = 0;
                        G_V.NG.p.acc = 0.05;
                    }
                    if (G_V.NG.p.image[G_V.NG.p.where].pos1.x + G_V.NG.p.image[G_V.NG.p.where].pos2.w > G_V.W-50)
                    {
                        G_V.NG.plystate = 7;
                    }
                    afficherPerso(G_V.NG.p, G_V.window);
                    break;
                case 7:
                    SDL_FillRect(G_V.window, NULL, G_V.col2);
                    SDL_BlitSurface(G_V.win.img, NULL, G_V.window, NULL);
                    if (timepassed(20000))
                        G_V.out = 1;
                    break;
                case 8:
                    if (aoug > 10)
                    {
                        G_V.NG.e_AI.ing = 0;
                        G_V.NG.e_AI.evaluation = 0;
                    }
                    else if (aoug < 10 && G_V.NG.e_AI.evaluation == 1)
                    {
                        if (G_V.NG.e_AI.derection == 3)
                            G_V.NG.e_AI.spsh = 10;
                        else if (G_V.NG.e_AI.derection == 4)
                            G_V.NG.e_AI.spsh = 2;
                        G_V.NG.e_AI.derection = G_V.NG.p.derec;
                        if (G_V.NG.e_AI.derection == 3)
                            G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x = G_V.NG.p.image[G_V.NG.p.where].pos1.x - 40;
                        else if (G_V.NG.e_AI.derection == 4)
                            G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x = G_V.NG.p.image[G_V.NG.p.where].pos1.x - 200;
                        G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].y = G_V.NG.p.image[G_V.NG.p.where].pos1.y - 80;
                        animateEnnemi(&G_V.NG.e_AI);
                        afficherEnnemi(G_V.NG.e_AI, G_V.window);
                        strcpy(G_V.NG.e_AI.satete, "bla");
                        aoug++;
                    }
                    if (timepassed_pro(10000) && aoug >= 10)
                    {
                        G_V.NG.plystate = 1;
                        G_V.in_e_ai = 1;
                        strcpy(G_V.NG.e_AI.satete, "idle");
                        G_V.NG.e_AI.spsh = 5;
                    }
                    break;
                case 9:
                    if (G_V.NG.e_AI.derection == 3)
                        G_V.NG.e_AI.spsh = 8;
                    else if (G_V.NG.e_AI.derection == 4)
                        G_V.NG.e_AI.spsh = 1;
                    if (aoug < 15)
                    {
                        aoug++;
                        G_V.NG.e_AI.derection = G_V.NG.p.derec;
                        if (G_V.NG.e_AI.derection == 3)
                            G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x = G_V.NG.p.image[G_V.NG.p.where].pos1.x - 40;
                        else if (G_V.NG.e_AI.derection == 4)
                            G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x = G_V.NG.p.image[G_V.NG.p.where].pos1.x - 200;
                        G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].y = G_V.NG.p.image[G_V.NG.p.where].pos1.y - 80;
                        animateEnnemi(&G_V.NG.e_AI);
                        afficherEnnemi(G_V.NG.e_AI, G_V.window);
                    }
                    else if (aoug >= 15)
                    {
                        G_V.NG.e_AI.ing = 0;
                        G_V.NG.e_AI.evaluation = 0;
                        G_V.in_e_ai = 1;
                        G_V.NG.plystate = 1;
                        G_V.NG.p.image[0].pos1.x = 50;
                        G_V.NG.p.image[0].pos1.y = 600;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.x = 0;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.y = G_V.NG.b.b_k[G_V.NG.b.i].img->h - G_V.H;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.w = G_V.W;
                        G_V.NG.b.b_k[G_V.NG.b.i].pos2.h = G_V.H;
                        G_V.NG.p.acc = 0;
                        G_V.NG.e_txt.which_gate = 2;
                    }
                    break;
                }
                // tache blanche omar
                if (G_V.NG.e_txt.which_gate == 1 && G_V.in_e_ai && G_V.NG.plystate != 4 && G_V.NG.plystate != 6 && G_V.NG.plystate != 2 && G_V.NG.plystate != 3)
                {
                    G_V.NG.e_AI.derection = G_V.NG.p.derec;
                    G_V.NG.e_AI.P_w = G_V.NG.p.image[G_V.NG.p.where].pos2.w;
                    G_V.NG.e_AI.P_h = G_V.NG.p.image[G_V.NG.p.where].pos2.h;
                    updateEnnemi(&G_V.NG.e_AI, G_V.NG.p.image[G_V.NG.p.where].pos1, G_V.window);
                    if (strcmp(G_V.NG.e_AI.satete, "run") == 0)
                    {
                        if (in)
                            G_V.NG.e_AI.spsh = 7;
                        else if (!in)
                            G_V.NG.e_AI.spsh = 15;
                    }
                    G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x = (33 * G_V.W) / 100 - G_V.NG.b.b_k[G_V.NG.b.i].pos2.x;
                    G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].y = (31 * G_V.W) / 100 - G_V.NG.b.b_k[G_V.NG.b.i].pos2.y;
                    if (strcmp(G_V.NG.e_AI.satete, "attack") == 0 && G_V.NG.e_AI.ing == 0)
                    {
                        G_V.NG.plystate = 4;
                        G_V.NG.e_AI.ing = 1;
                        G_V.in_e_ai = 0;
                        aoug = 0;
                    }
                    else if (!G_V.NG.e_AI.ing)
                    {
                        animateEnnemi(&G_V.NG.e_AI);
                        if (strcmp(G_V.NG.e_AI.satete, "run") == 0)
                        {

                            if (in)
                            {
                                aoug += 5;
                                if (aoug >= 100)
                                    in = 0;
                            }
                            else if (!in)
                            {
                                aoug -= 5;
                                if (aoug <= -50)
                                    in = 1;
                            }
                        }
                        else
                            aoug = 0;
                        G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x = G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x + aoug - 70;
                        afficherEnnemi(G_V.NG.e_AI, G_V.window);
                        G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x = G_V.NG.e_AI.pos1[G_V.NG.e_AI.spsh].x - aoug + 70;
                    }
                }
                G_V.end = SDL_GetTicks();
                timer_jeu(G_V.window, G_V.txt1.font);
            }
            break;
        case 12:
            SDL_BlitSurface(G_V.sa_or_res[0].img, NULL, G_V.window, &G_V.sa_or_res[0].pos1);
            SDL_BlitSurface(G_V.sa_or_res[1].img, NULL, G_V.window, &G_V.sa_or_res[1].pos1);
            SDL_BlitSurface(G_V.sa_or_res[3].img, NULL, G_V.window, &G_V.sa_or_res[3].pos1);
            SDL_BlitSurface(G_V.sa_or_res[5].img, NULL, G_V.window, &G_V.sa_or_res[5].pos1);
            switch (G_V.event.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                G_V.x1 = G_V.event.button.x;
                G_V.y1 = G_V.event.button.y;
                if (is_in_rect(G_V.x1, G_V.y1, G_V.sa_or_res[3].pos1) && G_V.state == 12)
                {
                    G_V.M.if2.casee = G_V.M.back_up - 1;
                    sauve(&G_V.M.if2, "save_pro.bin");
                    G_V.out = 1;
                    Mix_PlayChannel(-1, effect, 0);
                }
                else if (is_in_rect(G_V.x1, G_V.y1, G_V.sa_or_res[1].pos1) && G_V.state == 12)
                {
                    G_V.state = G_V.M.back_up;
                    Mix_PlayChannel(-1, effect, 0);
                }
                else if (is_in_rect(G_V.x1, G_V.y1, G_V.sa_or_res[5].pos1) && G_V.state == 12)
                {
                    G_V.state = 2;
                    Mix_PlayChannel(-1, effect, 0);
                }
                break;
            case SDL_MOUSEMOTION:
                G_V.x1 = G_V.event.button.x;
                G_V.y1 = G_V.event.button.y;
                if (is_in_rect(G_V.x1, G_V.y1, G_V.sa_or_res[3].pos1) && G_V.state == 12)
                    SDL_BlitSurface(G_V.sa_or_res[4].img, NULL, G_V.window, &G_V.sa_or_res[4].pos1);
                else if (is_in_rect(G_V.x1, G_V.y1, G_V.sa_or_res[1].pos1) && G_V.state == 12)
                    SDL_BlitSurface(G_V.sa_or_res[2].img, NULL, G_V.window, &G_V.sa_or_res[2].pos1);
                else if (is_in_rect(G_V.x1, G_V.y1, G_V.sa_or_res[5].pos1) && G_V.state == 12)
                    SDL_BlitSurface(G_V.sa_or_res[6].img, NULL, G_V.window, &G_V.sa_or_res[5].pos1);
                break;
            }
            break;
        }

        SDL_Flip(G_V.window);
    }
    freesurface(&G_V);
}
