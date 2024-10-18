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
bool gameOver = false;

void run()
{
	Initialization();

	SetTargetFPS(60 * static_cast<int>(GetFrameTime()));

	while (!WindowShouldClose())
	{
		
		update();
		draw();
	}

	close();
}

void Initialization()
{
	InitWindow(screenWidth, screenHeight, "basic window");

	initGameplay();
}

void update()
{
	if (!menuOn && !gameOver)
	{
		updateGameplay();

		
	}

	
}

void draw()
{
	BeginDrawing();

	ClearBackground(BLACK);

	if (menuOn)
	{
		drawMenu();
		if (IsKeyPressed(KEY_ENTER)) menuOn = false;
	}
	else if (gameOver)
	{
		drawGameOver();
	}
	else
	{
		drawGameplay();
	}

	EndDrawing();
}

void close()
{
	CloseWindow();
}