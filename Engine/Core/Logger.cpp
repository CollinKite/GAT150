#include "Logger.h"
#include <iostream>
#include <cstdarg>
#include <stdio.h>

namespace crae
{
	Logger g_logger;

	void Logger::Log(const char* format, ...)
	{
		va_list args;
		va_start(args, format);

		char str[1024];
		vsprintf_s(str, 1024, format, args);
//		printf("%s", str);
		va_end(args);

		std::cout << str << std::endl;
	}
}
