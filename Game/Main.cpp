#include "Engine.h"

#include <iostream>
#include <vector>

int main()
{
	crae::initializeMemory(); //Calls debug function for mem leak
	crae::SetFilePath("../Assets");

	rapidjson::Document document;
	bool success = crae::json::Load("json.txt", document);
	assert(success);

	std::string str;
	crae::json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	crae::json::Get(document, "boolean", b);
	std::cout << b << std::endl;

	int i1;
	crae::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	crae::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	crae::json::Get(document, "float", f);
	std::cout << f << std::endl;

	crae::Vector2 v2;
	crae::json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	crae::Color color;
	crae::json::Get(document, "color", color);
	std::cout << color << std::endl;

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