// TreNES.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ROM.cpp"
#include "PPU.cpp"
#include "Memory.cpp"

int main()
{
	PPU::InitialisePPU(); //Setup 16kb VRAM base addresses and 256b SPR_RAM
	Memory::InitialiseMemory(); //Setup Main RAM
	ROM currentROM = ROM(0);
	printf("Enter Rome Directory:\n");
	string ROMdirectory;
	cin >> ROMdirectory;
	currentROM.LoadROM(ROMdirectory);
	while (true) {} //keep console open for now; todo: implement boot , CPU, PPU, GL reference
    return 0;
}

