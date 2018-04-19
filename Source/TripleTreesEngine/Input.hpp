#pragma once
#include "GameObjectManager.h"
#include "AudioComponent.h"
#include "SFML/Window.hpp"
#include <map>
#include <vector>

#include "GameTag.h"

class Input {
public:
	Input(GameObjectManager* GameObjectManager);

	enum Actions
	{
		MoveForward,
		MoveBack,
		MoveLeft,
		MoveRight,
		LeaveGame,
		stopmusic,
		Choose,
	};


	void UpdateInput(sf::Time time, sf::RenderWindow& window, GameScreenRep* cscreen, GameState* state);
	void ReadTimeAction(sf::Time time, Actions action);

	GameObjectManager* m_gameObjectManager;
	std::map<sf::Keyboard::Key, Actions> m_keyMap;
	bool typed = false;

	sf::Clock keyclock;
	int timer = 0;
	int internal = 500;
	GameScreenRep* m_currentscreen;
	GameState* m_state;
	bool  loadedscreen = false;
	//track the button
	int Mainmenubutton = 0;
	int DeathScreenbutton = 0;
	
};


