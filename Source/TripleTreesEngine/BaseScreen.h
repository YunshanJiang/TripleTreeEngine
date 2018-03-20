#pragma once
#ifndef BaseScreen_h
#define BaseScreen_h
#include "GameObjectManager.h"
#include "PhysicsEngine.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class BaseScreen {
public:

	virtual void Awake() {}

	GameObjectManager* m_gameObjectManager;
	PhysicsEngine* m_physicsEngine;
};
#endif
