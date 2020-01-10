#ifndef _COLLISIONCUBE_H
#define _COLLISIONCUBE_H

#include "Constants.h"
#include "GameObject.h"
#include "BoxCollider.h"
#include "ProjectileGameObject.h"

//A gameobject which has a box collider
//attached.
class CollisionCube : public GameObject
{
	public:
		CollisionCube();
		BoxCollider* GetBoxCollider();
	private:
		BoxCollider* boxCollider;

};

#endif