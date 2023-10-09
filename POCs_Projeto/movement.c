#include <allegro5/allegro5.h>
#include "movement.h"
void freeAllCharacter(Character* persona){
	free(persona);
}

void movement(Character* persona, ALLEGRO_EVENT* event ) {
		
	switch (event->keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					persona->positionY -= 10;
					break;
				case ALLEGRO_KEY_DOWN:
					persona->positionY += 10;
					break;
				case ALLEGRO_KEY_LEFT:
					persona->positionX -= 10;
					break;
				case ALLEGRO_KEY_RIGHT:
					persona->positionX += 10;
					break;
		
	}
	
	printf("PersonaX: %d, PersonaY: %d", persona->positionX, persona->positionY);
}