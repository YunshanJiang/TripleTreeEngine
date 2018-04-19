#pragma once

#ifndef GameObject_h
#define GameObject_h

#include <stdio.h>
#include "BaseComponent.h"
#include "Transform.h"
#include "RenderComponent.hpp"
#include "RigidbodyComponent.h"

#include "GameTag.h"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>


class SpriteRenderComponent;
class RigidbodyComponent;
class TextRenderComponent;
class GameObject {
public:
	GameObject(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) { }

	int GetObjectID() const { return m_UniqueID; }

	void AddComponent(BaseComponent* component);
	SpriteRenderComponent* GetRenderCompponent();
	RigidbodyComponent* GetRigidbodyComponent();
	TextRenderComponent* GetTextRenderComponent();

	void SetParent(GameObject& parent) { m_Parent = &parent; }
	void AddChild(GameObject* child);

	void Update(sf::Time time);
	void Awake();
	void Start();
	void LateUpdate(sf::Time time);

	std::vector<BaseComponent*> m_Components;

public: // Members
	Transform transform;    //local transform
	sf::Transform worldTransform;
	bool isdead = false;
	int health = 1;
	GameTag Tag = GameTag::Default;

protected: // Members
	int m_UniqueID;

	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;
};
#endif