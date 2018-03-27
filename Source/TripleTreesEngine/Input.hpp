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
		stopmusic
	};

	void UpdateInput(sf::Time time);
	void ReadTimeAction(sf::Time time, Actions action);

	GameObjectManager* m_gameObjectManager;
	std::map<sf::Keyboard::Key, Actions> m_keyMap;
};


