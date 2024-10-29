#pragma once

struct Button
{
	int width;
	int height;
	int posX;
	int posY;
};

extern Button button;
extern Button controls;
extern Button credits;
extern Button backToMenu;
extern Button exitGame;
extern Button pauseGame;
extern Button resumeGame;
extern Button playAgain;
extern Button page1;
extern Button page2;

void initButton(Button& b, int xPos, int yPos);
void initPageButton(Button& b, int xPos, int yPos);
void drawButton(Button& b);
bool isButtonPressed(Button& b);

void drawPlayTitle();
void drawControlTitle();
void drawCreditsTitle();
void drawExitTitle();
void drawBackToMenuTitle();
void drawPauseButtonTitle();
void drawResumeGameTitle();
void drawPlayAgainTitle();
void drawPage1Title();
void drawPage2Title();