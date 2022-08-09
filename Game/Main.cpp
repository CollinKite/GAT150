#include "Engine.h"

#include <iostream>
#include <vector>
#include "Main.h"

int main()
{

	std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;
	std::cout << __FUNCTION__ << std::endl;


	crae::initializeMemory(); //Calls debug function for mem leak
	crae::SetFilePath("../Assets");



	//Create Systems
	crae::g_renderer.Initialize();
	crae::g_inputSystem.Initialize();
	crae::g_audioSystem.Initialize();

	crae::g_renderer.CreateWindow("Game Engine", 800, 600);
	crae::g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	crae::g_audioSystem.AddAudio("laser", "Audio/laser.wav");
	std::shared_ptr<crae::Texture> texture = std::make_shared<crae::Texture>();
	texture->Create(crae::g_renderer, "Textures/SpaceShip.png");

	//scene
	crae::Scene scene;


	//create actor
	crae::Transform transform{ crae::Vector2{400,300}, 90, {1,1} };
	std::unique_ptr<crae::Actor> actor = std::make_unique<crae::Actor>(transform);
	std::unique_ptr<crae::PlayerComponent> component = std::make_unique<crae::PlayerComponent>();
	std::unique_ptr<crae::SpriteComponent> s_component = std::make_unique<crae::SpriteComponent>();
	std::unique_ptr<crae::AudioComponent> a_component = std::make_unique<crae::AudioComponent>();
	std::unique_ptr<crae::PhysicsComponent> p_component = std::make_unique<crae::PhysicsComponent>();

	//pcomponent->key_up = crae::key_W;
	//pcomponent->key_down = crae::key_S;
	//pcomponent->key_left = crae::key_A;
	//pcomponent->key_right = crae::key_D;
	//actor->AddComponent(std::move(pcomponent));
	
	s_component->m_texture = texture;
	a_component->m_soundName = "laser";

	actor->AddComponent(std::move(s_component));
	actor->AddComponent(std::move(component));
	actor->AddComponent(std::move(a_component));
	actor->AddComponent(std::move(p_component));
	

	scene.Add(std::move(actor));

	float angle = 0;

	bool quit = false;
	while (!quit)
	{
		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;
		crae::g_inputSystem.Update();
		crae::g_time.Tick(); //Increment time, and frame time

		angle += 360.0f * crae::g_time.deltaTime;
		scene.Update();

		crae::g_renderer.BeginFrame();
		//crae::g_renderer.Draw(texture, { 400, 300 }, angle, {2,2}, {0.5f, 0.5f}); //0.5 1 to rotate at feet
		scene.Draw(crae::g_renderer);
		crae::g_renderer.EndFrame();
	}
	crae::g_renderer.Shutdown();
	crae::g_audioSystem.Shutdown();

}