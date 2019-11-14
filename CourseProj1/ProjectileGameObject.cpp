#include "ProjectileGameObject.h"

ProjectileGameObject::ProjectileGameObject() : GameObject(ballMeshName, shaderName, texture2Name)
{
	position = GetTransform()->GetPosition();
	const float ballScale = 0.05f;
	SetScale(Vec3(ballScale, ballScale, ballScale));
}

void ProjectileGameObject::SetDirection(Vec3 dir)
{
	direction = dir;
}

void ProjectileGameObject::Update(float delta)
{
	SetPosition((*position) + (direction * (speed * delta)));
}