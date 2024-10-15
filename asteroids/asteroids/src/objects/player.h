#pragma once

struct Player
{
    float posY;
    float posX;
    float width;
    float height;
    float actualSpeed;
    float maxSpeed;
};

extern Player player;  
extern Player mousePlayer;

void initPlayer(Player& player);
void initPos();

void updateMousePos(Player& mousePlayer);
void movePlayer(Player& player, Player& mousePlayer);

void drawPlayer(Player& player, Player& mousePlayer);



