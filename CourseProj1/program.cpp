#include "Game.h"

Game* game = Game::Instance();

#undef main

int main()
{
	return game->CreateWindow(windowTitle, windowWidth, windowHeight);
}