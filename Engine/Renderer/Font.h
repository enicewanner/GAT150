#pragma once

#include "Resource/Resource.h"
#include <iostream>


// !! forward declare the _TTF_Font struct 
struct _TTF_Font;
struct SDL_Surface;
struct SDL_Color;
struct Color;

namespace nae
{
	class Font : public Resource
	{
	public:
		friend class Text;

		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		SDL_Surface* CreateSurface(const std::string& text, const Color& color);

		bool Create(std::string filename, ...) override { return false; }
		void Load(const std::string& filename, int fontSize);

	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}