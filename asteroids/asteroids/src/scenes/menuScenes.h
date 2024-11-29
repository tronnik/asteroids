#pragma once

namespace asteroids
{
	void initMenu();

	void loadMenu();

	void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn);

	void drawConstrols(bool& menuOn, bool& controlsOn);

	void drawCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2);

	void drawSecondCredits(bool& menuOn, bool& creditsOn, bool& creditsOn2);

	void drawBackToMenu(bool& boolTrue, bool& boolFalse);

	void drawPause(bool& menuOn, bool& pauseOn);

	void drawGameOver(bool& menuOn, bool& gameOver, int playerScore);

	void unloadMenu();
}


