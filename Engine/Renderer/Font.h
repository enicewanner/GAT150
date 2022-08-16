#pragma once

#include "Resource/Resource.h"
#include <iostream>


// !! forward declare the _TTF_Font struct 
struct _TTF_Font;

namespace nae
{
	class Font : public Resource
	{
	public:
		friend class Text;

		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(const std::string& filename, void* data) override { return false; }
		void Load(const std::string& filename, int fontSize);

	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}