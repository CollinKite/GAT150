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



	crae::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&CollinGame::OnAddPoints, this, std::placeholders::_1));
}

void CollinGame::Shutdown()
{
	m_scene->RemoveAll();
}

void CollinGame::Update()
{
	switch (m_gameState)
	{
	case CollinGame::gameState::titleScreen:
		if (crae::g_inputSystem.GetKeyState(crae::key_space) == crae::InputSystem::Pressed)
		{
			m_gameState = gameState::startLevel;
		}
		break;
	case CollinGame::gameState::startLevel:
		for (int i = 0; i < 10; i++)
		{
			auto actor = crae::Factory::Instance().Create<crae::Actor>("Coin");
			actor->m_transform.position = { crae::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		m_gameState = gameState::game;
		break;
	case CollinGame::gameState::game:
		break;
	case CollinGame::gameState::playerDead:
		m_stateTimer -= crae::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = (m_lives > 0) ? gameState::startLevel : gameState::gameOver;
		}
		break;
	case CollinGame::gameState::gameOver:
		break;
	default:
		break;
	}
	m_scene->Update();
}

void CollinGame::Draw(crae::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void CollinGame::OnAddPoints(const crae::Event& event)
{
	AddPoints(std::get<int>(event.data));

	std::cout << event.name << std::endl;
	std::cout << std::get<int>(event.data) << std::endl;
}

void CollinGame::OnPlayerDead(const crae::Event& event)
{
	m_gameState = gameState::playerDead;
}
