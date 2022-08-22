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
	crae::g_physicsSystem.Initialize();

	crae::g_renderer.CreateWindow("Game Engine", 800, 600);
	crae::g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	crae::Engine::Instance().Register();


	crae::g_audioSystem.AddAudio("laser", "Audio/laser.wav");



	//scene
	crae::Scene scene;

	rapidjson::Document document;
	bool success = crae::json::Load("Models/level.txt", document);

	scene.Read(document);
	scene.Initialize();

	bool quit = false;
	while (!quit)
	{
		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;
		crae::g_inputSystem.Update();
		crae::g_time.Tick(); //Increment time, and frame time

		//angle += 360.0f * crae::g_time.deltaTime;
			
		scene.Update();
		crae::g_physicsSystem.Update();

		crae::g_renderer.BeginFrame();
		scene.Draw(crae::g_renderer);
		crae::g_renderer.EndFrame();
	}
	crae::g_renderer.Shutdown();
	crae::g_audioSystem.Shutdown();

}