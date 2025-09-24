#ifndef BRICKS_H
#define BRICKS_H
#include "Ball.h"
#include"Score.h"

// iMain funcs
void drawBrick();
void checkBrick();
void addBrick();


int checker;
int brickNo = 0;

//Brick
struct Brick{
	int x, y, width, height, element;
	bool visible;
};
Brick brick[100];

//Explosion
struct Expl{
	int x, y, radius;
};



void addBrick(int x, int y, int width, int height, int element, bool visible){
	if (brickNo < 100){
		brick[brickNo].x = x;
		brick[brickNo].y = y;
		brick[brickNo].width = width;
		brick[brickNo].height = height;
		brick[brickNo].element = element;
		brick[brickNo].visible = visible;
		brickNo++;
	}
}


void drawBricks() {
	for (int i = 0; i < brickNo; i++) {
		if (brick[i].visible == true) {
			if (brick[i].element == 1){
				iSetColor(210, 81, 32);
			}
			else if (brick[i].element == 2){
				iSetColor(0, 144, 238);
			}
			else if (brick[i].element == 3){
				iSetColor(156, 42, 185);
			}
			else if (brick[i].element == 4){
				iSetColor(102, 0, 255);
			}
			iFilledRectangle(brick[i].x, brick[i].y, brick[i].width, brick[i].height);
		}
	}
}



void Overloaded(){
	Expl expl = { ball.x, ball.y, 50 };
	for (int i = 0; i < brickNo; i++) {
		if (brick[i].visible == true) {
			if (expl.x + expl.radius >= brick[i].x &&
				expl.x - expl.radius <= brick[i].x + brick[i].width &&
				expl.y + expl.radius >= brick[i].y &&
				expl.y - expl.radius <= brick[i].y + brick[i].height){
				brick[i].visible = false;
				
				if (brick[i].element == 4){
					score = score + 3;
					combo = combo + 0.3;
				}
				else if (brick[i].element == 2){
					score = score + 2;
					combo = combo + 0.2;
				}
				else{
					score++;
					combo = combo + 0.1;
				}
			}
		}
	}


}
void ElecCharge(){
	Expl charge = { ball.x, ball.y, 35 };
	for (int i = 0; i < brickNo; i++) {
		if (brick[i].visible == true) {
			if (charge.x + charge.radius >= brick[i].x &&
				charge.x - charge.radius <= brick[i].x + brick[i].width &&
				charge.y + charge.radius >= brick[i].y &&
				charge.y - charge.radius <= brick[i].y + brick[i].height){
				if (brick[i].element == 2 || brick[i].element == 3){
					brick[i].element = 4;
					combo = combo + 0.1;
					ElecCharge();
				}
			}
		}
	}
}

			

void checkBrick() {
	srand(time(NULL));
	int rando = (rand() % 2) + 2;
	for (int i = 0; i < brickNo; i++) {
		if (brick[i].visible == true) {
			if (ball.x + ball.radius >= brick[i].x &&
				ball.x - ball.radius <= brick[i].x + brick[i].width &&
				ball.y + ball.radius >= brick[i].y &&
				ball.y - ball.radius <= brick[i].y + brick[i].height) {
				if (checker == i){
					continue;
				}
				else{
					checker = i;
					switch (ball.element){
					case 0: //neutral
						ball.element = brick[i].element;
						if (ball.element == 4){
							ball.element = rando;
							combo = combo + 0.1;
						}
						break;
					case 1: //fire
						if (brick[i].element == 2){
							brick[i].visible = false;
							score = score + 2;
							combo = combo + 0.2;
							ball.element = 0;
						}
						else if (brick[i].element == 3){
							Overloaded();
							ball.element = 0;
						}
						else if (brick[i].element == 4){
							Overloaded();
							ball.element = 0;
						}
						break;
					case 2: //water
						if (brick[i].element == 1){
							brick[i].visible = false;
							score = score + 4;
							combo = combo + 0.4;
							ball.element = 0;
						}
						else if (brick[i].element == 3){
							ElecCharge();
							ball.element = 0;
						}
						else if (brick[i].element == 4){
							brick[i].visible = false;
							score++;
							combo = combo + 0.1;
							ball.element = 3;
						}
						break;
					case 3: //electric
						if (brick[i].element == 1){
							Overloaded();
							ball.element = 0;
						}
						else if (brick[i].element == 2){
							ElecCharge();
							ball.element = 0;
						}
						else if (brick[i].element == 4){
							brick[i].visible = false;
							score++;
							combo = combo + 0.1;
							ball.element = 2;
						}
						break;
					}
					ball.dy = -ball.dy; // bounce

					break;
				}
			}
		}
	}
}
void resetBricks(){
	for (int i = 0; i < brickNo; i++){
		brick[i].visible = true;
	}
}
#endif