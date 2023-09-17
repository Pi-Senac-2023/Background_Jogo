#pragma once
#include <stdlib.h>
#ifndef PROGRAMTYPES
#define PROGRAMTYPES
    typedef struct DisplaySettings {
        int Width;
        int Height;
    } DisplaySettings;
    
    void freeAllTypes(DisplaySettings* Display);
#endif
