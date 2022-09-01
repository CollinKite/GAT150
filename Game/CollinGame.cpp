#include "CollinGame.h"
#include "GameComponents/EnemyComponent.h"
#include "Engine.h"

void CollinGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);


	m_scene = std::make_unique<crae::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scenes/prefabs.json", "scenes/tilemap.json", "scenes/level.json" };

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



	crae::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&CollinGame::OnNotify, this, std::placeholders::_1));
	crae::g_eventManager.Subscribe("EVENT_PLAYER_DEAD", std::bind(&CollinGame::OnNotify, this, std::placeholders::_1));
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
		{
			auto actor = crae::Factory::Instance().Create<crae::Actor>("Player");
			actor->m_transform.position = 400.0f, 100.0f;
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		//Spawn Coins
		for (int i = 0; i < 10; i++)
		{
			auto actor = crae::Factory::Instance().Create<crae::Actor>("Coin");
			actor->m_transform.position = { crae::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		//Spawn Enemies
		for (int i = 0; i < 3; i++)
		{
			auto actor = crae::Factory::Instance().Create<crae::Actor>("Ghost");
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
	std::cout << GetScore() << std::endl;

}

void CollinGame::OnPlayerDead(const crae::Event& event)
{
	m_gameState = gameState::playerDead;
	m_lives--;
	m_stateTimer = 3;
}

void CollinGame::OnNotify(const crae::Event& event)
{
	if (event.name == "EVENT_ADD_POINTS")
	{
		OnAddPoints(event);
	}
	if (event.name == "EVENT_PLAYER_DEAD")
	{
		OnPlayerDead(event);
	}

}
