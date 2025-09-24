#ifndef SCORE_H
#define SCORE_H

float score = 0; 
float total = 0;
float combo = 1;// global score variable
void drawScore() {
	
	char str[20];
	char str1[20];
	char str2[30];
	
	sprintf_s(str, "Score: %f", score);
	sprintf_s(str1, "Combo: %f", combo);
	sprintf_s(str2, "Total Score: %f", total);
	iSetColor(0, 255, 0);  // green text
	iText(1110, 600, str, GLUT_BITMAP_HELVETICA_18);
	iText(1100, 550, str1, GLUT_BITMAP_HELVETICA_18);
	iText(1070, 500, str2, GLUT_BITMAP_HELVETICA_18);
	
}
void calcScore(){
	total = total + score*combo;
	score = 0;
	combo = 1;
}

#endif