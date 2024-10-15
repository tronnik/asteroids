#pragma once

struct Player
{
    float posY;
    float posX;
    float width;
    float height;
};

extern Player player;  
extern Player mousePlayer;

void initPlayer(Player& player);
void updateMousePos(Player& mousePlayer);
void drawPlayer(Player& player, Player& mousePlayer);


