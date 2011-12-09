// win32.cpp
// compiles in the WinMain entry point when targeting Windows platform

#ifdef _WINDOWS

// include windows headers
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// regular entry point
int main();

// windows entry point
int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
	// call normal entry point
	return main();
}

#endif