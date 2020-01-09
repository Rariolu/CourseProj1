#ifndef _GAME_H
#define _GAME_H

#include "SDLWindowManager.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "CollisionDemoScene.h"
//#include "ObjLoad.h"
#include "Temp_obj_loader.h"
#include "ModelTexture.h"
#include "QuadMShader.h"
#include "SkyboxShader.h"

class Game
{
	public:
		static Game* Instance();
		~Game();
		int CreateWindow(string windowTitle, float width, float height);
		void Dispose();

	private:
		Game();
		
		void ResourceSetup();
		void SetupMesh(string name, string objfile);
		void Run(string startScene);
		ResourceManager* resourceManager;
		SDLWindowManager* windowManager;
		static Game* instance;

};

#endif