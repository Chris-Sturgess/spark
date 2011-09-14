// win32.cpp
// Compiles in the WinMain entry point when targeting Windows platform

#ifdef _WINDOWS

//Include windows headers
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

//Regular entry point
int main();

//Windows entry point
int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
	//Call normal entry point
	return main();
}

#endif