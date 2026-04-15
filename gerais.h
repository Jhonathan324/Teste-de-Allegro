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

typedef struct RETANGULO_PICA{
    int x, y;
    int largura, altura;
    int cor[3];
    int borda;
} RETANGULO_PICA;

typedef struct CAMERA{
    int x,y;
} CAMERA;

typedef struct BOTAO{
    RETANGULO_PICA retangulo;
    char texto[];
} BOTAO;


void Trocar_Cena(int d);

bool ColisaoRetangulo(RETANGULO retangulo1, RETANGULO retangulo2);
bool ColisaoMouseRetangulo(ALLEGRO_MOUSE_STATE mouse, RETANGULO retangulo,CAMERA camera);

void DesenharRetangulo(RETANGULO retangulo, int cor[3],CAMERA camera);
void DesenharRetanguloPica(RETANGULO_PICA retangulo, CAMERA camera);
void DesenharTiles(int tela[2], int tamanho, CAMERA camera);






#endif
