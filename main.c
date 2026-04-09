#include "gerais.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>









int main(){
    al_init();
    al_install_mouse();
    al_install_keyboard();

    al_init_primitives_addon();

    int tam_tela[2] = {800,600};

    ALLEGRO_DISPLAY *display = al_create_display(tam_tela[0], tam_tela[1]);
    ALLEGRO_TIMER *timer = al_create_timer(1.0/60);
    ALLEGRO_EVENT_QUEUE *fila = al_create_event_queue();
    ALLEGRO_KEYBOARD_STATE estado_teclado;
    ALLEGRO_MOUSE_STATE estado_mouse;
    ALLEGRO_EVENT evento_atual;


    al_register_event_source(fila, al_get_mouse_event_source());
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_register_event_source(fila, al_get_timer_event_source(timer));
    al_register_event_source(fila, al_get_display_event_source(display));


    bool jogo_lop = true;

    CAMERA camera = {0,0};

    RETANGULO bloco1 = {20,20,20,20};
    RETANGULO bloco2 = {50,50,20,20};
    RETANGULO bloco3 = {80,80,40,40};




    al_start_timer(timer);

    al_hide_mouse_cursor(display);

    while(jogo_lop){
        al_wait_for_event(fila, &evento_atual);
        if(evento_atual.type == ALLEGRO_EVENT_DISPLAY_CLOSE) jogo_lop = 0;

        if(evento_atual.type == ALLEGRO_EVENT_TIMER){
            al_get_keyboard_state(&estado_teclado);
            al_get_mouse_state(&estado_mouse);
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_ESCAPE)) jogo_lop =0;
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_RIGHT)) bloco1.x += 1;
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_LEFT)) bloco1.x -= 1;
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_UP)) bloco1.y -= 1;
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_DOWN)) bloco1.y += 1;




            camera.x = -bloco1.x + tam_tela[0]/2;
            camera.y = -bloco1.y + tam_tela[1]/2;

            al_clear_to_color(al_map_rgb(100,100,255));

            DesenharTiles(tam_tela,40,camera);

            {
                int cor1[3] = {20,20,20}, cor2[3] = {50,50,50}, cor3[3] = {200,50,50};

                DesenharRetangulo(bloco1,cor1,camera);
                DesenharRetangulo(bloco2,cor2,camera);
                DesenharRetanguloPica(bloco3,10,cor3,camera);

            }



            if(ColisaoRetangulo(bloco1,bloco2)) printf("bananinha");

            RETANGULO retangulo_mouse = {estado_mouse.x , estado_mouse.y , 20, 20};

            DesenharRetangulo(retangulo_mouse, al_mouse_button_down(&estado_mouse, 1) ? (int[3]){0,0,0} : (int[3]){255,255,255} , (CAMERA){0,0});

            if(al_mouse_button_down(&estado_mouse,1)) if (ColisaoMouseRetangulo(estado_mouse,bloco3,camera)) printf("Porra!");




            al_flip_display();

        }

    }

}
