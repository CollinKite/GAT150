#include "Engine.h"

#include <iostream>
#include <vector>

int main()
{
	crae::initializeMemory(); //Calls debug function for mem leak
	crae::SetFilePath("../Assets");



	//Create Systems
	crae::g_renderer.Initialize();
	crae::g_inputSystem.Initialize();
	crae::g_audioSystem.Initialize();
	crae::g_resources.Initialize();

	crae::g_renderer.CreateWindow("Game Engine", 800, 600);
	crae::g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	crae::g_audioSystem.AddAudio("laser", "Audio/laser.wav");

	//scene
	crae::Scene scene;

	//create actor
	crae::Transform transform{ crae::Vector2{400,300}, 90, {3,3} };
	std::unique_ptr<crae::Actor> actor = std::make_unique<crae::Actor>(transform);
	std::unique_ptr<crae::PlayerComponent> component = std::make_unique<crae::PlayerComponent>();
	std::unique_ptr<crae::SpriteComponent> s_component = std::make_unique<crae::SpriteComponent>();
	std::unique_ptr<crae::AudioComponent> a_component = std::make_unique<crae::AudioComponent>();
	std::unique_ptr<crae::PhysicsComponent> p_component = std::make_unique<crae::PhysicsComponent>();
	std::unique_ptr<crae::ModelComponent> m_component = std::make_unique<crae::ModelComponent>();
		
	m_component->m_model = crae::g_resources.Get<crae::Model>("Models/player1.txt");
	s_component->m_texture = crae::g_resources.Get<crae::Texture>("Textures/jesus.png", &crae::g_renderer);
	//a_component->m_soundName = "laser";

	actor->AddComponent(std::move(component));
	//actor->AddComponent(std::move(s_component));
	//actor->AddComponent(std::move(a_component));
	actor->AddComponent(std::move(p_component));
	actor->AddComponent(std::move(m_component));

	//child
	// 
	crae::Transform transformChild{ crae::Vector2{10,10}, 0, {1,1} };
	std::unique_ptr<crae::Actor> child = std::make_unique<crae::Actor>(transformChild);

	std::unique_ptr<crae::ModelComponent> m_componentC = std::make_unique<crae::ModelComponent>();
	m_componentC->m_model = crae::g_resources.Get<crae::Model>("Models/player1.txt");
	child->AddComponent(std::move(m_componentC));
	actor->AddChild(std::move(child));
		




	scene.Add(std::move(actor));

	float angle = 0;

	bool quit = false;
	while (!quit)
	{
		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;
		crae::g_inputSystem.Update();
		crae::g_time.Tick(); //Increment time, and frame time

		//angle += 360.0f * crae::g_time.deltaTime;
			
		scene.Update();

		crae::g_renderer.BeginFrame();
		scene.Draw(crae::g_renderer);
		crae::g_renderer.EndFrame();
	}
	crae::g_renderer.Shutdown();
	crae::g_audioSystem.Shutdown();

}