#include "Engine.h"

#include <iostream>
#include <vector>

int main()
{

	int i = 10;
	float f = 3.5f;
	bool b = true;
	if (b) std::cout << "true\n";

	printf("hello world %d %f \n", 5, f);

	crae::initializeMemory(); //Calls debug function for mem leak
	crae::SetFilePath("../Assets");



	//Create Systems
	crae::g_renderer.Initialize();
	crae::g_inputSystem.Initialize();
	crae::g_audioSystem.Initialize();

	crae::g_renderer.CreateWindow("Game Engine", 800, 600);
	crae::g_renderer.SetClearColor(crae::Color{ 0,0,0,255 });

	std::shared_ptr<crae::Texture> texture = std::make_shared<crae::Texture>();
	texture->Create(crae::g_renderer, "jesu.png");

	bool quit = false;
	while (!quit)
	{
		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;
		crae::g_inputSystem.Update();
		crae::g_time.Tick(); //Increment time, and frame time
		crae::g_renderer.BeginFrame();
		crae::g_renderer.Draw(texture, { 400, 300 }, 0);
		crae::g_renderer.EndFrame();
	}
	crae::g_renderer.Shutdown();
	crae::g_audioSystem.Shutdown();

}