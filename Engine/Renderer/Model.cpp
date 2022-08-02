#include "Model.h"
#include "../Core/File.h"	
#include <sstream>
#include <iostream>

namespace crae 
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
	}
	void Model::Draw(Renderer& renderer, Vector2& position, float angle, float scale)
	{
		//crae::Color color;
		//color.r = crae::random(256);
		//color.g = crae::random(256);
		//color.b = crae::random(256);
		//color.a = 255;

		//draw model
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			crae::Vector2 p1 = crae::Vector2::Rotate((m_points[i] * scale), angle) + position;
			crae::Vector2 p2 = crae::Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}
	void Model::Load(const std::string& filename)
	{
		std::string buffer;

		crae::ReadFile(filename, buffer);

		// read color
		std::istringstream stream(buffer);
		stream >> m_color;

		std::string line;
		std::getline(stream, line);

		size_t numpoints = std::stoi(line); //unsigned int always want it to be positive

		//std::cout << line << std::endl;

		for (size_t i = 0; i < numpoints; i++)
		{
			Vector2 point;
			stream >> point;

			m_points.push_back(point);
		}
	}
	float Model::CalculateRadius()
	{
		float radius = 0;

		for (auto& point : m_points)
		{
			if (radius < point.Length())
			{
				radius = point.Length();
			}
		}

		return radius;
	}
}

