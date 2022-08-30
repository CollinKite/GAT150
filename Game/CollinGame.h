#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"

class CollinGame : public crae::Game, public crae::INotify
{
public:
	enum class gameState
	{
		titleScreen,
		startLevel,
		game,
		playerDead,
		gameOver
	};
public:

	// Inherited via Game
	virtual void Initialize() override;

	virtual void Shutdown() override;

	virtual void Update() override;

	virtual void Draw(crae::Renderer& renderer) override;

	void OnAddPoints(const crae::Event& event);
	void OnPlayerDead(const crae::Event& event);
private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;

	// Inherited via INotify
	virtual void OnNotify(const crae::Event& event) override;
};