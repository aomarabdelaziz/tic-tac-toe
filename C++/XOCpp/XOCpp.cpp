#include <iostream>
#include "Game.h"
int main()
{
	Game* g_Game = new Game();
	g_Game->startGame();

	delete g_Game;
}
