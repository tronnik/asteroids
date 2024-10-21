#pragma once

#include "raylib.h"

struct Asteroid
{
    Vector2 position;
    Vector2 speed;
    Vector2 direction;
    float radius;
};

const int maxAsteroids = 5;  
extern Asteroid asteroids[maxAsteroids];

void initAsteroid();
void updateAsteroid();
void drawAsteroid();
void unloadAsteroid();

