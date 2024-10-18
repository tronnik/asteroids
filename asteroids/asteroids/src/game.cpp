#include "game.h"
#include "raylib.h"

//static void Initialization();
//static void update();
//static void draw();
//static void close();
//
//bool menuOn = true;
//bool gameOver = false;
//
//void run()
//{
//	Initialization();
//
//	while (!WindowShouldClose())
//	{
//		update();
//		draw();
//	}
//	close();
//}
//
//void Initialization()
//{
//	InitWindow(screenWidth, screenHeight, "basic window");
//
//	initGameplay();
//}
//
//void update()
//{
//	if (!menuOn && !gameOver)
//	{
//		updateGameplay();
//
//		if (player1.score >= 10 || player2.score >= 10)
//		{
//			gameOver = true;
//		}
//	}
//
//	if (gameOver)
//	{
//		if (IsKeyPressed(KEY_ENTER))
//		{
//			initGameplay();
//			gameOver = false;
//			menuOn = true;
//		}
//	}
//}
//
//void draw()
//{
//	BeginDrawing();
//
//	ClearBackground(BLACK);
//
//	if (menuOn)
//	{
//		drawMenu();
//		if (IsKeyPressed(KEY_ENTER)) menuOn = false;
//	}
//	else if (gameOver)
//	{
//		drawGameOver();
//	}
//	else
//	{
//		drawGameplay();
//	}
//
//	EndDrawing();
//}
//
//void close()
//{
//	CloseWindow();
//}