#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SplashScreen.hpp"
#include "Initialize.h"
#include "GameObjectManager.h"
#include "PhysicsEngine.h"
#include "RigidbodyComponent.h"
#include "GameScreen.h"
#include "BaseScreen.h"
#include "KeyInput.hpp"
#include "GameTag.h"

class TripleTreeEngine
{
public:
	TripleTreeEngine();
	void Start();
	bool Initialize();

private:
	void GameLogicLoop();
	void Render();
	void LoadScreen(BaseScreen* screen);


	GameState m_gameState;
	sf::Time runtime = sf::milliseconds(100);

	sf::RenderWindow m_mainWindow;
	PhysicsEngine* m_physicsEngine;
	GameObjectManager* m_gameObjectManager;
	CheckInput* m_Input;

	SplashScreen m_splashScreen;
	GameScreen* m_gameScreen;
};