#include "menuScenes.h"
#include "raylib.h"
#include "utils.h"

void drawMenu()
{
	Texture2D background = LoadTexture("res/background.png");
	DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);


}

void drawGameOver()
{
	
}