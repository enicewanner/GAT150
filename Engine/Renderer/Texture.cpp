#include "Texture.h"
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>

namespace nae
{
	Texture::~Texture()
	{
		if (m_texture) SDL_DestroyTexture(m_texture);
	}

	bool Texture::Create(Renderer& renderer, const std::string& file)
	{
		//load surface
		SDL_Surface* surface = IMG_Load(file.c_str());

		//create texture
		m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
		SDL_FreeSurface(surface);

		return true;

	}

	nae::Vector2 Texture::GetSize() const
	{
		SDL_Point point;
		SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);

		return point.x, point.y;
	}

}


