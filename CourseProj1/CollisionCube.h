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
	private:
		BoxCollider* boxCollider;

};

#endif