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
    // Inicializaci�n
    InitWindow(screenWidth, screenHeight, "Asteroids");
    initGameplay();

    // Loop
    while (!WindowShouldClose())
    {
        
        // Chequeo de Input
        
        updateGameplay();

        // Actualizaci�n

        // Dibujado
        BeginDrawing();
        ClearBackground(WHITE); // system("cls");

        
        drawGameplay();

        EndDrawing();
    }

    // Cierre
    CloseWindow();
}
