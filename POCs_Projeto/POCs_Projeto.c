#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

int displayWidth= 960;
int displayHeight= 720;
float PositionY = 0.0;
float PositionX = 0.0;
int sectionWidth = 1;

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

void handleMoviment(ALLEGRO_EVENT event) {
    float mapGameHeight = 0.0;
    float mapGameWidth = 0.0;
    float actionsHeight = (displayHeight / 4.0) * 3.0;
    float actionsWidth = (displayWidth / 3.0);
    switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            PositionY = mapGameHeight;
            break;
        case ALLEGRO_KEY_DOWN:
            PositionY = actionsHeight;
            break;
        case ALLEGRO_KEY_RIGHT:
            printf("Width: %f Section: %d \n", actionsWidth, sectionWidth);
            if (PositionY == actionsHeight && sectionWidth <= 3)
                PositionX = actionsWidth * sectionWidth++;
            break;
        case ALLEGRO_KEY_LEFT:
            printf("Width: %f Section: %d \n", actionsWidth, sectionWidth);
            if (PositionY == actionsHeight && sectionWidth > 0) {
                PositionX = actionsWidth * --sectionWidth;
            }
                
            break;
    }
    printf("X: %f Y: %f \n", PositionX, PositionY);
}

int main()
{
    initialize();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(displayWidth, displayHeight);
    ALLEGRO_FONT* font = al_create_builtin_font();
    
    if (!timer || !queue || !font || !disp) {
        printf("[ERROR] Não foi possível iniciar as variáveis de inicialização do jogo!");
        return 1;
    }

    registersEvent(disp, timer, queue);
    
    bool redraw = true;
    ALLEGRO_EVENT event;
    al_start_timer(timer);
    while (1)
    {
        bool done = false;

        al_wait_for_event(queue, &event);

        switch (event.type) {
        case ALLEGRO_EVENT_TIMER:
            redraw = true;
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            handleMoviment(event);
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done) break;
        
        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(255, 255, 255));
            al_draw_filled_rectangle(PositionX,PositionY,PositionX+30,PositionY+30,al_map_rgb(255,0,0));
            al_flip_display();
            redraw = false;
        }
    }
    finish(timer, queue,  disp, font);

    
    return 0;
}