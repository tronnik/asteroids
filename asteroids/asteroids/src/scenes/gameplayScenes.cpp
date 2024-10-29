#include "gameplayScenes.h"

#include "player.h"
#include "asteroid.h"
#include "button.h"
#include "utils.h"
#include "projectile.h"

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

	initButton(pauseGame, screenWidth - 250, screenHeight - 100);
}

void loadGameplay()
{
	loadPlayer();
	loadAsteroid();
}

void updateGameplay(bool& gameOver)
{
	updatePlayer(player, gameOver);
	checkPlayerCollisions(player);

	updateAsteroid();
	checkAsteroidCollisions(player);
}

void drawGameplay(bool& menuOn, bool& pauseOn)
{
	background = LoadTexture("res/background.png");
	DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	UpdateMusicStream(gameplayMusic);

	drawPlayer(player);

	drawAsteroid();

	drawButton(pauseGame);

	drawPauseButtonTitle();

	if (isButtonPressed(pauseGame))
	{
		pauseOn = true;
		menuOn = false;
	}
}

void resetGame()
{
	initPlayer(player);

	initAsteroid();

	projectileCount = 0;
}

void unloadGameplay()
{
	UnloadTexture(background);

	UnloadMusicStream(gameplayMusic);

	unloadPlayer();

	unloadAsteroid();

	unloadProjectiles();
}