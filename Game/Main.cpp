#include "Engine.h"

#include <iostream>
#include <vector>

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

	std::shared_ptr<crae::Texture> texture = std::make_shared<crae::Texture>();
	texture->Create(crae::g_renderer, "jesus.png");

	float angle = 0;

	bool quit = false;
	while (!quit)
	{
		if (crae::g_inputSystem.GetKeyDown(crae::key_escape)) quit = true;
		crae::g_inputSystem.Update();
		crae::g_time.Tick(); //Increment time, and frame time

		angle += 180.0f * crae::g_time.deltaTime;

		crae::g_renderer.BeginFrame();
		crae::g_renderer.Draw(texture, { 400, 300 }, angle, {2,2}, {0.5f, 0.5f}); //0.5 1 to rotate at feet
		crae::g_renderer.EndFrame();
	}
	crae::g_renderer.Shutdown();
	crae::g_audioSystem.Shutdown();

}