#include <allegro5/allegro5.h>
#include "movement.h"
void freeAllCharacter(Character* persona){
	free(persona);
}

void movement(Character* persona, ALLEGRO_EVENT* event) {
	
	int x = persona->positionX;
	int y = persona->positionY;


	switch (event.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			y++;
			break;
		case ALLEGRO_KEY_DOWN:
			y--;
			break;
		case ALLEGRO_KEY_LEFT:
			x--;
			break;
		case ALLEGRO_KEY_RIGHT:
			x++;
			break;

	}

	printf("PersonaX: %d, PersonaY: %d", x, y);
}