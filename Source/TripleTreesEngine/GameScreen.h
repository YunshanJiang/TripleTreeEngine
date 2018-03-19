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
};

#endif

