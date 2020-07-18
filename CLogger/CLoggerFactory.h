#pragma once
#include "ILogger.h"

namespace Logger
{
	class CLoggerAPI CLoggerFactory
	{
	public:
		~CLoggerFactory();

		/*
			This function will create an object of file logger.
			params:
			* severity = it is the least severity of log that would be printed by this logger
			* savePath = the path where the log file will be saved. 
						 By default, the log file will be saved in the "Log" folder created in
						 the folder where the program is ran; with the name of logger
		*/
		static ILogger* CreateFileLogger(std::string loggerName, LogSeverity loggerSeverity = LogSeverity::Trace, std::string savePath = "./Log");

		/*
			This function will create an object of console logger.
			params:
			* severity = it is the least severity of log that would be printed by this logger
		*/
		static ILogger* CreateConsoleLogger(std::string loggerName, LogSeverity loggerSeverity = LogSeverity::Trace);

	private:
		CLoggerFactory();
	};
}
