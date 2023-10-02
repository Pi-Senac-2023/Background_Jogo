#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "ProgramTypes.h"
#ifndef BUTTONS
#define BUTTONS

typedef struct ButtonSettings {
	float width;
	float height;
	int buttonX;
	int buttonY;
} ButtonSettings;

int checkButtonOnSpace(PositionMouse* mouse ,ButtonSettings* button);

void freeAllSettings(ButtonSettings* settings);
#endif
