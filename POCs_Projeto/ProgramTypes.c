#include "ProgramTypes.h"

void freeAllTypes(DisplaySettings* Display, PositionMouse* Mouse) {
	free(Display);
	free(Mouse);
}

void freeScreen(DisplaySettings* Display) {
	for (int i = 0; i < Display->Height; i++) {
		free(Display->screen[i]);
	}
	free(Display->screen);
}