#pragma once
#ifndef GameScreen_h
#define GameScreen_h

#include "BaseScreen.h"
#include "RigidbodyComponent.h"
#include <iostream>

class GameScreen : public BaseScreen
{
public:
	GameScreen(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine);
	void Awake();
};

#endif

