#include "TripleTreeEngine.h"
#include "Initialize.h"

TripleTreeEngine::TripleTreeEngine():
m_mainWindow(),
m_gameState(Uninitialized)
{
	
}

bool TripleTreeEngine::Initialize() {
	//Check is only instance;
	if (!Initialize::CheckIsOnlyInstance("My Game")) {
		cout << "Check instance : One instance has already running." << endl;
		return false;
	}

	//Initialize graphic system & show splash screen
	Initialize::InitGraphicSystem(&m_mainWindow, 700, 500, "My Game");
	m_splashScreen.Show(m_mainWindow);

	//Check system
	if (!Initialize::CheckHardDriveSpace(300*1024*1024)) {
		cout << "CheckStorage failure : Not enough physical storage." << endl;
		return false;
	}

	if (!Initialize::CheckRAM(500)) {
		cout << "Check RAM failure, Not enough RAM" << endl;
		return false;
	}

	if (!Initialize::CheckInputDevice()) {
		cout << "Check input device failure, No input device" << endl;
		return false;
	}

	if (!Initialize::CheckOutputDevice()) {
		cout << "Check output device failure, No output device" << endl;
		return false;
	}

	if (!Initialize::CheckCPUSpeed(2000)) {
		cout << "Check CPU speed failure, CPU speed too low" <<endl;
		return false;
	}

	//Initialize audio system
	Initialize::InitAudioSystem();

	//Initalize other...
	//Implement here

	//Initialization success
	m_gameState = Initialized;
	return true;
}

void TripleTreeEngine::Start()
{
	if (m_gameState == Uninitialized) {
		cout << "System check failed" << endl;
		return;
	}

	while (m_gameState!=Exiting)
	{
		sf::Event event;
		while (m_mainWindow.pollEvent(event))
		{   
			//Close
			if (event.type == sf::Event::Closed) {
				m_gameState = Exiting;
			}
			//leave the splash screen and enter to in game screen
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed) {
				m_screen = &m_gameScreen;
				m_gameState = Running;
			}
		}

		//while playing
		if (m_gameState == Running)
		{
			GameLogicLoop();
		}
	}

	m_mainWindow.close();
}

void TripleTreeEngine::GameLogicLoop() {
	//check input

	//update physics

	//Update
	m_screen->Update(0);
	m_screen->m_gameObjectManager.Update(0);

	//update AI

	//Late update
	m_screen->LateUpdate(0);
	m_screen->m_gameObjectManager.LateUpdate(0);
	
	// render
	m_screen->Render(m_mainWindow);

	// play audio
}
