#ifndef LEVEL1_H
#define LEVEL1_H
#include "Bricks.h"

int width = 50;
int height = 20;
int spaceX ;
int spaceY ;
int element;

void Level1(){
	int spaceX = 0;
	int spaceY = 0;
	for (int i = 0; i <12; i++){
		for (int j = 0; j <= i; j++){
			element = (rand() % 3) +1;
			addBrick(400 + spaceX, 200+spaceY, width, height, element, true);
			spaceX = spaceX + width + 1;
		}
		spaceY = spaceY + height + 1;
		spaceX = 0;
	}
}
void Level2(){
	int spaceX = 0;
	int spaceY = 0;
	for (int i = 12; i > 0; i--){
		for (int j = 0; j < i; j++){
			element = (rand() % 3) + 1;
			addBrick(400 + spaceX, 200 + spaceY, width, height, element, true);
			spaceX += width + 1;
		}
		spaceY += height + 1;
		spaceX = 0;
	}
}
void Level3(){
	spaceX = 0;
	spaceY = 0;
	for (int i = 1; i <= 12; i++) {   // Row count (1 brick → 12 bricks)
		// Center the row horizontally by shifting X
		spaceX = (12-i) * (width / 2);

		for (int j = 0; j < i; j++) {
			element = (rand() % 3) + 1;
			addBrick(400 + spaceX, 400 + spaceY, width, height, element, true);
			spaceX += width + 1;   // move right
		}

		spaceY += height + 1;      // move up for next row
	}
}
void resetLevel(){   //WIP faulty rn
	brickNo = 0;
}

#endif