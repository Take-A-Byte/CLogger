#include "stdafx.h"
#include "CLoggerFactory.h"

#include "CFileLogger.h"
#include "CConsoleLogger.h"

using namespace Logger;

ILogger * Logger::CLoggerFactory::CreateConsoleLogger(std::string loggerName, LogSeverity loggerSeverity)
{
	return new CConsoleLogger(loggerName, loggerSeverity);
}

CLoggerFactory::CLoggerFactory()
{
}


CLoggerFactory::~CLoggerFactory()
{
}

ILogger* CLoggerFactory::CreateFileLogger(std::string loggerName, LogSeverity loggerSeverity, std::string savePath)
{
	return new CFileLogger(loggerName, loggerSeverity, savePath);
}
