#pragma once

#include "raylib.h"
#include "projectile.h"

struct Asteroid
{
    Vector2 position;
    Vector2 speed;
    Vector2 direction;
    float radius;
    bool isActive;
};

const int maxAsteroids = 20;
extern Asteroid asteroids[maxAsteroids];

void initAsteroid();
void updateAsteroid();
bool checkCollsion(Asteroid asteroid, Projectile projectiles);
void checkAsteroidCollisions();
void regenerateAsteroid();
void drawAsteroid();
void unloadAsteroid();

