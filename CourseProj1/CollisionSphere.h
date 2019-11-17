#ifndef _COLLISIONSPHERE_H
#define _COLLISIONSPHERE_H

#include "GameObject.h"
#include "Constants.h"
#include "SphereCollider.h"

class CollisionSphere : public GameObject
{
	public:
		CollisionSphere();
		~CollisionSphere();
		SphereCollider* GetCollider();
		bool CollidesWith(CollisionSphere* other);
	private:
		SphereCollider* sphereCollider;
};

#endif