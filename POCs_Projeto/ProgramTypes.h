#pragma once
#include <stdlib.h>
#ifndef PROGRAMTYPES
#define PROGRAMTYPES
typedef struct DisplaySettings {
    int Width;
    int Height;
} DisplaySettings;

typedef struct PositionMouse {
    int x;
    int y;
} PositionMouse;

void freeAllTypes(DisplaySettings* Display, PositionMouse* Mouse);
#endif
