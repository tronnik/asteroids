#include "scenes/gameplayScenes.h"

#include "objects/player.h"
#include "objects/asteroid.h"
#include "objects/button.h"
#include "objects/utils.h"
#include "objects/projectile.h"

namespace asteroids
{
	static Texture2D background;
	extern Music gameplayMusic;

	static int hundred = 100;
	static int twoHundredFifty = 250;

	void initGameplay()
	{
		initPlayer(player);

		initAsteroid();

		initProjectiles();

		initButton(pauseGame, screenWidth - twoHundredFifty, screenHeight - hundred);
	}

	void loadGameplay()
	{
		loadPlayer();
		loadAsteroid();
		background = LoadTexture("res/background.png");
		gameplayMusic = LoadMusicStream("res/gameplayMusic.mp3");
	}

	

	void updateGameplay(bool& gameOver)
	{
		SetMusicVolume(gameplayMusic, 0.5f);

		PlayMusicStream(gameplayMusic);

		updatePlayer(player, gameOver);
		checkPlayerCollisions(player);

		updateAsteroid();
		checkAsteroidCollisions(player);
	}

	void drawGameplay(bool& menuOn, bool& pauseOn)
	{
		ClearBackground(BLACK);

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
}