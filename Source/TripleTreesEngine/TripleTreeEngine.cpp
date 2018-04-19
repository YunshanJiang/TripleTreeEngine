#include "TripleTreeEngine.h"


TripleTreeEngine::TripleTreeEngine() :
	m_mainWindow()
	//m_gameState(Uninitialized)
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
	m_screenManager = new ScreenManager(m_gameObjectManager, m_physicsEngine);
	m_gameScreen = new GameScreen(m_gameObjectManager, m_physicsEngine);
	m_screenOne = new ScreenOne(m_gameObjectManager, m_physicsEngine);
	m_screenTwo = new ScreenTwo(m_gameObjectManager, m_physicsEngine);
	m_mainMenu = new mainMenu(m_gameObjectManager, m_physicsEngine);
	m_DeathScreen = new DeathScreen(m_gameObjectManager, m_physicsEngine);
	//Initialize input system
	m_Input = new Input(m_gameObjectManager);

	//Initialize audio system
	Initialize::InitAudioSystem();

	//Initialization success
	*m_gameState = Initialized;
	return true;
}

void TripleTreeEngine::Start()
{
	if (*m_gameState == Uninitialized) {
		cout << "System check failed" << endl;
		return;
	}

	while (*m_gameState != Exiting)
	{
		
		//Window event and begin game.
		sf::Event event;
		while (m_mainWindow.pollEvent(event))
		{
			
			//Close
			if (event.type == sf::Event::Closed) {
				*m_gameState = Exiting;
			}
			//leave the splash screen and enter to in game screen
			if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed) {
				
				//Load screen
				if (*m_gameState != Running) {
					LoadScreen(m_mainMenu, "../../Assets/MainMenu.xml");
					
					//m_screenManager->Load("../../Assets/MainMenu.xml");
					*m_gameState = Running;
				}
				else {
					if (event.type == sf::Event::EventType::KeyReleased)
					{

						m_Input->keyclock.restart();
						m_Input->timer = 0;
					}

				}
				
			}
			
		}
		
		if (m_Input->loadedscreen == true && *m_currentscreen == InGameScreen) {
			LoadScreen(m_screenOne, "../../Assets/player.xml");
			m_Input->loadedscreen = false;
		}
		else if (m_Input->loadedscreen == true && *m_currentscreen == MainMenuScreen)
		{
			m_Input->loadedscreen = false;
			m_Input->typed = false;
			m_Input->keyclock.restart();
			LoadScreen(m_mainMenu, "../../Assets/MainMenu.xml");
			std::cout << m_screenOne->loadedscreen << std::endl;

		}
		else if (*m_currentscreen != DeadScreen  && m_screenOne->loadedscreen == true) {
			m_screenOne->loadedscreen = false;
			
			*m_currentscreen = DeadScreen;
		
			LoadScreen(m_DeathScreen, "../../Assets/death.xml");
			
		}
		
		//while playing
		if (*m_gameState == Running)
		{
			GameLogicLoop();
		}
	}

	m_mainWindow.close();
}

void TripleTreeEngine::GameLogicLoop() {
	//Load screen
	if (*m_currentscreen == MainMenuScreen) {
		//LoadScreen("../../Assets/player.xml");
		m_mainMenu->Update();
	}
	else if (*m_currentscreen == InGameScreen)
	{
		//LoadScreen(m_screenTwo);
		m_screenOne->Update(runtime);
	}
	else if (*m_currentscreen == DeadScreen)
	{
		//LoadScreen(m_gameScreen);
		m_DeathScreen->Update(runtime);
	}

	//check input
	m_Input->UpdateInput(runtime, m_mainWindow, m_currentscreen,  m_gameState);

	//Check input for loading screen


	//update physics
	m_physicsEngine->UpdatePhysics(runtime);

	//Update
	m_gameObjectManager->Update(runtime);

	//update AI

	//Late update
	m_gameObjectManager->LateUpdate(runtime);

	// render
	Render();
}

void TripleTreeEngine::Render() {
	m_mainWindow.clear();
	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (SpriteRenderComponent* r = dynamic_cast<SpriteRenderComponent*>((*j))) {
				r->Render(m_mainWindow, i->second);
			}
			if (TextRenderComponent* r = dynamic_cast<TextRenderComponent*>((*j))) {
				r->Render(m_mainWindow);
			}
		}
	}
	m_mainWindow.display();
}

void TripleTreeEngine::LoadScreen(BaseScreen* screen, const char* screenxml) {
	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (AudioComponent* r = dynamic_cast<AudioComponent*>((*j))) {
				r->Music.stop();
				r->Sound.stop();
			}
		}
	}
	int score = m_screenOne->timer;
	m_physicsEngine->RigidBodies.clear();
	m_gameObjectManager->m_Objects.clear();
	m_screenManager->Load(screenxml);
	if (*m_currentscreen == DeadScreen)
	{
		
		m_DeathScreen->Awake(m_Input, score);
	}
	else	
		screen->Awake(m_Input);
}

void TripleTreeEngine::LoadScreen(const char* screen) {
	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (AudioComponent* r = dynamic_cast<AudioComponent*>((*j))) {
				r->Music.stop();
				r->Sound.stop();
			}
		}
	}
	m_gameObjectManager->m_Objects.clear();
	m_screenManager->Load(screen);
}

