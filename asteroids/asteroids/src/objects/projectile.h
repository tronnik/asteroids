#pragma once

#include "raylib.h"

#include "objects/player.h"

namespace asteroids
{
    struct Projectile
    {
        Vector2 position;
        Vector2 direction;
        float speed;
        bool isActive;
        float radius;
    };

    const int maxProjectiles = 10000;

    extern Projectile projectiles[maxProjectiles];
    extern int projectileCount;
    extern Sound shootSfx;

    void initProjectiles();
    void fire(Player& p);
    void updateProjectiles();
    void drawProjectiles();
    void unloadProjectiles();
}