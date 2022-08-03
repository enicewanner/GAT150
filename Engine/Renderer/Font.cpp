#include "Font.h"
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

	void Font::Load(const std::string& filename, int fontSize)
	{
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
	}

}

