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
	texture->Create(nae::g_renderer, "spip.bmp");
	nae::g_audioSystem.AddAudio("laser", "Laser_Shoot.wav");

	//create actors
	nae::Scene scene;


	nae::Transform transform{nae::Vector2 {100, 100}, 90, {1, 1} };
	std::unique_ptr<nae::Actor> actor = std::make_unique<nae::Actor>(transform);
	std::unique_ptr<nae::PlayerComponent> pcomponent = std::make_unique<nae::PlayerComponent>();
	actor->AddComponent(std::move(pcomponent));
	std::unique_ptr<nae::PhysicsComponent> phcomponent = std::make_unique<nae::PhysicsComponent>();
	actor->AddComponent(std::move(phcomponent));
	std::unique_ptr<nae::SpriteComponent> scomponent = std::make_unique<nae::SpriteComponent>();
	scomponent->m_texture = texture;
	actor->AddComponent(std::move(scomponent));
	std::unique_ptr<nae::AudioComponent> acomponent = std::make_unique<nae::AudioComponent>();
	acomponent->m_soundname = "laser";
	actor->AddComponent(std::move(acomponent));
	scene.Add(std::move(actor));

	float angle = 0;



	bool cont = true;
	while (cont)
	{
		nae::g_time.Tick();
		nae::g_audioSystem.Update();
		nae::g_inputSystem.Update();

		if (nae::g_inputSystem.GetKeyDown(nae::key_escape)) cont = false;

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