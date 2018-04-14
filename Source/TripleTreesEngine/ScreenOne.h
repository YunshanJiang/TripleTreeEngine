#pragma once
#pragma once
#ifndef DemoOne_h
#define DemoOne_h

#include "BaseScreen.h"
#include "RigidbodyComponent.h"
#include "tinyxml2.h"

#include <iostream>

using namespace tinyxml2;

class ScreenOne : public BaseScreen
{
public:
	ScreenOne(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine);
	void Awake();
};

#endif