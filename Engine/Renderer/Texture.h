#pragma once
#include "Renderer.h"
#include "../Math/Vector2.h"
#include <string>

struct SDL_Texture;

namespace nae
{
	class Texture
	{
	public:
		friend class Renderer;
		friend struct SDL_Texture;
		
		Texture() = default;
		~Texture();

		bool Create(Renderer& renderer, const std::string& file);

		Vector2 GetSize() const;


	private:
		SDL_Texture* m_texture = nullptr;
	};
}
