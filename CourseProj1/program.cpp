#include "Game.h"

Game* game = Game::Instance();


//Remove SDL2's "main" macro
//so that a regular "main" function
//can be used.
#undef main

int main()
{
	return game->CreateWindow(windowTitle, windowWidth, windowHeight);
}