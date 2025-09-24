
#include "iGraphics.h"
#include"Ball.h"
#include "BallPaddel.h"
#include "Bricks.h"
#include "Score.h"
#include "Level1.h"
// Button 
int startX = 475, startY = 370, width0 = 300, height0 = 80;
int optionsY = 270;
int quitY = 170;


int screen = 0; // 0: menu, 1: start, 2: options, 3: quit
int x[10]; //buttons array
int bg;
int logo;
void Load()
{
		bg = iLoadImage("images//bg.jpg");
		logo = iLoadImage("images//eleme.png");
		x[0] = iLoadImage("images//play.png");
		x[1] = iLoadImage("images//options.png");
		x[2] = iLoadImage("images//quit.png");
		x[3] = iLoadImage("images//Level_1.png");
		x[4] = iLoadImage("images//Level_2.png");
		x[5] = iLoadImage("images//Level_3.png");
}	

void showMenu(){
	iShowImage(0, 0, screenWidth, screenHeight, bg);
	iShowImage(460, 400, 350, 350, logo);
	iShowImage(startX, startY, width0, height0, x[0]);
	iShowImage(startX, optionsY, width0, height0, x[1]);
	iShowImage(startX, quitY, width0, height0, x[2]);
}

void showLevel(){
	
	iShowImage(0, 0, screenWidth, screenHeight, bg); iShowImage(460, 400, 350, 350, logo);
	iShowImage(startX, startY, width0, height0, x[3]);
	iShowImage(startX, optionsY, width0, height0, x[4]);
	iShowImage(startX, quitY, width0, height0, x[5]);
	

}

void showOption(){


}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	{ //menu
		if (screen == 0)
		{
			showMenu();
		}
		else if (screen == 1)
		{
			showLevel();
			resetBall();
			resetLevel();
		}
		else if (screen == 2)
		{
			showOption();
		}
		else if (screen >= 3)
		{
			drawBall();
			drawPaddle();
			checkBall();
			drawBricks();
			checkBrick();
			drawScore();
			gameOver();
		}
	}

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (screen ==0 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) //menu
	{
		if (mx >= startX && mx <= startX + width0)
		{
			if (my >= startY && my <= startY + height0)
			{
				screen = 1;
			}
			else if (my >= optionsY && my <= optionsY + height0)
			{
				screen = 2;
			}
			else if (my >= quitY && my <= quitY + height0)
			{
				exit(0);
			}
		}
	}

	else if (screen == 1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)  //levels
	{
		if (mx >= startX && mx <= startX + width0)
		{
			if (my >= startY && my <= startY + height0)
			{
				screen = 3;
				Level1();
			}
			else if (my >= optionsY && my <= optionsY + height0)
			{
				screen = 4;
				Level2();
			}
			else if (my >= quitY && my <= quitY + height0)
			{
				screen = 5;
				Level3();
			}
		}
	}

	else if (screen >= 3 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) //GAEM
	{
		if (mx >= ball.x - ball.radius && mx <= ball.x + ball.radius &&
			my >= ball.y - ball.radius && my <= ball.y + ball.radius){
			ball.moving = true;
		}
	}

	
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (screen >= 3){
		if (key == ' ')
		{
			ball.moving = true;
		}
		if (key == '1')
		{
			ball.element = 1;
		}
		if (key == '2')
		{
			ball.element = 2;
		}
		if (key == '3')
		{
			ball.element = 3;
		}
	}
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if(key == GLUT_KEY_LEFT && paddle.x > 0){
		paddle.x -= 20;
	}

	if(key == GLUT_KEY_RIGHT && paddle.x + paddle.width < screenWidth){
		paddle.x += 20;
	}

	if (key == GLUT_KEY_HOME)
	{
		screen = 0;
		
	}
	
}


int main()
{
	
	iSetTimer(10, updateBall);
	iInitialize(screenWidth, screenHeight, "Elemental Breaker");
	Load();
	iStart();
	
	return 0;
}