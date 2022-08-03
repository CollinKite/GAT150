#pragma once


namespace crae
{
	class Logger
	{
	public:
		Logger() = default;
		~Logger() = default;

		void Log(const char* format, ...);


	private:


	};

	extern Logger g_logger;
}