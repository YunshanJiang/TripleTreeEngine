#include "TripleTreeEngine.h"


TripleTreeEngine::TripleTreeEngine() :
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
	if (!Initialize::CheckHardDriveSpace(300 * 1024 * 1024)) {
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
		cout << "Check CPU speed failure, CPU speed too low" << endl;
		return false;
	}

	//Initalize physics engine
	m_physicsEngine = new PhysicsEngine();

	//Initialize gameobject manager
	m_gameObjectManager = new GameObjectManager();

	//Initialize all screens
	m_gameScreen = new GameScreen(m_gameObjectManager, m_physicsEngine);
	m_Input = new CheckInput(m_gameObjectManager);
	//Initialize audio system
	Initialize::InitAudioSystem();

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

	while (m_gameState != Exiting)
	{
		//Window event and begin game.
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
				//Load screen
				LoadScreen(m_gameScreen);
				m_gameState = Running;
			}
		}

		//while playing
		while (m_gameState == Running)
		{
			GameLogicLoop();
		}
	}

	m_mainWindow.close();
}

void TripleTreeEngine::GameLogicLoop() {
	//check input
	
	m_Input->UdateInput(runtime);
	if (m_Input->LeaveGame())
	{
		m_gameState = Exiting;
	}
	//update physics
	m_physicsEngine->UpdatePhysics(runtime);

	//Update
	m_gameObjectManager->Update(runtime);

	//update AI

	//Late update
	m_gameObjectManager->LateUpdate(runtime);

	// render
	Render();

	// play audio
}

void TripleTreeEngine::Render() {
	m_mainWindow.clear();
	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (SpriteRenderComponent* r = dynamic_cast<SpriteRenderComponent*>((*j))) {
				r->Render(m_mainWindow, i->second);
			}
		}
	}
	m_mainWindow.display();
}

void TripleTreeEngine::LoadScreen(BaseScreen* screen) {
	m_gameObjectManager->m_Objects.clear();
	screen->Awake();
}