#include <iostream>
#include "utils.h"
#include "raylib.h"
#include "player.h"

using namespace std;

int screenWidth = 1024; 
int screenHeight = 768;

int main()
{
    // Inicialización
    InitWindow(screenWidth, screenHeight, "Asteroids");
    initPlayer(player);  
    initPos();

    // Loop
    while (!WindowShouldClose())
    {
        updateMousePos(mousePlayer);
        // Chequeo de Input
        
        movePlayer(player, mousePlayer);

        // Actualización

        // Dibujado
        BeginDrawing();
        ClearBackground(WHITE); // system("cls");

        
        drawPlayer(player, mousePlayer);

        EndDrawing();
    }

    // Cierre
    CloseWindow();
}
