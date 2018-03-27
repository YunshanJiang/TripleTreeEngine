#include "Input.hpp"

Input::Input(GameObjectManager* GameObjectManager) {
	
	m_gameObjectManager = GameObjectManager;
	
	//Define key and actions
	m_keyMap[sf::Keyboard::W] = Actions::MoveForward;
	m_keyMap[sf::Keyboard::S] = Actions::MoveBack;
	m_keyMap[sf::Keyboard::A] = Actions::MoveLeft;
	m_keyMap[sf::Keyboard::D] = Actions::MoveRight;

	m_keyMap[sf::Keyboard::Escape] = Actions::LeaveGame;
	m_keyMap[sf::Keyboard::Q] = Actions::stopmusic;
}

void Input::UpdateInput(sf::Time time) {
	
	for (std::map<sf::Keyboard::Key, Actions>::iterator i = m_keyMap.begin(); i != m_keyMap.end(); ++i) {
		if (sf::Keyboard::isKeyPressed(i->first))
		{
			ReadTimeAction(time, i->second);
		}
	}
}

void Input::ReadTimeAction(sf::Time time, Actions action) {
	std::map<int, GameObject*> temp_Objects = m_gameObjectManager->m_Objects;
	
	switch (action)
	{
	case  Actions::MoveForward:
		for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
			if (i->second->Tag == Player)
			{
				i->second->transform.m_Position.y -= time.asSeconds();
			}
		}
		break;
	case Actions::MoveBack:
		for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
			if (i->second->Tag == Player)
			{
				i->second->transform.m_Position.y += time.asSeconds();
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
		for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
			if (i->second->Tag == Player)
			{
				i->second->transform.m_Position.x -= time.asSeconds();
			}
		}
		break;
	case Actions::MoveRight:
		for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
			if (i->second->Tag == Player)
			{
				i->second->transform.m_Position.x += time.asSeconds();
			}
		}
		break;
	}
}
