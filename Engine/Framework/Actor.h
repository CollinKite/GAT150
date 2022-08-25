#pragma once
#include "GameObject.h"
#include "Component.h"

#include <vector>
#include <memory>

namespace crae
{
	class Scene; //fwd Delcaration
	class Renderer;
	class Actor : public GameObject, public ISerializable
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}

		std::unique_ptr<GameObject> Clone() { return std::make_unique<Actor>(); }

		virtual void Update() override; //Overide method from Game Object
		virtual void Draw(Renderer& renderer);
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
		virtual void Initialize() override;

		void AddChild(std::unique_ptr<Actor> child);

		void AddComponent(std::unique_ptr<Component> component);

		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; }// m_model.GetRadius(); }
		const std::string& GetTag() { return tag; }
		void SetTag(const std::string& tag) { this->tag = tag; }

		const std::string& GetName() { return name; }
		void SetName(const std::string& name) { this->name = name; }
		Transform m_transform;

		friend class Scene;
	protected:
		std::string name;
		std::string tag; //enemy & player
		bool m_destroy = false;

		

		bool m_loselife = false;

		Scene* m_scene = nullptr;
		Actor* m_parent = nullptr;

		std::vector<std::unique_ptr<Component>> m_components;
		std::vector<std::unique_ptr<Actor>> m_children;

		// Inherited via GameObject
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