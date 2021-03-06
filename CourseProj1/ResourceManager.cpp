#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	for (strmap<Mesh*>::iterator i = meshes.begin(); i != meshes.end(); i++)
	{
		delete i->second;
		i = meshes.erase(i);
	}
	for (strmap<ModelTexture*>::iterator i = modelTextures.begin(); i != modelTextures.end(); i++)
	{
		delete i->second;
		i = modelTextures.erase(i);
	}
	for (strmap<Scene*>::iterator i = scenes.begin(); i != scenes.end(); i++)
	{
		delete i->second;
		i = scenes.erase(i);
	}
	for (strmap<AbstractShader*>::iterator i = shaders.begin(); i != shaders.end(); i++)
	{
		delete i->second;
		i = shaders.erase(i);
	}
}

ResourceManager* ResourceManager::Instance()
{
	if (!instance)
	{
		return instance = new ResourceManager();
	}
	return instance;
}

void ResourceManager::AddMesh(string name, Mesh* mesh)
{
	if (!GetMesh(name))
	{
		meshes.insert(strpair<Mesh*>(name, mesh));
	}
}

void ResourceManager::AddModelTexture(string name, ModelTexture* modelTexture)
{
	if (!GetModelTexture(name))
	{
		modelTextures.insert(strpair<ModelTexture*>(name, modelTexture));
	}
}

void ResourceManager::AddScene(string name, Scene* scene)
{
	if (name != "")
	{
		if (!GetScene(name))
		{
			scenes.insert(strpair<Scene*>(name, scene));
		}
	}
}

void ResourceManager::AddShader(string name, AbstractShader* shader)
{
	if (!GetShader(name))
	{
		shaders.insert(strpair<AbstractShader*>(name, shader));
	}
}

Mesh* ResourceManager::GetMesh(string name)
{
	map<string, Mesh*>::iterator it = meshes.find(name);
	if (it != meshes.end())
	{
		return it->second;
	}
	return nullptr;
}

ModelTexture* ResourceManager::GetModelTexture(string name)
{
	strmap<ModelTexture*>::iterator it = modelTextures.find(name);
	if (it != modelTextures.end())
	{
		return it->second;
	}
	return nullptr;
}

Scene* ResourceManager::GetScene(string name)
{
	strmap<Scene*>::iterator it = scenes.find(name);
	if (it != scenes.end())
	{
		return it->second;
	}
	return nullptr;
}

AbstractShader* ResourceManager::GetShader(string name)
{
	strmap<AbstractShader*>::iterator it = shaders.find(name);
	if (it != shaders.end())
	{
		return it->second;
	}
	return nullptr;
}