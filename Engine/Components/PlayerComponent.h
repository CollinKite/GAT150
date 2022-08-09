#pragma once
#include "Framework/Component.h"

namespace crae
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		void Update() override;
		
	};
}
