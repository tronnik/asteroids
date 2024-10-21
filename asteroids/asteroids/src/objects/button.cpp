#include "button.h"
#include "raylib.h"
#include "utils.h"

Button button;

void initButton(Button& b, int xPos, int yPos)
{
    b.posX = xPos;
    b.posY = yPos;
    b.width = 200;
    b.height = 50;
    b.isPressed = false;
}

void drawButton(Button& b)
{
    Color buttonColor = CheckCollisionPointRec(GetMousePosition(),
        Rectangle{ static_cast<float>(b.posX), static_cast<float>(b.posY),
        static_cast<float>(b.width), static_cast<float>(b.height) }) ? DARKGRAY : LIGHTGRAY;

    DrawRectangle(b.posX, b.posY, b.width, b.height, buttonColor);
}

bool isButtonPressed(Button& b)
{
    return CheckCollisionPointRec(GetMousePosition(),
        Rectangle{ static_cast<float>(b.posX), static_cast<float>(b.posY), 
        static_cast<float>(b.width), static_cast<float>(b.height) }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void initPlayButton()
{
    initButton(button, screenWidth / 2 - 100, screenHeight / 2 - 200);
}

void drawPlayButton(bool& menuOn)
{
    drawButton(button);
    if (isButtonPressed(button)) menuOn = false; 
    
}


void initControlsButton()
{
    initButton(button, screenWidth / 2 - 100, screenHeight / 2 - 300);
}

void drawControlsButton()
{
}

void initCreditsButton()
{
    initButton(button, screenWidth / 2 - 100, screenHeight / 2 - 400);
}

void drawcreditsButton()
{
}

void initExitButton()
{
    initButton(button, screenWidth / 2 - 100, screenHeight / 2 - 500);
}

void drawexitButton()
{
}

