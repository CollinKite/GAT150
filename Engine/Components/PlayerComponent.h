#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"

namespace crae
{
	class PlayerComponent : public Component, public ICollision
	{
	public:
		float speed{ 0 };
	public:
		PlayerComponent() = default;

		void Initialize() override;
		void Update() override;
		
		// Inherited via ICollision
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;



	};
}
