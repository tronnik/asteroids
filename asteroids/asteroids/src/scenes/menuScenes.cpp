#include "scenes/menuScenes.h"

#include "raylib.h"

#include "objects/button.h"
#include "objects/utils.h"
#include "scenes/gameplayScenes.h"
#include "objects/player.h"
#include "game.h"

namespace asteroids
{
	extern Texture2D background;
	extern Music menuMusic;

	Button ItchButton;
	Button backgroundButton;
	Button spaceShipButton;
	Button bulletsButton;
	Button raylibButton;

	Button MenuMusicButton;
	Button gameplayMusicButton;
	Button clickSfxButton;
	Button explosionSfxButton;
	Button loseSfxButton;
	Button boostSfxButton;
	Button shootSfxButton;

	Sound clickSfx;

	static void drawPageButton(bool& creditsOn, bool& creditsOn2);

	static int hundred = 100;
	static int fifty = 50;
	static int oneHundredFifty = 150;
	static int twoHundred = 200;
	static int twoHundredFifty = 250;
	static int threeHundredFifty = 350;
	static int fourHundredFifty = 450;
	static int fiveHundred = 500;

	static int sevenHundred = 700;

	void initMenu()
	{
		initButton(button, (screenWidth / 2 - hundred), threeHundredFifty);

		initButton(controls, (screenWidth / 2 - hundred), (fiveHundred + fifty));

		initButton(credits, (screenWidth / 2 - hundred), fourHundredFifty);

		initButton(exitGame, (screenWidth / 2 - hundred), (fiveHundred + oneHundredFifty));

		initButton(backToMenu, (screenWidth / 2 + fifty), sevenHundred);

		initButton(resumeGame, (screenWidth / 2 - twoHundred), sevenHundred);

		initButton(playAgain, (screenWidth / 2 - twoHundred), sevenHundred);

		initButton(ItchButton, (screenWidth / 2 + fifty), oneHundredFifty);

		initButton(backgroundButton, (screenWidth / 2 + fifty), twoHundredFifty);

		initButton(spaceShipButton, (screenWidth / 2 + fifty), threeHundredFifty);

		initButton(bulletsButton, (screenWidth / 2 + fifty), fourHundredFifty);

		initButton(raylibButton, (screenWidth / 2 + fifty), (fiveHundred + fifty));

		initButton(MenuMusicButton, (screenWidth / 2 + fifty), hundred);

		initButton(gameplayMusicButton, (screenWidth / 2 + fifty), (oneHundredFifty + 30));

		initButton(clickSfxButton, (screenWidth / 2 + fifty), (twoHundredFifty + 10));

		initButton(explosionSfxButton, (screenWidth / 2 + fifty), (threeHundredFifty - 10));

		initButton(loseSfxButton, (screenWidth / 2 + fifty), (fourHundredFifty - 30));

		initButton(boostSfxButton, (screenWidth / 2 + fifty), fiveHundred);

		initButton(shootSfxButton, (screenWidth / 2 + fifty), (fiveHundred + 80));

		initPageButton(page1, (screenWidth / 2 - oneHundredFifty), sevenHundred);

		initPageButton(page2, (screenWidth / 2 - fifty), sevenHundred);
	}

	void loadMenu()
	{
		background = LoadTexture("res/background.png");
		menuMusic = LoadMusicStream("res/menuMusic.mp3");
		clickSfx = LoadSound("res/clickSfx.mp3");
	}

	void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn)
	{
		ClearBackground(BLACK);

		SetMusicVolume(menuMusic, 0.5f);

		SetSoundVolume(clickSfx, 0.3f);

		PlayMusicStream(menuMusic);
		UpdateMusicStream(menuMusic);

		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		DrawText(TextFormat("ASTEROIDS"), (screenWidth / 2 - twoHundredFifty), oneHundredFifty, hundred, RED);

		DrawText(TextFormat("2.0"), (screenWidth / 2 + fourHundredFifty), sevenHundred, sizeLetters, RED);

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
			PlaySound(clickSfx);

			menuOn = false;

			resetGame();
		}

		if (isButtonPressed(controls))
		{
			PlaySound(clickSfx);
			controlsOn = true;
			menuOn = false;
		}

		if (isButtonPressed(credits))
		{
			PlaySound(clickSfx);
			creditsOn = true;
			menuOn = false;
		}

		if (isButtonPressed(exitGame))
		{
			PlaySound(clickSfx);
			StopMusicStream(menuMusic);
			
			close();
		}

		if (isButtonPressed(backToMenu))
		{
			PlaySound(clickSfx);
			menuOn = true;
			creditsOn = false;
			controlsOn = false;
		}
	}

	void drawConstrols(bool& menuOn, bool& controlsOn)
	{
		ClearBackground(BLACK);

		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText("CONTROLS", (screenWidth / 2 - hundred), hundred, sizeLetters + 10, WHITE);

		DrawText("Left Click: ", (screenWidth / 2) - (twoHundred + 20), twoHundredFifty, sizeLetters, WHITE);

		DrawText("Shoot", (screenWidth / 2 + hundred), twoHundredFifty, sizeLetters, WHITE);

		DrawText("Right Click: ", (screenWidth / 2) - (twoHundred + 20), threeHundredFifty, sizeLetters, WHITE);

		DrawText("Move", (screenWidth / 2 + hundred), threeHundredFifty, sizeLetters, WHITE);

		drawBackToMenu(menuOn, controlsOn);

	}

	void drawCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
	{
		ClearBackground(BLACK);

		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText(TextFormat("CREDITS"), (screenWidth / 2 - fifty), fifty, sizeLetters, WHITE);

		DrawText("Developer: ", (screenWidth / 2 - twoHundredFifty), oneHundredFifty, sizeLetters, WHITE);

		drawButton(ItchButton);
		DrawText("Valentin Villar", (screenWidth / 2 + fifty + 10), oneHundredFifty + 10, sizeLetters - 5, RED);
		if (isButtonPressed(ItchButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://valentin-villar.itch.io/");
		}

		DrawText("Background By: ", (screenWidth / 2 - twoHundredFifty), twoHundredFifty, sizeLetters, WHITE);
		drawButton(backgroundButton);
		DrawText("Ansimuz", (screenWidth / 2 + hundred - 10), (twoHundredFifty + 10), sizeLetters, RED);
		if (isButtonPressed(backgroundButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://ansimuz.itch.io/space-background");
		}


		DrawText("Spaceship By: ", (screenWidth / 2 - twoHundredFifty), threeHundredFifty, sizeLetters, WHITE);
		drawButton(spaceShipButton);
		DrawText("Pixel By Pixel", (screenWidth / 2 + hundred - 30), (threeHundredFifty + 10), (sizeLetters - 5), RED);
		if (isButtonPressed(spaceShipButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://pixel-by-pixel.itch.io/alcwilliam-space-ship-pack");
		}

		DrawText("Bullets By: ", (screenWidth / 2 - twoHundredFifty), fourHundredFifty, sizeLetters, WHITE);
		drawButton(bulletsButton);
		DrawText("Ho88it", (screenWidth / 2 + hundred), (fourHundredFifty + 10), sizeLetters, RED);
		if (isButtonPressed(bulletsButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://ho88it.itch.io/2-d-projectile-sprites-wild-west-character-pack");
		}

		DrawText("Library: ", (screenWidth / 2 - twoHundredFifty), (fiveHundred + fifty), sizeLetters, WHITE);

		drawButton(raylibButton);
		DrawText("Raylib", (screenWidth / 2 + hundred - 10), (fiveHundred + 60), sizeLetters, RED);
		if (isButtonPressed(raylibButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://www.raylib.com/index.html");
		}

		drawPageButton(creditsOn, creditsOn2);

		drawBackToMenu(menuOn, creditsOn);

	}

	void drawSecondCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2)
	{
		ClearBackground(BLACK);

		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText(TextFormat("CREDITS"), (screenWidth / 2 - hundred - 40), fifty, sizeLetters, WHITE);

		DrawText("Menu Music: ", (screenWidth / 2 - twoHundredFifty), hundred, sizeLetters, WHITE);
		drawButton(MenuMusicButton);
		DrawText("Tronik", (screenWidth / 2 + hundred), (hundred + 10), sizeLetters, RED);
		if (isButtonPressed(MenuMusicButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://suno.com/song/e59ff0d9-1128-4a84-a976-4d21dfbc791c");
		}

		DrawText("Gameplay Music: ", (screenWidth / 2 - twoHundredFifty), (twoHundred - 20), sizeLetters, WHITE);
		drawButton(gameplayMusicButton);
		DrawText("Tronik", (screenWidth / 2 + hundred), (twoHundred - 10), sizeLetters, RED);
		if (isButtonPressed(gameplayMusicButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://suno.com/song/bbfb93c9-37f9-4d51-8cfd-e15823f02192");
		}


		DrawText("Click SFX By: ", (screenWidth / 2 - twoHundredFifty), (twoHundredFifty + 10), sizeLetters, WHITE);
		drawButton(clickSfxButton);
		DrawText("Pixaby", (screenWidth / 2 + hundred), (twoHundredFifty + 20), sizeLetters, RED);
		if (isButtonPressed(clickSfxButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://pixabay.com/sound-effects/click-234708/");
		}

		DrawText("Explosion SFX By: ", (screenWidth / 2 - twoHundredFifty), (threeHundredFifty - 10), sizeLetters, WHITE);
		drawButton(explosionSfxButton);
		DrawText("Zapslat", (screenWidth / 2 + hundred), threeHundredFifty, sizeLetters, RED);
		if (isButtonPressed(explosionSfxButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://www.zapsplat.com/music/8bit-medium-explosion-bomb-boom-or-blast-cannon-retro-old-school-classic-cartoon/");
		}

		DrawText("lose SFX By: ", (screenWidth / 2 - twoHundredFifty), (fourHundredFifty - 30), sizeLetters, WHITE);
		drawButton(loseSfxButton);
		DrawText("Zapslat", (screenWidth / 2 + hundred), (fourHundredFifty - 20), sizeLetters, RED);
		if (isButtonPressed(loseSfxButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://www.zapsplat.com/music/cartoon-orchestral-musical-pizzicato-riff-short-fail-or-lose/");
		}

		DrawText("Boost SFX by: ", (screenWidth / 2 - twoHundredFifty), fiveHundred, sizeLetters, WHITE);
		drawButton(boostSfxButton);
		DrawText("Elevenslab.io", (screenWidth / 2 + fifty), (fiveHundred + 10), sizeLetters, RED);
		if (isButtonPressed(boostSfxButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://elevenlabs.io/app/sound-effects/history");
		}

		DrawText("Shoot SFX by: ", (screenWidth / 2 - twoHundredFifty), (fiveHundred + 80), sizeLetters, WHITE);
		drawButton(shootSfxButton);
		DrawText("Zapslat", (screenWidth / 2 + hundred), (fiveHundred + 90), sizeLetters, RED);
		if (isButtonPressed(shootSfxButton))
		{
			PlaySound(clickSfx);
			OpenURL("https://www.zapsplat.com/music/anime-hard-and-fast-laser-shoot-3/");
		}

		drawPageButton(creditsOn, creditsOn2);

		drawBackToMenu(menuOn, creditsOn2);
	}

	void drawBackToMenu(bool& boolTrue, bool& boolFalse)
	{
		ClearBackground(BLACK);

		drawButton(backToMenu);

		drawBackToMenuTitle();

		if (isButtonPressed(backToMenu))
		{
			PlaySound(clickSfx);
			boolTrue = true;
			boolFalse = false;
		}
	}

	void drawPause(bool& menuOn, bool& pauseOn)
	{
		ClearBackground(BLACK);

		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText(TextFormat("Pause game"), (screenWidth / 2 - oneHundredFifty), (screenHeight / 2 - hundred), fifty, WHITE);

		DrawText(TextFormat("What Will You Do"), (screenWidth / 2 - twoHundred), (screenHeight / 2 - sizeLetters), fifty, WHITE);

		drawButton(resumeGame);
		drawResumeGameTitle();

		if (isButtonPressed(resumeGame))
		{
			PlaySound(clickSfx);
			pauseOn = false;
		}

		drawBackToMenu(menuOn, pauseOn);
	}

	void drawPageButton(bool& creditsOn, bool& creditsOn2)
	{
		ClearBackground(BLACK);

		drawButton(page1);
		drawPage1Title();

		if (isButtonPressed(page1))
		{
			PlaySound(clickSfx);
			creditsOn = true;
			creditsOn2 = false;
		}

		drawButton(page2);
		drawPage2Title();

		if (isButtonPressed(page2))
		{
			PlaySound(clickSfx);
			creditsOn = false;
			creditsOn2 = true;
		}
	}

	void drawGameOver(bool& menuOn, bool& gameOver, int playerScore)
	{

		ClearBackground(BLACK);

		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(menuMusic);

		DrawText(TextFormat("Game Over"), (screenWidth / 2 - hundred - 20), (screenHeight / 2 - hundred), fifty, WHITE);

		DrawText(TextFormat("Points: %01i", playerScore), (screenWidth / 2 - hundred), (screenHeight / 2 - sizeLetters), fifty, WHITE);

		DrawText(TextFormat("What Will You Do?"), (screenWidth / 2 - twoHundred), (screenHeight / 2 + 40), fifty, WHITE);

		drawButton(playAgain);
		drawPlayAgainTitle();

		if (isButtonPressed(playAgain))
		{
			PlaySound(clickSfx);
			gameOver = false;
			resetGame();
		}

		drawBackToMenu(menuOn, gameOver);
	}

	void unloadMenu()
	{
		UnloadTexture(background);
		UnloadMusicStream(menuMusic);
		UnloadSound(clickSfx);
	}

}
