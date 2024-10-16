#include <iostream>
#include "utils.h"
#include "raylib.h"
#include "player.h"
#include "gameplayScenes.h"

using namespace std;

int screenWidth = 1024; 
int screenHeight = 768;

int main()
{
    // Inicialización
    InitWindow(screenWidth, screenHeight, "Asteroids");
    initGameplay();

    // Loop
    while (!WindowShouldClose())
    {
        
        // Chequeo de Input
        
        updateGameplay();

        // Actualización

        // Dibujado
        BeginDrawing();
        ClearBackground(WHITE); // system("cls");

        
        drawGameplay();

        EndDrawing();
    }

    // Cierre
    CloseWindow();
}
