#include "game.h"

#include "raylib.h"

#include "objects/utils.h"
#include "scenes/gameplayScenes.h"
#include "scenes/menuScenes.h"
#include "objects/player.h"

namespace asteroids
{
	static void Initialization();
	static void loadGame();
	static void update();
	static void draw();
	static void unloadGame();
	

	int screenWidth = 1024;
	int screenHeight = 768;
	int screenWidthMin = 0;
	int screenHeightMin = 0;
	int sizeLetters = 30;

	bool menuOn = true;
	bool controlsOn = false;
	bool creditsOn = false;
	bool creditsOn2 = false;
	bool exitOn = false;
	bool gameOver = false;
	bool pauseOn = false;

	bool windowOpen = true;

	Texture2D background;
	Music menuMusic;
	Music gameplayMusic;

	void run()
	{
		Initialization();

		loadGame();

		while (!WindowShouldClose() && windowOpen)
		{
			update();
			draw();
		}

		unloadGame();

		close();

		CloseAudioDevice();

		CloseWindow();
	}

	void Initialization()
	{
		InitWindow(screenWidth, screenHeight, "asteroids");

		InitAudioDevice();

		initGameplay();

		initMenu();
	}

	void loadGame()
	{
		loadGameplay();
		loadMenu();
	}

	void update()
	{
		if (!menuOn && !gameOver && !creditsOn && !creditsOn2 && !controlsOn && !pauseOn)
			updateGameplay(gameOver);
	}

	void draw()
	{
		BeginDrawing();

		if (menuOn)
		{
			drawMenu(menuOn, controlsOn, creditsOn);
		}
		else if (controlsOn)
		{
			drawConstrols(menuOn, controlsOn);
		}
		else if (creditsOn)
		{
			drawCredits(menuOn, creditsOn, creditsOn2);
		}
		else if (creditsOn2)
		{
			drawSecondCredits(menuOn, creditsOn, creditsOn2);
		}
		else if (gameOver)
		{
			drawGameOver(menuOn, gameOver, player.point);
		}
		else if (pauseOn)
		{
			drawPause(menuOn, pauseOn);
		}
		else
		{
			drawGameplay(menuOn, pauseOn);
		}

		EndDrawing();
	}

	void unloadGame()
	{
		UnloadTexture(background);
		unloadMenu();
		unloadGameplay();
	}

	void close()
	{
		windowOpen = false;
	}
}