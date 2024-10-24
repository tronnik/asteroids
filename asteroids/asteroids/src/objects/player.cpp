#include "player.h"
#include <math.h>  
#include "utils.h"
#include "projectile.h"
#include "asteroid.h"


const float DECELERATION_RATE = 400.0f;
const float ACCELERATION_RATE = 1000.0f;

Player player;
Texture2D spaceShip;

bool isShooting = false;


void initPlayer(Player& p)
{
	p.position = { static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f };

	p.speed = { 0.0f, 0.0f };
	p.acceleration = { 0.0f, 0.0f };
	p.maxSpeed = 600.0f;

	p.mousePosition = { 0.0f, 0.0f };
	p.direction = { 0.0f, 0.0f };
	p.directionNormalized = { 0.0f, 0.0f };

	p.radius = 20.0f;
	p.angle = 0.0f;

	p.ammoSpeed = 200.0f;

	p.isActive = true;
	p.life = 3;
	p.respawnTime = 1.0f;

	spaceShip = LoadTexture("res/spaceShip.png");
}

void updatePlayer(Player& p)
{
	p.mousePosition = GetMousePosition();
	p.direction = { p.mousePosition.x - p.position.x, p.mousePosition.y - p.position.y };

	float magnitude = sqrtf(p.direction.x * p.direction.x + p.direction.y * p.direction.y);

	if (magnitude != 0.0f)
	{
		p.angle = atan2f(p.direction.y, p.direction.x) * (180.0f / PI);

		p.directionNormalized = { p.direction.x / magnitude, p.direction.y / magnitude };

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			p.acceleration.x = p.directionNormalized.x * ACCELERATION_RATE;
			p.acceleration.y = p.directionNormalized.y * ACCELERATION_RATE;
		}
		else
		{
			p.acceleration.x = 0.5f;
			p.acceleration.y = 0.5f;
		}
	}

	p.speed.x += p.acceleration.x * GetFrameTime();
	p.speed.y += p.acceleration.y * GetFrameTime();

	float speedMagnitude = sqrtf(p.speed.x * p.speed.x + p.speed.y * p.speed.y);
	if (speedMagnitude > p.maxSpeed)
	{
		Vector2 speedNormalized = { p.speed.x / speedMagnitude, p.speed.y / speedMagnitude };
		p.speed.x = speedNormalized.x * p.maxSpeed;
		p.speed.y = speedNormalized.y * p.maxSpeed;
	}

	if (p.position.x < static_cast<float>(screenWidthMin)) p.position.x = static_cast<float>(screenWidth);

	if (p.position.x > static_cast<float>(screenWidth)) p.position.x = static_cast<float>(screenWidthMin);

	if (p.position.y < static_cast<float>(screenHeightMin)) p.position.y = static_cast<float>(screenHeight);

	if (p.position.y > static_cast<float>(screenHeight)) p.position.y = static_cast<float>(screenHeightMin);

	p.position.x += p.speed.x * GetFrameTime();
	p.position.y += p.speed.y * GetFrameTime();

	fire(p);

	updateProjectiles();

	if (p.life == 0)
	{
		CloseWindow();
	}
}

bool checkCollsion(Player p, Asteroid asteroid)
{
	float distX = asteroid.position.x - p.position.x;
	float distY = asteroid.position.y - p.position.y;
	float distance = sqrtf((distX * distX) + (distY * distY)); 

	if (distance <= asteroid.radius + p.radius)
	{
		return true;
	}
	return false;
}

void checkPlayerCollisions(Player& p)
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		if (asteroids[i].isActive && p.isActive)
		{
			if (checkCollsion(p, asteroids[i]))
			{
				asteroids[i].isActive = false;
				p.isActive = false;

				p.life--;

				if (p.life > 0)
				{
					p.respawnTime = 1.0f;
				}

				regenerateAsteroid();
			}
		}
	}

	if (!p.isActive && p.life > 0)
	{
		p.respawnTime -= GetFrameTime();

		if (p.respawnTime <= 0.0f)
		{
			p.isActive = true;
			p.position = { static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f };
			p.speed = { 0.0f, 0.0f };
			p.respawnTime = 0.0f;
		}
	}
}

void drawPlayer(Player& p)
{

	if (p.isActive && p.life > 0)
	{
		//DrawCircle(static_cast<int>(p.position.x), static_cast<int>(p.position.y), p.radius, RED);

		Rectangle source = { 0.0f, 0.0f, static_cast<float>(spaceShip.width), static_cast<float>(spaceShip.height) };

		Rectangle dest = { p.position.x, p.position.y, p.radius * 2.0f, p.radius * 2.0f };  

		Vector2 origin = { (p.radius), (p.radius) };  

		float rotation = p.angle + 90.0f;  

		DrawTexturePro(spaceShip, source, dest, origin, rotation, WHITE);
	}
	drawProjectiles();
}

void drawLives(Player& p)
{
	DrawText(TextFormat(" Lifes: %01i", p.life), (screenWidth / 2) - 500, screenHeightMin + 10, 30, RED);
}

void unloadPlayer()
{
	UnloadTexture(spaceShip);
}