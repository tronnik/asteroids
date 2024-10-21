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

void initButton(Button& b, int xPos, int yPos);
void drawButton(Button& b);
bool isButtonPressed(Button& b);

void initPlayButton();
void drawPlayButton(bool& menuOn);

void initControlsButton();
void drawControlsButton();

void initCreditsButton();
void drawcreditsButton();

void initExitButton();
void drawexitButton();

