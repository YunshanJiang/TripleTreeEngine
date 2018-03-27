#pragma once
#ifndef DemoTwo_h
#define DemoTwo_h

#include "BaseScreen.h"
#include "RigidbodyComponent.h"

#include <iostream>

class ScreenTwo : public BaseScreen
{
public:
	ScreenTwo(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine);
	void Awake();
};

#endif