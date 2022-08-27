#pragma once
#include "Framework/Game.h"

class CollinGame : public crae::Game
{
public:

	// Inherited via Game
	virtual void Initialize() override;

	virtual void Shutdown() override;

	virtual void Update() override;

	virtual void Draw(crae::Renderer& renderer) override;
private:
};