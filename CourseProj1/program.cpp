#include "Game.h"

Game* game = Game::Instance();

int main(int argc, char** argv)
{
	return game->CreateWindow(windowTitle, windowWidth, windowHeight);
}