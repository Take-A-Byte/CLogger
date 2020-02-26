#pragma once
#include "ILogger.h"

namespace Logger
{
	class CLoggerAPI CLoggerFactory
	{
	public:
		~CLoggerFactory();

		/*
			params:
			* severity = it is the least severity of log that would be printed by this logger
			* savePath = the path where the log file will be saved. 
						 By default, the log file will be saved in the Log folder
						 with the name of logger
		*/
		static ILogger* CreateLogger(std::string loggerName, LogSeverity loggerSeverity = LogSeverity::Trace, std::string savePath = "./Log");

	private:
		CLoggerFactory();
	};
}
