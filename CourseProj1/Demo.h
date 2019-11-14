#ifndef _DEMO_H
#define _DEMO_H

#include "Scene.h"
#include "Constants.h"
#include "ResourceManager.h"

class Demo : public Scene
{
	public:
		Demo();
		void Dispose();
		void Initialise();
	private:
		bool KeyDown(SDL_Keycode keycode);
		bool MouseDown(SDL_MouseButtonEvent mousebutton);
		bool Update();
		GameObject* obj;
		GameObject* obj2;
		float rSpeed = 5.0f;
		AXIS axis = AXIS::X;
};

#endif