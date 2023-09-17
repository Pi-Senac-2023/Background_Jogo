#include "ProgramTypes.h"

void freeAllTypes(DisplaySettings* Display, PositionMouse* Mouse) {
	free(Display);
	free(Mouse);
}