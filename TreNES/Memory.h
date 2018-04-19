#pragma once
#include "DataStructs.h"

class Memory
{
private: static byte* RAM;
private:
	// Disallow creating an instance of this object
	Memory() {}
public:
	static void InitialiseMemory()
	{
		RAM = new byte[0xFFFF]; //Allocate all UInt16 address range
	}
};

