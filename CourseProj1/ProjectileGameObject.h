#ifndef _PROJECTILEGAMEOBJECT_H
#define _PROJECTILEGAMEOBJECT_H

#include "GameObject.h"
#include "Constants.h"
#include "SphereCollider.h"

class ProjectileGameObject : public GameObject
{
	public:
		ProjectileGameObject();

		//Set the direction vector that the ball moves in.
		void SetDirection(Vec3 dir);

		void SetScale(float scale);

		//Move the ball in its given direction according
		//to the amount of time that has passed since the
		//last frame.
		void Update(float delta);
	private:
		Vec3 direction;
		Vec3* position;
		const float speed = 4.0f;
		SphereCollider* sphereCollider;
};

#endif