#include "pch.h"
#include "GeometryObject.h"

void GeometryObject::GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color)
{
	point = GetCenter();
	color = GetColor();
}

void Line::GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color)
{
	__super::GetGeometryInfo(point, scale1, scale2, color);
	scale1 = m_length;
}

void Rectangle::GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color)
{
	__super::GetGeometryInfo(point, scale1, scale2, color);
	scale1 = m_width;
	scale2 = m_height;
}

void Circle::GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color)
{
	__super::GetGeometryInfo(point, scale1, scale2, color);
	scale1 = m_radius;
}

void Triangle::GetGeometryInfo(Point& point, int& scale1, int& scale2, Color& color)
{
	__super::GetGeometryInfo(point, scale1, scale2, color);
	scale1 = m_width;
	scale2 = m_height;
}