#include <iostream>
#include "Engine.h"
#include "TheGame.h"



int main()
{
	nae::InitializeMemory();
	nae::SetFilePath("../Assets");



	//intialize sys
	nae::g_audioSystem.Initialize();
	nae::g_renderer.Initialize();
	nae::g_inputSystem.Initialize();
	nae::g_resources.Initialize();
	nae::g_physicsSystem.Initialize();
	nae::g_eventManager.Initialize();

	nae::Engine::Instance().Register();

	nae::g_renderer.CreateWindow("Yes", 800, 800);

	//create game

	std::unique_ptr<TheGame> game = std::make_unique<TheGame>();
	game->Initialize();


	bool cont = true;
	while (cont)
	{
		nae::g_time.Tick();
		nae::g_audioSystem.Update();
		nae::g_inputSystem.Update();
		nae::g_physicsSystem.Update();
		nae::g_eventManager.Update();

		if (nae::g_inputSystem.GetKeyDown(nae::key_escape)) cont = false;

		//angle += 360.0f * nae::g_time.deltaTime;
		game->Update();


		nae::g_renderer.BeginFrame();
		//nae::g_renderer.Draw(texture, { 400, 400 }, angle, {1, 1}, {0.5f, 1.0f});
		game->Draw(nae::g_renderer);
		//std::cout << "running" << std::endl;
		nae::g_renderer.EndFrame();
	}
	game->Shutdown();
	game.reset();

	nae::Factory::Instance().Shutdown();

	nae::g_eventManager.Shutdown();
	nae::g_audioSystem.Shutdown();
	nae::g_renderer.Shutdown();
	//nae::g_inputSystem.Shutdown();
	//nae::g_physicsSystem.Shutdown();
}