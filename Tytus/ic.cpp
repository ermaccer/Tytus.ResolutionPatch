#include "pch.h"
#include "ic.h"

#include "MemoryMgr.h"

using namespace Memory::VP;

short resolutionX[] =	 { 640,800,1024,1280,1600,1280,1360,1366,1440,1600,1680,1920,2560,3840 };
short resolutionY[] =	 { 480,600,768,1024,1200,720,768,768,900, 900, 1050,1080,1440,2160 };
short resolutionBits[] = { 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32 };
const char* resolutionNames[] = {
	"640x480",
	"800x600",
	"1024x768",
	"1280x1024",
	"1600x1200",
	"1280x720",
	"1360x768",
	"1366x768",
	"1440x900",
	"1600x900",
	"1680x1050",
	"1920x1080",
	"2560x1440",
	"3840x2160"
};


void GetDisplayModes()
{
	Patch<int>(0x4AF02D, (int)&resolutionNames);
	Patch<int>(0x4B0ABD, (int)&resolutionNames);
	Patch<int>(0x4B0ACE, (int)&resolutionNames);
	Patch<int>(0x4B115E, (int)&resolutionNames);
	Patch<int>(0x4B116F, (int)&resolutionNames);
	Patch<int>(0x4B1210, (int)&resolutionNames);

	for (int i = 0; i < 204; i++)
		Patch<char>(0x58F59E + i, 0x00);

	for (int i = 0; i < 14; i++)
	{
		struct { short data[4]; } data = { resolutionX[i], resolutionY[i], resolutionBits[i],0x00 };
		Patch(0x58F59E + (i * 8), data);
	}

	Patch<int>(0x58F66C, 1);

}