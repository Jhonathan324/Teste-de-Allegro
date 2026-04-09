#ifndef GERAIS_H_INCLUDED
#define GERAIS_H_INCLUDED
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

typedef enum{
    MENU_INICIL,
    JOGO,
    PAUSE,
    OPCOES,
    CREDITOS
} Estado_jogo;

typedef struct RETANGULO{
    int x, y;
    int largura, altura;
} RETANGULO;

typedef struct CAMERA{
    int x,y;

} CAMERA;


void Trocar_Cena(int d);

bool ColisaoRetangulo(RETANGULO retangulo1, RETANGULO retangulo2);
bool ColisaoMouseRetangulo(ALLEGRO_MOUSE_STATE mouse, RETANGULO retangulo,CAMERA camera);

void DesenharRetangulo(RETANGULO retangulo, int cor[3],CAMERA camera);
void DesenharRetanguloPica(RETANGULO retangulo,int borda, int cor[3], CAMERA camera);
void DesenharTiles(int tela[2], int tamanho, CAMERA camera);






#endif
