#include "menuScenes.h"

#include "raylib.h"

#include "gameplayScenes.h"
#include "button.h"
#include "utils.h"
#include "buttonsInfo.h"

extern Texture2D background;

void initMenu()
{
    background = LoadTexture("res/background.png");
	initButton(button, screenWidth / 2 - 100, 350);
    initButton(controls, screenWidth / 2 - 100, 550);
    initButton(credits, screenWidth / 2 - 100, 450);
    initButton(exit, screenWidth / 2 - 100, 650);
    initButton(backToMenu, screenWidth / 2 - 100, 650);
}

void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn)
{   
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
    {
        controlsOn = true;
        menuOn = false;
    }

    if (isButtonPressed(credits))
    {
        creditsOn = true;
        menuOn = false;
    }
        
    if (isButtonPressed(exit))
    {
        CloseWindow();
    }

    if (isButtonPressed(backToMenu))
    {
        menuOn = true;
        creditsOn = false;
        controlsOn = false;
    }
}

void drawConstrols(bool& menuOn, bool& controlsOn)
{
    DrawText("CONTROLS", screenWidth / 2 - 100, 100, 40, BLACK);

    DrawText("Left Click: ", screenWidth / 2 - 220, 250, 30, BLACK);

    DrawText("Shoot", screenWidth / 2 + 100, 250, 30, BLACK);

    DrawText("Right Click: ", screenWidth / 2 - 220, 350, 30, BLACK);

    DrawText("Move", screenWidth / 2 + 100, 350, 30, BLACK);

    drawBackToMenu(menuOn, controlsOn);

}

void drawCredits(bool& menuOn, bool& creditsOn)
{
    DrawText(TextFormat("CREDITS"), screenWidth / 2 - 40, 100, 30, RED);

    drawBackToMenu(menuOn, creditsOn);

}

void drawBackToMenu(bool& boolTrue, bool& boolFalse)
{
    drawButton(backToMenu);

    drawBackToMenuTitle();

    if (isButtonPressed(backToMenu))
    {
        boolTrue = true;
        boolFalse = false;
    }
}

//void drawGameOver()
//{
//	
//}