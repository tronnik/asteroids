#pragma once

struct Button
{
	int width;
	int height;
	int posX;
	int posY;
	char label;
	bool isPressed;
};

extern Button button;
extern Button controls;
extern Button credits;
extern Button backToMenu;
extern Button exitGame;
extern Button pauseGame;
extern Button resumeGame;

void initButton(Button& b, int xPos, int yPos);
void drawButton(Button& b);
bool isButtonPressed(Button& b);

void drawPlayTitle();
void drawControlTitle();
void drawCreditsTitle();
void drawExitTitle();
void drawBackToMenuTitle();
void drawPauseButtonTitle();
void drawResumeGameTitle();