#pragma once

#include "raylib.h"
#include "player.h"

struct Projectile
{
    Vector2 position;
    Vector2 direction;
    float speed;
    bool isActive;
    float radius;
};

#define maxProjectiles 10000 

extern Projectile projectiles[maxProjectiles];
extern int projectileCount;

void fire(Player& p);
void updateProjectiles();
void drawProjectiles();




