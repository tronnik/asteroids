#pragma once

#include "raylib.h"
#include "player.h"

struct Projectile 
{
    Vector2 position;
    Vector2 direction;
    float speed;
    bool active; 
};

#define MAX_PROJECTILES 10000 

extern Projectile projectiles[MAX_PROJECTILES];
extern int projectileCount;

void shoot(Player& p);
void updateProjectiles();
void drawProjectiles();


