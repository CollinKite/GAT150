#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>

namespace crae
{
	class Scene; //fwd Delcaration
	class Renderer;
	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}

		virtual void Update() override; //Overide method from Game Object
		virtual void Draw(Renderer& renderer);

		void AddComponent(std::unique_ptr<Component> component);

		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; }// m_model.GetRadius(); }
		std::string& GetTag() { return m_tag; }
		Transform m_transform;

		friend class Scene;
	protected:
		std::string m_tag; //enemy & player
		bool m_destroy = false;

		

		bool m_loselife = false;
		//physics
		float m_damping = 1;
		Vector2 m_velocity;

		Scene* m_scene = nullptr;
		std::vector<std::unique_ptr<Component>> m_components;
	};


	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& component : m_components)
		{
			T* result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}
		return nullptr;
	}
}