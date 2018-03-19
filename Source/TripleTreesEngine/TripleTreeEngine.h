#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SplashScreen.hpp"
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

	enum GameState {
		Uninitialized, Initialized, Paused,
		Running, Exiting
	};
	GameState m_gameState;
	GameObjectManager m_gameObjectManager;
	sf::RenderWindow m_mainWindow;
	sf::Time runtime = sf::milliseconds(100);

	BaseScreen* m_screen;
	SplashScreen m_splashScreen;
	GameScreen m_gameScreen;
};