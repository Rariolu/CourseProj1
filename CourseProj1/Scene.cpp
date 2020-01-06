#include "Scene.h"

Scene::Scene()
{
	SDLWindowManager* sdlwindowmanager = SDLWindowManager::Instance();
	camera = new Camera(70.0f, sdlwindowmanager->GetScreenWidth() / sdlwindowmanager->GetScreenHeight(), 0.01f, 1000.0f);
	audioDevice = AudioDevice::Instance();
}

Scene::~Scene()
{
	delete camera;
	Dispose();
}

void Scene::Dispose()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
	gameObjects.clear();
	nextScene = "";
}

void Scene::Initialise()
{
	initialised = true;
	audioDevice->SetListener(camera);
}

string Scene::Run()
{
	if (initialised)
	{
		bool loop = true;
		while (loop && nextScene == "")
		{
			GenerateDeltaTime();
			bool input = GetInput();
			bool update = Update();
			Render();
			loop = input && update;
		}
	}
	return nextScene;
}

GameObject* Scene::AddGameObject(string meshName, string textureName, string shaderName)
{
	ResourceManager* rMan = ResourceManager::Instance();
	return AddGameObject(rMan->GetMesh(meshName), rMan->GetModelTexture(textureName), rMan->GetShader(shaderName));
}

GameObject* Scene::AddGameObject(Mesh* mesh, ModelTexture* texture, AbstractShader* shader)
{
	GameObject* gameObject = new GameObject(mesh, shader, texture);
	AddGameObject(gameObject);
	return gameObject;
}

void Scene::AddGameObject(GameObject* gameObject)
{
	gameObject->SetCamera(camera);
	gameObjects.push_back(gameObject);
}

float Scene::DeltaTime()
{
	return deltaTime;
}

void Scene::GenerateDeltaTime()
{
	float currentTime = (float)SDL_GetTicks() / 1000.0f;
	float milliseconds = (currentTime - previousTimeStamp);
	previousTimeStamp = currentTime;
	deltaTime = milliseconds;
}

void Scene::RemoveGameObject(GameObject* gameObject)
{
	if (gameObjects.size() > 0)
	{
		for (vector<GameObject*>::iterator i = gameObjects.begin(); i < gameObjects.end(); i++)
		{
			if (gameObject == (*i))
			{
				gameObjects.erase(i);
				break;
			}
		}
	}
}

void Scene::SetNextScene(string scenename)
{
	nextScene = scenename;
}

void Scene::SetSkyBox(SkyBox* _skybox)
{
	skybox = _skybox;
}

bool Scene::GetInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
		{
			return false;
		}
		case SDL_KEYDOWN:
		{
			SDL_Keycode keycode = event.key.keysym.sym;
			if (!KeyDown(keycode))
			{
				return false;
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			SDL_MouseButtonEvent mousebutton = event.button;
			if (!MouseDown(mousebutton))
			{
				return false;
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
	return true;
}

void Scene::Render()
{
	SDLWindowManager* wnd = SDLWindowManager::Instance();
	wnd->ClearDisplay(0.0f, 0.0f, 0.0f, 1.0f);
	for (GameObject* go : gameObjects)
	{
		if (go->IsActive())
		{
			go->Render();
		}
	}
	if (skybox)
	{
		skybox->Render();
	}
	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();
	wnd->SwapBuffer();
}