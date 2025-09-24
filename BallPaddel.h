
#ifndef BALLPADDEL_H
#define BALLPADDEL_H
#include"Ball.h"
#include"Score.h"
// Paddle structure
struct Paddle {
	int x, y;
	int width, height;
};

Paddle paddle = { 540, 50, 200, 20 }; // Position and size

void drawPaddle() {
	iSetColor(200, 200, 200); // paddle
	iFilledRectangle(paddle.x, paddle.y, paddle.width, paddle.height);
}


// Bounce on paddle

void checkBall(){
	if (ball.y - ball.radius <= paddle.y + paddle.height &&
		ball.x >= paddle.x &&
		ball.x <= paddle.x + paddle.width &&
		ball.dy < 0)  // Only check when the ball is moving downward
	{
		// Make the ball bounce upward
		ball.dy = -ball.dy;
		total = total + combo*score;
		combo = 1;
		score = 0;

		// Change direction based on where it hit the paddle
		int hitPos = ball.x - (paddle.x + paddle.width / 2);
		ball.dx = hitPos / 10; // control angle
	}
}
#endif