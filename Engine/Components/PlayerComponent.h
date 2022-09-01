#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"
#include "CharacterComponent.h"

namespace crae
{
	class PlayerComponent : public CharacterComponent
	{
	public:
		PlayerComponent() = default;
		CLASS_DECLARATION(PlayerComponent)


		void Initialize() override;
		void Update() override;
		
		// Inherited via ICollision
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;


		// Inherited via CharacterComponent
		virtual void OnNotify(const Event& event) override;
		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float jump = 30;
		int m_groundCount = 0;
	};
}
