#pragma once

#include "objects/player.h"
#include "objects/projectile.h"

namespace asteroids
{
	void initGameplay();

	void loadGameplay();

	bool checkCollsionAsteroidProjectile(Asteroid asteroid, Projectile projectile);

	void AsteroidCollision(Player& p);

	bool checkCollsionPlayerAsteroid(Player p, Asteroid asteroid);

	void playerCollision(Player& p);

	void updateGameplay(bool& gameOver);

	void drawGameplay(bool& menuOn, bool& pauseOn);

	void resetGame();

	void unloadGameplay();
}

