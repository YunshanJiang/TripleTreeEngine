#include "MainMenu.h"
#include <iostream>

mainMenu::mainMenu(GameObjectManager* gameObjectManager, PhysicsEngine* physicsEngine)
{
	m_gameObjectManager = gameObjectManager;
	m_physicsEngine = physicsEngine;
}

void mainMenu::Awake(Input* input) {
	baseinput = input;
	

	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		if (i->second->Tag == StartButton) {
			buttonstart = i->second;
		}
		else if (i->second->Tag == ExitButton) {
			buttonExit = i->second;
		}
	}
}

void mainMenu::Update() {
	if (baseinput->typed)
	{
		
		switch (baseinput->Mainmenubutton)
		{
		case 0:
			buttonstart->GetRenderCompponent()->SetTexture("../../Assets/Startchoose.png");
			buttonExit->GetRenderCompponent()->SetTexture("../../Assets/Exit.png");
			//std::cout << 0 << std::endl;
			break;
		case 1:
		
			buttonstart->GetRenderCompponent()->SetTexture("../../Assets/Start.png");
			buttonExit->GetRenderCompponent()->SetTexture("../../Assets/Exitchoose.png");
			//std::cout << 1 << std::endl;
			break;
		default:
			break;
		}
		baseinput->typed = false;
	}
	
}