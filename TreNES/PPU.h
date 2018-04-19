#include "stdafx.h"
#include "DataStructs.h"

class PPU
{
private: static byte* VRAM;
private: static byte* SPR_RAM;
private:
	// Disallow creating an instance of this object
	PPU() {}
public:
	static void InitialisePPU()
	{
		VRAM = new byte[0x3FFF]; //Plan: Backtrack mirrors to original mem
		SPR_RAM = new byte[256];
	}
};
