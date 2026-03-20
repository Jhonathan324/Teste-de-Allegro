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
    ALLEGRO_EVENT_QUEUE *lista = al_create_event_queue();


    al_register_event_source(lista, al_get_mouse_event_source());
    al_register_event_source(lista, al_get_keyboard_event_source());
    al_register_event_source(lista, al_get_timer_event_source(timer));
    al_register_event_source(lista, al_get_display_event_source(display));


    bool jogo_lop = true;

    al_start_timer();
    while(jogo_lop){

        printf("banana");
    }

}
