#ifndef _COLLISIONDEMOSCENE_H
#define _COLLISIONDEMOSCENE_H

#include "Scene.h"

class CollisionDemoScene : public Scene
{
	public:
		CollisionDemoScene();
		void Dispose();
		void Initialise();
	private:
		bool KeyDown(SDL_Keycode keycode);
		bool MouseDown(SDL_MouseButtonEvent mousebutton);
		bool Update();
};

#endif