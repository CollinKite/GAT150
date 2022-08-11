#pragma once
#include "RenderComponent.h"

namespace crae
{
	class Model;

	class ModelComponent : public RenderComponent
	{
	public:
		std::shared_ptr<Model> m_model;

	public:


		// Inherited via RenderComponent
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	};
}