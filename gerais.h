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


void Trocar_Cena(int d);

bool ColisaoRetangulo(RETANGULO *retangulo1, RETANGULO *retangulo2);
bool DesenharRetangulo(RETANGULO *retangulo, int cor[3]);
bool DesenharRetanguloPica(RETANGULO *retangulo,int borda, int cor[3]);
bool ColisaoMouseRetangulo(ALLEGRO_MOUSE_STATE *mouse, RETANGULO *retangulo);






#endif
