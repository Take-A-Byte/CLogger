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
		virtual void Flush(std::string logMessage) = 0;
		virtual void Trace(std::string message) override;
		virtual void Debug(std::string message) override;
		virtual void Info(std::string message) override;
		virtual void Warn(std::string message) override;
		virtual void Error(std::string message) override;
		virtual void Critical(std::string message) override;

	private:
		void log(LogSeverity severity, std::string message);
	};
}
