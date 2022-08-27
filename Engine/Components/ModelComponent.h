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
		CLASS_DECLARATION(ModelComponent)



		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;


	};
}