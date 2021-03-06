#pragma once

#ifdef _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#endif

#pragma comment(lib, "msimg32.lib")
#pragma comment(lib, "Strmiids.lib")

// Windows API
#define NOMINMAX
#include <Windows.h>

// C++ Standard Library
#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <functional>
#include <memory>
#include <mutex>
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <string>

// DirectX
#include <wrl/client.h>
#include <dshow.h>

// DirectXTK
#include <Audio.h>

// K WinAPI Game Framework
#include "enum.h"
#include "type.h"