#pragma once

#ifdef _DEBUG
	#define LOG(format, ...) nae::g_logger.log(format, __VA_ARGS__)
#else
	#define LOG(format, ...) ((void)0)
#endif // _DEBUG


namespace nae
{
	class Logger
	{
	public:
		Logger() = default;
		~Logger() = default;

		void log(const char* format, ...);

	private:

	};

	extern Logger g_logger;

}