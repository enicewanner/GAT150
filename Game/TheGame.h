#pragma once
#include "Framework/Game.h"

class TheGame : public nae::Game
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
	virtual void Draw(nae::Renderer& renderer) override;

	void OnAddPoints(const nae::Event& _event);
	void OnPlayerDead(const nae::Event& _event);

private:
	gameState m_gameState = gameState::titleScreen;

	float m_stateTimer = 0;
	int m_lives = 3;

};