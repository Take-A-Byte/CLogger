#pragma once
#include<ctime>
#include<string>
#include<sstream>

#ifdef CLoggerDLL
#define CLoggerAPI __declspec(dllexport)
#else
#define CLoggerAPI __declspec(dllimport)
#endif