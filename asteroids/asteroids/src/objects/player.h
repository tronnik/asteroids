#pragma once

#include "raylib.h"

struct Asteroid;

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
    bool isActive;
    int life;
    float respawnTime;
};

extern Player player;

void initPlayer(Player& p);
void updatePlayer(Player& p);
bool checkCollsion(Player p, Asteroid asteroid);
void checkPlayerCollisions(Player& p);
void drawPlayer(Player& p);
void drawLives(Player& p);
void unloadPlayer();




