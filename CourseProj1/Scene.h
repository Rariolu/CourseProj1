#ifndef _SCENE_H
#define _SCENE_H

#include "SDL.h"
#include "Aliases.h"
#include "GameObject.h"
#include "SDLWindowManager.h"

class Scene
{
	public:
		Scene();
		~Scene();
		virtual void Dispose();
		virtual void Initialise();
		string Run();
	protected:
		GameObject* AddGameObject(string meshName, string textureName, string shaderName);
		GameObject* AddGameObject(Mesh* mesh, ModelTexture* texture, AbstractShader* shader);
		void AddGameObject(GameObject* gameObject);
		float DeltaTime();
		void GenerateDeltaTime();
		void SetNextScene(string scenename);
		Camera* camera;
	private:
		bool GetInput();
		virtual bool KeyDown(SDL_Keycode keycode) = 0;
		virtual bool MouseDown(SDL_MouseButtonEvent mousebutton) = 0;
		void Render();
		virtual bool Update() = 0;
		float deltaTime = 0;
		bool initialised = false;
		vector<GameObject*> gameObjects;
		string nextScene = "";
		float previousTimeStamp = 0;
};

#endif