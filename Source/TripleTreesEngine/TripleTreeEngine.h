#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SplashScreen.hpp"
#include "PhysicsEngine.hpp"
#include "GameObjectManager.h"
#include "GameScreen.h"
#include "BaseScreen.h"

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

	enum GameState {
		Uninitialized, Initialized, Paused,
		Running, Exiting
	};
	GameState m_gameState;
	sf::Time runtime = sf::milliseconds(100);

	sf::RenderWindow m_mainWindow;
	PhysicsEngine* m_physicsEngine;
	GameObjectManager* m_gameObjectManager;


	SplashScreen m_splashScreen;
	GameScreen* m_gameScreen;
};