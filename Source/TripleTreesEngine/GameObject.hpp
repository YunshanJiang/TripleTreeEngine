#pragma once
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