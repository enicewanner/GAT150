#include <iostream>
#include "Engine.h"

int main()
{
	std::cout << "Hello World" << std::endl;

	nae::InitializeMemory();
	nae::SetFilePath("../Assets");

	nae::g_audioSystem.Initialize();
	nae::g_renderer.Initialize();
	nae::g_inputSystem.Initialize();

	nae::g_renderer.CreateWindow("Yes", 800, 800);

	std::shared_ptr<nae::Texture> texture = std::make_shared<nae::Texture>();
	texture->Create(nae::g_renderer, "alucard.bmp");

	bool cont = true;
	while (cont)
	{
		nae::g_time.Tick();
		nae::g_audioSystem.Update();
		nae::g_inputSystem.Update();

		if (nae::g_inputSystem.GetKeyDown(nae::key_escape)) cont = false;

		nae::g_renderer.BeginFrame();
		nae::g_renderer.Draw(texture, { 400, 300 }, 0);
		nae::g_renderer.EndFrame();
	}

	nae::g_audioSystem.Shutdown();
	nae::g_renderer.Shutdown();
	nae::g_inputSystem.Shutdown();

}