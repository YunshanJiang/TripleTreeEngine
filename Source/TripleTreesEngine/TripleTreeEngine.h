#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SplashScreen.hpp"
#include "Initialize.h"
#include "GameObjectManager.h"
#include "PhysicsEngine.h"
#include "RigidbodyComponent.h"
#include "GameScreen.h"
#include "BaseScreen.h"
#include "Input.hpp"
#include "GameTag.h"
#include "ScreenOne.h"
#include "ScreenTwo.h"
#include "MainMenu.h"
#include "DeathScreen.h"
#include "ScreenManager.h"

class TripleTreeEngine
{
public:
	TripleTreeEngine();
	void Start();
	bool Initialize();

	

	
	GameState* m_gameState = new GameState(Uninitialized);
	GameScreenRep* m_currentscreen = new GameScreenRep(MainMenuScreen);
private:
	void GameLogicLoop();
	void Render();
	void LoadScreen(BaseScreen* screen, const char* screenxml);
	void LoadScreen(const char* screenPath);


	sf::Time runtime = sf::milliseconds(100);
	bool* loadedscreen = false;
	sf::RenderWindow m_mainWindow;
	PhysicsEngine* m_physicsEngine;
	GameObjectManager* m_gameObjectManager;
	Input* m_Input;
	

	ScreenManager* m_screenManager;
	SplashScreen m_splashScreen;
	GameScreen* m_gameScreen;
	ScreenOne* m_screenOne;
	ScreenTwo* m_screenTwo;
	mainMenu* m_mainMenu;
	DeathScreen* m_DeathScreen;

};