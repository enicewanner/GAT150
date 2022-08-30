#include "Font.h"
#include "Core/Logger.h"
#include <SDL_ttf.h>

namespace nae
{
	Font::Font(const std::string& filename, int fontSize)
	{
		Font::Load(filename, fontSize);
	}

	Font::~Font()
	{
		if (m_ttfFont != NULL)
		{
			TTF_CloseFont(m_ttfFont);
		}
	}

	SDL_Surface* Font::CreateSurface(const std::string& text, const Color& color)
	{
		// !! convert Color color to SDL_Color c 
		// !! get address of color (&) 
		// !! cast to SDL_Color 
		// !! dereference 
		SDL_Color c = *((SDL_Color*)(&color));
		SDL_Surface* surface = TTF_RenderText_Solid(m_ttfFont, text.c_str(), c);

		// !! check if surface is nullptr, if so then LOG error 
		if (surface == nullptr)
		{
			LOG(SDL_GetError());
		}

		return surface;
	}

	void Font::Load(const std::string& filename, int fontSize)
	{
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
	}

}

