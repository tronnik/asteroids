#include "gameplayScenes.h"
#include "player.h"
#include "asteroid.h"

Texture2D background;

void initGameplay()
{
	initPlayer(player);
	initAsteroid();
}

void updateGameplay()
{
	updatePlayer(player);
	updateAsteroid();
	checkAsteroidCollisions();
}

void drawGameplay()
{
	background = LoadTexture("res/background.png");
	DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	drawPlayer(player);
	drawAsteroid();

}

void unloadGameplay()
{
	unloadPlayer();
	UnloadTexture(background);
	unloadAsteroid();
}