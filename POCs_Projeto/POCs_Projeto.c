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

void tracejarLinha(int** matriz, int x1, int y1, int x2, int y2) {
    int dx, dy, p, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    p = 2 * dy - dx;

    while (x < x2) {
        if (p >= 0) {
            matriz[y][x] = 2;
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        else {
            matriz[y][x] = 2;
            p = p + 2 * dy;
        }
        printf("x:%d y:%d\n", x, y);
        x++;
    }
}

void createLine(DisplaySettings* Display){ 
    int* pos = malloc(sizeof(int)*4);
    int index = 0;
    for (int i = 0; i < Display->Height; i++) {
        for (int j = 0; j < Display->Width; j++) {
            if (Display->screen[i][j] == 3 && pos) {
                pos[index++] = j;
                pos[index++] = i;

                if (Display->screen[i][j] == 3)
                    Display->screen[i][j] = 4;
                
                al_draw_circle(j,i,4, al_map_rgb(0, 255, 0),4);
            }
        }
    }
    
    tracejarLinha(Display->screen, pos[0], pos[1], pos[2], pos[3]);
    al_draw_line(pos[0], pos[1], pos[2], pos[3], al_map_rgb(0, 0, 255), 4);
    index = 0;

    free(pos);
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
        int links = 0;

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
                        Display->screen[--y][--x] = 3;
                        links++;
                        if (links == 2) {
                            createLine(Display);
                            links = 0;
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