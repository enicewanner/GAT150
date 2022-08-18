#include <iostream>
#include "Engine.h"



int main()
{
	nae::InitializeMemory();
	nae::SetFilePath("../Assets");



	//intialize sys
	nae::g_audioSystem.Initialize();
	nae::g_renderer.Initialize();
	nae::g_inputSystem.Initialize();
	nae::g_resources.Initialize();

	nae::g_renderer.CreateWindow("Yes", 800, 800);
	nae::g_renderer.SetClearColor(nae::g_renderer.m_clearColor);

	//load assets
	//std::shared_ptr<nae::Texture> texture = std::make_shared<nae::Texture>();
	//texture->Create(nae::g_renderer, "spip.bmp");
	//

	std::shared_ptr<nae::Texture> texture = nae::g_resources.Get<nae::Texture>("spip.bmp");


	//create actors
	nae::Scene scene;


	rapidjson::Document document;
	bool success = nae::json::Load("level.txt", document);


	scene.Read(document);
	

	float angle = 0;



	bool cont = true;
	while (cont)
	{
		nae::g_time.Tick();
		nae::g_audioSystem.Update();
		nae::g_inputSystem.Update();

		//if (nae::g_inputSystem.GetKeyDown(nae::key_escape)) cont = false;

		//angle += 360.0f * nae::g_time.deltaTime;
		scene.Update();


		nae::g_renderer.BeginFrame();
		//nae::g_renderer.Draw(texture, { 400, 400 }, angle, {1, 1}, {0.5f, 1.0f});
		scene.Draw(nae::g_renderer);
		nae::g_renderer.EndFrame();
	}

	nae::g_audioSystem.Shutdown();
	nae::g_renderer.Shutdown();
	nae::g_inputSystem.Shutdown();

}