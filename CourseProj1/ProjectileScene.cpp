#include "ProjectileScene.h"

void ProjectileScene::Dispose()
{
	Scene::Dispose();
	projectiles.clear();
}

void ProjectileScene::Initialise()
{
	Scene::Initialise();
	camera->SetPosition(0.0f, 0.0f, -5.0f);

	AddGameObject(mesh1Name, texture1Name, shaderName);
}

void ProjectileScene::LaunchProjectile()
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

bool ProjectileScene::MouseDown(SDL_MouseButtonEvent mousebutton)
{
	return true;
}

bool ProjectileScene::KeyDown(SDL_Keycode keycode)
{
	WASD(keycode);
	switch (keycode)
	{
	case SDLK_SPACE:
	{
		LaunchProjectile();
		break;
	}
	case SDLK_ESCAPE:
	{
		SetNextScene(demoScene);
		break;
		//return false;
	}
	}
	return true;
}

bool ProjectileScene::Update()
{
	for (ProjectileGameObject* ball : projectiles)
	{
		if (ball->IsActive())
		{
			ball->Update(DeltaTime());
			const float maxD = 4.0f;
			float d = glm::distance(*ball->GetTransform()->GetPosition(), *camera->GetPosition());
			if (d >= maxD)
			{
				ball->SetActive(false);
			}
		}
	}
	return true;
}

void ProjectileScene::WASD(SDL_Keycode keycode)
{
	switch (keycode)
	{
	case SDLK_w:
	{
		camera->Translate(AXIS::Z, speed * DeltaTime());
		break;
	}
	case SDLK_a:
	{
		camera->Translate(AXIS::X, speed * DeltaTime());
		break;
	}
	case SDLK_s:
	{
		camera->Translate(AXIS::Z, -speed * DeltaTime());
		break;
	}
	case SDLK_d:
	{
		camera->Translate(AXIS::X, -speed * DeltaTime());
		break;
	}
	}
}