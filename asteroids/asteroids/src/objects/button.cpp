#include "button.h"

#include "raylib.h"

#include "utils.h"

namespace asteroids
{
    Button button;
    Button controls;
    Button credits;
    Button backToMenu;
    Button exitGame;
    Button pauseGame;
    Button resumeGame;
    Button playAgain;
    Button page1;
    Button page2;

    void initButton(Button& b, int xPos, int yPos)
    {
        b.posX = xPos;
        b.posY = yPos;
        b.width = 200;
        b.height = 50;
    }

    void initPageButton(Button& b, int xPos, int yPos)
    {
        b.posX = xPos;
        b.posY = yPos;
        b.width = 50;
        b.height = 50;
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

    void drawPlayTitle()
    {
        DrawText(TextFormat("PLAY"), screenWidth / 2 - 40, 360, 30, RED);
    }

    void drawControlTitle()
    {
        DrawText(TextFormat("CREDITS"), screenWidth / 2 - 70, 460, 30, RED);
    }

    void drawCreditsTitle()
    {
        DrawText(TextFormat("CONTROLS"), screenWidth / 2 - 80, 560, 30, RED);
    }

    void drawExitTitle()
    {
        DrawText(TextFormat("EXIT"), screenWidth / 2 - 40, 660, 30, RED);
    }

    void drawBackToMenuTitle()
    {
        DrawText(TextFormat("MENU"), screenWidth / 2 + 110, 710, 30, RED);
    }

    void drawPauseButtonTitle()
    {
        DrawText(TextFormat("PAUSE"), screenWidth - 200, screenHeight - 90, 30, RED);
    }

    void drawResumeGameTitle()
    {
        DrawText(TextFormat("RESUME"), screenWidth / 2 - 160, 710, 30, RED);
    }

    void drawPlayAgainTitle()
    {
        DrawText(TextFormat("PLAY AGAIN"), screenWidth / 2 - 190, 710, 30, RED);
    }

    void drawPage1Title()
    {
        DrawText(TextFormat("1"), screenWidth / 2 - 130, 710, 30, RED);
    }

    void drawPage2Title()
    {
        DrawText(TextFormat("2"), screenWidth / 2 - 30, 710, 30, RED);
    }
}
