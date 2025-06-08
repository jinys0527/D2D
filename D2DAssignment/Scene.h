#pragma once
#include "GeometryObject.h"
#include <iostream>
#include <vector>

const int MAXOBJECTCOUNT = 10;

class Scene
{
public:
	Scene(const char* type, const char* id)
		: m_Type(type), m_ID(id) {
	}

	virtual ~Scene() {}

	virtual void OnEnter() = 0;

	virtual void OnLeave() = 0;

	virtual void Update(float deltaTime) = 0;

	virtual void Render(std::vector<RenderData>& RenderList) const = 0;

	virtual void AddGeometryObject(int type) = 0;

	virtual void RemoveGeometryObject() = 0;

	const char* GetType() const { return m_Type; }

	const char* GetID() const { return m_ID; }

protected:
	GeometryObject geometryObject[MAXOBJECTCOUNT];

	const char* m_Type = "Base";
	const char* m_ID = "None";

	Scene() = delete; // 기본 생성자 금지
	Scene(const Scene&) = delete; // 복사 생성자 금지
	Scene& operator=(const Scene&) = delete; // 대입 연산자 금지
};

class LineScene : public Scene
{
public:
	LineScene(const char* type, const char* id) :Scene(type, id) {}

	~LineScene() override { }

	void OnEnter() override;

	void OnLeave() override;

	void Update(float dt) override;

	void Render(std::vector<RenderData>& RenderList) const override;
};

