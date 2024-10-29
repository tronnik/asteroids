#include "asteroid.h"

#include <iostream>

#include "utils.h"
#include <cmath>

using namespace std;

Texture2D enemy;
Texture2D miniEnemy;

std::vector<Asteroid> asteroids;

Sound explosionSfx;
Sound pointsSfx;

void initAsteroid()
{
    asteroids.resize(maxAsteroids);

    for (int i = 0; i < maxAsteroids; i++)
    {
        int side = GetRandomValue(0, 3);

        switch (side)
        {
        case 0:
            asteroids[i].position = { static_cast<float>(screenWidthMin), static_cast<float>(GetRandomValue(screenHeightMin, screenHeight)) };
            break;
        case 1:
            asteroids[i].position = { static_cast<float>(screenWidth), static_cast<float>(GetRandomValue(screenHeightMin, screenHeight)) };
            break;
        case 2:
            asteroids[i].position = { static_cast<float>(GetRandomValue(screenWidthMin, screenWidth)), static_cast<float>(screenHeightMin) };
            break;
        case 3:
            asteroids[i].position = { static_cast<float>(GetRandomValue(screenWidthMin, screenWidth)), static_cast<float>(screenHeight) };
            break;
        }

        asteroids[i].speed = { static_cast<float>(rand() % 200), static_cast<float>(rand() % 200) };
        asteroids[i].direction = { asteroids[i].speed.x, asteroids[i].speed.y };
        asteroids[i].radius = 50.0f + static_cast<float>(rand() % 20);
        asteroids[i].isActive = true;
    }
}

void loadAsteroid()
{
    enemy = LoadTexture("res/asteroid-1.png");
    miniEnemy = LoadTexture("res/asteroid-2.png");

    shootSfx = LoadSound("res/shootSfx.mp3");
    explosionSfx = LoadSound("res/explosionSfx.mp3");
    pointsSfx = LoadSound("res/pointsSfx.mp3");
}

void updateAsteroid()
{
    for (int i = 0; i < static_cast<int>(asteroids.size()); i++)
    {
        asteroids[i].position.x += asteroids[i].speed.x * GetFrameTime();
        asteroids[i].position.y += asteroids[i].speed.y * GetFrameTime();

        if (asteroids[i].position.x < static_cast<float>(screenWidthMin))
            asteroids[i].position.x = static_cast<float>(screenWidth);

        if (asteroids[i].position.x > static_cast<float>(screenWidth))
            asteroids[i].position.x = static_cast<float>(screenWidthMin);

        if (asteroids[i].position.y < static_cast<float>(screenHeightMin))
            asteroids[i].position.y = static_cast<float>(screenHeight);

        if (asteroids[i].position.y > static_cast<float>(screenHeight))
            asteroids[i].position.y = static_cast<float>(screenHeightMin);
    }
}

bool checkCollision(Asteroid asteroid, Projectile projectile)
{
    float distX = asteroid.position.x - projectile.position.x;
    float distY = asteroid.position.y - projectile.position.y;
    float distance = sqrt((distX * distX) + (distY * distY));

    return distance <= asteroid.radius + projectile.radius;
}

void checkAsteroidCollisions(Player& p)
{
    for (int i = 0; i < static_cast<int>(asteroids.size()); i++)
    {
        if (asteroids[i].isActive)
        {
            for (int j = 0; j < projectileCount; j++)
            {
                if (projectiles[j].isActive)
                {
                    if (checkCollision(asteroids[i], projectiles[j]))
                    {
                        asteroids[i].isActive = false;
                        projectiles[j].isActive = false;
                        p.point += 10;

                        SetSoundVolume(explosionSfx, 0.3f);
                        PlaySound(explosionSfx);

                        SetSoundVolume(pointsSfx, 0.1f);
                        PlaySound(pointsSfx);
                    }
                }
            }
        }
    }
}

void drawAsteroid()
{
    for (int i = 0; i < static_cast<int>(asteroids.size()); i++)
    {
        if (asteroids[i].isActive)
        {
            DrawTextureEx(enemy, { asteroids[i].position.x ,  asteroids[i].position.y }, 0.0f, 2.0f, WHITE);

            for (int j = 0; j < projectileCount; j++)
            {
                if (checkCollision(asteroids[i], projectiles[j]))
                {
                    asteroids[i].isActive = false;


                    createNewASteroids();
                }
            }
        }
    }
}

void createNewASteroids()
{
    Asteroid newAsteroid;
    newAsteroid.position = { static_cast<float>(GetRandomValue(0, screenWidth), GetRandomValue(0, screenHeight)) };
    newAsteroid.direction = { static_cast<float>(GetRandomValue(-1, 1), GetRandomValue(-1, 1)) };
    newAsteroid.isActive = true;

    asteroids.push_back(newAsteroid);

    //Asteroid newAsteroid2;
    //newAsteroid2.position = { static_cast<float>(GetRandomValue(0, screenWidth), GetRandomValue(0, screenHeight)) };
    //newAsteroid2.direction = { static_cast<float>(GetRandomValue(-1, 1), GetRandomValue(-1, 1)) };
    //newAsteroid2.isActive = true;
    //
    //asteroids.push_back(newAsteroid2);
}

void unloadAsteroid()
{
    UnloadTexture(enemy);
    UnloadSound(pointsSfx);
    UnloadSound(explosionSfx);
}