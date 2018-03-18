#pragma once
#ifndef BaseScreen_h
#define BaseScreen_h

#include "GameObjectManager.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class BaseScreen {
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update(float delta) {}
	virtual void LateUpdate(float delta) {}
	virtual void Render(sf::RenderWindow& window){}

	GameObjectManager m_gameObjectManager;
};

#endif
