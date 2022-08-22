#include "Model.h"
#include "Core/File.h"
#include "Core/Logger.h"
#include "Math/Matrix3x3.h"
#include "Math/Transform.h"
#include <sstream>
#include <iostream>

nae::Model::Model(const std::string& filename)
{
	Load(filename);
	m_radius = CalculateRadius();
}

bool nae::Model::Create(const std::string& filename, void* data)
{
	if (!Load(filename))
	{
		LOG("Error couldn't read file %s", filename.c_str());
		return false;
	}

	return true;
}


void nae::Model::Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale)
{
	//nae::Color color;
	//color.r = nae::random(256);
	//color.g = nae::random(256);
	//color.b = nae::random(256);
	//color.r = 255;


	for (int i = 0; i < m_points.size() - 1; i++)
	{
		nae::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
		nae::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

		renderer.DrawLine(p1, p2, m_color);
	}
}

void nae::Model::Draw(Renderer& renderer, const Transform& transform)
{
	Matrix3x3 mx = transform.matrix;

	for (int i = 0; i < m_points.size() - 1; i++)
	{
		nae::Vector2 p1 = mx * m_points[i];
		nae::Vector2 p2 = mx * m_points[i + 1];

		renderer.DrawLine(p1, p2, m_color);
	}
}

bool nae::Model::Load(const std::string& filename)
{
	std::string buffer;

	if (!nae::ReadFile(filename, buffer))
	{
		LOG("Error could not read file %s", filename.c_str());
		return false;
	}
	nae::ReadFile(filename, buffer);
	
	std::istringstream stream(buffer);
	stream >> m_color;

	//read
	//m_color.r = 255;
	//m_color.g = 255;
	//m_color.b = 255;
	//m_color.a = 255;

	std::string line;
	std::getline(stream, line);

	size_t numPoints = std::stoi(line);

	//get number of points
	//std::cout << line << std::endl;

	//read model points
	for (size_t i = 0; i < numPoints; i++)
	{

		Vector2 point;

		stream >> point;

		m_points.push_back(point);
	}

	return true;
}

float nae::Model::CalculateRadius()
{
	float radius = 0;

	//find the largest length
	for (auto& point : m_points)
	{
		if (point.Length() > radius) { radius = point.Length(); }
		
	}


	return radius;
}
