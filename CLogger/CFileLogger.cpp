#include"stdafx.h"

#include <direct.h>
#include<fstream>

#include"CFileLogger.h"

using namespace Logger;

CFileLogger::CFileLogger(std::string loggerName, LogSeverity severity, std::string savePath): CLoggerBase(loggerName, severity)
{
	m_logFilePath = savePath;

	int check = _mkdir(savePath.c_str());
	m_logFilePath = savePath + '/' + loggerName + ".txt";
	
	std::ofstream logFile(m_logFilePath);
}

CFileLogger::~CFileLogger()
{

}

void CFileLogger::Flush(std::string logMessage)
{
	std::ofstream logFile;
	logFile.open(m_logFilePath, std::ios::out | std::ios::app);
	if (logFile.is_open())
	{
		logFile << logMessage;
	}
}
