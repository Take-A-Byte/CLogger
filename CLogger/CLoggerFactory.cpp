#include "stdafx.h"
#include "CLoggerFactory.h"

#include "CLogger.h"

using namespace Logger;

CLoggerFactory::CLoggerFactory()
{
}


CLoggerFactory::~CLoggerFactory()
{
}

ILogger* CLoggerFactory::CreateLogger(std::string loggerName, LogSeverity loggerSeverity, std::string savePath)
{
	return new CLogger(loggerName, loggerSeverity, savePath);
}
