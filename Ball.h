
#ifndef BALL_H
#define BALL_H
#include"Score.h"
// iMain func declarations
void drawBall();
void updateBall();
void resetBall();

// Ball 
struct Ball {
	int x, y;
	int radius;
	int dx;		//spd
	int dy;
	int element; //0,1,2,3,4 neutral, fire, water, electric, charged
	bool moving;
};
int screenWidth = 1280;
int screenHeight = 720;

//  ball
Ball ball = { 640, 160, 20, 5, 4, 0, false };


void drawBall()
{
	if (ball.element == 0){
		iSetColor(200, 200, 200);
	}
	else if (ball.element == 1){
		iSetColor(210, 81, 32);
	}
	else if (ball.element == 2){
		iSetColor(0, 144, 238);
	}
	else if (ball.element == 3){
		iSetColor(156, 42, 185);
	}
	iFilledCircle(ball.x, ball.y, ball.radius);
}

void updateBall()
{
	if (ball.moving==true){
		ball.x += ball.dx;
		ball.y += ball.dy;

		// horizontal walls
		if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= screenWidth)
			ball.dx = -ball.dx;

		// vertical walls
		if (ball.y - ball.radius <= 0 || ball.y + ball.radius >= screenHeight)
			ball.dy = -ball.dy;
		if (ball.y < 30){
			combo = 1;
		}
	}
	
}

void resetBall(){
		ball.x = 640;
		ball.y = 100;
		ball.element = 0;
		ball.moving = false;
}


#endif