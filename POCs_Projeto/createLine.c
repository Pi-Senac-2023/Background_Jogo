#include "createLine.h"
#include "ProgramTypes.h"
#include <stdio.h>
#include "AllegroSettings.h"

void createLine(DisplaySettings* Display) {
    int* pos = malloc(sizeof(int) * 4);
    int index = 0;
    for (int i = 0; i < Display->Height; i++) {
        for (int j = 0; j < Display->Width; j++) {
            if (Display->screen[i][j] == 3 && pos) {
                pos[index++] = j;
                pos[index++] = i;

                if (Display->screen[i][j] == 3)
                    Display->screen[i][j] = 4;

                al_draw_circle(j, i, 4, al_map_rgb(0, 255, 0), 4);
            }
        }
    }

    createLineOnMatrix(Display->screen, pos[0], pos[1], pos[2], pos[3]);
    al_draw_line(pos[0], pos[1], pos[2], pos[3], al_map_rgb(0, 0, 255), 4);
    index = 0;

    free(pos);
}

void createLineOnMatrix(int** matriz, int x1, int y1, int x2, int y2) {
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
