#pragma once

#include "raylib.h"

struct Player 
{
    Vector2 position;
    Vector2 speed;
    Vector2 acceleration;
    float maxSpeed;
    float width;
    float height;
    float angle;
};

extern Player player;

void initPlayer(Player& p);
void updatePlayer(Player& p);
void drawPlayer(Player& p);






