#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class TripleTreeEngine {
public:
	static void Start();
	static void Initialize();
private:
	static void GameLoop();

	static enum GameState
	{
		Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting
	};
	static GameState mGameState;
	static sf::RenderWindow mMainWindow;
};