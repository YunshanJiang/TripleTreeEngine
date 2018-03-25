#include "Keyinput.hpp"


CheckInput::CheckInput(GameObjectManager* GameObjectManager) {
	TheGameObjectManager = GameObjectManager;
	
		mKeyMap[sf::Keyboard::W] = ActionName::MoveForward;
		mKeyMap[sf::Keyboard::S] = ActionName::MoveBack;
		mKeyMap[sf::Keyboard::Escape] = ActionName::LeaveGame;
		mKeyMap[sf::Keyboard::Q] = ActionName::stopmusic;
}

void CheckInput::awake() {
	

	
}
void CheckInput::UdateInput(sf::Time time) {
	
	
		for (std::map<sf::Keyboard::Key, ActionName>::iterator i = mKeyMap.begin(); i != mKeyMap.end(); ++i) {
			if (sf::Keyboard::isKeyPressed(i->first))
			{
				actionlist = i->second;
			}
		}
		ReadTimeAction(time);
}

void CheckInput::ReadTimeAction(sf::Time time) {
	std::map<int, GameObject*> temp_Objects = TheGameObjectManager->m_Objects;
	
	
		switch (actionlist)
		{
		case  ActionName::MoveForward:
			for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
				if (i->second->Tag == Player)
				{
					i->second->transform.m_Position.y -= time.asSeconds();
				}
			}
			actionlist = null;
			break;
		case ActionName::MoveBack:
			for (std::map<int, GameObject*>::iterator i = temp_Objects.begin(); i != temp_Objects.end(); ++i) {
				if (i->second->Tag == Player)
				{
					i->second->transform.m_Position.y += time.asSeconds();
				}
			}
			actionlist = null;
			break;
		case  ActionName::stopmusic:
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
			actionlist = null;
			break;
		case ActionName::LeaveGame:

			break;
		default:
			
			break;
		}
		
	
	
}


bool CheckInput::LeaveGame() {
	if (actionlist == ActionName::LeaveGame)
		return true;
	return false;
}