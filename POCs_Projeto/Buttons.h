#pragma once
#include <stdlib.h>
#include <stdbool.h>
#ifndef BUTTONS
#define BUTTONS

typedef struct buttonSettings {
	int width;
	int height;
	int buttonX;
	int buttonsY;
	bool status;
} buttonSettings;

void freeAllSettings(buttonSettings* settings);
#endif
