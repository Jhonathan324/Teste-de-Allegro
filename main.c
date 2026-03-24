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

    ALLEGRO_DISPLAY *display = al_create_display(800, 600);
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

    RETANGULO botao_menu = {20,20,20,20,{30,70,20}};



    al_start_timer(timer);

    while(jogo_lop){
        al_wait_for_event(fila, &evento_atual);
        if(evento_atual.type == ALLEGRO_EVENT_DISPLAY_CLOSE) jogo_lop = 0;

        if(evento_atual.type == ALLEGRO_EVENT_TIMER){
            al_get_keyboard_state(&estado_teclado);
            al_get_mouse_state(&estado_mouse);
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_ESCAPE)) jogo_lop =0;
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_RIGHT)) botao_menu.x += 1;
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_LEFT)) botao_menu.x -= 1;
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_UP)) botao_menu.y -= 1;
            if (al_key_down(&estado_teclado,ALLEGRO_KEY_DOWN)) botao_menu.y += 1;

            al_clear_to_color(al_map_rgb(20,20,100));

            for(int i = 0; i<5; i++){
                al_draw_filled_rectangle(botao_menu.x + i*(botao_menu.largura+20),
                                        botao_menu.y,
                                        botao_menu.x+botao_menu.largura + i*(botao_menu.largura+20),
                                        botao_menu.y+botao_menu.altura,
                                        al_map_rgb(botao_menu.cor[0],
                                                botao_menu.cor[1],
                                                botao_menu.cor[2]));
            }

            al_draw_filled_rectangle(estado_mouse.x - 10,
                                     estado_mouse.y - 10,
                                     estado_mouse.x + 10,
                                     estado_mouse.y + 10,
                                     al_mouse_button_down(&estado_mouse, 1) ? al_map_rgb(0,0,0) :al_map_rgb(255,255,255));





            al_flip_display();

        }

    }

}
