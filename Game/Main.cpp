#include "Engine.h"

#include <iostream>
#include <vector>

int main()
{
	std::cout << "hello world" << std::endl;

	crae::initializeMemory(); //Calls debug function for mem leak
	crae::SetFilePath("../Assets");



	//Create Systems
	crae::g_renderer.Initialize();
	crae::g_inputSystem.Initialize();
	crae::g_audioSystem.Initialize();

	crae::g_renderer.CreateWindow("Astroids", 800, 600);
	crae::g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	bool quit = false;
	while (!quit)
	{
		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;
		crae::g_inputSystem.Update();
		crae::g_time.Tick(); //Increment time, and frame time
		crae::g_renderer.BeginFrame();
		crae::g_renderer.EndFrame();
	}
	crae::g_renderer.Shutdown();
	crae::g_audioSystem.Shutdown();

}