#pragma once
#include <allegro5/events.h>
#include <allegro5/timer.h>
#include <allegro5/display.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#ifndef ALLEGRO_H_INCLUDED
#define ALLEGRO_H_INCLUDED
	void initialize();
	void finish(ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_DISPLAY* disp, ALLEGRO_FONT* font);
	void registersEvent(ALLEGRO_DISPLAY* disp, ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* queue);
#endif
