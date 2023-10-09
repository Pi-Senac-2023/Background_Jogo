#pragma once
#include <stdlib.h>
#ifndef MOVE
#define MOVE

typedef struct Character {
	int positionX;
	int positionY;
} Character;

void movement(Character* persona);

void freeAllCharacter(Character* persona);

#endif