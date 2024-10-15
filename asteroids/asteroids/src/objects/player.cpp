#include "player.h"
#include "raylib.h"
#include <math.h>
#include "utils.h"

Player player; 
Player mousePlayer;

void initPlayer(Player& p)  
{
    p.posX = static_cast<float>(screenWidth) / 2.0f;
    p.posY = static_cast<float>(screenHeight) / 2.0f;
    p.width = 30;
    p.height = 30;
}

void updateMousePos(Player& m)
{
    m.posX = static_cast<float>(GetMouseX());
    m.posY = static_cast<float>(GetMouseY());
}

void drawPlayer(Player& p, Player& m)
{
    float dx = m.posX - p.posX;  // Diferencia en X entre jugador y mouse
    float dy = m.posY - p.posY;  // Diferencia en Y entre jugador y mouse
    float angle = atan2f(dy, dx);   // Calcular el ángulo en radianes

    // Dibujar el jugador rotado
    DrawRectanglePro(Rectangle{ p.posX, p.posY , p.width, p.height },  Vector2{ p.width / 2, p.height / 2 },  
        angle * (180.0f / PI),  // Convertir a grados para la función de rotación
        RED  
    );
}




