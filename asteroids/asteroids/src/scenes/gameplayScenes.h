#pragma once

namespace asteroids
{
	void initGameplay();

	void loadGameplay();

	void updateGameplay(bool& gameOver);

	void drawGameplay(bool& menuOn, bool& pauseOn);

	void resetGame();

	void unloadGameplay();
}

