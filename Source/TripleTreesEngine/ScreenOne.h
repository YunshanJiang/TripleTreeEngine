#pragma once
#pragma once
#ifndef DemoOne_h
#define DemoOne_h

#include "BaseScreen.h"
#include "RigidbodyComponent.h"
#include "tinyxml2.h"
#include "Input.hpp"

#include <iostream>
#include <vector>

using namespace tinyxml2;

class ScreenOne : public BaseScreen
{
public:
	ScreenOne(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine);
	void Awake(Input* input);
	void Update(sf::Time time);
	std::vector<GameObject*> background;
	std::vector<GameObject*> block;
	GameObject* player;
	GameScreenRep m_currentscreen = InGameScreen;
	bool loadedscreen = false;
	int timer = 0;
private:
	GameObject* lifetext;
	GameObject* timertext;
	sf::Clock thecolck;

	void SpawnEnemy();
	sf::Clock spawnClock;
	int spawnTime = 0;

};

#endif