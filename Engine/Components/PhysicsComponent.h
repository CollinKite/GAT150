#pragma once

#include "Framework/Component.h"

namespace crae
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;
			
		void Update() override;

		virtual void ApplyForce(const Vector2& force) { accleration += force; }
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

	public:
		Vector2 velocity;
		Vector2 accleration;

		float damping = 1.0f;


		// Inherited via Component

	};
}