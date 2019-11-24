#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Camera.h"
#include "Transform.h"
#include "ResourceManager.h"
#include "Collider.h"

class GameObject : public Transform
{
	public:
		GameObject(string meshName, string shaderName, string textureName);
		GameObject(Mesh* mesh, AbstractShader* shader, ModelTexture* texture);
		~GameObject();

		//Detects a collision between two GameObjects
		//using their colliders.
		bool CollidesWith(GameObject* other);

		//Get the collider that's attached to this gameobject.
		Collider* GetCollider();

		//Returns true if this GameObject is "active"
		//(meaning it is visible and can be collided with).
		bool IsActive();

		//Bind the relevant mesh, shader, and texture
		//in order to render this model to the screen.
		void Render();
		
		//Set the active state of this gameobject
		//(when it's active, it is rendered and
		//can be collided with).
		void SetActive(bool active);

		//Set the camera that's used to render this gameobject.
		void SetCamera(Camera* cam);
	protected:

		//Set the collider that's used to determine
		//collisions for this gameobject.
		void SetCollider(Collider* col);
	private:
		Camera* camera;
		bool isActive = true;
		Collider* collider;
		Mesh* mesh;
		AbstractShader* shader;
		ModelTexture* texture;
		//Transform* transform = new Transform();
		static ResourceManager* rescManager;
};

#endif