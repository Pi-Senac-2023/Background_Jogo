#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "ProgramTypes.h"
#ifndef BUTTONS
#define BUTTONS

typedef struct ButtonSettings {
	int width;
	int height;
	int buttonX;
	int buttonY;
} ButtonSettings;

void checkButtonOnSpace(PositionMouse* mouse ,ButtonSettings* button);

void freeAllSettings(ButtonSettings* settings);
#endif
