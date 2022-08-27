#include "Engine.h"

namespace crae
{
	Renderer g_renderer;
	InputSystem g_inputSystem;
	AudioSystem g_audioSystem;
	Time g_time;
	ResourceManager g_resources;
	PhysicsSystem g_physicsSystem;


	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(SpriteAnimComponent);
		REGISTER_CLASS(RBPhysicsComponent);
		REGISTER_CLASS(CollisionComponent);
		REGISTER_CLASS(TextComponent);
		REGISTER_CLASS(TilemapComponent);
	}
}