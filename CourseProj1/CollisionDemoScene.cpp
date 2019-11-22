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
	//cube2 = new CollisionCube();
	//sphere1 = new CollisionSphere();
	//sphere2 = new CollisionSphere();
	AddGameObject(cube1);
	//AddGameObject(cube2);
	//AddGameObject(sphere1);
	//AddGameObject(sphere2);
}

bool CollisionDemoScene::KeyDown(SDL_Keycode keycode)
{
	//WASD(keycode);
	switch (keycode)
	{
		case SDLK_ESCAPE:
		{
			return false;
		}
		case SDLK_SPACE:
		{
			Fire();
			//std::cout << "C1->C2 Collision: " << sphere1->CollidesWith(sphere2) << ";" << std::endl;
			//std::cout << "C2->C1 Collision: " << sphere2->CollidesWith(sphere1) << ";" << std::endl;
			//std::cout << "C1->C2 Collision: " << cube1->CollidesWith(cube2) << ";" << std::endl;
			//std::cout << "C2->C1 Collision: " << cube2->CollidesWith(cube1) << ";" << std::endl;
			break;
		}
	}
	return true;
}

void CollisionDemoScene::Fire()
{
	ProjectileGameObject* ball = new ProjectileGameObject();
	Vec3* forward = camera->GetForward();
	const float d = 0.5f;
	Vec3 pos = (*camera->GetPosition()) + ((*forward) * d);
	ball->SetPosition(pos);
	ball->SetDirection(*forward);
	AddGameObject(ball);
	projectiles.push_back(ball);
}

bool CollisionDemoScene::MouseDown(SDL_MouseButtonEvent mouseButton)
{
	return true;
}

bool CollisionDemoScene::Update()
{
	for (ProjectileGameObject* ball : projectiles)
	{
		ball->Update(DeltaTime());
		if (ball->CollidesWith(cube1))
		{
			//return false;
		}
	}
	return true;
}

void CollisionDemoScene::WASD(SDL_Keycode keycode)
{
	switch (keycode)
	{
		//case SDLK_w:
		//{
		//	sphere1->GetTransform()->Translate(AXIS::Z, speed* DeltaTime());
		//	//cube1->GetTransform()->Translate(AXIS::Z, speed* DeltaTime());
		//	break;
		//}
		//case SDLK_a:
		//{
		//	sphere1->GetTransform()->Translate(AXIS::X, (speed)*DeltaTime());
		//	//cube1->GetTransform()->Translate(AXIS::X, (speed)*DeltaTime());
		//	break;
		//}
		//case SDLK_s:
		//{
		//	sphere1->GetTransform()->Translate(AXIS::Z, (-speed)*DeltaTime());
		//	//cube1->GetTransform()->Translate(AXIS::Z, (-speed)*DeltaTime());
		//	break;
		//}
		//case SDLK_d:
		//{
		//	sphere1->GetTransform()->Translate(AXIS::X, (-speed)*DeltaTime());
		//	//cube1->GetTransform()->Translate(AXIS::X, (-speed)*DeltaTime());
		//	break;
		//}
	}
}