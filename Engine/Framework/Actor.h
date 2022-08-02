#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace crae
{
	class Scene; //fwd Delcaration

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : GameObject{ transform }, m_model{ model } {}

		virtual void Update() override {}; //Overide method from Game Object
		virtual void Draw(Renderer& renderer);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return m_model.GetRadius(); }
		std::string& GetTag() { return m_tag; }

		friend class Scene;
	protected:
		std::string m_tag; //enemy & player
		bool m_destroy = false;
		bool m_loselife = false;
		//physics
		float m_damping = 1;
		Vector2 m_velocity;

		Scene* m_scene = nullptr;
		Model m_model;
	};
}