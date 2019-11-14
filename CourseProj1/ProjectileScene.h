#ifndef _PROJECTILESCENE_H
#define _PROJECTILESCENE_H

#include "Scene.h"
#include "ProjectileGameObject.h"

class ProjectileScene : public Scene
{
public:
	void Dispose();
	void Initialise();
private:
	void LaunchProjectile();
	bool MouseDown(SDL_MouseButtonEvent mousebutton);
	bool KeyDown(SDL_Keycode keycode);
	bool Update();
	void WASD(SDL_Keycode keycode);
	float speed = 3.0f;
	vector<ProjectileGameObject*> projectiles;
};

#endif