#include "gerais.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


void Trocar_Cena(int d){
    printf("%d\n",d);
}

bool ColisaoRetangulo(RETANGULO r1, RETANGULO r2){
    if(r1.x >= r2.x && r1.x <= r2.x + r2.largura && r1.y >= r2.y && r1.y <= r2.y+r2.altura) return 1;
    else if(r1.x+r1.largura >= r2.x && r1.x+r1.largura <= r2.x + r2.largura && r1.y >= r2.y && r1.y <= r2.y+r2.altura) return 1;
    else if(r1.x >= r2.x && r1.x <= r2.x + r2.largura && r1.y+r1.altura >= r2.y && r1.y+r1.altura <= r2.y+r2.altura) return 1;
    else if(r1.x+r1.largura >= r2.x && r1.x+r1.largura <= r2.x + r2.largura && r1.y+r1.altura >= r2.y && r1.y+r1.altura <= r2.y+r2.altura) return 1;
    else if(r2.x >= r1.x && r2.x <= r1.x + r1.largura && r2.y >= r1.y && r2.y <= r1.y+r1.altura) return 1;
    else if(r2.x+r2.largura >= r1.x && r2.x+r2.largura <= r1.x + r1.largura && r2.y >= r1.y && r2.y <= r1.y+r1.altura) return 1;
    else if(r2.x >= r1.x && r2.x <= r1.x + r1.largura && r2.y+r2.altura >= r1.y && r2.y+r2.altura <= r1.y+r1.altura) return 1;
    else if(r2.x+r2.largura >= r1.x && r2.x+r2.largura <= r1.x + r1.largura && r2.y+r2.altura >= r1.y && r2.y+r2.altura <= r1.y+r1.altura) return 1;
    else return 0;
}

bool ColisaoMouseRetangulo(ALLEGRO_MOUSE_STATE mouse,RETANGULO retangulo,CAMERA camera){
    if(mouse.x - camera.x >= retangulo.x && mouse.x - camera.x <= retangulo.x + retangulo.largura && mouse.y - camera.y >= retangulo.y && mouse.y - camera.y <= retangulo.y+retangulo.altura) return 1;
    else return 0;
}

void DesenharRetangulo(RETANGULO retangulo, int cor[3], CAMERA camera){
    al_draw_filled_rectangle(retangulo.x + camera.x,
                             retangulo.y + camera.y,
                             retangulo.x+retangulo.largura + camera.x,
                             retangulo.y+retangulo.altura  + camera.y,
                             al_map_rgb(cor[0],cor[1],cor[2]));
}

void DesenharRetanguloPica(RETANGULO retangulo,int borda, int cor[3], CAMERA camera){
    al_draw_filled_rounded_rectangle(retangulo.x + camera.x,
                                     retangulo.y + camera.y,
                                     retangulo.x+retangulo.largura + camera.x,
                                     retangulo.y+retangulo.altura  + camera.y,
                                     borda,borda,
                                     al_map_rgb(cor[0],cor[1],cor[2]));
}

void DesenharTiles(int tela[2], int tamanho, CAMERA camera){
    for(int i = 0; i*tamanho < tela[0];i++){
        for(int j = 0; j*tamanho < tela[1]; j++){
            RETANGULO bloco = {i*tamanho,j*tamanho,tamanho,tamanho};
            if((j+i)%2)DesenharRetangulo(bloco,(int[3]){255,255,255}, camera);
            else DesenharRetangulo(bloco, (int[3]){230,230,230}, camera);



        }
    }


}


