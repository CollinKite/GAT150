#pragma once

#include "Framework/Component.h"

namespace crae
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;

		void Update() override;

		void ApplyForce(const Vector2& force) { m_accleration += force; }

	public:
		Vector2 m_velocity;
		Vector2 m_accleration;

		float m_damping = 0.9f;

	};
}