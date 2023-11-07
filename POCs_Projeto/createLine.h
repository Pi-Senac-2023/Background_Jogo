#pragma once
#include <allegro5/events.h>
#include <allegro5/timer.h>
#include <allegro5/display.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "ProgramTypes.h"

#ifndef CREATELINE
#define CREATELINE
	void createLineOnMatrix(int** matriz, int x1, int y1, int x2, int y2);
	void createLine(DisplaySettings* Display);
#endif
