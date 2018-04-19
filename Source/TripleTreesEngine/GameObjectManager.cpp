#include "GameObjectManager.h"

// Initialize our static unique objectID generator
int GameObjectManager::nextObjectID = 0;

void GameObjectManager::Awake() {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Awake();
	}
}

void GameObjectManager::Start() {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Start();
	}
}

void GameObjectManager::Update(sf::Time time) {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		//(i->second)->Update(time);
		
	}
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end();)
	{
		(i->second)->Update(time);
		if (i->second->isdead)
		{
			i = m_Objects.erase(i);
		}
		else
		{
			i++;
		}
	}
	
}

void GameObjectManager::LateUpdate(sf::Time time) {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->LateUpdate(time);
	}
}

GameObject* GameObjectManager::CreateObject()
{
	GameObject* newObj = new GameObject(nextObjectID++);
	m_Objects[newObj->GetObjectID()] = newObj;

	return newObj;
}

