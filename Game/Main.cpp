#include "Engine.h"
#include "TheGame.h"
#include <iostream>

int main(){

	nae::InitializeMemory();
	nae::SetFilePath("../Assets");

	nae::g_inputSystem.Initialize();
	nae::g_renderer.Initialize();
	nae::g_audioSystem.Initialize();
	nae::g_resources.Initialize();
	nae::g_physicsSystem.Initialize();
	nae::g_eventManager.Initialize();

	nae::Engine::Instance().Register();

	nae::g_renderer.CreateWindow("There is Game", 800, 600);
	nae::g_renderer.SetClearColor(nae::Color{ 10, 10, 10, 255 });

	std::unique_ptr<TheGame> game = std::make_unique<TheGame>();
	
	game->Initialize();

	float angle = 0;

	bool quit = false;
	while (!quit){
		
		nae::g_time.Tick();
		nae::g_inputSystem.Update();
		nae::g_audioSystem.Update();
		nae::g_physicsSystem.Update();
		nae::g_eventManager.Update();

		if (nae::g_inputSystem.GetKeyDown(nae::key_escape)) quit = true;

		game->Update();

		nae::g_renderer.BeginFrame();

		angle += 360.0f * nae::g_time.deltaTime;

		game->Draw(nae::g_renderer);

		nae::g_renderer.EndFrame();
	}

	game->Shutdown();
	game.reset();

	nae::Factory::Instance().Shutdown();

	nae::g_eventManager.Shutdown();
	nae::g_physicsSystem.Shutdown();
	nae::g_resources.Shutdown();
	nae::g_inputSystem.Shutdown();
	nae::g_renderer.Shutdown();
	nae::g_audioSystem.Shutdown();
}