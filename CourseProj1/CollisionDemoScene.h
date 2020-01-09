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

		//Create a collision cube at a random location and
		//add it to the list of gameobjects that are rendered.
		void CreateCube();

		//Remove the given cube from the collection of 
		//collision cubes.
		void DestroyCube(CollisionCube* cube);

		//Remove the given projectile from the collection
		//of projectiles.
		void DestroyProjectile(ProjectileGameObject* ball);
		
		//Instantiate a "ProjectileGameObject" object
		//and add it to the list of gameobjects that
		//are rendered.
		void Fire();

		//Process a key-down event (move the camera and fire
		//projectiles).
		bool KeyDown(SDL_Keycode keycode);

		//Process a mouse event (doesn't do anything in this implementation).
		bool MouseDown(SDL_MouseButtonEvent mousebutton);

		//Update the scene so that projectiles move and
		//collisions are checked.
		bool Update();

		//Move the camera depending on which of the
		//W, A, S, or D keys are pressed.
		void WASD(SDL_Keycode keycode);

		unsigned int bluesiSource;
		vector<CollisionCube*> cubes;
		vector<ProjectileGameObject*> projectiles;
		unsigned int shotSource;
		float speed = 50.0f;
};

#endif