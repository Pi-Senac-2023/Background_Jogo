#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "AllegroSettings.h"
#include "ProgramTypes.h"
#include <stdlib.h>
#include <string.h>
#include "createLine.h"
#include "ProgramSettings.h"


// area clickable = 10


void createClickableArea(DisplaySettings* Display, int xPoint, int yPoint, int radius) {
    for (int x = 0; x < Display->Height; x++) {
        for (int y = 0; y < Display->Width; y++) {
            int distance = (x - xPoint) * (x - xPoint) + (y - yPoint) * (y - yPoint);
            if (distance <= radius * radius) {
                printf("teste");
                Display->screen[x][y] = 10;
            }
        }
    }

}

bool isClickableArea(int** screen, int xClicked, int yClicked) {
    printf("x:%d y:%d", xClicked, yClicked);
    printf("result: %d", screen[yClicked][xClicked]);
    bool response = false;
    if (screen[yClicked][xClicked] == 10)
        response = true;
    return response;
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


        if (Display->screen) {
            for (int x = 0; x < Display->Height; x++) {
                for (int y = 0; y < Display->Width; y++) {
                    Display->screen[x][y] = 1;
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
        int links = 0;

        createClickableArea(Display,50,50,50);
        createClickableArea(Display, 700, 700, 50);

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
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                    if (event.mouse.button == 1 && Display->screen) {
                        int x = Mouse->x;
                        int y = Mouse->y;
                        if (isClickableArea(Display->screen,x,y)) {
                            Display->screen[--y][--x] = 3;
                            links++;
                            if (links == 2) {
                                createLine(Display);
                                links = 0;
                            }
                        }
                    }
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