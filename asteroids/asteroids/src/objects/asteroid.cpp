#include "asteroid.h"
#include "utils.h"
#include <random>

Texture2D enemy;
Asteroid asteroids[maxAsteroids];

void initAsteroid()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		int side = GetRandomValue(0, 3);

		switch (side)
		{
		case 0:
			asteroids[i].position = { 0.0f, static_cast<float>(GetRandomValue(0, screenHeight)) };
			break;
		case 1:
			asteroids[i].position = { static_cast<float>(screenWidth), static_cast<float>(GetRandomValue(0, screenHeight)) };
			break;
		case 2:
			asteroids[i].position = { static_cast<float>(GetRandomValue(0, screenWidth)), 0.0f };
			break;
		case 3:
			asteroids[i].position = { static_cast<float>(GetRandomValue(0, screenWidth)), static_cast<float>(screenHeight) };
			break;
		}

		asteroids[i].speed = { static_cast<float>(rand() % 200), static_cast<float>(rand() % 200) };
		asteroids[i].direction = { asteroids[i].speed.x, asteroids[i].speed.y };
		asteroids[i].radius = 50.0f + static_cast<float>(rand() % 20);
		asteroids[i].isActive = true;

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

bool checkCollsion(Asteroid asteroid, Projectile projectile)
{
	float distX = asteroid.position.x - projectile.position.x;
	float distY = asteroid.position.y - projectile.position.y;
	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= asteroid.radius + projectile.radius)
	{
		return true;
	}
	return false;
}

void checkAsteroidCollisions()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		if (asteroids[i].isActive)
		{
			for (int j = 0; j < projectileCount; j++)
			{
				if (projectiles[j].isActive)
				{
					if (checkCollsion(asteroids[i], projectiles[j]))
					{
						asteroids[i].isActive = false;
						projectiles[j].isActive = false;
					}
				}
			}
		}
	}
}

void regenerateAsteroid()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		if (!asteroids[i].isActive)  
		{
			asteroids[i].position = { static_cast<float>(GetRandomValue(0, screenWidth)), static_cast<float>(GetRandomValue(0, screenHeight)) };
			asteroids[i].radius = static_cast<float>(GetRandomValue(15, 30));
			asteroids[i].isActive = true;  
		}
	}
}

void drawAsteroid()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		if (asteroids[i].isActive)
		{
			DrawTextureEx(enemy, { asteroids[i].position.x ,  asteroids[i].position.y }, 0.0f, 2.0f, WHITE);
		}
	}

	
}

void unloadAsteroid()
{
	UnloadTexture(enemy);
}