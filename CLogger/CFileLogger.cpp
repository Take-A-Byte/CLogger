#include"stdafx.h"

#include <direct.h>
#include<fstream>

#include"CFileLogger.h"

using namespace Logger;

CFileLogger::CFileLogger(std::string loggerName, LogSeverity severity, std::string savePath)
{
	m_loggerName = loggerName;

	int check = _mkdir(savePath.c_str());
	m_logFilePath = savePath + '/' + m_loggerName + ".txt";
	
	std::ofstream logFile(m_logFilePath);
}

CFileLogger::~CFileLogger()
{

}


void CFileLogger::set_SeverityLevel(LogSeverity severity)
{

}

void CFileLogger::Log(LogSeverity severity, std::string message)
{
	std::stringstream log;

	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);
	log << '[' << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << "]  ";

	log << m_loggerName << ": ";
	log << message << std::endl;

	std::ofstream logFile;
	logFile.open(m_logFilePath, std::ios::out | std::ios::app);
	if (logFile.is_open())
	{
		logFile << log.str() << std::endl;
	}

}