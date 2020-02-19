#pragma once
#include<iostream>

#ifdef CLoggerDLL
#define CLoggerAPI __declspec(dllexport)
#else
#define CLoggerAPI __declspec(dllimport)
#endif