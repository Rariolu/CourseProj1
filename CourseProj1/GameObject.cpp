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
	
}

bool GameObject::CollidesWith(GameObject* other)
{
	//Return false if the other gameobject or this gameobject's
	//collider is null.
	if (!other || !collider)
	{
		return false;
	}

	//Return false if this gameobject or the other gameobject
	//is inactive.
	if (!(IsActive() && other->IsActive()))
	{
		return false;
	}

	//Return false if the other gameobject's collider is null.
	Collider* otherCollider = other->GetCollider();
	if (!otherCollider)
	{
		return false;
	}

	//Check for collisions between the two colliders.
	return collider->CollidesWith(otherCollider) || otherCollider->CollidesWith(collider);
}

Collider* GameObject::GetCollider()
{
	return collider;
}

bool GameObject::IsActive()
{
	return isActive;
}

void GameObject::Render()
{
	if (isActive && camera)
	{
		//Bind the shader
		shader->Bind();
		
		//Update the shader's uniform variables
		//according to the position, orientation, and scaling
		//of this object as well as the camera.
		shader->Update(this, camera);

		//Bind the texture
		texture->Bind();

		//Render the mesh
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

void GameObject::SetCollider(Collider* col)
{
	collider = col;
}