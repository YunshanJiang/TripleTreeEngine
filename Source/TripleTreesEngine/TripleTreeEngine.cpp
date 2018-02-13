#include "TripleTreeEngine.h"
#include "Initialize.h"

TripleTreeEngine::TripleTreeEngine():
m_mainWindow(),
m_gameState(Uninitialized)
{
	
}

void TripleTreeEngine::Initialize() {
	//Check system
	if (!Initialize::CheckIsOnlyInstance("My Game")) {
		cout << "Check instance : One instance has already running." << endl;
		return;
	}

	if (!Initialize::CheckHardDriveSpace(300*1024*1024)) {
		cout << "CheckStorage failure : Not enough physical storage." << endl;
		return;
	}

	if (!Initialize::CheckRAM(500)) {
		cout << "Check RAM failure, Not enough RAM" << endl;
		return;
	}

	if (!Initialize::CheckInputDevice()) {
		cout << "Check input device failure, No input device" << endl;
		return;
	}

	if (!Initialize::CheckOutputDevice()) {
		cout << "Check output device failure, No output device" << endl;
		return;
	}

	if (!Initialize::CheckCPUSpeed(2000)) {
		cout << "Check CPU speed failure, CPU speed too low" <<endl;
		return;
	}

	//Initialize graphic system
	Initialize::InitGraphicSystem(&m_mainWindow, 700, 500, "My Game");

	//Initialize audio system
	Initialize::InitAudioSystem();

	//Initalize other...
	//Implement here

	//Initialization success
	m_gameState = ShowingSplash;
}

void TripleTreeEngine::Start()
{
	if (m_gameState == Uninitialized) {
		cout << "System check failed" << endl;
		return;
	}

	while (m_gameState!=Exiting)
	{
		GameLogicLoop();
	}

	m_mainWindow.close();

}

void TripleTreeEngine::GameLogicLoop() {
	sf::Event event;
	while (m_mainWindow.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::KeyPressed
			|| event.type == sf::Event::EventType::MouseButtonPressed
			|| event.type == sf::Event::EventType::Closed) {
			m_gameState = Exiting;
		}
	}

	//Game logic start
	if (m_gameState == ShowingSplash)
	{
		m_splashScreen.Show(m_mainWindow);
	}
}
