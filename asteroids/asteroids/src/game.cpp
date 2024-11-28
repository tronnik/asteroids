#include "game.h"

#include "raylib.h"

#include "utils.h"
#include "gameplayScenes.h"
#include "menuScenes.h"

namespace asteroids
{
	static void Initialization();
	static void loadGame();
	static void update();
	static void draw();
	static void unloadGame();
	static void close();

	int screenWidth = 1024;
	int screenHeight = 768;
	int screenWidthMin = 0;
	int screenHeightMin = 0;

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
			drawGameOver(menuOn, gameOver);
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
		CloseAudioDevice();
		windowOpen = false;
	}
}