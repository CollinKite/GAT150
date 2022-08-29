#include "Engine.h"
#include "CollinGame.h"

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
	crae::g_physicsSystem.Initialize();
	crae::g_eventManager.Initialize();
	crae::Engine::Instance().Register();

	crae::g_renderer.CreateWindow("Game Engine", 800, 600);
	crae::g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	//create game
	std::unique_ptr<CollinGame> game = std::make_unique<CollinGame>();
	game->Initialize();





	

	bool quit = false;
	while (!quit)
	{
		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;
		crae::g_inputSystem.Update();
		crae::g_time.Tick(); //Increment time, and frame time

		//angle += 360.0f * crae::g_time.deltaTime;
			
		game->Update();
		crae::g_physicsSystem.Update();

		crae::g_renderer.BeginFrame();
		game->Draw(crae::g_renderer);
		crae::g_renderer.EndFrame();
	}
	game->Shutdown();
	game.reset();

	crae::Factory::Instance().Shutdown();

	crae::g_eventManager.Shutdown();
	crae::g_physicsSystem.Shutdown();
	crae::g_resources.Shutdown();
	crae::g_inputSystem.Shutdown();
	crae::g_audioSystem.Shutdown();
	crae::g_renderer.Shutdown();

}