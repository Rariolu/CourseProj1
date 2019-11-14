#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Camera.h"
#include "Transform.h"
#include "ResourceManager.h"

class GameObject
{
	public:
		GameObject(string meshName, string shaderName, string textureName);
		GameObject(Mesh* mesh, AbstractShader* shader, ModelTexture* texture);
		~GameObject();
		Transform* GetTransform();
		bool IsActive();
		void Render(Camera* camera);
		void SetActive(bool active);
		void SetPosition(Vec3 position);
		void SetRotation(Vec3 rotation);
		void SetScale(Vec3 scale);
	private:
		bool isActive = true;
		Mesh* mesh;
		AbstractShader* shader;
		ModelTexture* texture;
		Transform* transform = new Transform();
		static ResourceManager* rescManager;
};

#endif