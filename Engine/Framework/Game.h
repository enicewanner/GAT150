#pragma once
#include <memory>

namespace nae
{
	class Renderer;
	class Scene;

	class Game
	{
	public:
		Game() = default;
		virtual ~Game() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;

		virtual void Update() = 0;
		virtual void Draw(Renderer& renderer) = 0;

		int GetScore() { return m_score; }
		int AddScore(int points) { return m_score += points; }

	protected:
		std::unique_ptr<Scene> m_scene;
		int m_score = 0;

	};
}