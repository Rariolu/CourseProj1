#include "CollisionCube.h"

CollisionCube::CollisionCube() : GameObject(RandomNumber(0,1) == 0 ? cubeName : pyramidName,shaderName,texture1Name)
{
	boxCollider = new BoxCollider(Vec3(2, 2, 2), GetPosition());
	SetCollider(boxCollider);
}

BoxCollider* CollisionCube::GetBoxCollider()
{
	return boxCollider;
}