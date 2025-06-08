#include "pch.h"
#include "Scene.h"
#include "SceneManager.h"

void LineScene::OnEnter()
{
}

void LineScene::OnLeave()
{
}

void LineScene::Update(float dt)
{
	char ch = '\0';
	while (ch == '\0')
	{
		ch = getchar();
	}
}

void LineScene::Render(std::vector<RenderData>& RenderList) const
{
	for (auto obj : geometryObject)
	{
		RenderData data;
		obj.GetGeometryInfo(data);
		RenderList.push_back(data);
	}
}

