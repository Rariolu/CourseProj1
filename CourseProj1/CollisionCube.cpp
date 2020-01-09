#include "CollisionCube.h"

CollisionCube::CollisionCube() : GameObject(RandomNumber(0,1) == 0 ? cubeName : pyramidName,shaderName,texture1Name)
{
	boxCollider = new BoxCollider(Vec3(2, 2, 2), /*GetTransform()->*/GetPosition());
	SetCollider(boxCollider);
}

BoxCollider* CollisionCube::GetBoxCollider()
{
	return boxCollider;
}

//bool CollisionCube::CollidesWith(CollisionCube* cube)
//{
//	if (!(IsActive() && cube->IsActive()))
//	{
//		return false;
//	}
//	return boxCollider->CollidesWith(cube->GetBoxCollider());
//}