#include "SceneManager.h"

SceneManager::SceneManager()
{
	renderer.Initialize();
}

SceneManager::~SceneManager()
{
	renderer.Finalize();
}
