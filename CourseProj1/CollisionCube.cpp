#include "CollisionCube.h"

CollisionCube::CollisionCube() : GameObject(cubeName,shaderName,texture1Name)
{
	boxCollider = new BoxCollider(Vec3(1, 1, 1), GetTransform()->GetPosition());
}

BoxCollider* CollisionCube::GetBoxCollider()
{
	return boxCollider;
}

bool CollisionCube::CollidesWith(CollisionCube* cube)
{
	return boxCollider->CollidesWith(cube->GetBoxCollider());
}