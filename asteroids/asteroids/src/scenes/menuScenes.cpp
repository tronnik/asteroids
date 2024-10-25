#include "menuScenes.h"

#include "raylib.h"

#include "gameplayScenes.h"
#include "button.h"
#include "utils.h"
#include "buttonsInfo.h"

static Texture2D background;

void initMenu()
{
	initButton(button, screenWidth / 2 - 100, 350);
    initButton(controls, screenWidth / 2 - 100, 550);
    initButton(credits, screenWidth / 2 - 100, 450);
    initButton(exit, screenWidth / 2 - 100, 650);
}

void drawMenu(bool& menuOn, bool& controlsOn)
{
    background = LoadTexture("res/background.png");
	DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

    drawButton(button);
    drawButton(controls);
    drawButton(credits);
    drawButton(exit);

    drawPlayTitle();
    drawControlTitle();
    drawCreditsTitle();
    drawExitTitle();

    if (isButtonPressed(button))
        menuOn = false; 
    
    if (isButtonPressed(controls))
        controlsOn = true;

    drawConstrols();
}

void drawConstrols()
{
    DrawText(TextFormat("CONTROLS"), screenWidth / 2 - 40, 660, 30, RED);
}

//void drawGameOver()
//{
//	
//}