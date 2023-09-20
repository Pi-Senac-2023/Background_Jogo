#include "AllegroSettings.h"


void must_init(bool test, char* desc) {
    if (!test) {
        printf("Falha na inicializa??o do %s!\n ", desc);
    }
}

void initialize() {
    must_init(al_init(), "Allegro");
    must_init(al_install_keyboard(), "Teclado");
    must_init(al_install_mouse(), "Mouse");
    must_init(al_init_primitives_addon(), "Primitives Addon");
}

void finish(ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_DISPLAY* disp, ALLEGRO_FONT* font) {
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_shutdown_primitives_addon();
    al_uninstall_system();
}

void registersEvent(ALLEGRO_DISPLAY* disp, ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue) {
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
}