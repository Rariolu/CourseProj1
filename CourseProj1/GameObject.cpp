#include "GameObject.h"

ResourceManager* GameObject::rescManager = ResourceManager::Instance();

GameObject::GameObject(string meshName, string shaderName, string textureName) : GameObject(rescManager->GetMesh(meshName),rescManager->GetShader(shaderName),rescManager->GetModelTexture(textureName))
{

}

GameObject::GameObject(Mesh* mesh, AbstractShader* shader, ModelTexture* texture)
{
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
}

GameObject::~GameObject()
{
	//delete transform;
}

bool GameObject::CollidesWith(GameObject* other)
{
	if (!other || !collider)
	{
		return false;
	}
	if (!(IsActive() && other->IsActive()))
	{
		return false;
	}
	Collider* otherCollider = other->GetCollider();
	if (!otherCollider)
	{
		return false;
	}
	return collider->CollidesWith(otherCollider) || otherCollider->CollidesWith(collider);
}

Collider* GameObject::GetCollider()
{
	return collider;
}

//Transform* GameObject::GetTransform()
//{
//	return transform;
//}

bool GameObject::IsActive()
{
	return isActive;
}

void GameObject::Render()
{
	if (isActive && camera)
	{
		shader->Bind();
		shader->Update(this, camera);
		texture->Bind();
		mesh->Render();
	}
}

void GameObject::SetActive(bool active)
{
	isActive = active;
}

void GameObject::SetCamera(Camera* cam)
{
	camera = cam;
}
//
//void GameObject::SetPosition(Vec3 position)
//{
//	transform->SetPosition(position);
//}
//
//void GameObject::SetRotation(Vec3 rotation)
//{
//	transform->SetRotation(rotation);
//}
//
//void GameObject::SetScale(Vec3 scale)
//{
//	transform->SetScale(scale);
//}

void GameObject::SetCollider(Collider* col)
{
	collider = col;
}