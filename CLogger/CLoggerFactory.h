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
			* loggerName = name of logger.
			* printLogSeverity = if set, every log will be printed with it serverity.
								 By default, log severity will be printed with every log.
			* loggerSeverity = it is the least severity of log that would be printed by this logger.
							   By default, logger severity is set lowest.
			* savePath = the path where the log file will be saved. 
						 By default, the log file will be saved in the "Log" folder created in
						 the folder where the program is ran; with the name of logger
			*
			* NOTE: by default manual flush will be off.
		*/
		static ILogger* CreateFileLogger(
			std::string loggerName, 
			bool printLogSeverity = true,
			LogSeverity loggerSeverity = LogSeverity::Trace,
			std::string savePath = "./Log");

		/*
			This function will create an object of console logger.
			params:
			* loggerName = name of logger.
			* printLogSeverity = if set, every log will be printed with it serverity.
								 By default, log severity will be printed with every log.
			* loggerSeverity = it is the least severity of log that would be printed by this logger.
							   By default, logger severity is set lowest.
			*
			* NOTE: by default manual flush will be off.
		*/
		static ILogger* CreateConsoleLogger(
			std::string loggerName,
			bool printLogSeverity = true,
			LogSeverity loggerSeverity = LogSeverity::Trace);

	private:
		CLoggerFactory();
	};
}
