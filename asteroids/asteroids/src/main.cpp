#include "raylib.h"
#include "player.h"
#include "utils.h"
#include "gameplayScenes.h"


int screenWidth = 1024;
int screenHeight = 768;

int main() 
{
    InitWindow(screenWidth, screenHeight, "asteroids");

    initGameplay();

    SetTargetFPS(60); 

    while (!WindowShouldClose()) 
    {  
        updateGameplay();

        BeginDrawing();
        ClearBackground(RAYWHITE);  

        drawGameplay();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
