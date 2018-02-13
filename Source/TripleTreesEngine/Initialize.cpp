#include "Initialize.h"
#include <tchar.h>
#include <stdio.h>

bool Initialize::CheckIsOnlyInstance(LPCTSTR gameTitle) {
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	return true;
}

bool Initialize::CheckHardDriveSpace(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters =
		diskSpaceNeeded / (diskfree.sectors_per_cluster*diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) {
		// if you get here you don¡¯t have enough disk space!
		return false;
	}
	return true;
}

bool Initialize::CheckRAM(int requiredInMB) {
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);

	int unit = 1024;
	int phy = statex.ullAvailPhys / unit / unit;
	int vir = statex.ullAvailVirtual / unit / unit;

	if (phy < requiredInMB || vir < requiredInMB) {
		return false;
	}
	else
	{
		return true;
	}
}

bool Initialize::CheckInputDevice() {
	return true;
}

bool Initialize::CheckOutputDevice() {
	return true;
}

bool Initialize::CheckCPUSpeed(int requiredInGHZ) {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
	}

	if (dwMHz < requiredInGHZ) 
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Initialize::InitGraphicSystem(sf::RenderWindow* window, int x, int y, string title) {
	window->create(sf::VideoMode(x, y), title);
}

void Initialize::InitAudioSystem() {

}