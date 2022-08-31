#pragma once 
 
#include "Resource/Resource.h"
#include <string>

struct _TTF_Font;
struct SDL_Surface;

namespace nae{

	struct Color;

	class Font : public Resource{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		SDL_Surface* CreateSurface(const std::string& text, const Color& color);

		bool Create(std::string filename, ...) override;
		bool Load(const std::string& filename, int fontSize);

		friend class Text;

	private:
		_TTF_Font* m_ttfFont = nullptr;
		
	};
}