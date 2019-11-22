#ifndef _PROJECTILEGAMEOBJECT_H
#define _PROJECTILEGAMEOBJECT_H

#include "GameObject.h"
#include "Constants.h"
#include "SphereCollider.h"

class ProjectileGameObject : public GameObject
{
	public:
		ProjectileGameObject();
		void SetDirection(Vec3 dir);
		void SetScale(float scale);
		void Update(float delta);
	private:
		Vec3 direction;
		Vec3* position;
		const float speed = 4.0f;
		SphereCollider* sphereCollider;
};

#endif