#pragma once
#ifndef BaseScreen_h
#define BaseScreen_h
#include "GameObjectManager.h"
#include "PhysicsEngine.h"
#include "SFML/Window.hpp"
#include "AudioComponent.h"
#include "SFML/Graphics.hpp"
#include "Input.hpp"

class BaseScreen {
public:

	virtual void Awake(Input* input) {}

	virtual void Update(){}

	Input* baseinput;
	GameObjectManager* m_gameObjectManager;
	PhysicsEngine* m_physicsEngine;
};
#endif
