#include "Model.h"
#include "Math/Color.h"
#include "../Core/File.h"
#include "Core/Logger.h"
#include "Math/Transform.h"
#include "Math/MathUtils.h"
#include <iostream>
#include <sstream>

namespace nae
{
	Model::Model(const std::string filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
	}

	bool Model::Create(std::string filename, ...){
		if (!Load(filename))
		{
			LOG("Errow could not create model %s", filename.c_str());
			return false;
		}
		return true;
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale)
	{
		
		//if (m_points.size() == 0) return;

		//draw model
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			nae::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			nae::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			

			renderer.DrawLine(p1, p2, m_color);
		}
	}
	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		Matrix3x3 mx = transform.matrix;
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			nae::Vector2 p1 = mx * m_points[i];
			nae::Vector2 p2 = mx * m_points[i + 1];

			renderer.DrawLine(p1, p2, m_color);
		}
	}
	bool Model::Load(const std::string& filename)
	{
		std::string buffer;
		
		if (!nae::ReadFile(filename, buffer))
		{
			LOG("Errow could not load file %s", filename.c_str());
			return false;
		}

		//read color
		std::istringstream stream(buffer);
		stream >> m_color;

		std::string line;
		std::getline(stream, line);

		//get number of points
		size_t numPoints = std::stoi(line);

		// read model points
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;

			m_points.push_back(point);
		}
		return true;
	}
	float Model::CalculateRadius()
	{
		float radius = 0;

		//find the largest length (radius)
		for (auto& point : m_points)
		{
			if (point.Length() > radius) radius = point.Length();
		}

		return radius;
	}
}
