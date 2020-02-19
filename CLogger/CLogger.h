#pragma once 
#include "ILogger.h"

#include <string>

namespace Logger
{
	class CLogger: public ILogger
	{
	private:
		std::string m_loggerName;
		std::string m_logFilePath;
		LogSeverity m_severity;

	public:
		CLogger(std::string loggerName, LogSeverity loggerSeverity, std::string savePath);
		~CLogger();

		//Inherited from ILogger
		virtual void set_SeverityLevel(LogSeverity severity) override;
		virtual void Log(LogSeverity severity, std::string message) override;

	private:
		void Flush();

	};
}