#include "TheGame.h"
#include "Engine.h"

void TheGame::Initialize()
{
	m_scene = std::make_unique<nae::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "level.txt", "prefabs.txt", "Tilemap.txt"};

	for (auto sceneName : sceneNames)
	{
		bool success = nae::json::Load(sceneName, document);
		if (!success)
		{
			LOG("Could not load scene %s", sceneName.c_str());
			continue;
		}
		m_scene->Read(document);
	}


	m_scene->Initialize();



	//nae::g_eventManager.Subscribe("EVENTS_AND_POINTS", std::bind(&TheGame::OnAddPoints, this, std::placeholders::_1));

}

void TheGame::Shutdown()
{
	m_scene->RemoveAll();
}

void TheGame::Update()
{
	switch (m_gameState)
	{
	case TheGame::gameState::titleScreen:
		if (nae::g_inputSystem.GetKeyState(nae::key_space) == nae::InputSystem::State::Pressed)
		{
			//m_scene->GetActorFromName("Title")->SetActive(false)

			m_gameState = gameState::startLevel;
		}

		break;
	case TheGame::gameState::startLevel:
		for (int i = 0; i < 10; i++)
		{
			auto actor = nae::Factory::Singleton::Instance().Create<nae::Actor>("player");
			//actor->m_transform.position = {400.0f,  300.0f};
			//actor->Initialize();

			//m_scene->Add(std::move(actor));

		}

		break;
	case TheGame::gameState::game:
		break;
	case TheGame::gameState::playerDead:
		m_stateTimer -= nae::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = (m_lives > 0) ? gameState::startLevel : gameState::titleScreen;
		}
		break;
	case TheGame::gameState::gameOver:
		break;
	default:
		break;
	}


	m_scene->Update();
}

void TheGame::Draw(nae::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void TheGame::OnAddPoints(const nae::Event& _event)
{
	AddScore(std::get<int>(_event.data));

	std::cout << _event.name << std::endl;
	std::cout << std::get<int>(_event.data) << std::endl;
}

void TheGame::OnPlayerDead(const nae::Event& _event)
{
	m_gameState == gameState::playerDead;

}
