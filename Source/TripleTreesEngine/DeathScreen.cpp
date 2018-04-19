#include "DeathScreen.h"
#include <iostream>


DeathScreen::DeathScreen(GameObjectManager* gameObjManager, PhysicsEngine* physicsEngine) {
	m_gameObjectManager = gameObjManager;
	m_physicsEngine = physicsEngine;
}



void DeathScreen::Awake(Input* input, int score) {
	baseinput = input;
	thegamescore = score;
	for (std::map<int, GameObject*>::iterator i = m_gameObjectManager->m_Objects.begin(); i != m_gameObjectManager->m_Objects.end(); ++i) {
		if (i->second->Tag == RestartButton) {
			buttonReStart = i->second;
		}
		else if (i->second->Tag == MainMenuButton) {
			buttonMainMenu = i->second;
		}
		else if (i->second->Tag == ExitButton) {
			buttonExit = i->second;
		}
		else if (i->second->Tag == TimerText) {
			ScoreText = i->second;
		}
		else if (i->second->Tag == LifeText) {
			GameOverText = i->second;
		}
	}
}

void DeathScreen::Update(sf::Time time) {
	ScoreText->GetTextRenderComponent()->text.setString("Your score: " + std::to_string(thegamescore));
	GameOverText->GetTextRenderComponent()->text.setString("Game End");
	if (baseinput->typed)
	{
		switch (baseinput->DeathScreenbutton)
		{
		case 0:
			buttonReStart->GetRenderCompponent()->SetTexture("../../Assets/RestartChoose.png");
			buttonMainMenu->GetRenderCompponent()->SetTexture("../../Assets/MainMenu.png");
			buttonExit->GetRenderCompponent()->SetTexture("../../Assets/Exit.png");
			break;
		case 1:
			buttonReStart->GetRenderCompponent()->SetTexture("../../Assets/Restart.png");
			buttonMainMenu->GetRenderCompponent()->SetTexture("../../Assets/MainMenuChoose.png");
			buttonExit->GetRenderCompponent()->SetTexture("../../Assets/Exit.png");
			break;
		case 2:
			buttonReStart->GetRenderCompponent()->SetTexture("../../Assets/Restart.png");
			buttonMainMenu->GetRenderCompponent()->SetTexture("../../Assets/MainMenu.png");
			buttonExit->GetRenderCompponent()->SetTexture("../../Assets/Exitchoose.png");
			break;
		default:
			break;
		}
		baseinput->typed = false;
	}
}