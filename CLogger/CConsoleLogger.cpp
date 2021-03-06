#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#include "CConsoleLogger.h"

using namespace Logger;

CConsoleLogger::CConsoleLogger(std::string loggerName, LogSeverity severity) : CLoggerBase(loggerName, severity)
{
}

CConsoleLogger::~CConsoleLogger()
{

}

void CConsoleLogger::Flush(std::string logMessage)
{
	std::cout << logMessage << std::endl;
}
