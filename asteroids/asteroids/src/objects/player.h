#pragma once

#include "raylib.h"

#include "scenes/menuScenes.h"

namespace asteroids
{
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
        int point;
        float invensible;
    };

    extern Player player;
    extern Sound loseSfx;
    extern Sound boostSfx;

    void initPlayer(Player& p);
    void loadPlayer();
    void updatePlayer(Player& p, bool& gameOver);
    bool checkCollsion(Player p, Asteroid asteroid);
    void checkPlayerCollisions(Player& p);
    void drawPlayer(Player& p);
    void unloadPlayer();
}




