#include "stdafx.h"
#include "CLoggerFactory.h"

#include "CFileLogger.h"
#include "CConsoleLogger.h"

using namespace Logger;

CLoggerFactory::CLoggerFactory()
{
}


CLoggerFactory::~CLoggerFactory()
{
}

ILogger* CLoggerFactory::CreateFileLogger(
	std::string loggerName,
	bool printLogSeverity,
	LogSeverity loggerSeverity,
	std::string savePath)
{
	CFileLogger* newLogger = new CFileLogger(loggerName, loggerSeverity, savePath);
	newLogger->set_printLogSeverity(true);

	return newLogger;
}

ILogger* Logger::CLoggerFactory::CreateConsoleLogger(
	std::string loggerName,
	bool printLogSeverity,
	LogSeverity loggerSeverity)
{
	CConsoleLogger* newLogger = new CConsoleLogger(loggerName, loggerSeverity);
	newLogger->set_printLogSeverity(true);

	return newLogger;
}

