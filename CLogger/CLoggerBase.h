#pragma once
#include "ILogger.h"

namespace Logger
{
	class CLoggerBase: public ILogger 
	{
	private:
		LogSeverity m_baseSeverity;
		bool m_printLogSeverity;
		std::string m_loggerName;

	public:
		CLoggerBase(std::string loggerName, LogSeverity severity);
		
		// Inherited via ILogger
		virtual void set_SeverityLevel(LogSeverity severity) override;
		virtual void set_printLogSeverity(bool printLogSeverity) override;
		virtual void Log(LogSeverity severity, std::string message) override;
		virtual void Flush(std::string logMessage) = 0;
	};
}
