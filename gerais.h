#ifndef GERAIS_H_INCLUDED
#define GERAIS_H_INCLUDED
#include <stdbool.h>

typedef enum{
    MENU_INICIL,
    JOGO,
    PAUSE,
    OPCOES,
    CREDITOS
} Estado_jogo;

void Trocar_Cena(int d);

bool colisao_retangulo(int x1, int y1, int largura1, int altura1,int x2,int y2, int largura2, int altura2);


typedef struct RETANGULO{
    int x, y;
    int largura, altura;
    int cor[3];
} RETANGULO;



#endif
