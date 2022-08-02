#pragma once
// !! add necessary includes 
#include <string>
// !! forward declare the _TTF_Font struct 
struct _TTF_Font;

namespace crae
{
	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void Load(const std::string& filename, int fontSize);
		auto getFont() { return m_ttfFont; }

		friend class Text;

	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}