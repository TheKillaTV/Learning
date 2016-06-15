#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <TlHelp32.h>
#endif

// Note to self. Look up these macros.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define DEBUG_BOT

#ifdef __linux
#ifndef NULL
#define NULL 0
#endif
#endif

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <fstream>
