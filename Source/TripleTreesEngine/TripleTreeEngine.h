#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SplashScreen.hpp"

class TripleTreeEngine
{
public:
	TripleTreeEngine();
	void Start();
	void Initialize();
private:
	void GameLogicLoop();

	enum GameState {
		 Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};
	GameState m_gameState;
	sf::RenderWindow m_mainWindow;
	SplashScreen m_splashScreen;
};