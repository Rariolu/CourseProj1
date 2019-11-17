#ifndef _COLLISIONCUBE_H
#define _COLLISIONCUBE_H

#include "Constants.h"
#include "GameObject.h"
#include "BoxCollider.h"
#include "ProjectileGameObject.h"

class CollisionCube : public GameObject
{
	public:
		CollisionCube();
		BoxCollider* GetBoxCollider();
		bool CollidesWith(CollisionCube* cube);
	private:
		BoxCollider* boxCollider;

};

#endif