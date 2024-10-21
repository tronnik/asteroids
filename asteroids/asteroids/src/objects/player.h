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
    float radius;
    float angle;
    float ammoSpeed;
};

extern Player player;

void initPlayer(Player& p);
void updatePlayer(Player& p);
void drawPlayer(Player& p);
void unloadPlayer();






