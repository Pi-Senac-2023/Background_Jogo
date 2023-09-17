#include "AllegroSettings.h"


void initialize() {
    if (!al_init()) {
        printf("[ERROR] Não foi possível iniciar o allegro!");
        return 1;
    }
    if (!al_install_keyboard())
    {
        printf("[ERROR] Não foi instalar o teclado!");
        return 1;
    }
    if (!al_init_primitives_addon())
    {
        printf("Falha ao inicializar add-on primitiva.");
        return false;
    }
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
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
}