#pragma once 
#include "CLoggerBase.h"


namespace Logger
{
	class CConsoleLogger : public CLoggerBase
	{
	public:
		CConsoleLogger(std::string loggerName, LogSeverity loggerSeverity);
		~CConsoleLogger();

	private:
		virtual void Flush(std::string logMessage) override;

	};
}