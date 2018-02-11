#include "TripleTreeEngine.h"
#include "Initialize.h"

void TripleTreeEngine::Initialize() {
	if (!Initialize::CheckIsOnlyInstance("My Game")) {
		cout << "Check instance : One instance has already running." << endl;
		return;
	}

	if (!Initialize::CheckHardDriveSpace(300*1024*1024)) {
		cout << "CheckStorage failure : Not enough physical storage." << endl;
		return;
	}

	if (!Initialize::CheckRAM(500)) {
		cout << "Check RAM failure, Not enough RAM";
		return;
	}

	if (!Initialize::CheckInputDevice()) {
		cout << "Check input device failure, No input device";
		return;
	}

	if (!Initialize::CheckOutputDevice()) {
		cout << "Check output device failure, No output device";
		return;
	}

	if (!Initialize::CheckCPUSpeed(2000)) {
		cout << "Check CPU speed failure, CPU speed too low";
		return;
	}
}

void TripleTreeEngine::Start()
{
	m_mainWindow.create(sf::VideoMode(200, 200), "SFML works!");
}
