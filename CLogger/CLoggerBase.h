#pragma once
#include "ILogger.h"
#include <vector>

namespace Logger
{
	class CLoggerBase: public ILogger 
	{
	private:
		std::string m_loggerName;
		LogSeverity m_baseSeverity;
		bool m_printLogSeverity;
		bool m_manualFlush;

		std::vector<std::string> m_unFlushedLogs;

	public:
		CLoggerBase(std::string loggerName, LogSeverity severity);
		
		// Inherited via ILogger
		virtual void set_SeverityLevel(LogSeverity severity) override;
		virtual void set_printLogSeverity(bool printLogSeverity) override;

		virtual void Trace(std::string message) override;
		virtual void Debug(std::string message) override;
		virtual void Info(std::string message) override;
		virtual void Warn(std::string message) override;
		virtual void Error(std::string message) override;
		virtual void Critical(std::string message) override;

		virtual void set_ManualFlush(bool on) override;
		virtual void ForceFlush() override;

	protected:
		virtual void Flush(std::string logMessage) = 0;

	private:
		void log(LogSeverity severity, std::string message);
	};
}
