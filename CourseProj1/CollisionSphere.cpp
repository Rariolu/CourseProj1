#include "CollisionSphere.h"

CollisionSphere::CollisionSphere() : GameObject(ballMeshName,shaderName,texture2Name)
{
	sphereCollider = new SphereCollider(GetTransform()->GetPosition(), 1.0f);
}

CollisionSphere::~CollisionSphere()
{

}

SphereCollider* CollisionSphere::GetCollider()
{
	return sphereCollider;
}

bool CollisionSphere::CollidesWith(CollisionSphere* other)
{
	if (!(IsActive() && other->IsActive()))
	{
		return false;
	}
	return sphereCollider->CollidesWith(other->GetCollider());
}