#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "DataStructs.h"


using namespace std;

class ROM
{
public:
	byte* ROM_bytes = new byte[0];
	ROM(u32 size)
	{
		byte* ROM_bytes = new byte[size];
	}
	void LoadROM(string directory)
	{
		std::ifstream infile(directory); //open file
		infile.seekg(0, infile.end); //get length of file
		int length = infile.tellg();
		infile.seekg(0, infile.beg);
		char* newArray = new sbyte[length];
		// don't overflow the buffer!
		if (length > sizeof(ROM_bytes))
		{
			length = sizeof(ROM_bytes);
		}
		//read file
		infile.read(newArray, length);
		ROM_bytes = reinterpret_cast<byte*>(newArray);
	}
	byte getByte(u32 addr)
	{
		ROM_bytes[addr];
	}
	sbyte getSByte(u32 addr)
	{
		*(s8*)ROM_bytes[addr];
	}
	u16 getU16(u32 addr)
	{
		*(u16*)&ROM_bytes[addr];
	}
	s16 getS16(u32 addr)
	{
		*(s16*)&ROM_bytes[addr];
	}
	bool isFileNESROM(u32 header)
	{
		if (header == 0x4E45531A) return true; //"NES" format 0x1A
		else return false;
	}
	byte PRGROMBankCount()
	{
		return ROM_bytes[5];
	}
	byte VROMBankCount()
	{
		return ROM_bytes[5];
	}
	byte getControlByte1()
	{
		return ROM_bytes[6];
	}
	byte getControlByte2()
	{
		return ROM_bytes[7];
	}
	byte RAMBankCount()
	{
		return ROM_bytes[8];
	}
	bool hasVerticalMemMirror(byte* ControlByte1)
	{
		if ((*ControlByte1 & 0x80) == 0) return false; //horizontal
		else return true; //vertical
	}
	bool hasBatteryBackedRAM(byte* ControlByte1)
	{
		if ((*ControlByte1 & 0x40) == 0) return false; //Does not have
		else return true; //Does have
	}
	bool hasTrainer(byte* ControlByte1)
	{
		if ((*ControlByte1 & 0x20) == 0) return false; //Does not have
		else return true; //Does have
	}
	bool hasFourScreenMirroring(byte* ControlByte1)
	{
		if ((*ControlByte1 & 0x10) == 0) return false; //Does not have
		else return true; //Does have
	}
}; 