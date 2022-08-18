#pragma once
#include "Framework/Component.h"

namespace crae
{
	class PlayerComponent : public Component
	{
	public:
		float speed{ 0 };
	public:
		PlayerComponent() = default;

		void Update() override;
		

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

	};
}
