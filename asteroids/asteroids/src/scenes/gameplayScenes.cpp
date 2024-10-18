#include "gameplayScenes.h"
#include "player.h"

void initGameplay()
{
	initPlayer(player);
}

void updateGameplay()
{
	updatePlayer(player);
}

void drawGameplay()
{
	drawPlayer(player);
}
