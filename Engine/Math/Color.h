#pragma once
#include <cstdint>
#include <string>
#include <algorithm>
namespace crae
{
	//typedef unsigned char u8_t; Old version - defines unsigned char as a unsigned 8 bit
	//using u8_t = unsigned char; Modern Version does same thing

	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	inline std::istream& operator >> (std::istream& stream, Color& color)
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