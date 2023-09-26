#include "Buttons.h"
#include "ProgramTypes.h"
#include <allegro5/allegro5.h>

void freeAllSettings(ButtonSettings* settings) {
	free(settings);
}

void createButton(ButtonSettings *settings ,int widthWant,int heightWant) {

}

void checkButtonOnSpace(PositionMouse* mouse, ButtonSettings* button) {
	int mouseX = mouse->x;
	int mouseY = mouse->y;

	//printf("MouseX:%d, MouseY:%d", mouseX, mouseY);

	int buttonX = button->buttonX;
	int buttonY = button->buttonY;

	//printf("ButtonX:%d, ButtonY:%d", buttonX, buttonY);

	int width = button->width;
	int height = button->height;

	if (buttonX >= mouseX && mouseX <= buttonX + width) {
		if(buttonY >= mouseY && mouseY <= buttonY + height) { 
			printf("ok!! MouseX:%d, MouseY:%d", mouseX, mouseY);
		}
	}
	else {
		printf("fora!! MouseX:%d, MouseY:%d", mouseX, mouseY);
	}

}