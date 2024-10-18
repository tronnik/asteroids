#include "raylib.h"
#include "player.h"
#include "utils.h"
#include "gameplayScenes.h"
#include "menuScenes.h"


int screenWidth = 1024;
int screenHeight = 768;
int screenWidthMin = 0;
int screenHeightMin = 0;

int main() 
{
    InitWindow(screenWidth, screenHeight, "asteroids");

  // initGameplay();

    SetTargetFPS(60); 

    while (!WindowShouldClose()) 
    {  
       // updateGameplay();

        BeginDrawing();
        ClearBackground(RAYWHITE);  

        drawMenu();
      //  drawGameplay();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
