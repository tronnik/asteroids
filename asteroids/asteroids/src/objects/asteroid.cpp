#include "asteroid.h"
#include "utils.h"
#include <random>

Texture2D enemy;
Asteroid asteroids[maxAsteroids];

void initAsteroid()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		asteroids[i].position = { static_cast<float>(rand() % screenWidth), static_cast<float>(rand() % screenHeight) };
		asteroids[i].speed = { static_cast<float>(rand() % 200), static_cast<float>(rand() % 200) };
		asteroids[i].direction = { asteroids[i].speed.x, asteroids[i].speed.y };
		asteroids[i].radius = 0.0f + static_cast<float>(rand() % 20);

		enemy = LoadTexture("res/asteroid-1.png");
	}
}

void updateAsteroid()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		asteroids[i].position.x += asteroids[i].speed.x * GetFrameTime();
		asteroids[i].position.y += asteroids[i].speed.y * GetFrameTime();

		if (asteroids[i].position.x < static_cast<float>(screenWidthMin)) asteroids[i].position.x = static_cast<float>(screenWidth);
		if (asteroids[i].position.x > static_cast<float>(screenWidth)) asteroids[i].position.x = static_cast<float>(screenWidthMin);
		if (asteroids[i].position.y < static_cast<float>(screenHeightMin)) asteroids[i].position.y = static_cast<float>(screenHeight);
		if (asteroids[i].position.y > static_cast<float>(screenHeight)) asteroids[i].position.y = static_cast<float>(screenHeightMin);
	}
}

void drawAsteroid()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		DrawCircle(static_cast<int>(asteroids[i].position.x), static_cast<int>(asteroids[i].position.y), asteroids[i].radius, GREEN);
	}
}

void unloadAsteroid()
{
	UnloadTexture(enemy);
}