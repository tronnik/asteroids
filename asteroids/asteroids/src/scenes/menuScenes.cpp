#include "menuScenes.h"
#include "gameplayScenes.h"
#include "raylib.h"
#include "button.h"
#include "utils.h"
#include "buttonsInfo.h"


void initMenu()
{
	initButton(button, 100, 100);
}

void drawMenu(bool& menuOn) 
{
	Texture2D background = LoadTexture("res/background.png");
	DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

   

    drawButton(button);

    // Verificar si el botón fue presionado
    if (isButtonPressed(button))
    {
        // Cambiar a la escena del juego
        menuOn = false; // Cambia la variable que controla el estado del menú
    }
    
}

//void drawGameOver()
//{
//	
//}