#pragma once
#include "Scene.h"
#include "Actor.h"

#include <list>
#include <memory>

namespace crae
{
	class Actor; //Forward declaration since we use a Actor ptr, tells complier to find it later | if it wasn't a ptr we would include Actor.h
	class Renderer; //Fwd Declaration since we use a reference | we use these for optimization

	class Game;
	class Scene : public GameObject, public ISerializable
	{
	public:
		Scene() = default;
		Scene(Game* game) : m_game{ game } {};
		~Scene() = default;

		void Initialize() override;
		void Update() override;
		void Draw(Renderer& renderer);
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();

		template<typename T>
		T* GetActor();

		Game* GetGame() { return m_game; }

	private:
		Game* m_game = nullptr;
		std::list<std::unique_ptr<Actor>> m_actors;

	};
	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : m_actors)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}
		return nullptr;
	}
}