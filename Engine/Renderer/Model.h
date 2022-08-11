#pragma once
#include "Renderer.h"
#include <vector>
#include <string>

namespace crae
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<crae::Vector2>& points, const crae::Color& color) : m_points{points}, m_color{color} //Set private vars with constructor
		{
		}

		Model(const std::string& filename);

		bool Create(const std::string& filename);

		void Draw(Renderer& renderer, Vector2& position, float angle, const Vector2& scale = Vector2{ 1,1 });

		void Draw(Renderer& renderer, const Transform& transform);

		bool Load(const std::string& filename);

		float CalculateRadius();

		float GetRadius() { return m_radius; }

	private:
		crae::Color m_color {0,0,0,0};
		std::vector<crae::Vector2> m_points;

		float m_radius = 0;
	};
}