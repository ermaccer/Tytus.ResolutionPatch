// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "ic.h"
#include <iostream>
void Init()
{
	GetDisplayModes();
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Init();
	}
}