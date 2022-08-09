#pragma once
#pragma once
#include "RenderComponent.h"

namespace crae
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:
		std::shared_ptr<Texture> m_texture;

	public:


		// Inherited via RenderComponent
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	};
}