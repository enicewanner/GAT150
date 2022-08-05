#include <iostream>
#include "Engine.h"

int add(int a, int b)
{
	return a + b;
}

constexpr int add_c(int a, int b)
{
	return a + b;
}

int main()
{
	constexpr int i1 = 0;

	int i2 = add(6, 7);
	constexpr int i3 = add_c(6, 7);

	constexpr float degrees = Math::RadToDeg(Math::Pi);

	std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;
	std::cout << __FUNCTION__ << std::endl;


	
	nae::InitializeMemory();
	nae::SetFilePath("../Assets");

	nae::g_audioSystem.Initialize();
	nae::g_renderer.Initialize();
	nae::g_inputSystem.Initialize();

	nae::g_renderer.CreateWindow("Yes", 800, 800);

	std::shared_ptr<nae::Texture> texture = std::make_shared<nae::Texture>();
	texture->Create(nae::g_renderer, "alucard.bmp");

	float angle = 0;



	bool cont = true;
	while (cont)
	{
		nae::g_time.Tick();
		nae::g_audioSystem.Update();
		nae::g_inputSystem.Update();

		if (nae::g_inputSystem.GetKeyDown(nae::key_escape)) cont = false;

		angle += 360.0f * nae::g_time.deltaTime;

		nae::g_renderer.BeginFrame();
		nae::g_renderer.Draw(texture, { 400, 400 }, angle, {1, 1}, {0.5f, 1.0f});
		nae::g_renderer.EndFrame();
	}

	nae::g_audioSystem.Shutdown();
	nae::g_renderer.Shutdown();
	nae::g_inputSystem.Shutdown();

}