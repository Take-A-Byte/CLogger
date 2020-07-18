#include "stdafx.h"

#include "CLoggerBase.h"
#include "CLoggerUtilities.h"

using namespace Logger;

CLoggerBase::CLoggerBase(std::string loggerName, LogSeverity severity)
{
	m_loggerName = loggerName;
	m_baseSeverity = severity;
}

void CLoggerBase::set_SeverityLevel(LogSeverity severity)
{
	m_baseSeverity = severity;
}

void CLoggerBase::set_printLogSeverity(bool printLogSeverity)
{
	m_printLogSeverity = printLogSeverity;
}

void Logger::CLoggerBase::Trace(std::string message)
{
	log(LogSeverity::Trace, message);
}

void Logger::CLoggerBase::Debug(std::string message)
{
	log(LogSeverity::Debug, message);
}

void Logger::CLoggerBase::Info(std::string message)
{
	log(LogSeverity::Info, message);
}

void Logger::CLoggerBase::Warn(std::string message)
{
	log(LogSeverity::Warn, message);
}

void Logger::CLoggerBase::Error(std::string message)
{
	log(LogSeverity::Error, message);
}

void Logger::CLoggerBase::Critical(std::string message)
{
	log(LogSeverity::Critical, message);
}

void CLoggerBase::log(LogSeverity severity, std::string message)
{
	if (severity < m_baseSeverity)	return;

	std::stringstream log;

	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);
	log << '[' << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << "]  ";

	log << m_loggerName;
	if (m_printLogSeverity)
	{
		log << "[" << Utilities::CLoggerUtilities::NameOfSeverity(severity) << "] :  ";
	}

	log << message << std::endl;

	this->Flush(log.str());
}

