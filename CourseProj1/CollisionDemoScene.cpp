#include "CollisionDemoScene.h"

CollisionDemoScene::CollisionDemoScene()
{

}

void CollisionDemoScene::Dispose()
{
	Scene::Dispose();
}

void CollisionDemoScene::Initialise()
{
	Scene::Initialise();
	camera->SetPosition(Vec3(0, 0, -5.0f));
	cube1 = new CollisionCube();
	cube2 = new CollisionCube();
	AddGameObject(cube1);
	AddGameObject(cube2);
}

bool CollisionDemoScene::KeyDown(SDL_Keycode keycode)
{
	WASD(keycode);
	switch (keycode)
	{
		case SDLK_ESCAPE:
		{
			return false;
		}
		case SDLK_SPACE:
		{
			std::cout << "Collision: " << cube1->CollidesWith(cube2) << ";" << std::endl;
			break;
		}
	}
	return true;
}

bool CollisionDemoScene::MouseDown(SDL_MouseButtonEvent mouseButton)
{
	return true;
}

bool CollisionDemoScene::Update()
{
	
	return true;
}

void CollisionDemoScene::WASD(SDL_Keycode keycode)
{
	switch (keycode)
	{
		case SDLK_w:
		{
			cube1->GetTransform()->Translate(AXIS::Z, speed* DeltaTime());
			break;
		}
		case SDLK_a:
		{
			cube1->GetTransform()->Translate(AXIS::X, (speed)*DeltaTime());
			break;
		}
		case SDLK_s:
		{
			cube1->GetTransform()->Translate(AXIS::Z, (-speed)*DeltaTime());
			break;
		}
		case SDLK_d:
		{
			cube1->GetTransform()->Translate(AXIS::X, (-speed)*DeltaTime());
			break;
		}
	}
}