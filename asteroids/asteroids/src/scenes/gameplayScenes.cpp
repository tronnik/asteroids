#include "gameplayScenes.h"
#include "player.h"

void initGameplay()
{
	initPlayer(player);
}

void updateGameplay()
{
	updatePlayer(player);
}

void drawGameplay()
{
	Texture2D background = LoadTexture("res/background.png");
	DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);
	drawPlayer(player);
}
