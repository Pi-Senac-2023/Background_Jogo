#include "Buttons.h"
#include "ProgramTypes.h"
#include <allegro5/allegro5.h>

void freeAllSettings(ButtonSettings* settings) {
	free(settings);
}

void createButton(ButtonSettings *settings ,int widthWant,int heightWant) {

}

int checkButtonOnSpace(PositionMouse* mouse, ButtonSettings* button) {
	int mouseX = mouse->x;
	int mouseY = mouse->y;

	//printf("MouseX:%d, MouseY:%d", mouseX, mouseY);

	int buttonX = button->buttonX;
	int buttonY = button->buttonY;


	float width = button->width;
	float height = button->height;

	//printf("buttonX: %d, buttonY: %d\n", width + buttonX, height+buttonY);

	
	if (buttonX <= mouseX && buttonY <= mouseY) {
		if(mouseX <= buttonX + width && mouseY <= buttonY + height) {
			printf("ok!! MouseX:%d, MouseY:%d\n", mouseX, mouseY);
			return 1;
		}
	}
	
	printf("fora!! MouseX:%d, MouseY:%d\n", mouseX, mouseY);
	return 0;
	
}