#ifndef _SCENE_H
#define _SCENE_H

#include "SDL.h"
#include "Aliases.h"
#include "GameObject.h"
#include "SDLWindowManager.h"
#include "AudioDevice.h"

class Scene
{
	public:
		Scene();
		~Scene();
		virtual void Dispose();
		virtual void Initialise();
		
		//Begin the game loop of this scene
		//and iterate until the next scene
		//is designated or a quit event is
		//triggered.
		string Run();
	protected:
		//Create an instance of "GameObject" (using the name of a mesh, texture, and shader)
		//and add it to the list of gameobjects which get renderered in the game loop.
		GameObject* AddGameObject(string meshName, string textureName, string shaderName);

		//Create an instance of "GameObject" (using a mesh, texture, and shader)
		//and add it to the list of gameobjects which get renderered in the game loop.
		GameObject* AddGameObject(Mesh* mesh, ModelTexture* texture, AbstractShader* shader);
		
		//Add a given gameobject to the list of gameobjects which get
		//renderered in the game loop.
		void AddGameObject(GameObject* gameObject);

		//Return the quantity of seconds that have passed between the previous frame and
		//the current one.
		float DeltaTime();

		//Calculate the quantity of seconds that have passed between the previous
		//frame and the current one.
		void GenerateDeltaTime();

		void RemoveGameObject(GameObject* gameObject);

		//Designate the next scene to be loaded.
		void SetNextScene(string scenename);

		//The camera that's used to render the gameobjects
		//from a particular perspective.
		Camera* camera;

		AudioDevice* audioDevice;
	private:

		//Process the user's input and return true if
		//the input determines that the scene loop should
		//continue (and return false if it shouldn't).
		bool GetInput();

		//Process a key down event and return true if
		//the input determines that the scene loop should
		//continue (and return false if it shouldn't).
		virtual bool KeyDown(SDL_Keycode keycode) = 0;

		//Process a mouse event and return true if
		//the input determines that the scene loop should
		//continue (and return false if it shouldn't).
		virtual bool MouseDown(SDL_MouseButtonEvent mousebutton) = 0;

		//Iterate through all the gameobjects and render them.
		void Render();

		//A vague method intended to be used to update the state
		//of game objects and return true if the scene loop should
		//continue (and return false if it shouldn't).
		virtual bool Update() = 0;

		//The quantity of seconds that have passed between the previous frame and
		//the current one.
		float deltaTime = 0;

		//A value which is true if the "Initialise" method has been called
		//(and is false if it hasn't).
		bool initialised = false;

		//The list of gameobjects to be rendered.
		vector<GameObject*> gameObjects;

		//The name of the next scene to be loaded.
		string nextScene = "";

		//The time stamp of the previous frame.
		float previousTimeStamp = 0;
};

#endif