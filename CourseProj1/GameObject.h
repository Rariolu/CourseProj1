#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Camera.h"
#include "Transform.h"
#include "ResourceManager.h"
#include "Collider.h"

class GameObject
{
	public:
		GameObject(string meshName, string shaderName, string textureName);
		GameObject(Mesh* mesh, AbstractShader* shader, ModelTexture* texture);
		~GameObject();

		//Detects a collision between two GameObjects
		//using their colliders.
		bool CollidesWith(GameObject* other);
		Collider* GetCollider();
		Transform* GetTransform();
		//Returns true if this GameObject is "active"
		//(meaning it is visible and can be collided with).
		bool IsActive();

		//Bind the relevant mesh, shader, and texture
		//in order to render this model to the screen.
		void Render(Camera* camera);
		void SetActive(bool active);
		virtual void SetPosition(Vec3 position);
		virtual void SetRotation(Vec3 rotation);
		virtual void SetScale(Vec3 scale);
	protected:
		void SetCollider(Collider* col);
	private:
		bool isActive = true;
		Collider* collider;
		Mesh* mesh;
		AbstractShader* shader;
		ModelTexture* texture;
		Transform* transform = new Transform();
		static ResourceManager* rescManager;
};

#endif