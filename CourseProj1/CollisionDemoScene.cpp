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
	//Call the default "Initialise" method
	//for general purpose scene initialisation.
	Scene::Initialise();


	camera->SetPosition(Vec3(0, 0, -5.0f));
	
	//Load the audio files into the "audioDevice" so that they can be
	//played later.
	shotSource = audioDevice->LoadSound(shotSoundFile.c_str());
	bluesiSource = audioDevice->LoadSound(musicFile.c_str());

	//Play the music audio.
	audioDevice->PlaySound(bluesiSource);


	//Create a skybox from the path of the skybox textures
	//and the name of the skybox shader.
	SkyBox* sky = new SkyBox(skyboxFile, skyboxShaderName);
	sky->SetCamera(camera);

	//The skybox doesn't work properly, so the following line
	//has been commented out in order to remove it from
	//the implementation.

	//SetSkyBox(sky);
}

void CollisionDemoScene::CreateCube()
{
	CollisionCube* cube = new CollisionCube();
	cube->SetPosition(RandomNumber(-5, 5), 0, RandomNumber(8, 12));
	cubes.push_back(cube);
	AddGameObject(cube);
}

void CollisionDemoScene::DestroyCube(CollisionCube* cube)
{
	//Iterate through all the collision cubes until one is found,
	//then remove it from the vector and remove it as a game object.
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

void CollisionDemoScene::DestroyProjectile(ProjectileGameObject* ball)
{
	//Iterate through all the projectiles until one is found,
	//then remove it from the vector and remove it as a game object.
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

void CollisionDemoScene::Fire()
{
	//Instantiate a projectile
	ProjectileGameObject* ball = new ProjectileGameObject();

	//Set the direction of the projectile according to the
	//camera's orientation.
	Vec3* forward = camera->GetForward();
	ball->SetDirection(*forward);

	//Set the initial position of the projectile to be offset
	//from the camera's position.
	const float d = 0.5f;
	Vec3 pos = (*camera->GetPosition()) + ((*forward) * d);
	ball->SetPosition(pos);
	
	//Add the projectile to the collection of rendered gameobjects
	//and the collection of projectiles (which are updated in order
	//to move and collide).
	AddGameObject(ball);
	projectiles.push_back(ball);
}

bool CollisionDemoScene::KeyDown(SDL_Keycode keycode)
{
	//Translate the camera's position based on
	//whether any of the WASD keys are pressed.
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

bool CollisionDemoScene::MouseDown(SDL_MouseButtonEvent mouseButton)
{
	//Just return true so that the scene continues to run.
	return true;
}

bool CollisionDemoScene::Update()
{
	vector<ProjectileGameObject*> destroyedBalls;
	vector<CollisionCube*> destroyedCubes;
	//Iterate through all the projectiles and cubes to determine if
	//they collide.
	for (ProjectileGameObject* ball : projectiles)
	{
		//Provide the projectile with the amount of time
		//since the last frame so that it can move accordingly.
		ball->Update(DeltaTime());
		for (CollisionCube* cube : cubes)
		{
			if (ball->CollidesWith(cube))
			{
				cube->SetActive(false);
				destroyedCubes.push_back(cube);
				destroyedBalls.push_back(ball);
				audioDevice->PlaySound(shotSource, *ball->GetPosition());
			}
		}
	}

	//Remove all projectiles that have been "destroyed".
	for (ProjectileGameObject* ball : destroyedBalls)
	{
		DestroyProjectile(ball);
	}

	//Remove all cubes that have been "destroyed".
	for (CollisionCube* cube : destroyedCubes)
	{
		DestroyCube(cube);
	}

	//If a random number between 0 and 150
	//happens to be 0, spawn a collision object.
	if (RandomNumber(0, 150) == 0)
	{
		CreateCube();
	}
	return true;
}

void CollisionDemoScene::WASD(SDL_Keycode keycode)
{
	//Determine the amount to move the camera by, using
	//the predetermined speed and the amount of time
	//that's passed since the last frame.
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