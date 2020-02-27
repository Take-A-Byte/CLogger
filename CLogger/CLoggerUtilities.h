#pragma once 
#include "ILogger.h"

#define nameof(name) #name

namespace Logger
{
	namespace Utilities
	{
		class CLoggerUtilities
		{
		public:
			static std::string NameOfSeverity(LogSeverity severity);
		};
	}
}