#pragma once 
#include "ILogger.h"


namespace Logger
{
	class CFileLogger: public ILogger
	{
	private:
		std::string m_loggerName;
		std::string m_logFilePath;
		LogSeverity m_severity;

	public:
		CFileLogger(std::string loggerName, LogSeverity loggerSeverity, std::string savePath);
		~CFileLogger();

		//Inherited from ILogger
		virtual void set_SeverityLevel(LogSeverity severity) override;
		virtual void Log(LogSeverity severity, std::string message) override;

	private:
		void Flush();

	};
}