#pragma once

#include "raylib.h"

#include "projectile.h"
#include <vector>

struct Asteroid
{
    Vector2 position;
    Vector2 speed;
    Vector2 direction;
    float radius;
    bool isActive;
};

const int maxAsteroids = 10;
extern std::vector<Asteroid> asteroids;

extern Sound explosionSfx;
extern Sound pointsSfx;

void initAsteroid();
void loadAsteroid();
void updateAsteroid();
bool checkCollision(Asteroid asteroid, Projectile projectile);
void checkAsteroidCollisions(Player& p);
void drawAsteroid();
void createNewASteroids();
void unloadAsteroid();


