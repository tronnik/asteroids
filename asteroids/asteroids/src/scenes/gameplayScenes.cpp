#include "scenes/gameplayScenes.h"

#include "objects/player.h"
#include "objects/asteroid.h"
#include "objects/button.h"
#include "objects/utils.h"
#include "objects/projectile.h"

namespace asteroids
{
	static Texture2D background;
	extern Music gameplayMusic;

	static int hundred = 100;
	static int twoHundredFifty = 250;

	void initGameplay()
	{
		initPlayer(player);

		initAsteroid();

		initProjectiles();

		initButton(pauseGame, screenWidth - twoHundredFifty, screenHeight - hundred);
	}

	void loadGameplay()
	{
		loadPlayer();
		loadAsteroid();
		background = LoadTexture("res/background.png");
		gameplayMusic = LoadMusicStream("res/gameplayMusic.mp3");
	}

	bool checkCollsionAsteroidProjectile(Asteroid asteroid, Projectile projectile)
	{
		float distX = asteroid.position.x - projectile.position.x;
		float distY = asteroid.position.y - projectile.position.y;
		float distance = static_cast<float>(sqrt((distX * distX) + (distY * distY)));

		return distance <= asteroid.radius + projectile.radius;
	}

	void AsteroidCollision(Player& p)
	{
		for (size_t i = 0; i < asteroids.size(); ++i)
		{
			if (asteroids[i].isActive)
			{
				for (int j = 0; j < projectileCount; j++)
				{
					if (projectiles[j].isActive && checkCollsionAsteroidProjectile(asteroids[i], projectiles[j]))
					{
						AsteroidSize currentSize = asteroids[i].size;

						asteroids[i].isActive = false;
						projectiles[j].isActive = false;
						p.point += 10;

						SetSoundVolume(explosionSfx, 0.3f);
						PlaySound(explosionSfx);
						SetSoundVolume(pointsSfx, 0.1f);
						PlaySound(pointsSfx);

						if (currentSize != AsteroidSize::SMALL)
						{
							createNewAsteroids(currentSize, asteroids[i].position, asteroids[i].direction);
						}
					}
				}
			}
		}
	}

	bool checkCollsionPlayerAsteroid(Player p, Asteroid asteroid)
	{
		float distX = asteroid.position.x - p.position.x;
		float distY = asteroid.position.y - p.position.y;
		float distance = sqrtf((distX * distX) + (distY * distY));

		return distance <= asteroid.radius + p.radius;
	}

	void playerCollision(Player& p)
	{
		p.invensible -= GetFrameTime();

		for (size_t i = 0; i < asteroids.size(); ++i)
		{
			if (asteroids[i].isActive && p.isActive)
			{
				if (checkCollsionPlayerAsteroid(p, asteroids[i]))
				{
					if (p.invensible <= 0.0f)
					{
						p.isActive = false;
						p.life--;

						if (p.life > 0)
							p.respawnTime = 1.0f;

						SetSoundVolume(loseSfx, 0.3f);
						PlaySound(loseSfx);
					}
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

				p.invensible = 5.0f;
			}
		}
	}

	

	void updateGameplay(bool& gameOver)
	{
		SetMusicVolume(gameplayMusic, 0.5f);

		PlayMusicStream(gameplayMusic);

		updatePlayer(player, gameOver);
		playerCollision(player);

		updateAsteroid();
		AsteroidCollision(player);
	}

	void drawGameplay(bool& menuOn, bool& pauseOn)
	{
		ClearBackground(BLACK);

		DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

		UpdateMusicStream(gameplayMusic);

		drawPlayer(player);

		drawAsteroid();

		drawButton(pauseGame);

		drawPauseButtonTitle();

		if (isButtonPressed(pauseGame))
		{
			pauseOn = true;
			menuOn = false;
		}
	}

	void resetGame()
	{
		initPlayer(player);

		initAsteroid();

		projectileCount = 0;
	}

	void unloadGameplay()
	{
		UnloadTexture(background);

		UnloadMusicStream(gameplayMusic);

		unloadPlayer();

		unloadAsteroid();

		unloadProjectiles();
	}
}