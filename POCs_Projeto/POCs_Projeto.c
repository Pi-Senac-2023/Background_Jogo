#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "AllegroSettings.h"
#include "ProgramTypes.h"


float PositionY = 0.0;
float PositionX = 0.0;
int sectionWidth = 1;

int main()
{
    DisplaySettings* Display;
    Display = malloc(sizeof(*Display));
    if (Display != NULL) {
        Display->Height = 720;
        Display->Width = 920;

        initialize();

        ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
        ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
        ALLEGRO_DISPLAY* disp = al_create_display(Display->Width, Display->Height);
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
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
            }

            if (done) break;

            if (redraw && al_is_event_queue_empty(queue))
            {
                al_clear_to_color(al_map_rgb(255, 255, 255));
                al_draw_filled_rectangle(PositionX, PositionY, PositionX + 30, PositionY + 30, al_map_rgb(255, 0, 0));
                al_flip_display();
                redraw = false;
            }
        }

        finish(timer, queue, disp, font);
        freeAllTypes(Display);
    }
    return 0;
}