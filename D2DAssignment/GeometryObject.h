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

class GeometryObject
{
public:
	virtual void GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color);
	Point GetCenter() const { return m_center; }
	Color GetColor() const { return m_color; }
private:
	Point m_center;
	Color m_color;
};

class Line : GeometryObject
{
public:
	void GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color) override;
private:
	int m_length;
};

class Rectangle : GeometryObject
{
public:
	void GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color) override;
private:
	int m_width;
	int m_height;
};

class Circle : GeometryObject
{
public:
	void GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color) override;
private:
	int m_radius;
};

class Triangle : GeometryObject
{
public:
	void GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color) override;
private:
	int m_width;
	int m_height;
};