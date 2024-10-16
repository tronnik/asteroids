#include "gameplayScenes.h"
#include "player.h"

void initGameplay()
{
	initPlayer(player);
	initPos();
}

void updateGameplay()
{
	updateMousePos(mousePlayer);
	movePlayer(player,mousePlayer);
}

void drawGameplay()
{
	drawPlayer(player, mousePlayer);
}
