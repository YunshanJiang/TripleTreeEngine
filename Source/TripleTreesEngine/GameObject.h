#pragma once

#ifndef GameObject_h
#define GameObject_h

#include <stdio.h>
#include "BaseComponent.h"
#include "Transform.h"
#include "BaseMessage.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

class GameObject {
public:
	GameObject(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) {
	}

	int GetObjectID() const { return m_UniqueID; }

	void AddComponent(BaseComponent* component);


	void SetParent(GameObject& parent) { m_Parent = &parent; }
	void AddChild(GameObject* child);

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);

public: // Members
	Transform transform;    //local transform


private: // Members
	int m_UniqueID;

	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;

	sf::Transform worldTransform;
	std::vector<BaseComponent*> m_Components;
};
#endif