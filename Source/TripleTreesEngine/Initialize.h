#pragma once
#include "windows.h"
#include "direct.h"
#include <iostream>

using namespace std;

class Initialize
{
public:
	static bool CheckIsOnlyInstance(LPCTSTR gameTitle);
	static bool CheckHardDriveSpace(const DWORDLONG diskSpaceNeeded);
	static bool CheckRAM(int requiredInMB);
	static bool CheckInputDevice();
	static bool CheckOutputDevice();
	static bool CheckCPUSpeed(int requiredInGHZ);
};