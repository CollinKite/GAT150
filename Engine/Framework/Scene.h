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
		Scene (const Scene& other) {}
		~Scene() = default;

		CLASS_DECLARATION(Scene)


		void Initialize() override;
		void Update() override;
		void Draw(Renderer& renderer);
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();

		template<typename T = Actor>
		T* GetActorFromName(const std::string& name);

		template<typename T = Actor>
		std::vector<T*> GetActorsFromTag(const std::string& tag);

		template<typename T>
		T* GetActor();

		Game* GetGame() { return m_game; }

	private:
		Game* m_game = nullptr;
		std::list<std::unique_ptr<Actor>> m_actors;

	};

	template<typename T>
	inline T* Scene::GetActorFromName(const std::string& name)
	{
		for(auto& actor : m_actors)
		{
			//  !! compare name to actor GetName()) 
			if (actor->GetName() == name)
				{
					return dynamic_cast<T*>(actor.get());
				}
		}

		return nullptr;
	}

	template<typename T>
	inline std::vector<T*> Scene::GetActorsFromTag(const std::string& tag)
	{
		std::vector<T*> result;

		//  !! for loop (range based) through m_actors 
		for(auto& actor : m_actors)
		{
			if(actor->GetTag() == tag)
			{
				 T * tagActor = dynamic_cast<T*>(actor.get()); 
				 if (tagActor)
				 {
					 result.push_back(tagActor);
				 }//  !! push back tagActor to result vector 
			}
		}

		return result;
	}


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