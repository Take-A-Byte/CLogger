#include "stdafx.h"

#include "CLoggerUtilities.h"

using namespace Logger;
using namespace Logger::Utilities;

std::string CLoggerUtilities::NameOfSeverity(LogSeverity severity)
{
	switch (severity) {
	case LogSeverity::Trace:return nameof(Trace);
	case LogSeverity::Debug:return nameof(Debug);
	case LogSeverity::Info:return nameof(Info);
	case LogSeverity::Warn:return nameof(Warn);
	case LogSeverity::Error:return nameof(Error);
	case LogSeverity::Critical:return nameof(Critical);
	default: return nameof(Trace);
	}
}
