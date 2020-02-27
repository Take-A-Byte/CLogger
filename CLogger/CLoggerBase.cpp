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

void CLoggerBase::Log(LogSeverity severity, std::string message)
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

