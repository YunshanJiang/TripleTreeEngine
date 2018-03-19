#pragma once
#ifndef GameScreen_h
#define GameScreen_h

#include "BaseScreen.h"
#include <iostream>

class GameScreen : public BaseScreen
{
public:
	GameScreen(GameObjectManager* gameObjManager);

	void Awake();
	void Start();
	void Update(sf::Time time);
	void LateUpdate(sf::Time time);
	void Render(sf::RenderWindow& window);
private:
	GameObject* obj;
	GameObject* followobj;
	GameObject* followobjs;
	float a;
};

#endif

