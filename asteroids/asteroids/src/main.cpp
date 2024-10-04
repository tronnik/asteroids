#include <iostream>
#include "raylib.h"

using namespace std;

int main()
{
    // Inicializaci�n
    InitWindow(640, 480, "Mi juego");

    float posX = 320.0f;
    int posY = 225;
    int radio = 100;

    // Loop
    while (!WindowShouldClose())
    {
        // Chequeo de Input

        if (IsKeyDown(KEY_UP))
            posY--;

        if (IsKeyDown(KEY_DOWN))
            posY++;

        if (IsKeyDown(KEY_LEFT))
            posX--;

        if (IsKeyDown(KEY_RIGHT))
            posX++;


        // Actualizaci�n

        // Dibujado
        BeginDrawing();
        ClearBackground(WHITE); // system("cls");

        DrawCircle(posX, posY, radio, BLUE);

        EndDrawing();
    }

    // Cierre
    CloseWindow();
}