#include "Color.h"

namespace crae
{
	 const Color white = {255, 255, 255, 255};
	 const Color black = {0,0,0,255};
	 const Color red = {255,0,0,255};
	 const Color green = {0,255,255,255};
	 const Color blue = {0,0,255,255};

	std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		std::string str;


		str = line.substr(line.find("{") + 1, line.find(",") - line.find("{") + 1);
		color.r = (uint8_t)(std::stof(str) * 255);

		line = line.substr(line.find(',') + 1);
		str = str = line.substr(0, line.find(","));
		color.g = (uint8_t)(std::stof(str) * 255);

		line = line.substr(line.find(',') + 1);
		str = str = line.substr(0, line.find("}"));
		color.b = (uint8_t)(std::stof(str) * 255);
		color.a = 255;

		return stream;
	}
}