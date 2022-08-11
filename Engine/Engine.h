#pragma once

#include "Core\Memory.h" //header file to check for mem leak
#include "Core/File.h"
#include "Core/Time.h"

#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Math/Random.h"

#include "Math/MathUtils.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/ModelComponent.h"


//#include <memory>
//#include <list>
//#include <vector>


namespace crae
{
	//extern defines NOT declares
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
}