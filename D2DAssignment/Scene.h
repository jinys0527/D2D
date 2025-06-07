#pragma once
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

	virtual void Render() = 0;

	const char* GetType() const { return m_Type; }

	const char* GetID() const { return m_ID; }

protected:
	const char* m_Type = "Base";
	const char* m_ID = "None";

	Scene() = delete; // �⺻ ������ ����
	Scene(const Scene&) = delete; // ���� ������ ����
	Scene& operator=(const Scene&) = delete; // ���� ������ ����
};
