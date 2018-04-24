#include "Input.hpp"

Input::Input(GameObjectManager* GameObjectManager)
{
	
	m_gameObjectManager = GameObjectManager;
	
	//Define key and actions
	m_keyMap[sf::Keyboard::W] = Actions::MoveForward;
	m_keyMap[sf::Keyboard::S] = Actions::MoveBack;
	m_keyMap[sf::Keyboard::A] = Actions::MoveLeft;
	m_keyMap[sf::Keyboard::D] = Actions::MoveRight;

	m_keyMap[sf::Keyboard::Escape] = Actions::LeaveGame;
	m_keyMap[sf::Keyboard::Q] = Actions::stopmusic;

	m_keyMap[sf::Keyboard::Space] = Actions::Choose;

}

void Input::UpdateInput(sf::Time time, sf::RenderWindow& window, GameScreenRep* cscreen, GameState* state) {
	m_currentscreen = cscreen;
	m_state = state;
	
	
	
	
	
	
	for (std::map<sf::Keyboard::Key, Actions>::iterator i = m_keyMap.begin(); i != m_keyMap.end(); ++i) {
		if (sf::Keyboard::isKeyPressed(i->first))
		{
			typed = true;
			timer = keyclock.getElapsedTime().asMilliseconds();
			
			ReadTimeAction(time, i->second);
		}
		
	}
}

void Input::ReadTimeAction(sf::Time time, Actions action) {
	std::map<int, GameObject*> temp_Objects = m_gameObjectManager->m_Objects;
	
	switch (action)
	{
	case  Actions::MoveForward:
		
		if (*m_currentscreen == MainMenuScreen)
		{
			
			if (Mainmenubutton > 0) {
				Mainmenubutton -= 1;

			}
		}
		else if(*m_currentscreen == InGameScreen)
		{
			for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
				if (i->second->Tag == Player)
				{
					//i->second->transform.m_Position.y -= time.asSeconds();
					
					for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
						if (RigidbodyComponent* r = dynamic_cast<RigidbodyComponent*>((*j))) {
							r->AddForce(sf::Vector2f(0, 8));
						}
					}
					
				}

			}
		}
		else 
		{
			
			if (timer > internal && DeathScreenbutton > 0)
			{
				DeathScreenbutton -= 1;
				keyclock.restart();
			}

		}
		
		break;
	case Actions::MoveBack:
		if (*m_currentscreen == MainMenuScreen)
		{
		
			if (Mainmenubutton < 1) {
				Mainmenubutton += 1;

			}
		}
		else if(*m_currentscreen == InGameScreen){
			for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
				if (i->second->Tag == Player)
				{
					//i->second->transform.m_Position.y += time.asSeconds();
				}
			}
		}
		else
		{
			
			if (timer > internal && DeathScreenbutton < 2)
			{
				DeathScreenbutton += 1;
				keyclock.restart();
			}

		}
		break;
	case  Actions::stopmusic:
		for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
			if (i->second->Tag == Player)
			{
				for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
					if (AudioComponent* r = dynamic_cast<AudioComponent*>((*j))) {
						r->Music.stop();
					}
				}
			}
		}
		break;
	case Actions::MoveLeft:
		if (*m_currentscreen == InGameScreen)
		{
			for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
				if (i->second->Tag == Player && i->second->transform.m_Position.x>0)
				{
					i->second->transform.m_Position.x -= time.asSeconds() * 0.5f;
				}
			}
		}
		
		break;
	case Actions::MoveRight:
		if (*m_currentscreen == InGameScreen)
		{
			for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
				if (i->second->Tag == Player)
				{
					i->second->transform.m_Position.x += time.asSeconds() * 0.5f;
				}
			}
		}
		break;

	case Actions::Choose:
		if (*m_currentscreen == MainMenuScreen)
		{
			switch (Mainmenubutton)
			{
			case 0:
				*m_currentscreen = InGameScreen;
				Mainmenubutton = 0;
				loadedscreen = true;
				break;
			case 1:
				*m_state = Exiting;
				break;
		}

		}
		else if (*m_currentscreen == DeadScreen) {
			switch (DeathScreenbutton)
			{
			case 0:
				*m_currentscreen = InGameScreen;
				DeathScreenbutton = 0;
				loadedscreen = true;
				break;
			case 1:
				*m_currentscreen = MainMenuScreen;
				DeathScreenbutton = 0;
				loadedscreen = true;
				break;
			case 2:
				*m_state = Exiting;
				break;
			}
		}
		break;
	}
	
}


