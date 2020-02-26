#pragma once
#include "stdafx.h"

namespace Logger
{
	enum CLoggerAPI LogSeverity
	{
		Trace = 0,
		Debug = 1,
		Info = 2,
		Warn = 3,
		Error = 4,
		Critical = 5
	};

	class CLoggerAPI ILogger
	{
	public:
		virtual ~ILogger() = default;

		virtual void set_SeverityLevel(LogSeverity severity) = 0;
		virtual void set_printLogSeverity(bool printLogSeverity) = 0;
		virtual void Log(LogSeverity severity, std::string message) = 0;

		virtual void Flush(std::string logMessage) = 0;
	};
}