#include "ProgramTypes.h"
#include"ProgramSettings.h"

int** setScreenConfig(DisplaySettings* Display) {
    int** screen = malloc(Display->Height * sizeof(int*));
    if (screen) {
        for (int i = 0; i < Display->Height; i++) {
            screen[i] = malloc(Display->Width * sizeof(int*));
        }
    }
    return screen;
}