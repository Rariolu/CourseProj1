#include "CollisionDemoScene.h"

CollisionDemoScene::CollisionDemoScene()
{

}

void CollisionDemoScene::Dispose()
{
	Scene::Dispose();
	audioDevice->StopSound(bluesiSource);
}

void CollisionDemoScene::Initialise()
{
	Scene::Initialise();
	camera->SetPosition(Vec3(0, 0, -5.0f));
	//cube1 = new CollisionCube();
	//AddGameObject(cube1);
	shotSource = audioDevice->LoadSound("..\\Resources\\EnemyShot2.wav");
	bluesiSource = audioDevice->LoadSound("..\\Resources\\Bluesi.wav");
	audioDevice->PlaySound(bluesiSource);
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
			Fire();
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

void CollisionDemoScene::DestroyProjectile(ProjectileGameObject* ball)
{
	if (projectiles.size() > 0)
	{
		for (vector<ProjectileGameObject*>::iterator i = projectiles.begin(); i < projectiles.end(); i++)
		{
			if (ball == (*i))
			{
				RemoveGameObject(ball);
				projectiles.erase(i);
				break;
			}
		}
	}
}

void CollisionDemoScene::DestroyCube(CollisionCube* cube)
{
	if (cubes.size() > 0)
	{
		for (vector<CollisionCube*>::iterator i = cubes.begin(); i < cubes.end(); i++)
		{
			if (cube == (*i))
			{
				RemoveGameObject(cube);
				cubes.erase(i);
				break;
			}
		}
	}
}

bool CollisionDemoScene::MouseDown(SDL_MouseButtonEvent mouseButton)
{
	return true;
}

bool CollisionDemoScene::Update()
{
	vector<ProjectileGameObject*> destroyedBalls;
	vector<CollisionCube*> destroyedCubes;
	for (ProjectileGameObject* ball : projectiles)
	{
		ball->Update(DeltaTime());
		for (CollisionCube* cube : cubes)
		{
			if (ball->CollidesWith(cube))
			{
				cube->SetActive(false);
				//RemoveGameObject(cube);
				destroyedCubes.push_back(cube);
				//RemoveGameObject(ball);
				destroyedBalls.push_back(ball);
				audioDevice->PlaySound(shotSource, *ball->GetPosition());
			}
		}
	}
	for (ProjectileGameObject* ball : destroyedBalls)
	{
		DestroyProjectile(ball);
	}
	for (CollisionCube* cube : destroyedCubes)
	{
		DestroyCube(cube);
	}
	if (RandomNumber(0, 150) == 0)
	{
		CreateCube();
	}
	return true;
}

void CollisionDemoScene::CreateCube()
{
	CollisionCube* cube = new CollisionCube();
	cube->SetPosition(RandomNumber(-5, 5), 0, RandomNumber(8, 12));
	cubes.push_back(cube);
	AddGameObject(cube);
}

void CollisionDemoScene::WASD(SDL_Keycode keycode)
{
	float dts = DeltaTime()* speed;
	switch (keycode)
	{
		case SDLK_w:
		{
			camera->Translate(AXIS::Z, dts);
			break;
		}
		case SDLK_a:
		{
			camera->Translate(AXIS::X, dts);
			break;
		}
		case SDLK_s:
		{
			camera->Translate(AXIS::Z,-dts);
			break;
		}
		case SDLK_d:
		{
			camera->Translate(AXIS::X, -dts);
			break;
		}
	}
}