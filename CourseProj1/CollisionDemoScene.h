#ifndef _COLLISIONDEMOSCENE_H
#define _COLLISIONDEMOSCENE_H

#include "Scene.h"
#include "CollisionCube.h"
#include "CollisionSphere.h"
#include <iostream>

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
		void WASD(SDL_Keycode keycode);
		CollisionCube* cube1;
		CollisionCube* cube2;
		CollisionSphere* sphere1;
		CollisionSphere* sphere2;
		float speed = 50.0f;
};

#endif