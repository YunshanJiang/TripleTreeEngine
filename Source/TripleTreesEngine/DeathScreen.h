#pragma once
#include "BaseScreen.h"
#include "tinyxml2.h"
#include "GameTag.h"
#include <iostream>

using namespace tinyxml2;

class DeathScreen : public BaseScreen
{
public:
	DeathScreen(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine);
	void Awake(Input* input, int score);

	void Update(sf::Time time);
	GameObject* buttonReStart;
	GameObject* buttonMainMenu;
	GameObject* buttonExit;
	GameObject* GameOverText;
	GameObject* ScoreText;
	int thegamescore;

};