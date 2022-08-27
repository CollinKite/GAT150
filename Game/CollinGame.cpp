#include "CollinGame.h"
#include "Engine.h"

void CollinGame::Initialize()
{
	m_scene = std::make_unique<crae::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scenes/prefabs.txt", "scenes/tilemap.txt", "scenes/level.txt" };

	for (auto sceneName : sceneNames)
	{
		bool success = crae::json::Load(sceneName, document);
		if (!success)
		{
			LOG("Couldn't load %s", sceneName.c_str());
			continue;
		}
		m_scene->Read(document);
	}
	m_scene->Initialize();

	for (int i = 0; i < 10; i++)
	{
		auto actor = crae::Factory::Instance().Create<crae::Actor>("Coin");
		actor->m_transform.position = { crae::randomf(0,800), 100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
}

void CollinGame::Shutdown()
{
	m_scene->RemoveAll();
}

void CollinGame::Update()
{
	m_scene->Update();
}

void CollinGame::Draw(crae::Renderer& renderer)
{
	m_scene->Draw(renderer);
}
