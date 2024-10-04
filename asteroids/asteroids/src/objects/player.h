#pragma once

struct Player
{
	int posY;
	int posX;
	int width;
	int height;
};

extern Player player;

void initPlayer(Player& player);
