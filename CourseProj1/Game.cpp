#include "Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
	resourceManager = ResourceManager::Instance();
	windowManager = nullptr;
}

Game::~Game()
{
	Dispose();
}

Game* Game::Instance()
{
	if (!instance)
	{
		return instance = new Game();
	}
	return instance;
}

int Game::CreateWindow(string windowTitle, float width, float height)
{
	bool initialised = SDLWindowManager::GenerateWindowManager(windowTitle, width, height, windowManager);
	if (!initialised)
	{
		return -1;
	}
	ResourceSetup();
	Run(collisionDemoScene);
	return 0;
}

void Game::Dispose()
{
	delete resourceManager;
}

void Game::ResourceSetup()
{
	//Add textures
	ModelTexture* texture1 = new ModelTexture(texture1File);
	resourceManager->AddModelTexture(texture1Name, texture1);

	ModelTexture* texture2 = new ModelTexture(texture2File);
	resourceManager->AddModelTexture(texture2Name, texture2);

	//Add meshes
	SetupMesh(cubeName, mesh1File);
	SetupMesh(mesh2Name, mesh2File);
	SetupMesh(ballMeshName, ballMeshFile);

	//Shaders
	QuadMShader* shader4 = new QuadMShader(quadMShaderFile);
	resourceManager->AddShader(shaderName, shader4);

	//Add scenes
	resourceManager->AddScene(collisionDemoScene, new CollisionDemoScene());
}

void Game::SetupMesh(string name, string objfile)
{
	//Mesh* mesh1 = nullptr;
	//if (LoadOBJ(objfile, mesh1))
	//{
	//	resourceManager->AddMesh(name, mesh1);
	//}
	OBJModel model(objfile);
	ObjIndexedModel imodel = model.ToIndexedModel();
	Mesh* mesh = Mesh::LoadModel(&imodel);
	if (mesh)
	{
		resourceManager->AddMesh(name, mesh);
	}
}

void Game::Run(string startScene)
{
	string nextScene = startScene;
	Scene* currentScene;
	while (currentScene = resourceManager->GetScene(nextScene))
	{
		currentScene->Initialise();
		nextScene = currentScene->Run();
		currentScene->Dispose();
	}
}