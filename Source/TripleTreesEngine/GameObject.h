#pragma once
/*
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "BaseComponent.h"
#include "Transform.h"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

class GameObject {
public:
	GameObject() { parent = NULL; }
	~GameObject(void);

	void SetTransform(const sf::Transform &matrix) { transform = matrix; }
	sf::Transform GetTransform() { return transform; }
	sf::Transform GetWorldTransform() { return worldTransform; }

	void SetParent(GameObject& p) { parent = &p; }
	void AddChild(GameObject* s);

	virtual void Update(float msec);
private:
	sf::Transform worldTransform;
	sf::Transform transform;

	GameObject* parent;
	std::vector<GameObject*> children;
};
*/


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