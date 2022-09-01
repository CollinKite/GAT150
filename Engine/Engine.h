#pragma once

#include "Serialization/Json.h"

#include "Core\Memory.h" //header file to check for mem leak
#include "Core/File.h"
#include "Core/Time.h"

#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"
#include "Framework/EventManager.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Resource/ResourceManager.h"
#include "Core/Logger.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Model.h"

#include "Math/Random.h"
#include "Math/MathUtils.h"

#include "Physics/PhysicsSystem.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/ModelComponent.h"
#include "Components/TextComponent.h"
#include "Components/TilemapComponent.h"
#include "Components/CharacterComponent.h"
#include "Components/CameraComponent.h"

//#include <memory>
//#include <list>
//#include <vector>
#include <variant>


namespace crae
{
	//extern defines NOT declares
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;
	extern EventManager g_eventManager;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}