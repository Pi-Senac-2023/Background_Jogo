#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "AllegroSettings.h"
#include "ProgramTypes.h"
#include <stdlib.h>
#include <string.h>

int** setScreenConfig(DisplaySettings* Display) {
        int** screen = malloc(Display->Height * sizeof(int*));
        if (screen) {
            for (int i = 0; i < Display->Height; i++) {
                screen[i] = malloc(Display->Width * sizeof(int*));
            }
        }

        return screen;
}


int main()
{
    DisplaySettings* Display = malloc(sizeof(DisplaySettings));
    PositionMouse* Mouse = malloc(sizeof(PositionMouse));
    
    if (Display && Mouse) {
        Display->Height = 720;
        Display->Width = 920;
        Display->screen = setScreenConfig(Display);
        Mouse->x = 0;
        Mouse->y = 0;

        int counter = 0;

        if (Display->screen) {
            for (int i = 0; i < Display->Height; i++) {
                for (int j = 0; j < Display->Width; j++) {
                    Display->screen[i][j] = 1;
                    counter++;
                }
            }
       }

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

        while (true)
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
                case ALLEGRO_EVENT_MOUSE_AXES:
                    Mouse->x = event.mouse.x;
                    Mouse->y = event.mouse.y;
                    break;
            }

            if (done) break;

            if (redraw && al_is_event_queue_empty(queue))
            {
                al_flip_display();
                redraw = false;
            }
        }

        finish(timer, queue, disp, font);
        freeScreen(Display);
        freeAllTypes(Display, Mouse);
    }
    return 0;
}