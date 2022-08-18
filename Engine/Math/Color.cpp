#include "Color.h"

namespace nae
{
	const Color Color::white{ 255, 255, 255 };
	const Color Color::black{0, 0, 0};
	const Color Color::red{255, 0, 0};
	const Color Color::green{0, 255, 0};
	const Color Color::blue{0, 0, 255};


	std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		std::string str;

		str = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
		color.r = (uint8_t)((std::stof(str)) * 255);

		line = line.substr(line.find(",") + 1);

		str = line.substr(0, line.find(",") + 1);
		color.g = (uint8_t)((std::stof(str)) * 255);

		//line = line.substr(line.find(",") + 1);

		str = line.substr(line.find(",") + 1, line.find("}") - line.find(",") + 1);
		color.b = (uint8_t)((std::stof(str)) * 255);


		color.a = 255;


		return stream;
	}
	std::ostream& operator<<(std::ostream& stream, const Color& color)
	{
		stream << (int)color.r << " " << (int)color.g << " " << (int)color.b << " " << (int)color.a;

		return stream;
	}
}