#pragma once


#include "BaseScreen.h"
#include "RigidbodyComponent.h"
#include "tinyxml2.h"
#include "GameTag.h"
#include <iostream>

using namespace tinyxml2;

class mainMenu : public BaseScreen
{
public:
	mainMenu(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine);
	void Awake(Input* input);

	void Update();

	GameObject* buttonstart;
	GameObject* buttonExit;

	int screenrep = 0;
};
