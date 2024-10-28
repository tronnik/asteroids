#include "gameplayScenes.h"

#include "player.h"
#include "asteroid.h"

static Texture2D background;
extern Music gameplayMusic;

void initGameplay()
{
	gameplayMusic = LoadMusicStream("res/gameplayMusic.mp3");

	SetMusicVolume(gameplayMusic, 0.5f);

	PlayMusicStream(gameplayMusic);

	initPlayer(player);

	initAsteroid();

	initProjectiles();
}

void updateGameplay(bool& gameOver)
{
	updatePlayer(player,gameOver);
	checkPlayerCollisions(player);

	updateAsteroid();
	checkAsteroidCollisions(player);
}

void drawGameplay()
{
	background = LoadTexture("res/background.png");
	DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	UpdateMusicStream(gameplayMusic);

	drawPlayer(player);

	drawAsteroid();
}

void unloadGameplay()
{
	UnloadTexture(background);

	UnloadMusicStream(gameplayMusic);

	unloadPlayer();

	unloadAsteroid();
}