#pragma once 
#include "CLoggerBase.h"


namespace Logger
{
	class CFileLogger: public CLoggerBase
	{
	private:
		std::string m_logFilePath;

	public:
		CFileLogger(std::string loggerName, LogSeverity loggerSeverity, std::string savePath);
		~CFileLogger();

	private:
		virtual void Flush(std::string logMessage) override;

	};
}