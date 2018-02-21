#include <stdio.h>
#include "iostream"
#include <map>
#include <list>
#include <iterator>

#include "GameObject.hpp"


class GameObjectManager
{
public:
	GameObject* CreateObject();

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);

private:
	std::map<int, GameObject*> m_Objects;
	static int nextObjectID;
};