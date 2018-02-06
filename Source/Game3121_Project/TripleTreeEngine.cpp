#include "TripleTreeEngine.h"
#include "Initialization.cpp"
#include "windows.h"
#include <shlobj.h>
#include "direct.h"

#include <iostream>
using namespace std;


bool CheckStorage(const DWORDLONG diskSpaceNeeded) {

	// Check for enough free disk space on the current disk.

	int const drive = _getdrive();

	struct _diskfree_t diskfree;

	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters =

		diskSpaceNeeded / (diskfree.sectors_per_cluster*diskfree.bytes_per_sector);



	if (diskfree.avail_clusters < neededClusters) {

		// if you get here you don¡¯t have enough disk space!

		cout << "CheckStorage Failure : Not enough physical storage." << endl;

		return false;

	}

	return true;

}



DWORD ReadCPUSpeed() {

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

	return dwMHz;

}



void checkMemory(int MB) {

	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;


	cout << "the RAM available is: " << memInfo.ullTotalPhys / MB << " MB." << endl;

	cout << "The visual memory is: " << totalVirtualMem / MB << " MB." << endl;

}

void TripleTreeEngine::Start(void) {

}

void TripleTreeEngine::Initialize(void) {
	//mMainWindow.create(sf::VideoMode(1024, 768, 32), "MyGame");
	//mGameState = Playing;
	int MB = 1024 * 1024;
	checkMemory(MB);
	system("pause");
}


