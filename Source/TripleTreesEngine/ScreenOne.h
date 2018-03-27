#pragma once
#pragma once
#ifndef DemoOne_h
#define DemoOne_h

#include "BaseScreen.h"
#include "RigidbodyComponent.h"

#include <iostream>

class ScreenOne : public BaseScreen
{
public:
	ScreenOne(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine);
	void Awake();
};

#endif