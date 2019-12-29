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

		//Move the camera depending on which of the
		//W, A, S, or D keys are pressed.
		void WASD(SDL_Keycode keycode);

		void Fire();
		void DestroyProjectile(ProjectileGameObject* ball);
		void DestroyCube(CollisionCube* cube);

		void CreateCube();
		//CollisionCube* cube1;
		float speed = 50.0f;
		vector<ProjectileGameObject*> projectiles;
		vector<CollisionCube*> cubes;
		unsigned int shotSource;
		unsigned int bluesiSource;
};

#endif