#include "game.h"

#include "raylib.h"

#include "utils.h"
#include "gameplayScenes.h"
#include "menuScenes.h"

static void Initialization();
static void update();
static void draw();
static void close();

int screenWidth = 1024;
int screenHeight = 768;
int screenWidthMin = 0;
int screenHeightMin = 0;

bool menuOn = true;
bool controlsOn = false;
bool creditsOn = false;
bool exitOn = false;
bool gameOver = false;

Texture2D background;
Music menuMusic;
Music gameplayMusic;

void run()
{
	Initialization();

	while (!WindowShouldClose())
	{		
		update();
		draw();
	}

	unloadGameplay();

	close();
}

void Initialization()
{
	InitWindow(screenWidth, screenHeight, "asteroids");

	InitAudioDevice();

	initGameplay();

	initMenu();
}

void update()
{	
	if (!menuOn && !gameOver && !creditsOn && !controlsOn)
		updateGameplay(gameOver);
	
	if (gameOver)
		initGameplay();
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
		drawCredits(menuOn, creditsOn);
	}
	else if (gameOver)
	{
		drawGameOver(menuOn, gameOver);
	}
	else
	{
		drawGameplay();
	}

	EndDrawing();	
}

void close()
{
	UnloadTexture(background);
	unloadMenu();
	CloseAudioDevice();
	CloseWindow();
}