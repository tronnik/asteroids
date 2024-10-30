#include "menuScenes.h"

#include "raylib.h"

#include "button.h"
#include "utils.h"
#include "gameplayScenes.h"

namespace asteroids
{
    extern Texture2D background;
    extern Music menuMusic;

    void initMenu()
    {
        background = LoadTexture("res/background.png");

        menuMusic = LoadMusicStream("res/menuMusic.mp3");

        SetMusicVolume(menuMusic, 0.5f);

        PlayMusicStream(menuMusic);

        initButton(button, screenWidth / 2 - 100, 350);
        initButton(controls, screenWidth / 2 - 100, 550);
        initButton(credits, screenWidth / 2 - 100, 450);
        initButton(exitGame, screenWidth / 2 - 100, 650);
        initButton(backToMenu, screenWidth / 2 + 50, 700);
        initButton(resumeGame, screenWidth / 2 - 200, 700);
        initButton(playAgain, screenWidth / 2 - 200, 700);

        initPageButton(page1, screenWidth / 2 - 150, 700);
        initPageButton(page2, screenWidth / 2 - 50, 700);
    }

    void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn)
    {
        UpdateMusicStream(menuMusic);

        DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

        DrawText(TextFormat("ASTEROIDS"), screenWidth / 2 - 250, 150, 100, RED);

        drawButton(button);
        drawButton(controls);
        drawButton(credits);
        drawButton(exitGame);

        drawPlayTitle();
        drawControlTitle();
        drawCreditsTitle();
        drawExitTitle();

        if (isButtonPressed(button))
        {
            menuOn = false;

            resetGame();
        }

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

        if (isButtonPressed(exitGame))
        {
            StopMusicStream(menuMusic);
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
        DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

        UpdateMusicStream(menuMusic);

        DrawText("CONTROLS", screenWidth / 2 - 100, 100, 40, WHITE);

        DrawText("Left Click: ", screenWidth / 2 - 220, 250, 30, WHITE);

        DrawText("Shoot", screenWidth / 2 + 100, 250, 30, WHITE);

        DrawText("Right Click: ", screenWidth / 2 - 220, 350, 30, WHITE);

        DrawText("Move", screenWidth / 2 + 100, 350, 30, WHITE);

        drawBackToMenu(menuOn, controlsOn);

    }

    void drawCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
    {
        DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

        UpdateMusicStream(menuMusic);

        DrawText(TextFormat("CREDITS"), screenWidth / 2 - 60, 50, 30, WHITE);

        DrawText("Developer: ", screenWidth / 2 - 250, 150, 30, WHITE);

        DrawText("Valentin Villar", screenWidth / 2 + 50, 150, 30, WHITE);
        DrawText("Tronik in ITCH.IO ", screenWidth / 2 + 50, 180, 30, WHITE);

        DrawText("Background By: ", screenWidth / 2 - 250, 250, 30, WHITE);

        DrawText("Ansimuz in ITCH.IO", screenWidth / 2 + 50, 250, 30, WHITE);

        DrawText("Spaceship By: ", screenWidth / 2 - 250, 350, 30, WHITE);

        DrawText("Pixel By Pixel in ITCH.IO", screenWidth / 2 + 50, 350, 30, WHITE);

        DrawText("Bullets By: ", screenWidth / 2 - 250, 450, 30, WHITE);

        DrawText("Ho88it in ITCH.IO", screenWidth / 2 + 50, 450, 30, WHITE);

        DrawText("Library: ", screenWidth / 2 - 250, 550, 30, WHITE);

        DrawText("Raylib", screenWidth / 2 + 50, 550, 30, WHITE);

        drawPageButton(creditsOn, creditsOn2);

        drawBackToMenu(menuOn, creditsOn);

    }

    void drawSecondCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
    {
        DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

        UpdateMusicStream(menuMusic);

        DrawText(TextFormat("CREDITS"), screenWidth / 2 - 60, 50, 30, WHITE);

        DrawText("Menu Music: ", screenWidth / 2 - 250, 150, 30, WHITE);

        DrawText("Valentin Villar", screenWidth / 2 + 50, 150, 30, WHITE);
        DrawText("Tronik in SUNO AI ", screenWidth / 2 + 50, 180, 30, WHITE);

        DrawText("Points SFX By: ", screenWidth / 2 - 250, 250, 30, WHITE);

        DrawText("Zapslat", screenWidth / 2 + 50, 250, 30, WHITE);

        DrawText("Explosion SFX By: ", screenWidth / 2 - 250, 350, 30, WHITE);

        DrawText("Zapslat", screenWidth / 2 + 50, 350, 30, WHITE);

        DrawText("lose SFX By: ", screenWidth / 2 - 250, 450, 30, WHITE);

        DrawText("Zapslat", screenWidth / 2 + 50, 450, 30, WHITE);

        DrawText("Boost SFX by: ", screenWidth / 2 - 250, 550, 30, WHITE);

        DrawText("Zapslat", screenWidth / 2 + 50, 550, 30, WHITE);

        DrawText("Shoot SFX by: ", screenWidth / 2 - 250, 650, 30, WHITE);

        DrawText("Zapslat", screenWidth / 2 + 50, 650, 30, WHITE);

        drawPageButton(creditsOn, creditsOn2);

        drawBackToMenu(menuOn, creditsOn2);
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

    void drawPause(bool& menuOn, bool& pauseOn)
    {
        DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

        UpdateMusicStream(menuMusic);

        DrawText(TextFormat("Pause game"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

        DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);

        drawButton(resumeGame);
        drawResumeGameTitle();

        if (isButtonPressed(resumeGame))
            pauseOn = false;

        drawBackToMenu(menuOn, pauseOn);
    }

    void drawPageButton(bool& creditsOn, bool& creditsOn2)
    {
        drawButton(page1);
        drawPage1Title();

        if (isButtonPressed(page1))
        {
            creditsOn = true;
            creditsOn2 = false;
        }

        drawButton(page2);
        drawPage2Title();

        if (isButtonPressed(page2))
        {
            creditsOn = false;
            creditsOn2 = true;
        }
    }

    void drawGameOver(bool& menuOn, bool& gameOver)
    {
        DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

        UpdateMusicStream(menuMusic);

        DrawText(TextFormat("Game Over"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

        DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);

        drawButton(playAgain);
        drawPlayAgainTitle();

        if (isButtonPressed(playAgain))
            gameOver = false;
        resetGame();

        drawBackToMenu(menuOn, gameOver);
    }

    void unloadMenu()
    {
        UnloadTexture(background);
        UnloadMusicStream(menuMusic);
    }

}
