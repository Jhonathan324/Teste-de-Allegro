#include "gerais.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


void Trocar_Cena(int d){
    printf("%d\n",d);
}

bool colisao_retangulo(int x1, int y1, int largura1, int altura1,int x2,int y2, int largura2, int altura2){
    if(x1 >= x2 && x1 <=x2 + largura2 && y1 >= y2 && y1<=y2+altura2) return 1; //verificado para um ponto do retangulo 1, falta 3.


}
