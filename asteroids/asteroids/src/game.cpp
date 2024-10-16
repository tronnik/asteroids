#include "game.h"
#include "raylib.h"

static void Initialization();
static void update();
static void draw();
static void close();

void run()
{

	

	while (!WindowShouldClose())
	{
		update();
		draw();
	}
	close();
}

void Initialization()
{
	
}

void update()
{
	//if (!menuOn && !gameOver)
	//{
	//	updateGameplay();
	//
	//	if (player1.score >= 10 || player2.score >= 10)
	//	{
	//		gameOver = true;
	//	}
	//}
	//
	//if (gameOver)
	//{
	//	if (slGetKey(SL_KEY_ENTER))
	//	{
	//		initGameplay();
	//		gameOver = false;
	//		menuOn = true;
	//	}
	//}
}

void draw()
{
	

	//if (menuOn)
	//{
	//	slSprite(backgroundImage, textX / 2, textY / 2, 1000, 1000);
	//	drawMenu();
	//	if (slGetKey(SL_KEY_ENTER)) menuOn = false;
	//}
	//else if (gameOver)
	//{
	//	drawGameOver();
	//	slSprite(winnerImage, (textX / 2 + 250), (textY - textY + 300), 100, 100);
	//}
	//else
	//{
	//	drawGameplay();
	//}

	
}

void close()
{
	CloseWindow();
}