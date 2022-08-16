#pragma once
#include <cstdint>
#include <string>
#include <iostream>
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

		uint8_t operator [] (size_t index) const { return (&r)[index]; }
		uint8_t& operator [] (size_t index) { return (&r)[index]; }

		static const Color white;
		static const Color black;
		static const Color red;
		static const Color green;
		static const Color blue;

	};
	std::istream& operator >> (std::istream& stream, Color& color);
	std::ostream& operator << (std::ostream& stream, const Color& color);

}