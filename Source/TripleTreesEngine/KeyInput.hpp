#pragma once
#include "GameObjectManager.h"
#include "AudioComponent.h"
#include "SFML/Window.hpp"
#include <map>
#include <vector>
#include "GameTag.h"

enum ActionName
{
	null,
	
MoveForward,
MoveBack,
LeaveGame,
stopmusic,
};

class CheckInput {
	

public:
	void awake();
	explicit CheckInput(GameObjectManager* GameObjectManager);
	void UdateInput(sf::Time time);
	bool LeaveGame();
	void ReadTimeAction(sf::Time time);
	GameObjectManager* TheGameObjectManager;
	std::map<sf::Keyboard::Key, ActionName> mKeyMap;
	ActionName actionlist;
	
};


