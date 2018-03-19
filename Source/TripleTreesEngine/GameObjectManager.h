#ifndef GameObjectManager_h
#define GameObjectManager_h


#include <stdio.h>
#include "iostream"
#include <map>
#include <list>
#include <iterator>

#include "GameObject.h"


class GameObjectManager
{
public:
	GameObject* CreateObject();

	void Update(sf::Time time);
	void Awake();
	void Start();
	void LateUpdate(sf::Time time);

	std::map<int, GameObject*> m_Objects;

private:
	static int nextObjectID;
};

#endif