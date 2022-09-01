#pragma once

#include "Framework/Game.h"
#include "Framework/Event.h"
#include "rapidjson/rapidjson.h"

class TheGame : public nae::Game, public nae::INotify{

public:
	enum class gameState {

		titleScreen,
		startLevel,
		game, 
		playerDead, 
		gameOver


	};

	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(nae::Renderer& renderer) override;

	void OnAddPoints(const nae::Event& event);
	void OnPlayerDead(const nae::Event& event);

	gameState m_gameState = gameState::titleScreen;
	float m_startTimer = 0;
	float m_spawnTimerE = 5;
	float m_spawnTimerC = 5;
	float m_gameTimer = 60;
	int m_lives = 3;


	// Inherited via INotify
	virtual void OnNotify(const nae::Event& event) override;


};