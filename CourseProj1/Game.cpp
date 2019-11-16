#include "Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
	resourceManager = ResourceManager::Instance();
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
	//Run(demoScene);
	Run(projectileScene);
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
	OriginalShader* shader1 = new OriginalShader(shaderFile);
	//resourceManager->AddShader(shaderName, shader1);
	
	DoubleUniformShader* shader2 = new DoubleUniformShader(alternateShaderFile);
	//resourceManager->AddShader(shaderName, shader2);

	QuadrupleUniformShader* shader3 = new QuadrupleUniformShader(alternateShaderFile2);
	resourceManager->AddShader(shaderName, shader3);

	//Add scenes
	resourceManager->AddScene(demoScene, new Demo());
	resourceManager->AddScene(projectileScene, new ProjectileScene());
}

void Game::SetupMesh(string name, string objfile)
{
	//if (LoadOBJ(mesh1File, mesh1))
	//{
	//	resourceManager->AddMesh(mesh1Name, mesh1);
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