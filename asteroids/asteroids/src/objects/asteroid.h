#pragma once

#include <vector>

#include "raylib.h"

namespace asteroids
{
    enum class AsteroidSize
    {
        LARGE,
        MEDIUM,
        SMALL
    };

    struct Asteroid
    {
        Vector2 position;
        Vector2 speed;
        Vector2 direction;
        AsteroidSize size;
        float radius;
        bool isActive;
    };

    const int maxAsteroids = 5;
    extern std::vector<Asteroid> asteroids;

    extern Sound explosionSfx;
    extern Sound pointsSfx;

    void initAsteroid();
    void loadAsteroid();
    void updateAsteroid();
    void createNewAsteroids(AsteroidSize size, Vector2 position, Vector2 direction);
    void spawnAsteroids();
    void drawAsteroid();
    void unloadAsteroid();
}
