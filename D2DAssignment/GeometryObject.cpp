#include "pch.h"
#include "GeometryObject.h"

void GeometryObject::GetGeometryInfo(RenderData& data)
{
	data.center = GetCenter();
	data.color = GetColor();
}

void Line::GetGeometryInfo(RenderData& data)
{
	__super::GetGeometryInfo(data);
	data.scale1 = m_length;
	data.scale2 = 0;
	data.shape = RenderData::LINE;
}

void Rectangle::GetGeometryInfo(RenderData& data)
{
	__super::GetGeometryInfo(data);
	data.scale1 = m_width;
	data.scale2 = m_height;
	data.shape = RenderData::RECTANGLE;
}

void Circle::GetGeometryInfo(RenderData& data)
{
	__super::GetGeometryInfo(data);
	data.scale1 = m_radius;
	data.scale2 = 0;
	data.shape = RenderData::CIRCLE;
}

void Triangle::GetGeometryInfo(RenderData& data)
{
	__super::GetGeometryInfo(data);
	data.scale1 = m_width;
	data.scale2 = m_height;
	data.shape = RenderData::TRIANGLE;
}