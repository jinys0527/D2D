#pragma once
#include "Renderer.h"
#include "Scene.h"

#define MAX_SCENES 16

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void RegisterScene(Scene* scene);

	void ChangeScene(const char* id);

	void Update(float deltaTime);

	void Render();

private:
	Renderer renderer;

	struct SceneEntry
	{
		const char* id;
		Scene* ptr;
	};

	SceneEntry m_SceneTable[MAX_SCENES];
	int        m_SceneCount;

	Scene* m_CurrentScene;
};
