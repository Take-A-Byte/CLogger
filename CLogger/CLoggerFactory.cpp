#include "stdafx.h"
#include "CLoggerFactory.h"

#include "CFileLogger.h"

using namespace Logger;

CLoggerFactory::CLoggerFactory()
{
}


CLoggerFactory::~CLoggerFactory()
{
}

ILogger* CLoggerFactory::CreateLogger(std::string loggerName, LogSeverity loggerSeverity, std::string savePath)
{
	return new CFileLogger(loggerName, loggerSeverity, savePath);
}
