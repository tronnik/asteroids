#pragma once

#include "raylib.h"

#include "projectile.h"
#include <vector>

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
        float radius;
        bool isActive;
        AsteroidSize size;
    };

    const int maxAsteroids = 20;
    extern std::vector<Asteroid> asteroids;

    extern Sound explosionSfx;
    extern Sound pointsSfx;

    void initAsteroid();
    void loadAsteroid();
    void updateAsteroid();
    bool checkCollision(Asteroid asteroid, Projectile projectile);
    void checkAsteroidCollisions(Player& p);
    void createNewAsteroids(AsteroidSize size, Vector2 position, Vector2 direction);
    void drawAsteroid();
    void unloadAsteroid();
}