#pragma once
#include "windows.h"
#include "direct.h"
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

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
	static void InitGraphicSystem(sf::RenderWindow* window, int x, int y, string title);
	static void InitAudioSystem();
};