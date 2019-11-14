#include "Demo.h"

Demo::Demo() : Scene()
{
	
}

void Demo::Dispose()
{
	Scene::Dispose();
}

void Demo::Initialise()
{
	Scene::Initialise();
	camera->SetPosition(Vec3(0, 0, -5.0f));
	ResourceManager* rManager = ResourceManager::Instance();
	obj = AddGameObject(mesh1Name, texture1Name, shaderName);
	obj2 = AddGameObject(mesh2Name, texture1Name, shaderName);
	obj2->SetPosition(Vec3(3.5f, -2.4f, 1.7f));
}

bool Demo::KeyDown(SDL_Keycode keycode)
{
	switch (keycode)
	{
		case SDLK_ESCAPE:
		{
			return false;
		}
		case SDLK_x:
		{
			axis = AXIS::X;
			break;
		}
		case SDLK_y:
		{
			axis = AXIS::Y;
			break;
		}
		case SDLK_z:
		{
			axis = AXIS::Z;
			break;
		}
		case SDLK_DOWN:
		{
			rSpeed = rSpeed - 0.5f > 0.0f ? rSpeed - 0.5f : 0.0f;
			break;
		}
		case SDLK_UP:
		{
			rSpeed += 0.5f;
			break;
		}
		case SDLK_w:
		{
			camera->Translate(AXIS::Z, rSpeed * DeltaTime());
			break;
		}
		case SDLK_a:
		{
			camera->Translate(AXIS::X, rSpeed * DeltaTime());
			break;
		}
		case SDLK_s:
		{
			camera->Translate(AXIS::Z, -rSpeed * DeltaTime());
			break;
		}
		case SDLK_d:
		{
			camera->Translate(AXIS::X, -rSpeed * DeltaTime());
			break;
		}
		case SDLK_b:
		{
			obj->SetActive(!obj->IsActive());
			break;
		}
		default:
		{
			break;
		}
	}
	return true;
}

bool Demo::MouseDown(SDL_MouseButtonEvent mousebutton)
{
	return true;
}

bool Demo::Update()
{
	float d = DeltaTime();
	float r = rSpeed * d;
	obj->GetTransform()->Rotate(axis, r);
	return true;
}