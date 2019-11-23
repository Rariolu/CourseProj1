#include "ProjectileGameObject.h"

ProjectileGameObject::ProjectileGameObject() : GameObject(ballMeshName, shaderName, texture2Name)
{
	position = /*GetTransform()->*/GetPosition();
	const float ballScale = 0.05f;
	SetScale(ballScale);
}

void ProjectileGameObject::SetDirection(Vec3 dir)
{
	direction = dir;
}

void ProjectileGameObject::SetScale(float scale)
{
	GameObject::SetScale(Vec3(scale, scale, scale));
	if (sphereCollider)
	{
		delete sphereCollider;
	}
	sphereCollider = new SphereCollider(position, scale);
	SetCollider(sphereCollider);
}

void ProjectileGameObject::Update(float delta)
{
	SetPosition((*position) + (direction * (speed * delta)));
}