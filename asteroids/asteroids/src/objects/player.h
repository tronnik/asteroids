#pragma once

#include "raylib.h"

struct Player 
{
    Vector2 position;
    Vector2 speed;
    Vector2 acceleration;
    Vector2 mousePosition;
    Vector2 direction;
    Vector2 directionNormalized;
    float maxSpeed;
    float width;
    float height;
    float angle;
    float ammoSpeed;
};

extern Player player;
extern Player ammo;

void initPlayer(Player& p);
void updatePlayer(Player& p);
void drawPlayer(Player& p);
void unloadTexture();






