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

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);

	std::map<int, GameObject*> m_Objects;

private:
	static int nextObjectID;
};

#endif