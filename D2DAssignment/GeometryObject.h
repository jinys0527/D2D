#pragma once

struct Point
{
	int x;
	int y;
};

struct Color
{
	float R;
	float G;
	float B;
	float A;
};

struct RenderData
{
	Point center;
	int scale1;
	int scale2;
	Color color;
	enum ShapeType {LINE, RECTANGLE, CIRCLE, TRIANGLE} shape;
};

class GeometryObject
{
public:
	GeometryObject() { m_center = { 0, 0 }; m_color = { 1, 1, 1, 1 }; }
	GeometryObject(Point center, Color color) : m_center(center), m_color(color) {}
	virtual ~GeometryObject() {}
	virtual void GetGeometryInfo(RenderData& data);
	Point GetCenter() const { return m_center; }
	Color GetColor() const { return m_color; }
private:
	Point m_center;
	Color m_color;
};

class Line : public GeometryObject
{
public:
	Line(Point center, Color color, int length) : GeometryObject(center, color), m_length(length) {}
	void GetGeometryInfo(RenderData& data) override;
private:
	int m_length;
};

class Rectangle : public GeometryObject
{
public:
	Rectangle(Point center, Color color, int width, int height) : GeometryObject(center, color), m_width(width), m_height(height) {}
	void GetGeometryInfo(RenderData& data) override;
private:
	int m_width;
	int m_height;
};

class Circle : public GeometryObject
{
public:
	Circle(Point center, Color color, int radius) : GeometryObject(center, color), m_radius(radius) {}
	void GetGeometryInfo(RenderData& data) override;
private:
	int m_radius;
};

class Triangle : public GeometryObject
{
public:
	Triangle(Point center, Color color, int width, int height) : GeometryObject(center, color), m_width(width), m_height(height) {}
	void GetGeometryInfo(RenderData& data) override;
private:
	int m_width;
	int m_height;
};