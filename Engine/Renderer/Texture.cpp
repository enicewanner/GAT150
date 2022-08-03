#include "Texture.h"
#include "Renderer.h"
#include "Core/Logger.h"
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
		if (surface == nullptr)
		{
			LOG(SDL_GetError());
			return false;
		}

		//create texture
		m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
		if (m_texture == nullptr)
		{
			LOG(SDL_GetError());
			SDL_FreeSurface(surface);
			return false;
		}
		SDL_FreeSurface(surface);

		return true;

	}

	nae::Vector2 Texture::GetSize() const
	{
		SDL_Point point;
		if (SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y));


		return (float)point.x, (float)point.y;
	}

}


