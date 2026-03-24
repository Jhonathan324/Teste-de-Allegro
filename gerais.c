#include "gerais.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


void Trocar_Cena(int d){
    printf("%d\n",d);
}

bool ColisaoRetangulo(RETANGULO *r1, RETANGULO *r2){
    if(r1->x >= r2->x && r1->x <= r2->x + r2->largura && r1->y >= r2->y && r1->y <= r2->y+r2->altura) return 1;
    else if(r1->x+r1->largura >= r2->x && r1->x+r1->largura <= r2->x + r2->largura && r1->y >= r2->y && r1->y <= r2->y+r2->altura) return 1;
    else if(r1->x >= r2->x && r1->x <= r2->x + r2->largura && r1->y+r1->altura >= r2->y && r1->y+r1->altura <= r2->y+r2->altura) return 1;
    else if(r1->x+r1->largura >= r2->x && r1->x+r1->largura <= r2->x + r2->largura && r1->y+r1->altura >= r2->y && r1->y+r1->altura <= r2->y+r2->altura) return 1;
    else if(r2->x >= r1->x && r2->x <= r1->x + r1->largura && r2->y >= r1->y && r2->y <= r1->y+r1->altura) return 1;
    else if(r2->x+r2->largura >= r1->x && r2->x+r2->largura <= r1->x + r1->largura && r2->y >= r1->y && r2->y <= r1->y+r1->altura) return 1;
    else if(r2->x >= r1->x && r2->x <= r1->x + r1->largura && r2->y+r2->altura >= r1->y && r2->y+r2->altura <= r1->y+r1->altura) return 1;
    else if(r2->x+r2->largura >= r1->x && r2->x+r2->largura <= r1->x + r1->largura && r2->y+r2->altura >= r1->y && r2->y+r2->altura <= r1->y+r1->altura) return 1;
    else return 0;
}

bool DesenharRetangulo(RETANGULO *retangulo, int cor[3]){
    al_draw_filled_rectangle(retangulo->x,
                             retangulo->y,
                             retangulo->x+retangulo->largura,
                             retangulo->y+retangulo->altura,
                             al_map_rgb(cor[0],cor[1],cor[2]));
    return 0;
}

bool DesenharRetanguloPica(RETANGULO *retangulo,int borda, int cor[3]){
    al_draw_filled_rounded_rectangle(retangulo->x,
                             retangulo->y,
                             retangulo->x+retangulo->largura,
                             retangulo->y+retangulo->altura,
                             borda,borda,
                             al_map_rgb(cor[0],cor[1],cor[2]));

    return 0;
}

bool ColisaoMouseRetangulo(ALLEGRO_MOUSE_STATE *mouse,RETANGULO *retangulo){
    if(mouse->x >= retangulo->x && mouse->x <= retangulo->x + retangulo->largura && mouse->y >= retangulo->y && mouse->y <= retangulo->y+retangulo->altura) return 1;
    else return 0;
}
