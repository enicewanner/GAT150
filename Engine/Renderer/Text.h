#pragma once
// !! add necessary includes 
#include <string>

// !! forward declare the SDL_Texture struct 

struct SDL_Texture;

namespace nae
{
	// !! forward declare the Font, Renderer, Color and Vector2 classes no
	class Font;
	class Renderer;
	struct Color;
	struct Vector2;

	class Text
	{
	public:
		//<!!create default constructor>
		Text() = default;
		Text(Font* font); //<!!initialize m_font with font parameter>{}
		~Text();

		void Create(Renderer& renderer, const std::string& text, const Color& color);
		void Draw(Renderer& renderer, const Vector2& position);

	private:
		Font* m_font = nullptr; //<!!initialize m_font to nullptr>
		SDL_Texture* m_texture = nullptr; //<!!initialize m_texture to nullptr>

		friend class Font;
	};
}