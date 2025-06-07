#include "SceneManager.h"
#include "iostream"
#include "cassert"

SceneManager::SceneManager() : m_SceneCount(0), m_CurrentScene(nullptr)
{
	renderer.Initialize();
	for (int i = 0; i < MAX_SCENES; ++i)
	{
		m_SceneTable[i].id = nullptr;
		m_SceneTable[i].ptr = nullptr;
	}
}

SceneManager::~SceneManager()
{
	renderer.Finalize();

	for (int i = 0; i < m_SceneCount; ++i)
	{
		delete m_SceneTable[i].ptr;
	}
}

void SceneManager::RegisterScene(Scene* scene)
{
	assert(scene != nullptr);
	assert(m_SceneCount < MAX_SCENES);

	const char* id = scene->GetID();
	assert(id != nullptr);

	// �ߺ� Ȯ��
	for (int i = 0; i < m_SceneCount; ++i)
	{
		if (std::strcmp(m_SceneTable[i].id, id) == 0)
		{
			assert(false && "�ߺ��� �� ID ���");
			return;
		}
	}

	m_SceneTable[m_SceneCount].id = id;
	m_SceneTable[m_SceneCount].ptr = scene;

	++m_SceneCount;
}

void SceneManager::ChangeScene(const char* id)
{
	assert(id != nullptr);

	for (int i = 0; i < m_SceneCount; ++i)
	{
		if (std::strcmp(m_SceneTable[i].id, id) == 0)
		{
			if (m_CurrentScene)
				m_CurrentScene->OnLeave();

			m_CurrentScene = m_SceneTable[i].ptr;
			m_CurrentScene->OnEnter();
			return;
		}
	}

	assert(false && "������ ID�� ���� �������� ����");
}

void SceneManager::Update(float deltaTime)
{
	if (m_CurrentScene)
		m_CurrentScene->Update(deltaTime);
}

void SceneManager::Render()
{
	if (m_CurrentScene)
		m_CurrentScene->Render();
}