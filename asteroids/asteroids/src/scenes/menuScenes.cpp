#include "menuScenes.h"

#include "raylib.h"

#include "button.h"
#include "utils.h"
#include "gameplayScenes.h"

namespace asteroids
{
	extern Texture2D background;
	extern Music menuMusic;

	Button backgroundButton;
	Button spaceShipButton;
	Button bulletsButton;
	Button raylibButton;

	Button MenuMusicButton;
	Button gameplayMusicButton;
	Button pointsSfxButton;
	Button explosionSfxButton;
	Button loseSfxButton;
	Button boostSfxButton;
	Button shootSfxButton;


	void initMenu()
	{
		background = LoadTexture("res/background.png");

		menuMusic = LoadMusicStream("res/menuMusic.mp3");

		SetMusicVolume(menuMusic, 0.5f);

		PlayMusicStream(menuMusic);

		initButton(button, screenWidth / 2 - 100, 350);
		initButton(controls, screenWidth / 2 - 100, 550);
		initButton(credits, screenWidth / 2 - 100, 450);
		initButton(exitGame, screenWidth / 2 - 100, 650);
		initButton(backToMenu, screenWidth / 2 + 50, 700);
		initButton(resumeGame, screenWidth / 2 - 200, 700);
		initButton(playAgain, screenWidth / 2 - 200, 700);

		initButton(backgroundButton, screenWidth / 2 + 50, 250);
		initButton(spaceShipButton, screenWidth / 2 + 50, 350);
		initButton(bulletsButton, screenWidth / 2 + 50, 450);
		initButton(raylibButton, screenWidth / 2 + 50, 550);

		initButton(MenuMusicButton, screenWidth / 2 + 50, 100);
		initButton(gameplayMusicButton, screenWidth / 2 + 50, 180);
		initButton(pointsSfxButton, screenWidth / 2 + 50, 260);
		initButton(explosionSfxButton, screenWidth / 2 + 50, 340);
		initButton(loseSfxButton, screenWidth / 2 + 50, 420);
		initButton(boostSfxButton, screenWidth / 2 + 50, 500);
		initButton(shootSfxButton, screenWidth / 2 + 50, 580);

		initPageButton(page1, screenWidth / 2 - 150, 700);
		initPageButton(page2, screenWidth / 2 - 50, 700);
	}

	void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn)
	{
		UpdateMusicStream(menuMusic);

		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		DrawText(TextFormat("ASTEROIDS"), screenWidth / 2 - 250, 150, 100, RED);

		drawButton(button);
		drawButton(controls);
		drawButton(credits);
		drawButton(exitGame);

		drawPlayTitle();
		drawControlTitle();
		drawCreditsTitle();
		drawExitTitle();

		if (isButtonPressed(button))
		{
			menuOn = false;

			resetGame();
		}

		if (isButtonPressed(controls))
		{
			controlsOn = true;
			menuOn = false;
		}

		if (isButtonPressed(credits))
		{
			creditsOn = true;
			menuOn = false;
		}

		if (isButtonPressed(exitGame))
		{
			StopMusicStream(menuMusic);
			CloseWindow();
		}

		if (isButtonPressed(backToMenu))
		{
			menuOn = true;
			creditsOn = false;
			controlsOn = false;
		}
	}

	void drawConstrols(bool& menuOn, bool& controlsOn)
	{
		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText("CONTROLS", screenWidth / 2 - 100, 100, 40, WHITE);

		DrawText("Left Click: ", screenWidth / 2 - 220, 250, 30, WHITE);

		DrawText("Shoot", screenWidth / 2 + 100, 250, 30, WHITE);

		DrawText("Right Click: ", screenWidth / 2 - 220, 350, 30, WHITE);

		DrawText("Move", screenWidth / 2 + 100, 350, 30, WHITE);

		drawBackToMenu(menuOn, controlsOn);

	}

	void drawCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
	{
		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText(TextFormat("CREDITS"), screenWidth / 2 - 60, 50, 30, WHITE);

		DrawText("Developer: ", screenWidth / 2 - 250, 150, 30, WHITE);

		DrawText("Valentin Villar", screenWidth / 2 + 50, 150, 30, WHITE);
		DrawText("Tronik in ITCH.IO ", screenWidth / 2 + 50, 180, 30, WHITE);

		DrawText("Background By: ", screenWidth / 2 - 250, 250, 30, WHITE);

		drawButton(backgroundButton);
		DrawText("Ansimuz", screenWidth / 2 + 90, 260, 30, RED);
		if (isButtonPressed(backgroundButton))
		{
			OpenURL("https://ansimuz.itch.io/space-background");
		}


		DrawText("Spaceship By: ", screenWidth / 2 - 250, 350, 30, WHITE);
		drawButton(spaceShipButton);
		DrawText("Pixel By Pixel", screenWidth / 2 + 70, 360, 25, RED);
		if (isButtonPressed(spaceShipButton))
		{
			OpenURL("https://pixel-by-pixel.itch.io/alcwilliam-space-ship-pack");
		}

		DrawText("Bullets By: ", screenWidth / 2 - 250, 450, 30, WHITE);
		drawButton(bulletsButton);
		DrawText("Ho88it", screenWidth / 2 + 100, 460, 30, RED);
		if (isButtonPressed(bulletsButton))
		{
			OpenURL("https://ho88it.itch.io/2-d-projectile-sprites-wild-west-character-pack");
		}

		DrawText("Library: ", screenWidth / 2 - 250, 550, 30, WHITE);

		drawButton(raylibButton);
		DrawText("Raylib", screenWidth / 2 + 90, 560, 30, RED);
		if (isButtonPressed(raylibButton))
		{
			OpenURL("https://www.raylib.com/index.html");
		}

		drawPageButton(creditsOn, creditsOn2);

		drawBackToMenu(menuOn, creditsOn);

	}

	void drawSecondCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
	{
		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText(TextFormat("CREDITS"), screenWidth / 2 - 60, 50, 30, WHITE);

		DrawText("Menu Music: ", screenWidth / 2 - 250, 100, 30, WHITE);
		drawButton(MenuMusicButton);
		DrawText("Tronik", screenWidth / 2 + 100, 110, 30, RED);
		if (isButtonPressed(MenuMusicButton))
		{
			OpenURL("https://suno.com/song/e59ff0d9-1128-4a84-a976-4d21dfbc791c");
		}

		DrawText("Gameplay Music: ", screenWidth / 2 - 250, 180, 30, WHITE);
		drawButton(gameplayMusicButton);
		DrawText("Tronik", screenWidth / 2 + 70, 190, 30, RED);
		if (isButtonPressed(gameplayMusicButton))
		{
			OpenURL("https://suno.com/song/bbfb93c9-37f9-4d51-8cfd-e15823f02192");
		}


		DrawText("Points SFX By: ", screenWidth / 2 - 250, 260, 30, WHITE);
		drawButton(pointsSfxButton);
		DrawText("Zapslat", screenWidth / 2 + 70, 270, 30, RED);
		if (isButtonPressed(pointsSfxButton))
		{
			OpenURL("https://www.zapsplat.com/music/game-sound-friendly-happy-positive-chime-good-for-win-gain-points-or-bonus/");
		}

		DrawText("Explosion SFX By: ", screenWidth / 2 - 250, 340, 30, WHITE);
		drawButton(explosionSfxButton);
		DrawText("Zapslat", screenWidth / 2 + 70, 350, 30, RED);
		if (isButtonPressed(explosionSfxButton))
		{
			OpenURL("https://www.zapsplat.com/music/8bit-medium-explosion-bomb-boom-or-blast-cannon-retro-old-school-classic-cartoon/");
		}

		DrawText("lose SFX By: ", screenWidth / 2 - 250, 420, 30, WHITE);
		drawButton(loseSfxButton);
		DrawText("Zapslat", screenWidth / 2 + 70, 430, 30, RED);
		if (isButtonPressed(loseSfxButton))
		{
			OpenURL("https://www.zapsplat.com/music/cartoon-orchestral-musical-pizzicato-riff-short-fail-or-lose/");
		}

		DrawText("Boost SFX by: ", screenWidth / 2 - 250, 500, 30, WHITE);
		drawButton(boostSfxButton);
		DrawText("Zapslat", screenWidth / 2 + 70, 510, 30, RED);
		if (isButtonPressed(boostSfxButton))
		{
			//OpenURL("");
		}

		DrawText("Shoot SFX by: ", screenWidth / 2 - 250, 580, 30, WHITE);
		drawButton(shootSfxButton);
		DrawText("Zapslat", screenWidth / 2 + 70, 590, 30, RED);
		if (isButtonPressed(boostSfxButton))
		{
			OpenURL("https://www.zapsplat.com/music/anime-hard-and-fast-laser-shoot-3/");
		}

		drawPageButton(creditsOn, creditsOn2);

		drawBackToMenu(menuOn, creditsOn2);
	}

	void drawBackToMenu(bool& boolTrue, bool& boolFalse)
	{
		drawButton(backToMenu);

		drawBackToMenuTitle();

		if (isButtonPressed(backToMenu))
		{
			boolTrue = true;
			boolFalse = false;
		}
	}

	void drawPause(bool& menuOn, bool& pauseOn)
	{
		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText(TextFormat("Pause game"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

		DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);

		drawButton(resumeGame);
		drawResumeGameTitle();

		if (isButtonPressed(resumeGame))
			pauseOn = false;

		drawBackToMenu(menuOn, pauseOn);
	}

	void drawPageButton(bool& creditsOn, bool& creditsOn2)
	{
		drawButton(page1);
		drawPage1Title();

		if (isButtonPressed(page1))
		{
			creditsOn = true;
			creditsOn2 = false;
		}

		drawButton(page2);
		drawPage2Title();

		if (isButtonPressed(page2))
		{
			creditsOn = false;
			creditsOn2 = true;
		}
	}

	void drawGameOver(bool& menuOn, bool& gameOver)
	{
		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText(TextFormat("Game Over"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

		DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);

		drawButton(playAgain);
		drawPlayAgainTitle();

		if (isButtonPressed(playAgain))
			gameOver = false;
		resetGame();

		drawBackToMenu(menuOn, gameOver);
	}

	void unloadMenu()
	{
		UnloadTexture(background);
		UnloadMusicStream(menuMusic);
	}

}
